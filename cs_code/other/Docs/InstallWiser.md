# Install Wiser to build DotNetIsolator
_[↖ Back to Readme](../README.md)_
## Prerequisites

1. Download and Install Rust & Cargo `https://win.rustup.rs/` (After running the tool, you will see text in the CLI, press enter to install, if you add any other key, it will quit).

2. Refresh the path.
```ps
$env:Path = [System.Environment]::GetEnvironmentVariable("Path","Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path","User") 
```

3. Temporarily disable file antivirus (Rust is sus)

4. Then Install Wiser
```ps
cargo install wizer --all-features
```

5. Build with dotnet CLI (will build all projects)
```ps
dotnet build 
```

6. Run tests
```ps
dotnet test
```

## Ignore these steps, visual studio is dumb, it requires a computer restart as far as I could test.
5. Visual Studio and CMD may not recognize new Path variables. To fix this we can install a package manager Chocolatey and install a script to update the path on cmd.<br/>
Open an **Administrative** PowerShell window and Install Chocolatey.
```ps
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```

6. Open a CMD window and run
```ps
SET "PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin"
```

7. Then run RefreshEnv
```cmd
RefreshEnv
```
---
_[↖ Back to Readme](../README.md)_