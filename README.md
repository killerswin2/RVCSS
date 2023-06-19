### What is RVCSS
RVCSS (Real Virtual C Sharp Scripting) is a intercept based plugin that allows for script writting in C# instead of sqf.

### Who is this for?
This project was designed as a entire replacement of sqf. RVCSS main target is developers, mainly those tired of SQF, and want modern language features that SQF cannot provide. RVCSS is not designed for beginners of Arma 3 modding. Beginners should instead focus on learning more about SQF, Arma 3 in general,  and design some scripts before moving on to RVCSS. 

## Requirements to use
RVCSS currently only works on windows (2023-06-18). (Linux support will be provided later) As such given the nature of C#, developers should install the [.NET 7 SDK](http://https://dotnet.microsoft.com/en-us/download/dotnet/7.0 ".NET SDK"). Non-devs should install [ASP.NET Core Runtime 7.0.5 and .NET Runtime 7.0.5](http://https://dotnet.microsoft.com/en-us/download/dotnet/7.0 ".NET SDK"). Installation of .NET Desktop Runtime 7.0.5 will be left up to developers, if they want to target features from it.

## Offical Requirements
- [CBA](https://github.com/CBATeam/CBA_A3)
- [Intercept](https://github.com/intercept/intercept)
-  [ASP.NET Core Runtime 7.0.5 and .NET Runtime 7.0.5](http://https://dotnet.microsoft.com/en-us/download/dotnet/7.0 ".NET SDK").

### Building Requirements
TODO

### Example of use
C# code
```csharp
using System;
using System.Runtime.InteropServices;
using System.Numerics;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using RV;
namespace arma_code
{
    public static class Printer
    {
        public delegate void CustomEntryPointDelegate();
        public static void EntryLocation()
        {
            Console.WriteLine("Before");
            GameValue hello = new GameValue("Hello!");
            GameValue.SystemChat(hello);

            List<int> list = new List<int>() {10, 20, 30};
            GameValue array = new GameValue(list);
            GameValue arrayStr = GameValue.Str(array);
            String gameString = GameValue.GetString(arrayStr);

            Console.WriteLine("Well this is from Arma 3: " + gameString);

            GameValue vectorDis = GameValue.VectorDistance(array, new GameValue(new Vector3(100, 200, 330)));
            GameValue.SystemChat(GameValue.Str(vectorDis));

            // convert to c# native vector3
            float distance = GameValue.GetFloat(vectorDis);
            Console.WriteLine("distance: " + distance);
            float velocity = 10.0f; //10 m/s

            float timeToReach = distance / velocity;
            String message = string.Format("This object will travel {0} meters in {1} secs.", distance, timeToReach);

            GameValue.Diag_log(new GameValue(message));
            Console.WriteLine(message);

        }
    }
}

```
SQF code
```
// recommended to place the return value of csLoad into a global. As calling multiple times initializes more runtimes.
A3A_CSHOST = csLoad "test_cs_code";
A3A_CSHOST csCall ["EntryLocation","CustomEntryPointDelegate"];
```