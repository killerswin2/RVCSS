using System;
using System.Runtime.InteropServices;
using System.Numerics;
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
            Console.WriteLine("Before!");
            GameObject gameObject = new GameObject("B_T_LSV_01_unarmed_F", new Vector3(0.0f));
            Vector3 pos = new Vector3(25.0f, 0.0f, 0.0f);

            gameObject.SetPos(pos);
            Vector3 getpos = gameObject.GetPos();

            Console.WriteLine("X:{0} Y:{1} Z:{2}", getpos.X, getpos.Y, getpos.Z);

            bool isAlive = gameObject.Alive();

            if (isAlive)
            {
                Console.WriteLine("Alive");
                Console.WriteLine("Vehicle: {0} is alive", gameObject.TypeOf());
            }
            else
            {
                Console.WriteLine("Dead");
                Console.WriteLine("Vehicle: {0} is dead", gameObject.TypeOf());
            }
        }
    }
}
