using System.Text.Json;

if (GetConfigPath(args) is not string configPath)
    return;
if (GetBuildConfig(configPath) is not BuildConfig buildConfig)
    return;
PostBuildRoutine(buildConfig);

string? GetConfigPath(string[] args) {
    if (args.Length < 1) {
        Console.WriteLine("Expected first argument to contain the path to the build config.");
        return null;
    }
    string path = args[0];
    Console.WriteLine($"PostBuild Config path: {path}");
    // Check that path is absolute, otherwise, prefix with current directory
    if (!Path.IsPathFullyQualified(path)) {
        path = Path.GetFullPath(path: path, basePath: Environment.CurrentDirectory);
        Console.WriteLine($"PostBuild Config path was not fully qualified, corrected to: {path}");
    }
    string configPath = Path.GetFullPath(path: "config.json", basePath: path);
    return configPath;
}

BuildConfig? GetBuildConfig(string jsonFilePath) {
    try {
        using FileStream fileStream = new(jsonFilePath, FileMode.Open, FileAccess.Read);
        // Allow case-insensitive property names for the config
        JsonSerializerOptions jsonOptions = new(JsonSerializerOptions.Default) { PropertyNameCaseInsensitive = true };
        BuildConfig? data = JsonSerializer.Deserialize<BuildConfig>(fileStream, jsonOptions);
        if (data is null)
            Console.WriteLine($"Failed to deserialize json file: {jsonFilePath}");
        return data;
    } catch (IOException e) when (e is FileNotFoundException or DirectoryNotFoundException) {
        Console.WriteLine($"Bad build config file path: {jsonFilePath}");
        return null;
    }
}

void PostBuildRoutine(BuildConfig buildConfig) {
    string filePath = Path.GetFullPath(path: buildConfig.FileName, basePath: buildConfig.BuildPath);
    if (!File.Exists(filePath)) {
        Console.WriteLine($"Bad file path: {filePath}");
        return;
    }

    // try copy to new location
    try {
        string outputcopyPath = Path.GetFullPath(path: buildConfig.FileName, basePath: buildConfig.OutputPath);
        // copy and allow overrides
        File.Copy(filePath, outputcopyPath, true);
    } catch (IOException e) when (e is FileNotFoundException or DirectoryNotFoundException) {
        Console.WriteLine($"Bad Directory path: {buildConfig.OutputPath}");
    }
}

/// <summary> Used for Json storage of build configuration.</summary>
/// <param name="BuildPath"> Location of dll / shared lib </param>
/// <param name="OutputPath"> where to place the dll / shared lib </param>
/// <param name="FileName"> the filename of the dll / shared lib </param>
record class BuildConfig(string BuildPath = "", string OutputPath = "", string FileName = "");
