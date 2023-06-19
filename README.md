### What is RVCSS
RVCSS (Real Virtual C Sharp Scripting) is a intercept based plugin that allows for script writting in C# instead of sqf.

### Who is this for?
This project was designed as a entire replacement of sqf. RVCSS main target is developers, mainly those tired of SQF, and want modern language features that SQF cannot provide. RVCSS is not designed for beginners of Arma 3 modding. Beginners should instead focus on learning more about SQF, Arma 3 in general,  and design some scripts before moving on to RVCSS. 

## Requirements to use
RVCSS currently only works on windows (2023-06-18). (Linux support will be provided later) As such given the nature of C#, developers should install the [.NET 7 SDK](http://https://dotnet.microsoft.com/en-us/download/dotnet/7.0 ".NET SDK"). Non-devs should install [ASP.NET Core Runtime 7.0.5 and .NET Runtime 7.0.5](http://https://dotnet.microsoft.com/en-us/download/dotnet/7.0 ".NET SDK"). Installation of .NET Desktop Runtime 7.0.5 will be left up to developers, if they want to target features from it.

## Offical Requirements
- [CBA](https://github.com/CBATeam/CBA_A3)
- [Intercept](https://github.com/intercept/intercept)
- [ASP.NET Core Runtime 7.0.5 and .NET Runtime 7.0.5](http://https://dotnet.microsoft.com/en-us/download/dotnet/7.0 ".NET SDK").

### Building Requirements
TODO

### Example of use
This C# code is the code we will use, look over it, and notice a few things.
RVCSS requires that your code be wrapped into a namespace with same name as your output assembly. Entry Classes, must be declared as public static else RVCSS will fail on function finding. Entry functions must have a delegate, look at lines 13 and 14. EntryLocation is the method that we will call but RVCSS requires that there be a delegate involved. This was mainly done to allow for more complex functions and functions paramters later.
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

### Developing with RVCSS
RVCSS implements two sqf commands that it depends on for initialization and calling methods in C#.

##### csLoad
csLoad loads the assembly code for cs and initializes the runtime.
It takes a string as an argument. This string is the classname under the rvcss class.
csLoad returns a cs_game_data_type, which is an object that holds the host context.
###### csLoad Example
```
A3A_CSHOST = csLoad "test_cs_code";
```
##### csCall
csCall simple calls the method supplied using the initialized runtime, host context, and loaded assembly code.
It takes two arguments. The left arg is the cs_game_data_type c# host and loaded assembly. The right arg is an array of strings of size two. The first element in the array is the method name to call. The second element is the custom delegate name used for the call.
###### csCall Example
```
A3A_CSHOST csCall ["EntryLocation","
CustomEntryPointDelegate"];
```
#### C Sharp Development
RVCSS provides a binding (wrapper) for every single SQF function. These functions call the underlying c++ code for the SQF function. Now because of the nature of c# being managed code and c++ unmanaged, we have to [p/invoke](https://learn.microsoft.com/en-us/dotnet/standard/native-interop/pinvoke). Special care was done to make sure that the invokes are done fast, meaning there is no stack walking for unmanaged code. Further more because of design choices and development use, namely not using the mono runtime, we don't declare these are interall calls. What does that mean, well don't expect RVCSS to be as fast as native c++ calls, but they "should" be faster than SQF. (Do not quote me on this)

Now that is out of the way, lets talk about real development. RVCSS expects your assemblies to be in a certain file under the name of "assembly" in your mod directory.

![Screenshot 2023-06-18 194915](https://github.com/killerswin2/RVCSS/assets/8095345/1b602541-7153-46cf-ae56-77a295e601fa)
![Screenshot 2023-06-18 194941](https://github.com/killerswin2/RVCSS/assets/8095345/d811cfe7-224f-41a8-b038-a23dfc346cde)

If assembly does not exist or RVCSS can not find, RVCSS will not work.

#### General Arma Development
RVCSS requires a config class with members: 
- assemblyName: string - assembly (dll) name
- assemblyClassName - assembly class name, the static public class in assembly

```
class rvcss
{
	class test_cs_code //Change this. It's the classname that you pass to csLoad
	{ 
		assemblyName = "arma_code";
		assemblyClassName = "Printer";
	};
};
```
