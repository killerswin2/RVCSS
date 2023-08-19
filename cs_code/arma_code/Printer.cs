using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using System.Numerics;
using System.Text;
using RV;
using RV.Scripting;
using System.Text.Encodings.Web;

namespace arma_code
{
    public static class Printer
    {
        public delegate void CustomEntryPointDelegate();
        public static void EntryLocation()
        {
            TestGameDataReferences.TestReferences();
            Value floatValue = new Value(20.0f);
            Value boolValue = new Value(true);
            Value stringValue = new Value("String!");

            Value player = GameValueMethods.Player();
            Value radius = new Value(1000.0f);
            Value roads = new Value(GameValueMethods.NearRoads(player.Data, radius.Data));
            //GameValueMethods.TestGameData(player.Data);

            //String? returnString = roads.ToString();
            //Console.WriteLine("Roads: {0}", returnString);

            // Now Test the player again!!!
            //String? playerString = player.ToString();
            //Console.WriteLine("Player: {0}", playerString);

            RVArray types = new() { "ROAD" };

            RVArray nearestParams = new() {
                player, 
                types,
                3000.0f,
                false,
                false
            };

            Value nearestTerrain = GameValueMethods.NearestTerrainObjects(nearestParams);
            Console.WriteLine("Nearest Terrain Objects: {0}", nearestTerrain.ToString());

        }
    }
}
