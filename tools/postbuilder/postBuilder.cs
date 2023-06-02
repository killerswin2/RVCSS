using Newtonsoft.Json;
using System;
using System.IO;

public class JsonData
{
    // location of dll / shared lib
    public string buildPath = string.Empty;
    // where to place the dll / shared lib
    public string outputPath = string.Empty;
    // the filename of the dll / shared lib
    public string fileName = string.Empty;
}

public class ReadAndParseJson
{
    private readonly string _JsonFilePath;
    public ReadAndParseJson(string JsonFilePath)
    {
        if(!File.Exists(JsonFilePath))
        {
            Console.WriteLine($"Bad file path: {JsonFilePath}");
            return;
        }
        _JsonFilePath = JsonFilePath;
    }

    public JsonData UserDefinedObject()
    {
        using StreamReader reader = new(_JsonFilePath);
        var json = reader.ReadToEnd();
        JsonData data = JsonConvert.DeserializeObject<JsonData>(json);
        return data;
    }
}

public class Program
{
    public static void Main(String[] args)
    {
    
        string path = args[0];
        Console.WriteLine(path);
        ReadAndParseJson parser = new ReadAndParseJson(path + "/"+"config.json");
        JsonData json = parser.UserDefinedObject();
        PostBuildRoutine(json);
    }

    public static void PostBuildRoutine(JsonData json)
    {
        string filepath = json.buildPath + "/" +json.fileName;
        if(!File.Exists(filepath))
        {
            Console.WriteLine($"Bad file path: {filepath}");
            return;
        }

        // try to copy to new location
        // First check that dir exists
        if(!Directory.Exists(json.outputPath))
        {
            Console.WriteLine($"Bad Directory path: {json.outputPath}");
            return;
        }

        // now copy to new location
        try
        {
            string outputcopyPath = json.outputPath + "/" +json.fileName;
            // copy and allow overrides
            File.Copy(filepath, outputcopyPath, true);
        } 
        catch (Exception e)
        {
            Console.WriteLine(e.Message);
            return;
        }
    }
}