using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using System.Security;
using System.Text;
using System.Numerics;
using System.Collections;

namespace RV
{
    namespace Scripting
    {
        /// <summary>
        /// Class <c>Value</c> Is the GameValue data encapsulation.
        /// </summary>
        public class Value
        {
            [NonSerialized]
            protected GameValue _gameData;
            public GameValue Data => _gameData;
            public Value()
            {
                _gameData = GameValueMethods.CreateGameValue();
            }

            public Value(float value)
            {
                _gameData = GameValueMethods.CreateGameValue(value);
            }

            public Value(bool value)
            {
                _gameData = GameValueMethods.CreateGameValue(value);
            }

            public Value(String value)
            {
                _gameData = GameValueMethods.CreateGameValue(value);
            }

            public Value(Value instance)
            {
                _gameData = instance._gameData;
            }

            public Value(AutoArray array)
            {
                _gameData = GameValueMethods.CreateGameValue(array);
            }

            public Value(GameValue pointer)
            {
                _gameData = pointer;
            }

            public Value(RVArray array)
            {
                _gameData = GameValueMethods.CreateGameValue(array._array);
            }

            ~Value()
            {
                GameValueMethods.DeleteGameValue(_gameData.data);
            }

            public override string ToString()
            {
                if (Type() == VTablePtrs.GameDataString)
                {
                    return GetAsString();
                }
                else
                {
                    unsafe
                    {
                        GameValue gameString = GameValueMethods.Str(_gameData);
                        GameDataString* gameStringData = (GameDataString*)gameString.data.ToPointer();
                        RString* rawGameString = (RString*)gameStringData->rawString.ToPointer();

                        String? returnString = Marshal.PtrToStringUTF8(new nint(&rawGameString->_string))!;
                        return returnString;
                    }
                }
            }

            // cast/conversion operators
            public static implicit operator Value(float value) => new Value(value);
            public static implicit operator Value(bool value) => new Value(value);
            public static implicit operator Value(String value) => new Value(value);
            public static implicit operator Value(RVArray array) => new Value(array);
            public static implicit operator Value(AutoArray array) => new Value(array);
            public static implicit operator Value(GameValue gValue) => new Value(gValue);

            // implicit conversion for gamevalue
            public static implicit operator GameValue(Value value) => value.Data;

            // cast/conversion operators explicit
            public static explicit operator float(Value value) => value.GetAsFloat();
            public static explicit operator bool(Value value) => value.GetAsBool();
            public static explicit operator string(Value value) => value.ToString();
            public static explicit operator RVArray(Value value) => value.GetAsArray();

            /// <summary>
            /// Returns the Vtable Pointer for GameValue
            /// </summary>
            public IntPtr Getvtptr()
            {
                return _gameData._vtptr;
            }

            // Returns the VTPTR for type checking
            public IntPtr Type()
            {
                unsafe
                {
                    // convert to base type and get the vtableptr
                    GameData* pointer = (GameData*)_gameData.data.ToPointer();
                    if (pointer == null)
                    {
#if DEBUG
                        Console.WriteLine("Pointer null");
#endif
                        throw new NullReferenceException("data member points to a null value");
                    }
                    return pointer->_vtptr;
                }
            }

            public RVArray GetAsArray()
            {
                unsafe
                {
                    if (Type() != VTablePtrs.GameDataArray)
                    {
                        throw new BadTypeException("RVValue is not of Type Array");
                    }
                    GameDataArray* array = (GameDataArray*)_gameData.data.ToPointer();
                    return new RVArray(array->data);
                }
            }

            public void SetAsArray(RVArray value)
            {
                unsafe
                {
                    if (Type() != VTablePtrs.GameDataArray)
                    {
                        throw new BadTypeException("RVValue is not of Type Array");
                    }
                    GameDataArray* array = (GameDataArray*)_gameData.data.ToPointer();
                    array->data = value._array;
                }
            }

            public bool GetAsBool()
            {
                unsafe
                {
                    if (Type() != VTablePtrs.GameDataBool)
                    {
                        throw new BadTypeException("RVValue is not of Type Bool");
                    }
                    GameDataBool* booldata = (GameDataBool*)_gameData.data.ToPointer();
                    return Convert.ToBoolean(booldata->val);
                }
            }

            public void SetAsBool(bool value)
            {
                unsafe
                {
                    if (Type() != VTablePtrs.GameDataBool)
                    {
                        throw new BadTypeException("RVValue is not of Type Bool");
                    }
                    GameDataBool* booldata = (GameDataBool*)_gameData.data.ToPointer();
                    booldata->val = Convert.ToByte(value);
                }
            }

            public float GetAsFloat()
            {
                unsafe
                {
                    if (Type() != VTablePtrs.GameDataNumber)
                    {
                        throw new BadTypeException("RVValue is not of Type Float");
                    }
                    GameDataNumber* number = (GameDataNumber*)_gameData.data.ToPointer();
                    return number->number;
                }
            }

            public void SetAsFloat(float value)
            {
                unsafe
                {
                    if (Type() != VTablePtrs.GameDataNumber)
                    {
                        throw new BadTypeException("RVValue is not of Type Float");
                    }
                    GameDataNumber* number = (GameDataNumber*)_gameData.data.ToPointer();
                    number->number = value;
                }
            }

            public string GetAsString()
            {
                unsafe
                {
                    String? str = String.Empty;
                    if (Type() != VTablePtrs.GameDataString)
                    {
                        throw new BadTypeException("RVValue is not of Type String");
                    }
                    GameDataString* stringData = (GameDataString*)_gameData.data.ToPointer();

                    RString* rawStringData = (RString*)stringData->rawString.ToPointer();
                    Console.WriteLine("RawString value: {0}", rawStringData->_size);
                    void* stringBuffer = &rawStringData->_string;

                    if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
                    {
                        str = Marshal.PtrToStringUTF8(new nint(stringBuffer))!;
                    }
                    return str;
                }
            }
            public static Value abs(Value rightGameValue)
            {
                return GameValueMethods.unary__abs__scalar_nan__ret__scalar_nan(rightGameValue);
            }
            public static Value acos(Value rightGameValue)
            {
                return GameValueMethods.unary__acos__scalar_nan__ret__scalar_nan(rightGameValue);
            }
            public static void action(Value rightGameValue)
            {
                GameValueMethods.unary__action__array__ret__nothing(rightGameValue);
            }
            public static Value actionids(Value rightGameValue)
            {
                return GameValueMethods.unary__actionids__object__ret__array(rightGameValue);
            }
            public static Value actionkeys(Value rightGameValue)
            {
                return GameValueMethods.unary__actionkeys__string__ret__array(rightGameValue);
            }
            public static Value actionkeys(Value rightGameValue)
            {
                return GameValueMethods.unary__actionkeys__array__ret__array(rightGameValue);
            }
            public static Value actionkeysex(Value rightGameValue)
            {
                return GameValueMethods.unary__actionkeysex__string__ret__array(rightGameValue);
            }
            public static Value actionkeysimages(Value rightGameValue)
            {
                return GameValueMethods.unary__actionkeysimages__string_array__ret__text(rightGameValue);
            }
            public static Value actionkeysnames(Value rightGameValue)
            {
                return GameValueMethods.unary__actionkeysnames__string_array__ret__string(rightGameValue);
            }
            public static Value actionkeysnamesarray(Value rightGameValue)
            {
                return GameValueMethods.unary__actionkeysnamesarray__string_array__ret__array(rightGameValue);
            }
            public static Value actionname(Value rightGameValue)
            {
                return GameValueMethods.unary__actionname__string__ret__string(rightGameValue);
            }
            public static void activateaddons(Value rightGameValue)
            {
                GameValueMethods.unary__activateaddons__array__ret__nothing(rightGameValue);
            }
            public static void activatekey(Value rightGameValue)
            {
                GameValueMethods.unary__activatekey__string__ret__nothing(rightGameValue);
            }
            public static Value activetitleeffectparams(Value rightGameValue)
            {
                return GameValueMethods.unary__activetitleeffectparams__scalar__ret__array(rightGameValue);
            }
            public static void add3denconnection(Value rightGameValue)
            {
                GameValueMethods.unary__add3denconnection__array__ret__nothing(rightGameValue);
            }
            public static Value add3deneventhandler(Value rightGameValue)
            {
                return GameValueMethods.unary__add3deneventhandler__array__ret__scalar(rightGameValue);
            }
            public static void addcamshake(Value rightGameValue)
            {
                GameValueMethods.unary__addcamshake__array__ret__nothing(rightGameValue);
            }
            public static void addcuratorselected(Value rightGameValue)
            {
                GameValueMethods.unary__addcuratorselected__array__ret__nothing(rightGameValue);
            }
            public static Value addforcegeneratorrtd(Value rightGameValue)
            {
                return GameValueMethods.unary__addforcegeneratorrtd__array__ret__scalar(rightGameValue);
            }
            public static void additempool(Value rightGameValue)
            {
                GameValueMethods.unary__additempool__array__ret__nothing(rightGameValue);
            }
            public static void addmagazinepool(Value rightGameValue)
            {
                GameValueMethods.unary__addmagazinepool__array__ret__nothing(rightGameValue);
            }
            public static Value addmissioneventhandler(Value rightGameValue)
            {
                return GameValueMethods.unary__addmissioneventhandler__array__ret__scalar(rightGameValue);
            }
            public static Value addmusiceventhandler(Value rightGameValue)
            {
                return GameValueMethods.unary__addmusiceventhandler__array__ret__scalar(rightGameValue);
            }
            public static Value addonfiles(Value rightGameValue)
            {
                return GameValueMethods.unary__addonfiles__array__ret__array(rightGameValue);
            }
            public static void addswitchableunit(Value rightGameValue)
            {
                GameValueMethods.unary__addswitchableunit__object__ret__nothing(rightGameValue);
            }
            public static void addtoremainscollector(Value rightGameValue)
            {
                GameValueMethods.unary__addtoremainscollector__array__ret__nothing(rightGameValue);
            }
            public static Value adduseractioneventhandler(Value rightGameValue)
            {
                return GameValueMethods.unary__adduseractioneventhandler__array__ret__scalar(rightGameValue);
            }
            public static void addweaponpool(Value rightGameValue)
            {
                GameValueMethods.unary__addweaponpool__array__ret__nothing(rightGameValue);
            }
            public static Value admin(Value rightGameValue)
            {
                return GameValueMethods.unary__admin__scalar__ret__scalar(rightGameValue);
            }
            public static Value agent(Value rightGameValue)
            {
                return GameValueMethods.unary__agent__team_member__ret__object(rightGameValue);
            }
            public static Value agltoasl(Value rightGameValue)
            {
                return GameValueMethods.unary__agltoasl__array__ret__array(rightGameValue);
            }
            public static Value aimpos(Value rightGameValue)
            {
                return GameValueMethods.unary__aimpos__object__ret__array(rightGameValue);
            }
            public static Value airdensityrtd(Value rightGameValue)
            {
                return GameValueMethods.unary__airdensityrtd__scalar__ret__scalar(rightGameValue);
            }
            public static Value airplanethrottle(Value rightGameValue)
            {
                return GameValueMethods.unary__airplanethrottle__object__ret__scalar(rightGameValue);
            }
            public static Value airportside(Value rightGameValue)
            {
                return GameValueMethods.unary__airportside__object_scalar__ret__side(rightGameValue);
            }
            public static void aisfinishheal(Value rightGameValue)
            {
                GameValueMethods.unary__aisfinishheal__array__ret__nothing(rightGameValue);
            }
            public static Value alive(Value rightGameValue)
            {
                return GameValueMethods.unary__alive__object__ret__bool(rightGameValue);
            }
            public static Value allcontrols(Value rightGameValue)
            {
                return GameValueMethods.unary__allcontrols__display__ret__array(rightGameValue);
            }
            public static Value allcontrols(Value rightGameValue)
            {
                return GameValueMethods.unary__allcontrols__control__ret__array(rightGameValue);
            }
            public static Value alldiarysubjects(Value rightGameValue)
            {
                return GameValueMethods.unary__alldiarysubjects__object__ret__array(rightGameValue);
            }
            public static Value alllods(Value rightGameValue)
            {
                return GameValueMethods.unary__alllods__object_string__ret__array(rightGameValue);
            }
            public static Value allmissionobjects(Value rightGameValue)
            {
                return GameValueMethods.unary__allmissionobjects__string__ret__array(rightGameValue);
            }
            public static Value allowedservice(Value rightGameValue)
            {
                return GameValueMethods.unary__allowedservice__object__ret__scalar(rightGameValue);
            }
            public static Value allsimpleobjects(Value rightGameValue)
            {
                return GameValueMethods.unary__allsimpleobjects__array__ret__array(rightGameValue);
            }
            public static Value allturrets(Value rightGameValue)
            {
                return GameValueMethods.unary__allturrets__array__ret__array(rightGameValue);
            }
            public static Value allturrets(Value rightGameValue)
            {
                return GameValueMethods.unary__allturrets__object__ret__array(rightGameValue);
            }
            public static Value allvariables(Value rightGameValue)
            {
                return GameValueMethods.unary__allvariables__control__ret__array(rightGameValue);
            }
            public static Value allvariables(Value rightGameValue)
            {
                return GameValueMethods.unary__allvariables__display__ret__array(rightGameValue);
            }
            public static Value allvariables(Value rightGameValue)
            {
                return GameValueMethods.unary__allvariables__team_member__ret__array(rightGameValue);
            }
            public static Value allvariables(Value rightGameValue)
            {
                return GameValueMethods.unary__allvariables__namespace__ret__array(rightGameValue);
            }
            public static Value allvariables(Value rightGameValue)
            {
                return GameValueMethods.unary__allvariables__object__ret__array(rightGameValue);
            }
            public static Value allvariables(Value rightGameValue)
            {
                return GameValueMethods.unary__allvariables__group__ret__array(rightGameValue);
            }
            public static Value allvariables(Value rightGameValue)
            {
                return GameValueMethods.unary__allvariables__task__ret__array(rightGameValue);
            }
            public static Value allvariables(Value rightGameValue)
            {
                return GameValueMethods.unary__allvariables__location__ret__array(rightGameValue);
            }
            public static Value animationnames(Value rightGameValue)
            {
                return GameValueMethods.unary__animationnames__object__ret__array(rightGameValue);
            }
            public static Value animationstate(Value rightGameValue)
            {
                return GameValueMethods.unary__animationstate__object__ret__string(rightGameValue);
            }
            public static Value asin(Value rightGameValue)
            {
                return GameValueMethods.unary__asin__scalar_nan__ret__scalar_nan(rightGameValue);
            }
            public static Value asltoagl(Value rightGameValue)
            {
                return GameValueMethods.unary__asltoagl__array__ret__array(rightGameValue);
            }
            public static Value asltoatl(Value rightGameValue)
            {
                return GameValueMethods.unary__asltoatl__array__ret__array(rightGameValue);
            }
            public static Value assert(Value rightGameValue)
            {
                return GameValueMethods.unary__assert__bool__ret__bool(rightGameValue);
            }
            public static Value assignedcargo(Value rightGameValue)
            {
                return GameValueMethods.unary__assignedcargo__object__ret__array(rightGameValue);
            }
            public static Value assignedcommander(Value rightGameValue)
            {
                return GameValueMethods.unary__assignedcommander__object__ret__object(rightGameValue);
            }
            public static Value assigneddriver(Value rightGameValue)
            {
                return GameValueMethods.unary__assigneddriver__object__ret__object(rightGameValue);
            }
            public static Value assignedgroup(Value rightGameValue)
            {
                return GameValueMethods.unary__assignedgroup__object__ret__group(rightGameValue);
            }
            public static Value assignedgunner(Value rightGameValue)
            {
                return GameValueMethods.unary__assignedgunner__object__ret__object(rightGameValue);
            }
            public static Value assigneditems(Value rightGameValue)
            {
                return GameValueMethods.unary__assigneditems__object_array__ret__array(rightGameValue);
            }
            public static Value assignedtarget(Value rightGameValue)
            {
                return GameValueMethods.unary__assignedtarget__object__ret__object(rightGameValue);
            }
            public static Value assignedteam(Value rightGameValue)
            {
                return GameValueMethods.unary__assignedteam__object__ret__string(rightGameValue);
            }
            public static Value assignedvehicle(Value rightGameValue)
            {
                return GameValueMethods.unary__assignedvehicle__object__ret__object(rightGameValue);
            }
            public static Value assignedvehiclerole(Value rightGameValue)
            {
                return GameValueMethods.unary__assignedvehiclerole__object__ret__array(rightGameValue);
            }
            public static Value assignedvehicles(Value rightGameValue)
            {
                return GameValueMethods.unary__assignedvehicles__group__ret__array(rightGameValue);
            }
            public static Value atan(Value rightGameValue)
            {
                return GameValueMethods.unary__atan__scalar_nan__ret__scalar_nan(rightGameValue);
            }
            public static Value atg(Value rightGameValue)
            {
                return GameValueMethods.unary__atg__scalar_nan__ret__scalar_nan(rightGameValue);
            }
            public static Value atltoasl(Value rightGameValue)
            {
                return GameValueMethods.unary__atltoasl__array__ret__array(rightGameValue);
            }
            public static Value attachedobject(Value rightGameValue)
            {
                return GameValueMethods.unary__attachedobject__location__ret__object(rightGameValue);
            }
            public static Value attachedobjects(Value rightGameValue)
            {
                return GameValueMethods.unary__attachedobjects__object__ret__array(rightGameValue);
            }
            public static Value attachedto(Value rightGameValue)
            {
                return GameValueMethods.unary__attachedto__object__ret__object(rightGameValue);
            }
            public static Value attackenabled(Value rightGameValue)
            {
                return GameValueMethods.unary__attackenabled__object_group__ret__bool(rightGameValue);
            }
            public static Value backpack(Value rightGameValue)
            {
                return GameValueMethods.unary__backpack__object__ret__string(rightGameValue);
            }
            public static Value backpackcargo(Value rightGameValue)
            {
                return GameValueMethods.unary__backpackcargo__object__ret__array(rightGameValue);
            }
            public static Value backpackcontainer(Value rightGameValue)
            {
                return GameValueMethods.unary__backpackcontainer__object__ret__object(rightGameValue);
            }
            public static Value backpackitems(Value rightGameValue)
            {
                return GameValueMethods.unary__backpackitems__object__ret__array(rightGameValue);
            }
            public static Value backpackmagazines(Value rightGameValue)
            {
                return GameValueMethods.unary__backpackmagazines__object__ret__array(rightGameValue);
            }
            public static Value backpacks(Value rightGameValue)
            {
                return GameValueMethods.unary__backpacks__object__ret__array(rightGameValue);
            }
            public static Value behaviour(Value rightGameValue)
            {
                return GameValueMethods.unary__behaviour__object__ret__string(rightGameValue);
            }
            public static Value binocular(Value rightGameValue)
            {
                return GameValueMethods.unary__binocular__object__ret__string(rightGameValue);
            }
            public static Value binocularitems(Value rightGameValue)
            {
                return GameValueMethods.unary__binocularitems__object__ret__array(rightGameValue);
            }
            public static Value binocularmagazine(Value rightGameValue)
            {
                return GameValueMethods.unary__binocularmagazine__object__ret__string(rightGameValue);
            }
            public static Value boundingbox(Value rightGameValue)
            {
                return GameValueMethods.unary__boundingbox__object__ret__array(rightGameValue);
            }
            public static Value boundingboxreal(Value rightGameValue)
            {
                return GameValueMethods.unary__boundingboxreal__object__ret__array(rightGameValue);
            }
            public static Value boundingboxreal(Value rightGameValue)
            {
                return GameValueMethods.unary__boundingboxreal__array__ret__array(rightGameValue);
            }
            public static Value boundingcenter(Value rightGameValue)
            {
                return GameValueMethods.unary__boundingcenter__object__ret__array(rightGameValue);
            }
            public static Value brakesdisabled(Value rightGameValue)
            {
                return GameValueMethods.unary__brakesdisabled__object__ret__bool(rightGameValue);
            }
            public static void breakout(Value rightGameValue)
            {
                GameValueMethods.unary__breakout__string__ret__nothing(rightGameValue);
            }
            public static void breakto(Value rightGameValue)
            {
                GameValueMethods.unary__breakto__string__ret__nothing(rightGameValue);
            }
            public static Value breakwith(Value rightGameValue)
            {
                return GameValueMethods.unary__breakwith__any__ret__any(rightGameValue);
            }
            public static void buldozer_enableroaddiag(Value rightGameValue)
            {
                GameValueMethods.unary__buldozer_enableroaddiag__bool__ret__nothing(rightGameValue);
            }
            public static Value buldozer_loadnewroads(Value rightGameValue)
            {
                return GameValueMethods.unary__buldozer_loadnewroads__string__ret__bool(rightGameValue);
            }
            public static Value buttonaction(Value rightGameValue)
            {
                return GameValueMethods.unary__buttonaction__control__ret__string(rightGameValue);
            }
            public static Value buttonaction(Value rightGameValue)
            {
                return GameValueMethods.unary__buttonaction__scalar__ret__string(rightGameValue);
            }
            public static void buttonsetaction(Value rightGameValue)
            {
                GameValueMethods.unary__buttonsetaction__array__ret__nothing(rightGameValue);
            }
            public static Value calculatepath(Value rightGameValue)
            {
                return GameValueMethods.unary__calculatepath__array__ret__object(rightGameValue);
            }
            public static void calculateplayervisibilitybyfriendly(Value rightGameValue)
            {
                GameValueMethods.unary__calculateplayervisibilitybyfriendly__bool__ret__nothing(rightGameValue);
            }
            public static Value call(Value rightGameValue)
            {
                return GameValueMethods.unary__call__code__ret__any(rightGameValue);
            }
            public static Value camcommitted(Value rightGameValue)
            {
                return GameValueMethods.unary__camcommitted__object__ret__bool(rightGameValue);
            }
            public static void camdestroy(Value rightGameValue)
            {
                GameValueMethods.unary__camdestroy__object__ret__nothing(rightGameValue);
            }
            public static void cameraeffectenablehud(Value rightGameValue)
            {
                GameValueMethods.unary__cameraeffectenablehud__bool__ret__nothing(rightGameValue);
            }
            public static Value camerainterest(Value rightGameValue)
            {
                return GameValueMethods.unary__camerainterest__object__ret__scalar(rightGameValue);
            }
            public static Value campreloaded(Value rightGameValue)
            {
                return GameValueMethods.unary__campreloaded__object__ret__bool(rightGameValue);
            }
            public static Value camtarget(Value rightGameValue)
            {
                return GameValueMethods.unary__camtarget__object__ret__object(rightGameValue);
            }
            public static void camusenvg(Value rightGameValue)
            {
                GameValueMethods.unary__camusenvg__bool__ret__nothing(rightGameValue);
            }
            public static void cancelsimpletaskdestination(Value rightGameValue)
            {
                GameValueMethods.unary__cancelsimpletaskdestination__task__ret__nothing(rightGameValue);
            }
            public static Value candeployweapon(Value rightGameValue)
            {
                return GameValueMethods.unary__candeployweapon__object__ret__bool(rightGameValue);
            }
            public static Value canfire(Value rightGameValue)
            {
                return GameValueMethods.unary__canfire__object__ret__bool(rightGameValue);
            }
            public static Value canmove(Value rightGameValue)
            {
                return GameValueMethods.unary__canmove__object__ret__bool(rightGameValue);
            }
            public static Value canstand(Value rightGameValue)
            {
                return GameValueMethods.unary__canstand__object__ret__bool(rightGameValue);
            }
            public static Value cantriggerdynamicsimulation(Value rightGameValue)
            {
                return GameValueMethods.unary__cantriggerdynamicsimulation__object__ret__bool(rightGameValue);
            }
            public static Value canunloadincombat(Value rightGameValue)
            {
                return GameValueMethods.unary__canunloadincombat__object__ret__bool(rightGameValue);
            }
            public static Value captive(Value rightGameValue)
            {
                return GameValueMethods.unary__captive__object__ret__bool(rightGameValue);
            }
            public static Value captivenum(Value rightGameValue)
            {
                return GameValueMethods.unary__captivenum__object__ret__scalar(rightGameValue);
            }
            public static Value case(Value rightGameValue)
{
	return GameValueMethods.unary__case__any__ret__switch(rightGameValue);
}
        public static Value cbchecked(Value rightGameValue)
        {
            return GameValueMethods.unary__cbchecked__control__ret__bool(rightGameValue);
        }
        public static Value ceil(Value rightGameValue)
        {
            return GameValueMethods.unary__ceil__scalar_nan__ret__scalar_nan(rightGameValue);
        }
        public static Value channelenabled(Value rightGameValue)
        {
            return GameValueMethods.unary__channelenabled__scalar__ret__array(rightGameValue);
        }
        public static Value checkaifeature(Value rightGameValue)
        {
            return GameValueMethods.unary__checkaifeature__string__ret__bool(rightGameValue);
        }
        public static Value classname(Value rightGameValue)
        {
            return GameValueMethods.unary__classname__location__ret__string(rightGameValue);
        }
        public static void clear3deninventory(Value rightGameValue)
        {
            GameValueMethods.unary__clear3deninventory__array__ret__nothing(rightGameValue);
        }
        public static void clearallitemsfrombackpack(Value rightGameValue)
        {
            GameValueMethods.unary__clearallitemsfrombackpack__object__ret__nothing(rightGameValue);
        }
        public static void clearbackpackcargo(Value rightGameValue)
        {
            GameValueMethods.unary__clearbackpackcargo__object__ret__nothing(rightGameValue);
        }
        public static void clearbackpackcargoglobal(Value rightGameValue)
        {
            GameValueMethods.unary__clearbackpackcargoglobal__object__ret__nothing(rightGameValue);
        }
        public static void cleargroupicons(Value rightGameValue)
        {
            GameValueMethods.unary__cleargroupicons__group__ret__nothing(rightGameValue);
        }
        public static void clearitemcargo(Value rightGameValue)
        {
            GameValueMethods.unary__clearitemcargo__object__ret__nothing(rightGameValue);
        }
        public static void clearitemcargoglobal(Value rightGameValue)
        {
            GameValueMethods.unary__clearitemcargoglobal__object__ret__nothing(rightGameValue);
        }
        public static void clearmagazinecargo(Value rightGameValue)
        {
            GameValueMethods.unary__clearmagazinecargo__object__ret__nothing(rightGameValue);
        }
        public static void clearmagazinecargoglobal(Value rightGameValue)
        {
            GameValueMethods.unary__clearmagazinecargoglobal__object__ret__nothing(rightGameValue);
        }
        public static void clearoverlay(Value rightGameValue)
        {
            GameValueMethods.unary__clearoverlay__control__ret__nothing(rightGameValue);
        }
        public static void clearweaponcargo(Value rightGameValue)
        {
            GameValueMethods.unary__clearweaponcargo__object__ret__nothing(rightGameValue);
        }
        public static void clearweaponcargoglobal(Value rightGameValue)
        {
            GameValueMethods.unary__clearweaponcargoglobal__object__ret__nothing(rightGameValue);
        }
        public static void closedialog(Value rightGameValue)
        {
            GameValueMethods.unary__closedialog__scalar__ret__nothing(rightGameValue);
        }
        public static void closeoverlay(Value rightGameValue)
        {
            GameValueMethods.unary__closeoverlay__control__ret__nothing(rightGameValue);
        }
        public static void collapseobjecttree(Value rightGameValue)
        {
            GameValueMethods.unary__collapseobjecttree__control__ret__nothing(rightGameValue);
        }
        public static void collect3denhistory(Value rightGameValue)
        {
            GameValueMethods.unary__collect3denhistory__code__ret__nothing(rightGameValue);
        }
        public static Value collectivertd(Value rightGameValue)
        {
            return GameValueMethods.unary__collectivertd__object__ret__scalar(rightGameValue);
        }
        public static Value collisiondisabledwith(Value rightGameValue)
        {
            return GameValueMethods.unary__collisiondisabledwith__object__ret__array(rightGameValue);
        }
        public static Value combatbehaviour(Value rightGameValue)
        {
            return GameValueMethods.unary__combatbehaviour__object__ret__string(rightGameValue);
        }
        public static Value combatbehaviour(Value rightGameValue)
        {
            return GameValueMethods.unary__combatbehaviour__group__ret__string(rightGameValue);
        }
        public static Value combatmode(Value rightGameValue)
        {
            return GameValueMethods.unary__combatmode__object_group__ret__string(rightGameValue);
        }
        public static Value commander(Value rightGameValue)
        {
            return GameValueMethods.unary__commander__object__ret__object(rightGameValue);
        }
        public static void commandgetout(Value rightGameValue)
        {
            GameValueMethods.unary__commandgetout__object_array__ret__nothing(rightGameValue);
        }
        public static void commandstop(Value rightGameValue)
        {
            GameValueMethods.unary__commandstop__object_array__ret__nothing(rightGameValue);
        }
        public static void comment(Value rightGameValue)
        {
            GameValueMethods.unary__comment__string__ret__nothing(rightGameValue);
        }
        public static void commitoverlay(Value rightGameValue)
        {
            GameValueMethods.unary__commitoverlay__control__ret__nothing(rightGameValue);
        }
        public static Value compatibleitems(Value rightGameValue)
        {
            return GameValueMethods.unary__compatibleitems__string_array__ret__array(rightGameValue);
        }
        public static Value compatiblemagazines(Value rightGameValue)
        {
            return GameValueMethods.unary__compatiblemagazines__string_array__ret__array(rightGameValue);
        }
        public static Value compile(Value rightGameValue)
        {
            return GameValueMethods.unary__compile__string__ret__code(rightGameValue);
        }
        public static Value compilefinal(Value rightGameValue)
        {
            return GameValueMethods.unary__compilefinal__code_string__ret__code(rightGameValue);
        }
        public static Value compilefinal(Value rightGameValue)
        {
            return GameValueMethods.unary__compilefinal__hashmap__ret__hashmap(rightGameValue);
        }
        public static Value compilescript(Value rightGameValue)
        {
            return GameValueMethods.unary__compilescript__array__ret__code(rightGameValue);
        }
        public static Value completedfsm(Value rightGameValue)
        {
            return GameValueMethods.unary__completedfsm__scalar__ret__bool(rightGameValue);
        }
        public static Value composetext(Value rightGameValue)
        {
            return GameValueMethods.unary__composetext__array__ret__text(rightGameValue);
        }
        public static Value confighierarchy(Value rightGameValue)
        {
            return GameValueMethods.unary__confighierarchy__config__ret__array(rightGameValue);
        }
        public static Value configname(Value rightGameValue)
        {
            return GameValueMethods.unary__configname__config__ret__string(rightGameValue);
        }
        public static Value configof(Value rightGameValue)
        {
            return GameValueMethods.unary__configof__object__ret__config(rightGameValue);
        }
        public static Value configproperties(Value rightGameValue)
        {
            return GameValueMethods.unary__configproperties__array__ret__array(rightGameValue);
        }
        public static Value configsourceaddonlist(Value rightGameValue)
        {
            return GameValueMethods.unary__configsourceaddonlist__config__ret__array(rightGameValue);
        }
        public static Value configsourcemod(Value rightGameValue)
        {
            return GameValueMethods.unary__configsourcemod__config__ret__string(rightGameValue);
        }
        public static Value configsourcemodlist(Value rightGameValue)
        {
            return GameValueMethods.unary__configsourcemodlist__config__ret__array(rightGameValue);
        }
        public static void connecttoserver(Value rightGameValue)
        {
            GameValueMethods.unary__connecttoserver__array__ret__nothing(rightGameValue);
        }
        public static Value continuewith(Value rightGameValue)
        {
            return GameValueMethods.unary__continuewith__any__ret__any(rightGameValue);
        }
        public static Value conversationdisabled(Value rightGameValue)
        {
            return GameValueMethods.unary__conversationdisabled__object__ret__bool(rightGameValue);
        }
        public static void copytoclipboard(Value rightGameValue)
        {
            GameValueMethods.unary__copytoclipboard__string__ret__nothing(rightGameValue);
        }
        public static Value cos(Value rightGameValue)
        {
            return GameValueMethods.unary__cos__scalar_nan__ret__scalar_nan(rightGameValue);
        }
        public static Value count(Value rightGameValue)
        {
            return GameValueMethods.unary__count__array__ret__scalar(rightGameValue);
        }
        public static Value count(Value rightGameValue)
        {
            return GameValueMethods.unary__count__string__ret__scalar(rightGameValue);
        }
        public static Value count(Value rightGameValue)
        {
            return GameValueMethods.unary__count__config__ret__scalar(rightGameValue);
        }
        public static Value count(Value rightGameValue)
        {
            return GameValueMethods.unary__count__hashmap__ret__scalar(rightGameValue);
        }
        public static Value create3dencomposition(Value rightGameValue)
        {
            return GameValueMethods.unary__create3dencomposition__array__ret__array(rightGameValue);
        }
        public static Value create3denentity(Value rightGameValue)
        {
            return GameValueMethods.unary__create3denentity__array__ret__any(rightGameValue);
        }
        public static Value createagent(Value rightGameValue)
        {
            return GameValueMethods.unary__createagent__array__ret__object(rightGameValue);
        }
        public static Value createcenter(Value rightGameValue)
        {
            return GameValueMethods.unary__createcenter__side__ret__side(rightGameValue);
        }
        public static Value createdialog(Value rightGameValue)
        {
            return GameValueMethods.unary__createdialog__string__ret__bool(rightGameValue);
        }
        public static Value createdialog(Value rightGameValue)
        {
            return GameValueMethods.unary__createdialog__array__ret__display(rightGameValue);
        }
        public static Value creatediarylink(Value rightGameValue)
        {
            return GameValueMethods.unary__creatediarylink__array__ret__string(rightGameValue);
        }
        public static void creategeardialog(Value rightGameValue)
        {
            GameValueMethods.unary__creategeardialog__array__ret__nothing(rightGameValue);
        }
        public static Value creategroup(Value rightGameValue)
        {
            return GameValueMethods.unary__creategroup__side_array__ret__group(rightGameValue);
        }
        public static void createguardedpoint(Value rightGameValue)
        {
            GameValueMethods.unary__createguardedpoint__array__ret__nothing(rightGameValue);
        }
        public static Value createhashmapfromarray(Value rightGameValue)
        {
            return GameValueMethods.unary__createhashmapfromarray__array__ret__hashmap(rightGameValue);
        }
        public static Value createhashmapobject(Value rightGameValue)
        {
            return GameValueMethods.unary__createhashmapobject__array__ret__hashmap(rightGameValue);
        }
        public static Value createlocation(Value rightGameValue)
        {
            return GameValueMethods.unary__createlocation__array__ret__location(rightGameValue);
        }
        public static Value createmarker(Value rightGameValue)
        {
            return GameValueMethods.unary__createmarker__array__ret__string(rightGameValue);
        }
        public static Value createmarkerlocal(Value rightGameValue)
        {
            return GameValueMethods.unary__createmarkerlocal__array__ret__string(rightGameValue);
        }
        public static Value createmine(Value rightGameValue)
        {
            return GameValueMethods.unary__createmine__array__ret__object(rightGameValue);
        }
        public static Value createsimpleobject(Value rightGameValue)
        {
            return GameValueMethods.unary__createsimpleobject__array__ret__object(rightGameValue);
        }
        public static Value createsoundsource(Value rightGameValue)
        {
            return GameValueMethods.unary__createsoundsource__array__ret__object(rightGameValue);
        }
        public static Value createteam(Value rightGameValue)
        {
            return GameValueMethods.unary__createteam__array__ret__team_member(rightGameValue);
        }
        public static Value createtrigger(Value rightGameValue)
        {
            return GameValueMethods.unary__createtrigger__array__ret__object(rightGameValue);
        }
        public static Value createvehicle(Value rightGameValue)
        {
            return GameValueMethods.unary__createvehicle__array__ret__object(rightGameValue);
        }
        public static Value createvehiclecrew(Value rightGameValue)
        {
            return GameValueMethods.unary__createvehiclecrew__object__ret__group(rightGameValue);
        }
        public static Value createvehiclelocal(Value rightGameValue)
        {
            return GameValueMethods.unary__createvehiclelocal__array__ret__object(rightGameValue);
        }
        public static Value crew(Value rightGameValue)
        {
            return GameValueMethods.unary__crew__object__ret__array(rightGameValue);
        }
        public static Value ctaddheader(Value rightGameValue)
        {
            return GameValueMethods.unary__ctaddheader__control__ret__array(rightGameValue);
        }
        public static Value ctaddrow(Value rightGameValue)
        {
            return GameValueMethods.unary__ctaddrow__control__ret__array(rightGameValue);
        }
        public static void ctclear(Value rightGameValue)
        {
            GameValueMethods.unary__ctclear__control__ret__nothing(rightGameValue);
        }
        public static Value ctcursel(Value rightGameValue)
        {
            return GameValueMethods.unary__ctcursel__control__ret__scalar(rightGameValue);
        }
        public static Value ctheadercount(Value rightGameValue)
        {
            return GameValueMethods.unary__ctheadercount__control__ret__scalar(rightGameValue);
        }
        public static void ctrlactivate(Value rightGameValue)
        {
            GameValueMethods.unary__ctrlactivate__control__ret__nothing(rightGameValue);
        }
        public static Value ctrlangle(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlangle__control__ret__array(rightGameValue);
        }
        public static Value ctrlautoscrolldelay(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlautoscrolldelay__control__ret__scalar(rightGameValue);
        }
        public static Value ctrlautoscrollrewind(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlautoscrollrewind__control__ret__bool(rightGameValue);
        }
        public static Value ctrlautoscrollspeed(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlautoscrollspeed__control__ret__scalar(rightGameValue);
        }
        public static Value ctrlbackgroundcolor(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlbackgroundcolor__control__ret__array(rightGameValue);
        }
        public static Value ctrlchecked(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlchecked__control__ret__bool(rightGameValue);
        }
        public static Value ctrlclassname(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlclassname__control__ret__string(rightGameValue);
        }
        public static Value ctrlcommitted(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlcommitted__control__ret__bool(rightGameValue);
        }
        public static Value ctrldelete(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrldelete__control__ret__bool(rightGameValue);
        }
        public static void ctrlenable(Value rightGameValue)
        {
            GameValueMethods.unary__ctrlenable__array__ret__nothing(rightGameValue);
        }
        public static Value ctrlenabled(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlenabled__control__ret__bool(rightGameValue);
        }
        public static Value ctrlenabled(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlenabled__scalar__ret__bool(rightGameValue);
        }
        public static Value ctrlfade(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlfade__control__ret__scalar(rightGameValue);
        }
        public static Value ctrlfontheight(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlfontheight__control__ret__scalar(rightGameValue);
        }
        public static Value ctrlforegroundcolor(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlforegroundcolor__control__ret__array(rightGameValue);
        }
        public static Value ctrlhtmlloaded(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlhtmlloaded__control__ret__bool(rightGameValue);
        }
        public static Value ctrlidc(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlidc__control__ret__scalar(rightGameValue);
        }
        public static Value ctrlidd(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlidd__display__ret__scalar(rightGameValue);
        }
        public static void ctrlmapanimclear(Value rightGameValue)
        {
            GameValueMethods.unary__ctrlmapanimclear__control__ret__nothing(rightGameValue);
        }
        public static void ctrlmapanimcommit(Value rightGameValue)
        {
            GameValueMethods.unary__ctrlmapanimcommit__control__ret__nothing(rightGameValue);
        }
        public static Value ctrlmapanimdone(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlmapanimdone__control__ret__bool(rightGameValue);
        }
        public static Value ctrlmapdir(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlmapdir__control__ret__scalar(rightGameValue);
        }
        public static Value ctrlmapmouseover(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlmapmouseover__control__ret__array(rightGameValue);
        }
        public static Value ctrlmapposition(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlmapposition__control__ret__array(rightGameValue);
        }
        public static Value ctrlmapscale(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlmapscale__control__ret__scalar(rightGameValue);
        }
        public static Value ctrlmodel(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlmodel__control__ret__string(rightGameValue);
        }
        public static Value ctrlmodeldirandup(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlmodeldirandup__control__ret__array(rightGameValue);
        }
        public static Value ctrlmodelscale(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlmodelscale__control__ret__scalar(rightGameValue);
        }
        public static Value ctrlmouseposition(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlmouseposition__control__ret__array(rightGameValue);
        }
        public static Value ctrlparent(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlparent__control__ret__display(rightGameValue);
        }
        public static Value ctrlparentcontrolsgroup(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlparentcontrolsgroup__control__ret__control(rightGameValue);
        }
        public static Value ctrlposition(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlposition__control__ret__array(rightGameValue);
        }
        public static Value ctrlscale(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlscale__control__ret__scalar(rightGameValue);
        }
        public static Value ctrlscrollvalues(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlscrollvalues__control__ret__array(rightGameValue);
        }
        public static void ctrlsetfocus(Value rightGameValue)
        {
            GameValueMethods.unary__ctrlsetfocus__control__ret__nothing(rightGameValue);
        }
        public static void ctrlsettext(Value rightGameValue)
        {
            GameValueMethods.unary__ctrlsettext__array__ret__nothing(rightGameValue);
        }
        public static Value ctrlshadow(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlshadow__control__ret__scalar(rightGameValue);
        }
        public static void ctrlshow(Value rightGameValue)
        {
            GameValueMethods.unary__ctrlshow__array__ret__nothing(rightGameValue);
        }
        public static Value ctrlshown(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlshown__control__ret__bool(rightGameValue);
        }
        public static Value ctrlstyle(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlstyle__control__ret__scalar(rightGameValue);
        }
        public static Value ctrltext(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrltext__control__ret__string(rightGameValue);
        }
        public static Value ctrltext(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrltext__scalar__ret__string(rightGameValue);
        }
        public static Value ctrltextcolor(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrltextcolor__control__ret__array(rightGameValue);
        }
        public static Value ctrltextheight(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrltextheight__control__ret__scalar(rightGameValue);
        }
        public static Value ctrltextsecondary(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrltextsecondary__control__ret__string(rightGameValue);
        }
        public static Value ctrltextselection(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrltextselection__control__ret__array(rightGameValue);
        }
        public static Value ctrltextwidth(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrltextwidth__control__ret__scalar(rightGameValue);
        }
        public static Value ctrltooltip(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrltooltip__control__ret__string(rightGameValue);
        }
        public static Value ctrltype(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrltype__control__ret__scalar(rightGameValue);
        }
        public static Value ctrlurl(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlurl__control__ret__string(rightGameValue);
        }
        public static Value ctrlurloverlaymode(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlurloverlaymode__control__ret__scalar(rightGameValue);
        }
        public static Value ctrlvisible(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrlvisible__scalar__ret__bool(rightGameValue);
        }
        public static Value ctrowcount(Value rightGameValue)
        {
            return GameValueMethods.unary__ctrowcount__control__ret__scalar(rightGameValue);
        }
        public static Value curatoraddons(Value rightGameValue)
        {
            return GameValueMethods.unary__curatoraddons__object__ret__array(rightGameValue);
        }
        public static Value curatorcameraarea(Value rightGameValue)
        {
            return GameValueMethods.unary__curatorcameraarea__object__ret__array(rightGameValue);
        }
        public static Value curatorcameraareaceiling(Value rightGameValue)
        {
            return GameValueMethods.unary__curatorcameraareaceiling__object__ret__scalar(rightGameValue);
        }
        public static Value curatoreditableobjects(Value rightGameValue)
        {
            return GameValueMethods.unary__curatoreditableobjects__object__ret__array(rightGameValue);
        }
        public static Value curatoreditingarea(Value rightGameValue)
        {
            return GameValueMethods.unary__curatoreditingarea__object__ret__array(rightGameValue);
        }
        public static Value curatoreditingareatype(Value rightGameValue)
        {
            return GameValueMethods.unary__curatoreditingareatype__object__ret__bool(rightGameValue);
        }
        public static Value curatorpoints(Value rightGameValue)
        {
            return GameValueMethods.unary__curatorpoints__object__ret__scalar(rightGameValue);
        }
        public static Value curatorregisteredobjects(Value rightGameValue)
        {
            return GameValueMethods.unary__curatorregisteredobjects__object__ret__array(rightGameValue);
        }
        public static Value curatorselectionpreset(Value rightGameValue)
        {
            return GameValueMethods.unary__curatorselectionpreset__scalar__ret__array(rightGameValue);
        }
        public static Value curatorwaypointcost(Value rightGameValue)
        {
            return GameValueMethods.unary__curatorwaypointcost__object__ret__scalar(rightGameValue);
        }
        public static Value currentcommand(Value rightGameValue)
        {
            return GameValueMethods.unary__currentcommand__object__ret__string(rightGameValue);
        }
        public static Value currentmagazine(Value rightGameValue)
        {
            return GameValueMethods.unary__currentmagazine__object__ret__string(rightGameValue);
        }
        public static Value currentmagazinedetail(Value rightGameValue)
        {
            return GameValueMethods.unary__currentmagazinedetail__object__ret__array(rightGameValue);
        }
        public static Value currentmuzzle(Value rightGameValue)
        {
            return GameValueMethods.unary__currentmuzzle__object__ret__string(rightGameValue);
        }
        public static Value currentpilot(Value rightGameValue)
        {
            return GameValueMethods.unary__currentpilot__object__ret__object(rightGameValue);
        }
        public static Value currenttask(Value rightGameValue)
        {
            return GameValueMethods.unary__currenttask__object__ret__task(rightGameValue);
        }
        public static Value currenttasks(Value rightGameValue)
        {
            return GameValueMethods.unary__currenttasks__team_member__ret__array(rightGameValue);
        }
        public static Value currentthrowable(Value rightGameValue)
        {
            return GameValueMethods.unary__currentthrowable__object__ret__array(rightGameValue);
        }
        public static Value currentvisionmode(Value rightGameValue)
        {
            return GameValueMethods.unary__currentvisionmode__object__ret__scalar(rightGameValue);
        }
        public static Value currentvisionmode(Value rightGameValue)
        {
            return GameValueMethods.unary__currentvisionmode__array__ret__array(rightGameValue);
        }
        public static Value currentwaypoint(Value rightGameValue)
        {
            return GameValueMethods.unary__currentwaypoint__group__ret__scalar(rightGameValue);
        }
        public static Value currentweapon(Value rightGameValue)
        {
            return GameValueMethods.unary__currentweapon__object__ret__string(rightGameValue);
        }
        public static Value currentweaponmode(Value rightGameValue)
        {
            return GameValueMethods.unary__currentweaponmode__object__ret__string(rightGameValue);
        }
        public static Value currentzeroing(Value rightGameValue)
        {
            return GameValueMethods.unary__currentzeroing__object__ret__scalar(rightGameValue);
        }
        public static void cutobj(Value rightGameValue)
        {
            GameValueMethods.unary__cutobj__array__ret__nothing(rightGameValue);
        }
        public static void cutrsc(Value rightGameValue)
        {
            GameValueMethods.unary__cutrsc__array__ret__nothing(rightGameValue);
        }
        public static void cuttext(Value rightGameValue)
        {
            GameValueMethods.unary__cuttext__array__ret__nothing(rightGameValue);
        }
        public static Value damage(Value rightGameValue)
        {
            return GameValueMethods.unary__damage__object__ret__scalar(rightGameValue);
        }
        public static Value datetonumber(Value rightGameValue)
        {
            return GameValueMethods.unary__datetonumber__array__ret__scalar(rightGameValue);
        }
        public static void deactivatekey(Value rightGameValue)
        {
            GameValueMethods.unary__deactivatekey__string__ret__nothing(rightGameValue);
        }
        public static Value debriefingtext(Value rightGameValue)
        {
            return GameValueMethods.unary__debriefingtext__string__ret__scalar(rightGameValue);
        }
        public static void debuglog(Value rightGameValue)
        {
            GameValueMethods.unary__debuglog__any__ret__nothing(rightGameValue);
        }
        public static Value decaygraphvalues(Value rightGameValue)
        {
            return GameValueMethods.unary__decaygraphvalues__array__ret__array(rightGameValue);
        }
        public static void default(Value rightGameValue)
{
	GameValueMethods.unary__default__code__ret__nothing(rightGameValue);
}
    public static Value deg(Value rightGameValue)
    {
        return GameValueMethods.unary__deg__scalar_nan__ret__scalar_nan(rightGameValue);
    }
    public static void delete3denentities(Value rightGameValue)
    {
        GameValueMethods.unary__delete3denentities__array__ret__nothing(rightGameValue);
    }
    public static void deletecenter(Value rightGameValue)
    {
        GameValueMethods.unary__deletecenter__side__ret__nothing(rightGameValue);
    }
    public static void deletecollection(Value rightGameValue)
    {
        GameValueMethods.unary__deletecollection__object__ret__nothing(rightGameValue);
    }
    public static void deletegroup(Value rightGameValue)
    {
        GameValueMethods.unary__deletegroup__group__ret__nothing(rightGameValue);
    }
    public static Value deleteidentity(Value rightGameValue)
    {
        return GameValueMethods.unary__deleteidentity__string__ret__bool(rightGameValue);
    }
    public static void deletelocation(Value rightGameValue)
    {
        GameValueMethods.unary__deletelocation__location__ret__nothing(rightGameValue);
    }
    public static void deletemarker(Value rightGameValue)
    {
        GameValueMethods.unary__deletemarker__string__ret__nothing(rightGameValue);
    }
    public static void deletemarkerlocal(Value rightGameValue)
    {
        GameValueMethods.unary__deletemarkerlocal__string__ret__nothing(rightGameValue);
    }
    public static void deletesite(Value rightGameValue)
    {
        GameValueMethods.unary__deletesite__object__ret__nothing(rightGameValue);
    }
    public static Value deletestatus(Value rightGameValue)
    {
        return GameValueMethods.unary__deletestatus__string__ret__bool(rightGameValue);
    }
    public static void deleteteam(Value rightGameValue)
    {
        GameValueMethods.unary__deleteteam__team_member__ret__nothing(rightGameValue);
    }
    public static void deletevehicle(Value rightGameValue)
    {
        GameValueMethods.unary__deletevehicle__object__ret__nothing(rightGameValue);
    }
    public static void deletevehiclecrew(Value rightGameValue)
    {
        GameValueMethods.unary__deletevehiclecrew__object__ret__nothing(rightGameValue);
    }
    public static void deletewaypoint(Value rightGameValue)
    {
        GameValueMethods.unary__deletewaypoint__array__ret__nothing(rightGameValue);
    }
    public static void detach(Value rightGameValue)
    {
        GameValueMethods.unary__detach__object__ret__nothing(rightGameValue);
    }
    public static Value detectedmines(Value rightGameValue)
    {
        return GameValueMethods.unary__detectedmines__side__ret__array(rightGameValue);
    }
    public static void diag_captureframe(Value rightGameValue)
    {
        GameValueMethods.unary__diag_captureframe__scalar__ret__nothing(rightGameValue);
    }
    public static void diag_captureframetofile(Value rightGameValue)
    {
        GameValueMethods.unary__diag_captureframetofile__scalar__ret__nothing(rightGameValue);
    }
    public static void diag_captureslowframe(Value rightGameValue)
    {
        GameValueMethods.unary__diag_captureslowframe__array__ret__nothing(rightGameValue);
    }
    public static Value diag_codeperformance(Value rightGameValue)
    {
        return GameValueMethods.unary__diag_codeperformance__array__ret__array(rightGameValue);
    }
    public static void diag_drawmode(Value rightGameValue)
    {
        GameValueMethods.unary__diag_drawmode__string__ret__nothing(rightGameValue);
    }
    public static void diag_dumpscriptassembly(Value rightGameValue)
    {
        GameValueMethods.unary__diag_dumpscriptassembly__code__ret__nothing(rightGameValue);
    }
    public static void diag_dynamicsimulationend(Value rightGameValue)
    {
        GameValueMethods.unary__diag_dynamicsimulationend__string__ret__nothing(rightGameValue);
    }
    public static Value diag_enabled(Value rightGameValue)
    {
        return GameValueMethods.unary__diag_enabled__string__ret__bool(rightGameValue);
    }
    public static void diag_exportconfig(Value rightGameValue)
    {
        GameValueMethods.unary__diag_exportconfig__array__ret__nothing(rightGameValue);
    }
    public static void diag_exportterrainsvg(Value rightGameValue)
    {
        GameValueMethods.unary__diag_exportterrainsvg__array__ret__nothing(rightGameValue);
    }
    public static Value diag_getterrainsegmentoffset(Value rightGameValue)
    {
        return GameValueMethods.unary__diag_getterrainsegmentoffset__array__ret__array(rightGameValue);
    }
    public static void diag_lightnewload(Value rightGameValue)
    {
        GameValueMethods.unary__diag_lightnewload__string__ret__nothing(rightGameValue);
    }
    public static Value diag_list(Value rightGameValue)
    {
        return GameValueMethods.unary__diag_list__string__ret__array(rightGameValue);
    }
    public static Value diag_localized(Value rightGameValue)
    {
        return GameValueMethods.unary__diag_localized__string__ret__array(rightGameValue);
    }
    public static void diag_log(Value rightGameValue)
    {
        GameValueMethods.unary__diag_log__any__ret__nothing(rightGameValue);
    }
    public static void diag_logslowframe(Value rightGameValue)
    {
        GameValueMethods.unary__diag_logslowframe__array__ret__nothing(rightGameValue);
    }
    public static void diag_mergeconfigfile(Value rightGameValue)
    {
        GameValueMethods.unary__diag_mergeconfigfile__array__ret__nothing(rightGameValue);
    }
    public static void diag_recordturretlimits(Value rightGameValue)
    {
        GameValueMethods.unary__diag_recordturretlimits__bool__ret__nothing(rightGameValue);
    }
    public static void diag_setlightnew(Value rightGameValue)
    {
        GameValueMethods.unary__diag_setlightnew__string__ret__nothing(rightGameValue);
    }
    public static Value diag_testscriptsimplevm(Value rightGameValue)
    {
        return GameValueMethods.unary__diag_testscriptsimplevm__code__ret__string(rightGameValue);
    }
    public static void diag_toggle(Value rightGameValue)
    {
        GameValueMethods.unary__diag_toggle__string__ret__nothing(rightGameValue);
    }
    public static Value didjipowner(Value rightGameValue)
    {
        return GameValueMethods.unary__didjipowner__object__ret__bool(rightGameValue);
    }
    public static Value difficultyenabled(Value rightGameValue)
    {
        return GameValueMethods.unary__difficultyenabled__string__ret__bool(rightGameValue);
    }
    public static Value difficultyoption(Value rightGameValue)
    {
        return GameValueMethods.unary__difficultyoption__string__ret__scalar(rightGameValue);
    }
    public static Value difficultyoption(Value rightGameValue)
    {
        return GameValueMethods.unary__difficultyoption__array__ret__array(rightGameValue);
    }
    public static Value direction(Value rightGameValue)
    {
        return GameValueMethods.unary__direction__object__ret__scalar(rightGameValue);
    }
    public static Value direction(Value rightGameValue)
    {
        return GameValueMethods.unary__direction__location__ret__scalar(rightGameValue);
    }
    public static void disablemapindicators(Value rightGameValue)
    {
        GameValueMethods.unary__disablemapindicators__array__ret__nothing(rightGameValue);
    }
    public static void disableremotesensors(Value rightGameValue)
    {
        GameValueMethods.unary__disableremotesensors__bool__ret__nothing(rightGameValue);
    }
    public static void disableuserinput(Value rightGameValue)
    {
        GameValueMethods.unary__disableuserinput__bool__ret__nothing(rightGameValue);
    }
    public static Value displaychild(Value rightGameValue)
    {
        return GameValueMethods.unary__displaychild__display__ret__display(rightGameValue);
    }
    public static Value displayctrl(Value rightGameValue)
    {
        return GameValueMethods.unary__displayctrl__scalar__ret__control(rightGameValue);
    }
    public static Value displayparent(Value rightGameValue)
    {
        return GameValueMethods.unary__displayparent__display__ret__display(rightGameValue);
    }
    public static Value displayuniquename(Value rightGameValue)
    {
        return GameValueMethods.unary__displayuniquename__display__ret__string(rightGameValue);
    }
    public static void displayupdate(Value rightGameValue)
    {
        GameValueMethods.unary__displayupdate__display__ret__nothing(rightGameValue);
    }
    public static void dissolveteam(Value rightGameValue)
    {
        GameValueMethods.unary__dissolveteam__string__ret__nothing(rightGameValue);
    }
    public static void do3denaction(Value rightGameValue)
    {
        GameValueMethods.unary__do3denaction__string__ret__nothing(rightGameValue);
    }
    public static void dogetout(Value rightGameValue)
    {
        GameValueMethods.unary__dogetout__object_array__ret__nothing(rightGameValue);
    }
    public static void dostop(Value rightGameValue)
    {
        GameValueMethods.unary__dostop__object_array__ret__nothing(rightGameValue);
    }
    public static void drawicon3d(Value rightGameValue)
    {
        GameValueMethods.unary__drawicon3d__array__ret__nothing(rightGameValue);
    }
    public static void drawlaser(Value rightGameValue)
    {
        GameValueMethods.unary__drawlaser__array__ret__nothing(rightGameValue);
    }
    public static void drawline3d(Value rightGameValue)
    {
        GameValueMethods.unary__drawline3d__array__ret__nothing(rightGameValue);
    }
    public static Value driver(Value rightGameValue)
    {
        return GameValueMethods.unary__driver__object__ret__object(rightGameValue);
    }
    public static void drop(Value rightGameValue)
    {
        GameValueMethods.unary__drop__array__ret__nothing(rightGameValue);
    }
    public static Value dynamicsimulationdistance(Value rightGameValue)
    {
        return GameValueMethods.unary__dynamicsimulationdistance__string__ret__scalar(rightGameValue);
    }
    public static Value dynamicsimulationdistancecoef(Value rightGameValue)
    {
        return GameValueMethods.unary__dynamicsimulationdistancecoef__string__ret__scalar(rightGameValue);
    }
    public static Value dynamicsimulationenabled(Value rightGameValue)
    {
        return GameValueMethods.unary__dynamicsimulationenabled__object__ret__bool(rightGameValue);
    }
    public static Value dynamicsimulationenabled(Value rightGameValue)
    {
        return GameValueMethods.unary__dynamicsimulationenabled__group__ret__bool(rightGameValue);
    }
    public static void echo(Value rightGameValue)
    {
        GameValueMethods.unary__echo__string__ret__nothing(rightGameValue);
    }
    public static void edit3denmissionattributes(Value rightGameValue)
    {
        GameValueMethods.unary__edit3denmissionattributes__string__ret__nothing(rightGameValue);
    }
    public static Value effectivecommander(Value rightGameValue)
    {
        return GameValueMethods.unary__effectivecommander__object__ret__object(rightGameValue);
    }
    public static Value enableaudiofeature(Value rightGameValue)
    {
        return GameValueMethods.unary__enableaudiofeature__array__ret__bool(rightGameValue);
    }
    public static void enablecamshake(Value rightGameValue)
    {
        GameValueMethods.unary__enablecamshake__bool__ret__nothing(rightGameValue);
    }
    public static void enablecaustics(Value rightGameValue)
    {
        GameValueMethods.unary__enablecaustics__bool__ret__nothing(rightGameValue);
    }
    public static void enabledebriefingstats(Value rightGameValue)
    {
        GameValueMethods.unary__enabledebriefingstats__array__ret__nothing(rightGameValue);
    }
    public static void enablediaglegend(Value rightGameValue)
    {
        GameValueMethods.unary__enablediaglegend__bool__ret__nothing(rightGameValue);
    }
    public static void enabledynamicsimulationsystem(Value rightGameValue)
    {
        GameValueMethods.unary__enabledynamicsimulationsystem__bool__ret__nothing(rightGameValue);
    }
    public static void enableengineartillery(Value rightGameValue)
    {
        GameValueMethods.unary__enableengineartillery__bool__ret__nothing(rightGameValue);
    }
    public static void enableenvironment(Value rightGameValue)
    {
        GameValueMethods.unary__enableenvironment__bool_array__ret__nothing(rightGameValue);
    }
    public static void enableradio(Value rightGameValue)
    {
        GameValueMethods.unary__enableradio__bool__ret__nothing(rightGameValue);
    }
    public static void enablesatnormalondetail(Value rightGameValue)
    {
        GameValueMethods.unary__enablesatnormalondetail__bool__ret__nothing(rightGameValue);
    }
    public static void enablesaving(Value rightGameValue)
    {
        GameValueMethods.unary__enablesaving__bool_array__ret__nothing(rightGameValue);
    }
    public static void enablesentences(Value rightGameValue)
    {
        GameValueMethods.unary__enablesentences__bool__ret__nothing(rightGameValue);
    }
    public static void enablestressdamage(Value rightGameValue)
    {
        GameValueMethods.unary__enablestressdamage__bool__ret__nothing(rightGameValue);
    }
    public static void enableteamswitch(Value rightGameValue)
    {
        GameValueMethods.unary__enableteamswitch__bool__ret__nothing(rightGameValue);
    }
    public static void enabletraffic(Value rightGameValue)
    {
        GameValueMethods.unary__enabletraffic__bool__ret__nothing(rightGameValue);
    }
    public static void enableweapondisassembly(Value rightGameValue)
    {
        GameValueMethods.unary__enableweapondisassembly__bool__ret__nothing(rightGameValue);
    }
    public static void endmission(Value rightGameValue)
    {
        GameValueMethods.unary__endmission__string__ret__nothing(rightGameValue);
    }
    public static Value enginesisonrtd(Value rightGameValue)
    {
        return GameValueMethods.unary__enginesisonrtd__object__ret__array(rightGameValue);
    }
    public static Value enginespowerrtd(Value rightGameValue)
    {
        return GameValueMethods.unary__enginespowerrtd__object__ret__array(rightGameValue);
    }
    public static Value enginesrpmrtd(Value rightGameValue)
    {
        return GameValueMethods.unary__enginesrpmrtd__object__ret__array(rightGameValue);
    }
    public static Value enginestorquertd(Value rightGameValue)
    {
        return GameValueMethods.unary__enginestorquertd__object__ret__array(rightGameValue);
    }
    public static Value entities(Value rightGameValue)
    {
        return GameValueMethods.unary__entities__string__ret__array(rightGameValue);
    }
    public static Value entities(Value rightGameValue)
    {
        return GameValueMethods.unary__entities__array__ret__array(rightGameValue);
    }
    public static Value equipmentdisabled(Value rightGameValue)
    {
        return GameValueMethods.unary__equipmentdisabled__object__ret__array(rightGameValue);
    }
    public static void estimatedtimeleft(Value rightGameValue)
    {
        GameValueMethods.unary__estimatedtimeleft__scalar__ret__nothing(rightGameValue);
    }
    public static Value everybackpack(Value rightGameValue)
    {
        return GameValueMethods.unary__everybackpack__object__ret__array(rightGameValue);
    }
    public static Value everycontainer(Value rightGameValue)
    {
        return GameValueMethods.unary__everycontainer__object__ret__array(rightGameValue);
    }
    public static Value execfsm(Value rightGameValue)
    {
        return GameValueMethods.unary__execfsm__string__ret__scalar(rightGameValue);
    }
    public static Value execvm(Value rightGameValue)
    {
        return GameValueMethods.unary__execvm__string__ret__script(rightGameValue);
    }
    public static Value exp(Value rightGameValue)
    {
        return GameValueMethods.unary__exp__scalar_nan__ret__scalar_nan(rightGameValue);
    }
    public static Value expecteddestination(Value rightGameValue)
    {
        return GameValueMethods.unary__expecteddestination__object__ret__array(rightGameValue);
    }
    public static void exportjipmessages(Value rightGameValue)
    {
        GameValueMethods.unary__exportjipmessages__string__ret__nothing(rightGameValue);
    }
    public static Value eyedirection(Value rightGameValue)
    {
        return GameValueMethods.unary__eyedirection__object__ret__array(rightGameValue);
    }
    public static Value eyepos(Value rightGameValue)
    {
        return GameValueMethods.unary__eyepos__object__ret__array(rightGameValue);
    }
    public static Value face(Value rightGameValue)
    {
        return GameValueMethods.unary__face__object__ret__string(rightGameValue);
    }
    public static Value faction(Value rightGameValue)
    {
        return GameValueMethods.unary__faction__object__ret__string(rightGameValue);
    }
    public static void failmission(Value rightGameValue)
    {
        GameValueMethods.unary__failmission__string__ret__nothing(rightGameValue);
    }
    public static Value fileexists(Value rightGameValue)
    {
        return GameValueMethods.unary__fileexists__string__ret__bool(rightGameValue);
    }
    public static void fillweaponsfrompool(Value rightGameValue)
    {
        GameValueMethods.unary__fillweaponsfrompool__object__ret__nothing(rightGameValue);
    }
    public static Value finddisplay(Value rightGameValue)
    {
        return GameValueMethods.unary__finddisplay__scalar__ret__display(rightGameValue);
    }
    public static Value finddisplay(Value rightGameValue)
    {
        return GameValueMethods.unary__finddisplay__string__ret__display(rightGameValue);
    }
    public static Value finite(Value rightGameValue)
    {
        return GameValueMethods.unary__finite__scalar_nan__ret__bool(rightGameValue);
    }
    public static Value firstbackpack(Value rightGameValue)
    {
        return GameValueMethods.unary__firstbackpack__object__ret__object(rightGameValue);
    }
    public static Value flag(Value rightGameValue)
    {
        return GameValueMethods.unary__flag__object__ret__object(rightGameValue);
    }
    public static Value flaganimationphase(Value rightGameValue)
    {
        return GameValueMethods.unary__flaganimationphase__object__ret__scalar(rightGameValue);
    }
    public static Value flagowner(Value rightGameValue)
    {
        return GameValueMethods.unary__flagowner__object__ret__object(rightGameValue);
    }
    public static Value flagside(Value rightGameValue)
    {
        return GameValueMethods.unary__flagside__object__ret__side(rightGameValue);
    }
    public static Value flagtexture(Value rightGameValue)
    {
        return GameValueMethods.unary__flagtexture__object__ret__string(rightGameValue);
    }
    public static Value flatten(Value rightGameValue)
    {
        return GameValueMethods.unary__flatten__array__ret__array(rightGameValue);
    }
    public static Value fleeing(Value rightGameValue)
    {
        return GameValueMethods.unary__fleeing__object__ret__bool(rightGameValue);
    }
    public static Value floor(Value rightGameValue)
    {
        return GameValueMethods.unary__floor__scalar_nan__ret__scalar_nan(rightGameValue);
    }
    public static Value focusedctrl(Value rightGameValue)
    {
        return GameValueMethods.unary__focusedctrl__display__ret__control(rightGameValue);
    }
    public static Value for(Value rightGameValue)
{
	return GameValueMethods.unary__for__string__ret__for(rightGameValue);
}
public static Value for (Value rightGameValue)
{
    return GameValueMethods.unary__for__array__ret__for(rightGameValue);
}
public static Value forceatpositionrtd(Value rightGameValue)
{
    return GameValueMethods.unary__forceatpositionrtd__array__ret__array(rightGameValue);
}
public static Value forcecadetdifficulty(Value rightGameValue)
{
    return GameValueMethods.unary__forcecadetdifficulty__array__ret__array(rightGameValue);
}
public static Value forcegeneratorrtd(Value rightGameValue)
{
    return GameValueMethods.unary__forcegeneratorrtd__scalar__ret__array(rightGameValue);
}
public static void forcemap(Value rightGameValue)
{
    GameValueMethods.unary__forcemap__bool__ret__nothing(rightGameValue);
}
public static void forcerespawn(Value rightGameValue)
{
    GameValueMethods.unary__forcerespawn__object__ret__nothing(rightGameValue);
}
public static void forceunicode(Value rightGameValue)
{
    GameValueMethods.unary__forceunicode__scalar__ret__nothing(rightGameValue);
}
public static Value format(Value rightGameValue)
{
    return GameValueMethods.unary__format__array__ret__string(rightGameValue);
}
public static Value formation(Value rightGameValue)
{
    return GameValueMethods.unary__formation__object_group__ret__string(rightGameValue);
}
public static Value formation(Value rightGameValue)
{
    return GameValueMethods.unary__formation__team_member__ret__string(rightGameValue);
}
public static Value formationdirection(Value rightGameValue)
{
    return GameValueMethods.unary__formationdirection__object__ret__scalar(rightGameValue);
}
public static Value formationleader(Value rightGameValue)
{
    return GameValueMethods.unary__formationleader__object__ret__object(rightGameValue);
}
public static Value formationmembers(Value rightGameValue)
{
    return GameValueMethods.unary__formationmembers__object__ret__array(rightGameValue);
}
public static Value formationposition(Value rightGameValue)
{
    return GameValueMethods.unary__formationposition__object__ret__array(rightGameValue);
}
public static Value formationtask(Value rightGameValue)
{
    return GameValueMethods.unary__formationtask__object__ret__string(rightGameValue);
}
public static Value formattext(Value rightGameValue)
{
    return GameValueMethods.unary__formattext__array__ret__text(rightGameValue);
}
public static Value formleader(Value rightGameValue)
{
    return GameValueMethods.unary__formleader__object__ret__object(rightGameValue);
}
public static Value freeextension(Value rightGameValue)
{
    return GameValueMethods.unary__freeextension__string__ret__bool_nothing(rightGameValue);
}
public static Value fromeditor(Value rightGameValue)
{
    return GameValueMethods.unary__fromeditor__team_member__ret__bool(rightGameValue);
}
public static Value fuel(Value rightGameValue)
{
    return GameValueMethods.unary__fuel__object__ret__scalar(rightGameValue);
}
public static Value fullcrew(Value rightGameValue)
{
    return GameValueMethods.unary__fullcrew__object__ret__array(rightGameValue);
}
public static Value fullcrew(Value rightGameValue)
{
    return GameValueMethods.unary__fullcrew__array__ret__array(rightGameValue);
}
public static Value gearidcammocount(Value rightGameValue)
{
    return GameValueMethods.unary__gearidcammocount__scalar__ret__scalar(rightGameValue);
}
public static Value gearslotammocount(Value rightGameValue)
{
    return GameValueMethods.unary__gearslotammocount__control__ret__scalar(rightGameValue);
}
public static Value gearslotdata(Value rightGameValue)
{
    return GameValueMethods.unary__gearslotdata__control__ret__string(rightGameValue);
}
public static Value gesturestate(Value rightGameValue)
{
    return GameValueMethods.unary__gesturestate__object__ret__string(rightGameValue);
}
public static Value get3denactionstate(Value rightGameValue)
{
    return GameValueMethods.unary__get3denactionstate__string__ret__scalar(rightGameValue);
}
public static Value get3denconnections(Value rightGameValue)
{
    return GameValueMethods.unary__get3denconnections__any__ret__array(rightGameValue);
}
public static Value get3denentity(Value rightGameValue)
{
    return GameValueMethods.unary__get3denentity__scalar__ret__any(rightGameValue);
}
public static Value get3denentityid(Value rightGameValue)
{
    return GameValueMethods.unary__get3denentityid__any__ret__scalar(rightGameValue);
}
public static void get3dengrid(Value rightGameValue)
{
    GameValueMethods.unary__get3dengrid__string__ret__nothing(rightGameValue);
}
public static Value get3denlayerentities(Value rightGameValue)
{
    return GameValueMethods.unary__get3denlayerentities__scalar__ret__array(rightGameValue);
}
public static Value get3denselected(Value rightGameValue)
{
    return GameValueMethods.unary__get3denselected__string__ret__array(rightGameValue);
}
public static Value getaimingcoef(Value rightGameValue)
{
    return GameValueMethods.unary__getaimingcoef__object__ret__scalar(rightGameValue);
}
public static Value getallenv3dsoundcontrollers(Value rightGameValue)
{
    return GameValueMethods.unary__getallenv3dsoundcontrollers__object__ret__array(rightGameValue);
}
public static Value getallenvsoundcontrollers(Value rightGameValue)
{
    return GameValueMethods.unary__getallenvsoundcontrollers__array__ret__array(rightGameValue);
}
public static Value getallhitpointsdamage(Value rightGameValue)
{
    return GameValueMethods.unary__getallhitpointsdamage__object__ret__array(rightGameValue);
}
public static Value getallownedmines(Value rightGameValue)
{
    return GameValueMethods.unary__getallownedmines__object__ret__array(rightGameValue);
}
public static Value getallpylonsinfo(Value rightGameValue)
{
    return GameValueMethods.unary__getallpylonsinfo__object__ret__array(rightGameValue);
}
public static Value getallsoundcontrollers(Value rightGameValue)
{
    return GameValueMethods.unary__getallsoundcontrollers__object__ret__array(rightGameValue);
}
public static Value getallunittraits(Value rightGameValue)
{
    return GameValueMethods.unary__getallunittraits__object__ret__array(rightGameValue);
}
public static Value getammocargo(Value rightGameValue)
{
    return GameValueMethods.unary__getammocargo__object__ret__scalar(rightGameValue);
}
public static Value getanimaimprecision(Value rightGameValue)
{
    return GameValueMethods.unary__getanimaimprecision__object__ret__scalar(rightGameValue);
}
public static Value getanimspeedcoef(Value rightGameValue)
{
    return GameValueMethods.unary__getanimspeedcoef__object__ret__scalar(rightGameValue);
}
public static Value getarray(Value rightGameValue)
{
    return GameValueMethods.unary__getarray__config__ret__array(rightGameValue);
}
public static Value getartilleryammo(Value rightGameValue)
{
    return GameValueMethods.unary__getartilleryammo__array__ret__array(rightGameValue);
}
public static Value getassetdlcinfo(Value rightGameValue)
{
    return GameValueMethods.unary__getassetdlcinfo__object_string__ret__array(rightGameValue);
}
public static Value getassetdlcinfo(Value rightGameValue)
{
    return GameValueMethods.unary__getassetdlcinfo__array__ret__array(rightGameValue);
}
public static Value getassignedcuratorlogic(Value rightGameValue)
{
    return GameValueMethods.unary__getassignedcuratorlogic__object__ret__object(rightGameValue);
}
public static Value getassignedcuratorunit(Value rightGameValue)
{
    return GameValueMethods.unary__getassignedcuratorunit__object__ret__object(rightGameValue);
}
public static Value getattacktarget(Value rightGameValue)
{
    return GameValueMethods.unary__getattacktarget__object__ret__object(rightGameValue);
}
public static Value getbackpackcargo(Value rightGameValue)
{
    return GameValueMethods.unary__getbackpackcargo__object__ret__array(rightGameValue);
}
public static Value getbleedingremaining(Value rightGameValue)
{
    return GameValueMethods.unary__getbleedingremaining__object__ret__scalar(rightGameValue);
}
public static Value getburningvalue(Value rightGameValue)
{
    return GameValueMethods.unary__getburningvalue__object__ret__scalar(rightGameValue);
}
public static Value getcameraviewdirection(Value rightGameValue)
{
    return GameValueMethods.unary__getcameraviewdirection__object__ret__array(rightGameValue);
}
public static Value getcenterofmass(Value rightGameValue)
{
    return GameValueMethods.unary__getcenterofmass__object__ret__array(rightGameValue);
}
public static Value getconnecteduav(Value rightGameValue)
{
    return GameValueMethods.unary__getconnecteduav__object__ret__object(rightGameValue);
}
public static Value getconnecteduavunit(Value rightGameValue)
{
    return GameValueMethods.unary__getconnecteduavunit__object__ret__object(rightGameValue);
}
public static Value getcontainermaxload(Value rightGameValue)
{
    return GameValueMethods.unary__getcontainermaxload__string__ret__scalar(rightGameValue);
}
public static Value getcorpse(Value rightGameValue)
{
    return GameValueMethods.unary__getcorpse__object__ret__object(rightGameValue);
}
public static Value getcruisecontrol(Value rightGameValue)
{
    return GameValueMethods.unary__getcruisecontrol__object__ret__array(rightGameValue);
}
public static Value getcustomaimcoef(Value rightGameValue)
{
    return GameValueMethods.unary__getcustomaimcoef__object__ret__scalar(rightGameValue);
}
public static Value getcustomsoundcontroller(Value rightGameValue)
{
    return GameValueMethods.unary__getcustomsoundcontroller__array__ret__scalar(rightGameValue);
}
public static Value getcustomsoundcontrollercount(Value rightGameValue)
{
    return GameValueMethods.unary__getcustomsoundcontrollercount__object__ret__scalar(rightGameValue);
}
public static Value getdammage(Value rightGameValue)
{
    return GameValueMethods.unary__getdammage__object__ret__scalar(rightGameValue);
}
public static Value getdebriefingtext(Value rightGameValue)
{
    return GameValueMethods.unary__getdebriefingtext__string__ret__array(rightGameValue);
}
public static Value getdescription(Value rightGameValue)
{
    return GameValueMethods.unary__getdescription__object__ret__array(rightGameValue);
}
public static Value getdir(Value rightGameValue)
{
    return GameValueMethods.unary__getdir__object__ret__scalar(rightGameValue);
}
public static Value getdirvisual(Value rightGameValue)
{
    return GameValueMethods.unary__getdirvisual__object__ret__scalar(rightGameValue);
}
public static Value getdiverstate(Value rightGameValue)
{
    return GameValueMethods.unary__getdiverstate__object__ret__bool(rightGameValue);
}
public static Value getdlcassetsusagebyname(Value rightGameValue)
{
    return GameValueMethods.unary__getdlcassetsusagebyname__string__ret__array(rightGameValue);
}
public static Value getdlcs(Value rightGameValue)
{
    return GameValueMethods.unary__getdlcs__scalar__ret__array(rightGameValue);
}
public static Value getdlcusagetime(Value rightGameValue)
{
    return GameValueMethods.unary__getdlcusagetime__scalar__ret__scalar(rightGameValue);
}
public static Value geteditorcamera(Value rightGameValue)
{
    return GameValueMethods.unary__geteditorcamera__control__ret__object(rightGameValue);
}
public static Value geteditormode(Value rightGameValue)
{
    return GameValueMethods.unary__geteditormode__control__ret__string(rightGameValue);
}
public static Value getenginetargetrpmrtd(Value rightGameValue)
{
    return GameValueMethods.unary__getenginetargetrpmrtd__object__ret__array(rightGameValue);
}
public static Value geteventhandlerinfo(Value rightGameValue)
{
    return GameValueMethods.unary__geteventhandlerinfo__array__ret__array(rightGameValue);
}
public static Value getfatigue(Value rightGameValue)
{
    return GameValueMethods.unary__getfatigue__object__ret__scalar(rightGameValue);
}
public static Value getfieldmanualstartpage(Value rightGameValue)
{
    return GameValueMethods.unary__getfieldmanualstartpage__display__ret__array(rightGameValue);
}
public static Value getforcedflagtexture(Value rightGameValue)
{
    return GameValueMethods.unary__getforcedflagtexture__object__ret__string(rightGameValue);
}
public static Value getforcedspeed(Value rightGameValue)
{
    return GameValueMethods.unary__getforcedspeed__object__ret__scalar(rightGameValue);
}
public static Value getfuelcargo(Value rightGameValue)
{
    return GameValueMethods.unary__getfuelcargo__object__ret__scalar(rightGameValue);
}
public static Value getgraphvalues(Value rightGameValue)
{
    return GameValueMethods.unary__getgraphvalues__array__ret__array(rightGameValue);
}
public static Value getgroupiconparams(Value rightGameValue)
{
    return GameValueMethods.unary__getgroupiconparams__group__ret__array(rightGameValue);
}
public static Value getgroupicons(Value rightGameValue)
{
    return GameValueMethods.unary__getgroupicons__group__ret__array(rightGameValue);
}
public static Value getitemcargo(Value rightGameValue)
{
    return GameValueMethods.unary__getitemcargo__object__ret__array(rightGameValue);
}
public static Value getlightingat(Value rightGameValue)
{
    return GameValueMethods.unary__getlightingat__object__ret__array(rightGameValue);
}
public static Value getmagazinecargo(Value rightGameValue)
{
    return GameValueMethods.unary__getmagazinecargo__object__ret__array(rightGameValue);
}
public static Value getmarkercolor(Value rightGameValue)
{
    return GameValueMethods.unary__getmarkercolor__string__ret__string(rightGameValue);
}
public static Value getmarkerpos(Value rightGameValue)
{
    return GameValueMethods.unary__getmarkerpos__string__ret__array(rightGameValue);
}
public static Value getmarkerpos(Value rightGameValue)
{
    return GameValueMethods.unary__getmarkerpos__array__ret__array(rightGameValue);
}
public static Value getmarkersize(Value rightGameValue)
{
    return GameValueMethods.unary__getmarkersize__string__ret__array(rightGameValue);
}
public static Value getmarkertype(Value rightGameValue)
{
    return GameValueMethods.unary__getmarkertype__string__ret__string(rightGameValue);
}
public static Value getmass(Value rightGameValue)
{
    return GameValueMethods.unary__getmass__object__ret__scalar(rightGameValue);
}
public static Value getmissionconfig(Value rightGameValue)
{
    return GameValueMethods.unary__getmissionconfig__string__ret__config(rightGameValue);
}
public static Value getmissionconfigvalue(Value rightGameValue)
{
    return GameValueMethods.unary__getmissionconfigvalue__string_array__ret__array_string(rightGameValue);
}
public static Value getmissionlayerentities(Value rightGameValue)
{
    return GameValueMethods.unary__getmissionlayerentities__string_scalar__ret__array(rightGameValue);
}
public static Value getmissionpath(Value rightGameValue)
{
    return GameValueMethods.unary__getmissionpath__string__ret__string(rightGameValue);
}
public static Value getmodelinfo(Value rightGameValue)
{
    return GameValueMethods.unary__getmodelinfo__object__ret__array(rightGameValue);
}
public static Value getnumber(Value rightGameValue)
{
    return GameValueMethods.unary__getnumber__config__ret__scalar(rightGameValue);
}
public static Value getobjectdlc(Value rightGameValue)
{
    return GameValueMethods.unary__getobjectdlc__object__ret__scalar(rightGameValue);
}
public static Value getobjectfov(Value rightGameValue)
{
    return GameValueMethods.unary__getobjectfov__object__ret__scalar(rightGameValue);
}
public static Value getobjectid(Value rightGameValue)
{
    return GameValueMethods.unary__getobjectid__object__ret__string(rightGameValue);
}
public static Value getobjectmaterials(Value rightGameValue)
{
    return GameValueMethods.unary__getobjectmaterials__object__ret__array(rightGameValue);
}
public static Value getobjectscale(Value rightGameValue)
{
    return GameValueMethods.unary__getobjectscale__object__ret__scalar(rightGameValue);
}
public static Value getobjecttextures(Value rightGameValue)
{
    return GameValueMethods.unary__getobjecttextures__object__ret__array(rightGameValue);
}
public static Value getobjecttype(Value rightGameValue)
{
    return GameValueMethods.unary__getobjecttype__object__ret__scalar(rightGameValue);
}
public static Value getoxygenremaining(Value rightGameValue)
{
    return GameValueMethods.unary__getoxygenremaining__object__ret__scalar(rightGameValue);
}
public static Value getpersonuseddlcs(Value rightGameValue)
{
    return GameValueMethods.unary__getpersonuseddlcs__object__ret__array(rightGameValue);
}
public static Value getpilotcameradirection(Value rightGameValue)
{
    return GameValueMethods.unary__getpilotcameradirection__object__ret__array(rightGameValue);
}
public static Value getpilotcameraopticsmode(Value rightGameValue)
{
    return GameValueMethods.unary__getpilotcameraopticsmode__object__ret__scalar(rightGameValue);
}
public static Value getpilotcameraposition(Value rightGameValue)
{
    return GameValueMethods.unary__getpilotcameraposition__object__ret__array(rightGameValue);
}
public static Value getpilotcamerarotation(Value rightGameValue)
{
    return GameValueMethods.unary__getpilotcamerarotation__object__ret__array(rightGameValue);
}
public static Value getpilotcameratarget(Value rightGameValue)
{
    return GameValueMethods.unary__getpilotcameratarget__object__ret__array(rightGameValue);
}
public static Value getplatenumber(Value rightGameValue)
{
    return GameValueMethods.unary__getplatenumber__object__ret__string(rightGameValue);
}
public static Value getplayerchannel(Value rightGameValue)
{
    return GameValueMethods.unary__getplayerchannel__object__ret__scalar(rightGameValue);
}
public static Value getplayerid(Value rightGameValue)
{
    return GameValueMethods.unary__getplayerid__object__ret__string(rightGameValue);
}
public static Value getplayerscores(Value rightGameValue)
{
    return GameValueMethods.unary__getplayerscores__object__ret__array(rightGameValue);
}
public static Value getplayeruid(Value rightGameValue)
{
    return GameValueMethods.unary__getplayeruid__object__ret__string(rightGameValue);
}
public static Value getplayervonvolume(Value rightGameValue)
{
    return GameValueMethods.unary__getplayervonvolume__object__ret__scalar(rightGameValue);
}
public static Value getpos(Value rightGameValue)
{
    return GameValueMethods.unary__getpos__object__ret__array(rightGameValue);
}
public static Value getpos(Value rightGameValue)
{
    return GameValueMethods.unary__getpos__location__ret__array(rightGameValue);
}
public static Value getposasl(Value rightGameValue)
{
    return GameValueMethods.unary__getposasl__object__ret__array(rightGameValue);
}
public static Value getposaslvisual(Value rightGameValue)
{
    return GameValueMethods.unary__getposaslvisual__object__ret__array(rightGameValue);
}
public static Value getposaslw(Value rightGameValue)
{
    return GameValueMethods.unary__getposaslw__object__ret__array(rightGameValue);
}
public static Value getposatl(Value rightGameValue)
{
    return GameValueMethods.unary__getposatl__object__ret__array(rightGameValue);
}
public static Value getposatlvisual(Value rightGameValue)
{
    return GameValueMethods.unary__getposatlvisual__object__ret__array(rightGameValue);
}
public static Value getposvisual(Value rightGameValue)
{
    return GameValueMethods.unary__getposvisual__object__ret__array(rightGameValue);
}
public static Value getposworld(Value rightGameValue)
{
    return GameValueMethods.unary__getposworld__object__ret__array(rightGameValue);
}
public static Value getposworldvisual(Value rightGameValue)
{
    return GameValueMethods.unary__getposworldvisual__object__ret__array(rightGameValue);
}
public static Value getpylonmagazines(Value rightGameValue)
{
    return GameValueMethods.unary__getpylonmagazines__object__ret__array(rightGameValue);
}
public static Value getrepaircargo(Value rightGameValue)
{
    return GameValueMethods.unary__getrepaircargo__object__ret__scalar(rightGameValue);
}
public static Value getroadinfo(Value rightGameValue)
{
    return GameValueMethods.unary__getroadinfo__object__ret__array(rightGameValue);
}
public static Value getrotorbrakertd(Value rightGameValue)
{
    return GameValueMethods.unary__getrotorbrakertd__object__ret__scalar(rightGameValue);
}
public static Value getsensortargets(Value rightGameValue)
{
    return GameValueMethods.unary__getsensortargets__object__ret__array(rightGameValue);
}
public static Value getsensorthreats(Value rightGameValue)
{
    return GameValueMethods.unary__getsensorthreats__object__ret__array(rightGameValue);
}
public static Value getshotparents(Value rightGameValue)
{
    return GameValueMethods.unary__getshotparents__object__ret__array(rightGameValue);
}
public static Value getslingload(Value rightGameValue)
{
    return GameValueMethods.unary__getslingload__object__ret__object(rightGameValue);
}
public static Value getstamina(Value rightGameValue)
{
    return GameValueMethods.unary__getstamina__object__ret__scalar(rightGameValue);
}
public static Value getstatvalue(Value rightGameValue)
{
    return GameValueMethods.unary__getstatvalue__string__ret__scalar(rightGameValue);
}
public static Value getsuppression(Value rightGameValue)
{
    return GameValueMethods.unary__getsuppression__object__ret__scalar(rightGameValue);
}
public static Value getterrainheight(Value rightGameValue)
{
    return GameValueMethods.unary__getterrainheight__array__ret__scalar(rightGameValue);
}
public static Value getterrainheightasl(Value rightGameValue)
{
    return GameValueMethods.unary__getterrainheightasl__array__ret__scalar(rightGameValue);
}
public static Value gettext(Value rightGameValue)
{
    return GameValueMethods.unary__gettext__config__ret__string(rightGameValue);
}
public static Value gettextraw(Value rightGameValue)
{
    return GameValueMethods.unary__gettextraw__config__ret__string(rightGameValue);
}
public static Value gettextureinfo(Value rightGameValue)
{
    return GameValueMethods.unary__gettextureinfo__string__ret__array(rightGameValue);
}
public static Value gettowparent(Value rightGameValue)
{
    return GameValueMethods.unary__gettowparent__object__ret__object(rightGameValue);
}
public static Value gettrimoffsetrtd(Value rightGameValue)
{
    return GameValueMethods.unary__gettrimoffsetrtd__object__ret__array(rightGameValue);
}
public static Value getturretopticsmode(Value rightGameValue)
{
    return GameValueMethods.unary__getturretopticsmode__object__ret__array(rightGameValue);
}
public static Value getunitfreefallinfo(Value rightGameValue)
{
    return GameValueMethods.unary__getunitfreefallinfo__object__ret__array(rightGameValue);
}
public static Value getunitloadout(Value rightGameValue)
{
    return GameValueMethods.unary__getunitloadout__object_array__ret__array(rightGameValue);
}
public static Value getunitloadout(Value rightGameValue)
{
    return GameValueMethods.unary__getunitloadout__string__ret__array(rightGameValue);
}
public static Value getunitloadout(Value rightGameValue)
{
    return GameValueMethods.unary__getunitloadout__config__ret__array(rightGameValue);
}
public static Value getunloadincombat(Value rightGameValue)
{
    return GameValueMethods.unary__getunloadincombat__object__ret__array(rightGameValue);
}
public static Value getuserinfo(Value rightGameValue)
{
    return GameValueMethods.unary__getuserinfo__string__ret__array(rightGameValue);
}
public static Value getusermfdtext(Value rightGameValue)
{
    return GameValueMethods.unary__getusermfdtext__object__ret__array(rightGameValue);
}
public static Value getusermfdvalue(Value rightGameValue)
{
    return GameValueMethods.unary__getusermfdvalue__object__ret__array(rightGameValue);
}
public static Value getvehiclecargo(Value rightGameValue)
{
    return GameValueMethods.unary__getvehiclecargo__object__ret__array(rightGameValue);
}
public static Value getvehicletipars(Value rightGameValue)
{
    return GameValueMethods.unary__getvehicletipars__object__ret__array(rightGameValue);
}
public static Value getweaponcargo(Value rightGameValue)
{
    return GameValueMethods.unary__getweaponcargo__object__ret__array(rightGameValue);
}
public static Value getweaponsway(Value rightGameValue)
{
    return GameValueMethods.unary__getweaponsway__object__ret__scalar(rightGameValue);
}
public static Value getwingsorientationrtd(Value rightGameValue)
{
    return GameValueMethods.unary__getwingsorientationrtd__object__ret__scalar(rightGameValue);
}
public static Value getwingspositionrtd(Value rightGameValue)
{
    return GameValueMethods.unary__getwingspositionrtd__object__ret__scalar(rightGameValue);
}
public static Value getwppos(Value rightGameValue)
{
    return GameValueMethods.unary__getwppos__array__ret__array(rightGameValue);
}
public static Value goggles(Value rightGameValue)
{
    return GameValueMethods.unary__goggles__object__ret__string(rightGameValue);
}
public static void goto(Value rightGameValue)
{
    GameValueMethods.unary__goto__string__ret__nothing(rightGameValue);
}
public static Value group(Value rightGameValue)
{
    return GameValueMethods.unary__group__object__ret__group(rightGameValue);
}
public static Value groupfromnetid(Value rightGameValue)
{
    return GameValueMethods.unary__groupfromnetid__string__ret__group(rightGameValue);
}
public static Value groupid(Value rightGameValue)
{
    return GameValueMethods.unary__groupid__group__ret__string(rightGameValue);
}
public static Value groupid(Value rightGameValue)
{
    return GameValueMethods.unary__groupid__object__ret__scalar(rightGameValue);
}
public static Value groupowner(Value rightGameValue)
{
    return GameValueMethods.unary__groupowner__group__ret__scalar(rightGameValue);
}
public static Value groups(Value rightGameValue)
{
    return GameValueMethods.unary__groups__side__ret__array(rightGameValue);
}
public static Value groupselectedunits(Value rightGameValue)
{
    return GameValueMethods.unary__groupselectedunits__object__ret__array(rightGameValue);
}
public static Value gunner(Value rightGameValue)
{
    return GameValueMethods.unary__gunner__object__ret__object(rightGameValue);
}
public static Value handgunitems(Value rightGameValue)
{
    return GameValueMethods.unary__handgunitems__object__ret__array(rightGameValue);
}
public static Value handgunmagazine(Value rightGameValue)
{
    return GameValueMethods.unary__handgunmagazine__object__ret__string(rightGameValue);
}
public static Value handgunweapon(Value rightGameValue)
{
    return GameValueMethods.unary__handgunweapon__object__ret__string(rightGameValue);
}
public static Value handshit(Value rightGameValue)
{
    return GameValueMethods.unary__handshit__object__ret__scalar(rightGameValue);
}
public static Value hashvalue(Value rightGameValue)
{
    return GameValueMethods.unary__hashvalue__object_side__ret__string(rightGameValue);
}
public static Value haspilotcamera(Value rightGameValue)
{
    return GameValueMethods.unary__haspilotcamera__object__ret__bool(rightGameValue);
}
public static Value hcallgroups(Value rightGameValue)
{
    return GameValueMethods.unary__hcallgroups__object__ret__array(rightGameValue);
}
public static Value hcleader(Value rightGameValue)
{
    return GameValueMethods.unary__hcleader__group__ret__object(rightGameValue);
}
public static void hcremoveallgroups(Value rightGameValue)
{
    GameValueMethods.unary__hcremoveallgroups__object__ret__nothing(rightGameValue);
}
public static Value hcselected(Value rightGameValue)
{
    return GameValueMethods.unary__hcselected__object__ret__array(rightGameValue);
}
public static void hcshowbar(Value rightGameValue)
{
    GameValueMethods.unary__hcshowbar__bool__ret__nothing(rightGameValue);
}
public static Value headgear(Value rightGameValue)
{
    return GameValueMethods.unary__headgear__object__ret__string(rightGameValue);
}
public static void hidebody(Value rightGameValue)
{
    GameValueMethods.unary__hidebody__object__ret__nothing(rightGameValue);
}
public static void hideobject(Value rightGameValue)
{
    GameValueMethods.unary__hideobject__object__ret__nothing(rightGameValue);
}
public static void hideobjectglobal(Value rightGameValue)
{
    GameValueMethods.unary__hideobjectglobal__object__ret__nothing(rightGameValue);
}
public static void hint(Value rightGameValue)
{
    GameValueMethods.unary__hint__text_string__ret__nothing(rightGameValue);
}
public static void hintc(Value rightGameValue)
{
    GameValueMethods.unary__hintc__string__ret__nothing(rightGameValue);
}
public static void hintcadet(Value rightGameValue)
{
    GameValueMethods.unary__hintcadet__text_string__ret__nothing(rightGameValue);
}
public static void hintsilent(Value rightGameValue)
{
    GameValueMethods.unary__hintsilent__text_string__ret__nothing(rightGameValue);
}
public static Value hmd(Value rightGameValue)
{
    return GameValueMethods.unary__hmd__object__ret__string(rightGameValue);
}
public static void hostmission(Value rightGameValue)
{
    GameValueMethods.unary__hostmission__array__ret__nothing(rightGameValue);
}
public static Value if (Value rightGameValue)
{
    return GameValueMethods.unary__if__bool__ret__if(rightGameValue);
}
public static Value image(Value rightGameValue)
{
    return GameValueMethods.unary__image__string__ret__text(rightGameValue);
}
public static void importallgroups(Value rightGameValue)
{
    GameValueMethods.unary__importallgroups__control__ret__nothing(rightGameValue);
}
public static Value importance(Value rightGameValue)
{
    return GameValueMethods.unary__importance__location__ret__scalar(rightGameValue);
}
public static Value incapacitatedstate(Value rightGameValue)
{
    return GameValueMethods.unary__incapacitatedstate__object__ret__string(rightGameValue);
}
public static Value inflamed(Value rightGameValue)
{
    return GameValueMethods.unary__inflamed__object__ret__bool(rightGameValue);
}
public static Value infopanel(Value rightGameValue)
{
    return GameValueMethods.unary__infopanel__string__ret__array(rightGameValue);
}
public static Value infopanels(Value rightGameValue)
{
    return GameValueMethods.unary__infopanels__object_array__ret__array(rightGameValue);
}
public static void ingameuiseteventhandler(Value rightGameValue)
{
    GameValueMethods.unary__ingameuiseteventhandler__array__ret__nothing(rightGameValue);
}
public static Value inheritsfrom(Value rightGameValue)
{
    return GameValueMethods.unary__inheritsfrom__config__ret__config(rightGameValue);
}
public static Value inputaction(Value rightGameValue)
{
    return GameValueMethods.unary__inputaction__string__ret__scalar(rightGameValue);
}
public static Value inputcontroller(Value rightGameValue)
{
    return GameValueMethods.unary__inputcontroller__scalar__ret__scalar(rightGameValue);
}
public static Value inputmouse(Value rightGameValue)
{
    return GameValueMethods.unary__inputmouse__scalar__ret__scalar(rightGameValue);
}
public static Value inputmouse(Value rightGameValue)
{
    return GameValueMethods.unary__inputmouse__string__ret__bool(rightGameValue);
}
public static Value insidebuilding(Value rightGameValue)
{
    return GameValueMethods.unary__insidebuilding__object__ret__scalar(rightGameValue);
}
public static Value isabletobreathe(Value rightGameValue)
{
    return GameValueMethods.unary__isabletobreathe__object__ret__bool(rightGameValue);
}
public static Value isagent(Value rightGameValue)
{
    return GameValueMethods.unary__isagent__team_member__ret__bool(rightGameValue);
}
public static Value isaimprecisionenabled(Value rightGameValue)
{
    return GameValueMethods.unary__isaimprecisionenabled__object__ret__bool(rightGameValue);
}
public static Value isallowedcrewinimmobile(Value rightGameValue)
{
    return GameValueMethods.unary__isallowedcrewinimmobile__object__ret__bool(rightGameValue);
}
public static Value isarray(Value rightGameValue)
{
    return GameValueMethods.unary__isarray__config__ret__bool(rightGameValue);
}
public static Value isautohoveron(Value rightGameValue)
{
    return GameValueMethods.unary__isautohoveron__object__ret__bool(rightGameValue);
}
public static Value isautonomous(Value rightGameValue)
{
    return GameValueMethods.unary__isautonomous__object__ret__bool(rightGameValue);
}
public static Value isautostartupenabledrtd(Value rightGameValue)
{
    return GameValueMethods.unary__isautostartupenabledrtd__object__ret__array(rightGameValue);
}
public static Value isautotrimonrtd(Value rightGameValue)
{
    return GameValueMethods.unary__isautotrimonrtd__object__ret__bool(rightGameValue);
}
public static Value isawake(Value rightGameValue)
{
    return GameValueMethods.unary__isawake__object__ret__bool(rightGameValue);
}
public static Value isbleeding(Value rightGameValue)
{
    return GameValueMethods.unary__isbleeding__object__ret__bool(rightGameValue);
}
public static Value isburning(Value rightGameValue)
{
    return GameValueMethods.unary__isburning__object__ret__bool(rightGameValue);
}
public static Value isclass(Value rightGameValue)
{
    return GameValueMethods.unary__isclass__config__ret__bool(rightGameValue);
}
public static Value iscollisionlighton(Value rightGameValue)
{
    return GameValueMethods.unary__iscollisionlighton__object__ret__bool(rightGameValue);
}
public static Value iscopilotenabled(Value rightGameValue)
{
    return GameValueMethods.unary__iscopilotenabled__object__ret__bool(rightGameValue);
}
public static Value isdamageallowed(Value rightGameValue)
{
    return GameValueMethods.unary__isdamageallowed__object__ret__bool(rightGameValue);
}
public static Value isdlcavailable(Value rightGameValue)
{
    return GameValueMethods.unary__isdlcavailable__scalar__ret__bool(rightGameValue);
}
public static Value isengineon(Value rightGameValue)
{
    return GameValueMethods.unary__isengineon__object__ret__bool(rightGameValue);
}
public static Value isfinal(Value rightGameValue)
{
    return GameValueMethods.unary__isfinal__any__ret__bool(rightGameValue);
}
public static Value isforcedwalk(Value rightGameValue)
{
    return GameValueMethods.unary__isforcedwalk__object__ret__bool(rightGameValue);
}
public static Value isformationleader(Value rightGameValue)
{
    return GameValueMethods.unary__isformationleader__object__ret__bool(rightGameValue);
}
public static Value isgroupdeletedwhenempty(Value rightGameValue)
{
    return GameValueMethods.unary__isgroupdeletedwhenempty__group__ret__bool(rightGameValue);
}
public static Value ishidden(Value rightGameValue)
{
    return GameValueMethods.unary__ishidden__object__ret__bool(rightGameValue);
}
public static Value isinremainscollector(Value rightGameValue)
{
    return GameValueMethods.unary__isinremainscollector__object__ret__bool(rightGameValue);
}
public static Value iskeyactive(Value rightGameValue)
{
    return GameValueMethods.unary__iskeyactive__string__ret__bool(rightGameValue);
}
public static Value islaseron(Value rightGameValue)
{
    return GameValueMethods.unary__islaseron__object__ret__bool(rightGameValue);
}
public static Value islighton(Value rightGameValue)
{
    return GameValueMethods.unary__islighton__object_array__ret__bool(rightGameValue);
}
public static Value islocalized(Value rightGameValue)
{
    return GameValueMethods.unary__islocalized__string__ret__bool(rightGameValue);
}
public static Value ismanualfire(Value rightGameValue)
{
    return GameValueMethods.unary__ismanualfire__object__ret__bool(rightGameValue);
}
public static Value ismarkedforcollection(Value rightGameValue)
{
    return GameValueMethods.unary__ismarkedforcollection__object__ret__bool(rightGameValue);
}
public static Value isnil(Value rightGameValue)
{
    return GameValueMethods.unary__isnil__code_string__ret__bool(rightGameValue);
}
public static Value isnull(Value rightGameValue)
{
    return GameValueMethods.unary__isnull__object__ret__bool(rightGameValue);
}
public static Value isnull(Value rightGameValue)
{
    return GameValueMethods.unary__isnull__group__ret__bool(rightGameValue);
}
public static Value isnull(Value rightGameValue)
{
    return GameValueMethods.unary__isnull__script__ret__bool(rightGameValue);
}
public static Value isnull(Value rightGameValue)
{
    return GameValueMethods.unary__isnull__config__ret__bool(rightGameValue);
}
public static Value isnull(Value rightGameValue)
{
    return GameValueMethods.unary__isnull__display__ret__bool(rightGameValue);
}
public static Value isnull(Value rightGameValue)
{
    return GameValueMethods.unary__isnull__control__ret__bool(rightGameValue);
}
public static Value isnull(Value rightGameValue)
{
    return GameValueMethods.unary__isnull__team_member__ret__bool(rightGameValue);
}
public static Value isnull(Value rightGameValue)
{
    return GameValueMethods.unary__isnull__netobject__ret__bool(rightGameValue);
}
public static Value isnull(Value rightGameValue)
{
    return GameValueMethods.unary__isnull__task__ret__bool(rightGameValue);
}
public static Value isnull(Value rightGameValue)
{
    return GameValueMethods.unary__isnull__diary_record__ret__bool(rightGameValue);
}
public static Value isnull(Value rightGameValue)
{
    return GameValueMethods.unary__isnull__location__ret__bool(rightGameValue);
}
public static Value isnumber(Value rightGameValue)
{
    return GameValueMethods.unary__isnumber__config__ret__bool(rightGameValue);
}
public static Value isobjecthidden(Value rightGameValue)
{
    return GameValueMethods.unary__isobjecthidden__object__ret__bool(rightGameValue);
}
public static Value isobjectrtd(Value rightGameValue)
{
    return GameValueMethods.unary__isobjectrtd__object__ret__bool(rightGameValue);
}
public static Value isonroad(Value rightGameValue)
{
    return GameValueMethods.unary__isonroad__object_array__ret__bool(rightGameValue);
}
public static Value isplayer(Value rightGameValue)
{
    return GameValueMethods.unary__isplayer__object__ret__bool(rightGameValue);
}
public static Value isplayer(Value rightGameValue)
{
    return GameValueMethods.unary__isplayer__array__ret__bool(rightGameValue);
}
public static Value isrealtime(Value rightGameValue)
{
    return GameValueMethods.unary__isrealtime__control__ret__bool(rightGameValue);
}
public static Value isshowing3dicons(Value rightGameValue)
{
    return GameValueMethods.unary__isshowing3dicons__control__ret__bool(rightGameValue);
}
public static Value issimpleobject(Value rightGameValue)
{
    return GameValueMethods.unary__issimpleobject__object__ret__bool(rightGameValue);
}
public static Value issprintallowed(Value rightGameValue)
{
    return GameValueMethods.unary__issprintallowed__object__ret__bool(rightGameValue);
}
public static Value isstaminaenabled(Value rightGameValue)
{
    return GameValueMethods.unary__isstaminaenabled__object__ret__bool(rightGameValue);
}
public static Value istext(Value rightGameValue)
{
    return GameValueMethods.unary__istext__config__ret__bool(rightGameValue);
}
public static Value istouchingground(Value rightGameValue)
{
    return GameValueMethods.unary__istouchingground__object__ret__bool(rightGameValue);
}
public static Value isturnedout(Value rightGameValue)
{
    return GameValueMethods.unary__isturnedout__object__ret__bool(rightGameValue);
}
public static Value isuavconnected(Value rightGameValue)
{
    return GameValueMethods.unary__isuavconnected__object__ret__bool(rightGameValue);
}
public static Value isvehiclecargo(Value rightGameValue)
{
    return GameValueMethods.unary__isvehiclecargo__object__ret__object(rightGameValue);
}
public static Value isvehicleradaron(Value rightGameValue)
{
    return GameValueMethods.unary__isvehicleradaron__object__ret__bool(rightGameValue);
}
public static Value iswalking(Value rightGameValue)
{
    return GameValueMethods.unary__iswalking__object__ret__bool(rightGameValue);
}
public static Value isweapondeployed(Value rightGameValue)
{
    return GameValueMethods.unary__isweapondeployed__object__ret__bool(rightGameValue);
}
public static Value isweapondeployed(Value rightGameValue)
{
    return GameValueMethods.unary__isweapondeployed__array__ret__bool(rightGameValue);
}
public static Value isweaponrested(Value rightGameValue)
{
    return GameValueMethods.unary__isweaponrested__object__ret__bool(rightGameValue);
}
public static Value itemcargo(Value rightGameValue)
{
    return GameValueMethods.unary__itemcargo__object__ret__array(rightGameValue);
}
public static Value items(Value rightGameValue)
{
    return GameValueMethods.unary__items__object__ret__array(rightGameValue);
}
public static Value itemswithmagazines(Value rightGameValue)
{
    return GameValueMethods.unary__itemswithmagazines__object__ret__array(rightGameValue);
}
public static Value keyimage(Value rightGameValue)
{
    return GameValueMethods.unary__keyimage__string_scalar__ret__text(rightGameValue);
}
public static Value keyname(Value rightGameValue)
{
    return GameValueMethods.unary__keyname__string_scalar__ret__string(rightGameValue);
}
public static Value keys(Value rightGameValue)
{
    return GameValueMethods.unary__keys__hashmap__ret__array(rightGameValue);
}
public static Value landresult(Value rightGameValue)
{
    return GameValueMethods.unary__landresult__object__ret__string(rightGameValue);
}
public static Value lasertarget(Value rightGameValue)
{
    return GameValueMethods.unary__lasertarget__object__ret__object(rightGameValue);
}
public static Value lbadd(Value rightGameValue)
{
    return GameValueMethods.unary__lbadd__array__ret__scalar(rightGameValue);
}
public static void lbclear(Value rightGameValue)
{
    GameValueMethods.unary__lbclear__control__ret__nothing(rightGameValue);
}
public static void lbclear(Value rightGameValue)
{
    GameValueMethods.unary__lbclear__scalar__ret__nothing(rightGameValue);
}
public static Value lbcolor(Value rightGameValue)
{
    return GameValueMethods.unary__lbcolor__array__ret__array(rightGameValue);
}
public static Value lbcolorright(Value rightGameValue)
{
    return GameValueMethods.unary__lbcolorright__array__ret__array(rightGameValue);
}
public static Value lbcursel(Value rightGameValue)
{
    return GameValueMethods.unary__lbcursel__control__ret__scalar(rightGameValue);
}
public static Value lbcursel(Value rightGameValue)
{
    return GameValueMethods.unary__lbcursel__scalar__ret__scalar(rightGameValue);
}
public static Value lbdata(Value rightGameValue)
{
    return GameValueMethods.unary__lbdata__array__ret__string(rightGameValue);
}
public static void lbdelete(Value rightGameValue)
{
    GameValueMethods.unary__lbdelete__array__ret__nothing(rightGameValue);
}
public static Value lbpicture(Value rightGameValue)
{
    return GameValueMethods.unary__lbpicture__array__ret__string(rightGameValue);
}
public static Value lbpictureright(Value rightGameValue)
{
    return GameValueMethods.unary__lbpictureright__array__ret__string(rightGameValue);
}
public static Value lbselection(Value rightGameValue)
{
    return GameValueMethods.unary__lbselection__control__ret__array(rightGameValue);
}
public static void lbsetcolor(Value rightGameValue)
{
    GameValueMethods.unary__lbsetcolor__array__ret__nothing(rightGameValue);
}
public static void lbsetcolorright(Value rightGameValue)
{
    GameValueMethods.unary__lbsetcolorright__array__ret__nothing(rightGameValue);
}
public static void lbsetcursel(Value rightGameValue)
{
    GameValueMethods.unary__lbsetcursel__array__ret__nothing(rightGameValue);
}
public static void lbsetdata(Value rightGameValue)
{
    GameValueMethods.unary__lbsetdata__array__ret__nothing(rightGameValue);
}
public static void lbsetpicture(Value rightGameValue)
{
    GameValueMethods.unary__lbsetpicture__array__ret__nothing(rightGameValue);
}
public static void lbsetpicturecolor(Value rightGameValue)
{
    GameValueMethods.unary__lbsetpicturecolor__array__ret__nothing(rightGameValue);
}
public static void lbsetpicturecolordisabled(Value rightGameValue)
{
    GameValueMethods.unary__lbsetpicturecolordisabled__array__ret__nothing(rightGameValue);
}
public static void lbsetpicturecolorselected(Value rightGameValue)
{
    GameValueMethods.unary__lbsetpicturecolorselected__array__ret__nothing(rightGameValue);
}
public static void lbsetpictureright(Value rightGameValue)
{
    GameValueMethods.unary__lbsetpictureright__array__ret__nothing(rightGameValue);
}
public static void lbsetselectcolor(Value rightGameValue)
{
    GameValueMethods.unary__lbsetselectcolor__array__ret__nothing(rightGameValue);
}
public static void lbsetselectcolorright(Value rightGameValue)
{
    GameValueMethods.unary__lbsetselectcolorright__array__ret__nothing(rightGameValue);
}
public static Value lbsettext(Value rightGameValue)
{
    return GameValueMethods.unary__lbsettext__array__ret__string(rightGameValue);
}
public static void lbsettooltip(Value rightGameValue)
{
    GameValueMethods.unary__lbsettooltip__array__ret__nothing(rightGameValue);
}
public static void lbsetvalue(Value rightGameValue)
{
    GameValueMethods.unary__lbsetvalue__array__ret__nothing(rightGameValue);
}
public static Value lbsize(Value rightGameValue)
{
    return GameValueMethods.unary__lbsize__control__ret__scalar(rightGameValue);
}
public static Value lbsize(Value rightGameValue)
{
    return GameValueMethods.unary__lbsize__scalar__ret__scalar(rightGameValue);
}
public static void lbsort(Value rightGameValue)
{
    GameValueMethods.unary__lbsort__control__ret__nothing(rightGameValue);
}
public static void lbsort(Value rightGameValue)
{
    GameValueMethods.unary__lbsort__array__ret__nothing(rightGameValue);
}
public static void lbsort(Value rightGameValue)
{
    GameValueMethods.unary__lbsort__scalar__ret__nothing(rightGameValue);
}
public static void lbsortbyvalue(Value rightGameValue)
{
    GameValueMethods.unary__lbsortbyvalue__control__ret__nothing(rightGameValue);
}
public static void lbsortbyvalue(Value rightGameValue)
{
    GameValueMethods.unary__lbsortbyvalue__scalar__ret__nothing(rightGameValue);
}
public static Value lbtext(Value rightGameValue)
{
    return GameValueMethods.unary__lbtext__array__ret__string(rightGameValue);
}
public static Value lbtextright(Value rightGameValue)
{
    return GameValueMethods.unary__lbtextright__array__ret__string(rightGameValue);
}
public static Value lbtooltip(Value rightGameValue)
{
    return GameValueMethods.unary__lbtooltip__array__ret__string(rightGameValue);
}
public static Value lbvalue(Value rightGameValue)
{
    return GameValueMethods.unary__lbvalue__array__ret__scalar(rightGameValue);
}
public static Value leader(Value rightGameValue)
{
    return GameValueMethods.unary__leader__object__ret__object(rightGameValue);
}
public static Value leader(Value rightGameValue)
{
    return GameValueMethods.unary__leader__group__ret__object(rightGameValue);
}
public static Value leader(Value rightGameValue)
{
    return GameValueMethods.unary__leader__team_member__ret__team_member(rightGameValue);
}
public static Value leaderboarddeinit(Value rightGameValue)
{
    return GameValueMethods.unary__leaderboarddeinit__string__ret__bool(rightGameValue);
}
public static Value leaderboardgetrows(Value rightGameValue)
{
    return GameValueMethods.unary__leaderboardgetrows__string__ret__array(rightGameValue);
}
public static Value leaderboardinit(Value rightGameValue)
{
    return GameValueMethods.unary__leaderboardinit__string__ret__bool(rightGameValue);
}
public static Value leaderboardrequestrowsfriends(Value rightGameValue)
{
    return GameValueMethods.unary__leaderboardrequestrowsfriends__string__ret__bool(rightGameValue);
}
public static Value leaderboardrequestrowsglobal(Value rightGameValue)
{
    return GameValueMethods.unary__leaderboardrequestrowsglobal__array__ret__bool(rightGameValue);
}
public static Value leaderboardrequestrowsglobalarounduser(Value rightGameValue)
{
    return GameValueMethods.unary__leaderboardrequestrowsglobalarounduser__array__ret__bool(rightGameValue);
}
public static Value leaderboardsrequestuploadscore(Value rightGameValue)
{
    return GameValueMethods.unary__leaderboardsrequestuploadscore__array__ret__bool(rightGameValue);
}
public static Value leaderboardsrequestuploadscorekeepbest(Value rightGameValue)
{
    return GameValueMethods.unary__leaderboardsrequestuploadscorekeepbest__array__ret__bool(rightGameValue);
}
public static Value leaderboardstate(Value rightGameValue)
{
    return GameValueMethods.unary__leaderboardstate__string__ret__scalar(rightGameValue);
}
public static Value lifestate(Value rightGameValue)
{
    return GameValueMethods.unary__lifestate__object__ret__string(rightGameValue);
}
public static void lightdetachobject(Value rightGameValue)
{
    GameValueMethods.unary__lightdetachobject__object__ret__nothing(rightGameValue);
}
public static Value lightison(Value rightGameValue)
{
    return GameValueMethods.unary__lightison__object__ret__string(rightGameValue);
}
public static Value linearconversion(Value rightGameValue)
{
    return GameValueMethods.unary__linearconversion__array__ret__scalar(rightGameValue);
}
public static Value lineintersects(Value rightGameValue)
{
    return GameValueMethods.unary__lineintersects__array__ret__bool(rightGameValue);
}
public static Value lineintersectsobjs(Value rightGameValue)
{
    return GameValueMethods.unary__lineintersectsobjs__array__ret__array(rightGameValue);
}
public static Value lineintersectssurfaces(Value rightGameValue)
{
    return GameValueMethods.unary__lineintersectssurfaces__array__ret__array(rightGameValue);
}
public static Value lineintersectswith(Value rightGameValue)
{
    return GameValueMethods.unary__lineintersectswith__array__ret__array(rightGameValue);
}
public static Value list(Value rightGameValue)
{
    return GameValueMethods.unary__list__object__ret__array(rightGameValue);
}
public static Value listremotetargets(Value rightGameValue)
{
    return GameValueMethods.unary__listremotetargets__side__ret__array(rightGameValue);
}
public static Value listvehiclesensors(Value rightGameValue)
{
    return GameValueMethods.unary__listvehiclesensors__object__ret__array(rightGameValue);
}
public static Value ln(Value rightGameValue)
{
    return GameValueMethods.unary__ln__scalar_nan__ret__scalar_nan(rightGameValue);
}
public static Value lnbaddarray(Value rightGameValue)
{
    return GameValueMethods.unary__lnbaddarray__array__ret__scalar(rightGameValue);
}
public static Value lnbaddcolumn(Value rightGameValue)
{
    return GameValueMethods.unary__lnbaddcolumn__array__ret__scalar(rightGameValue);
}
public static Value lnbaddrow(Value rightGameValue)
{
    return GameValueMethods.unary__lnbaddrow__array__ret__scalar(rightGameValue);
}
public static void lnbclear(Value rightGameValue)
{
    GameValueMethods.unary__lnbclear__control__ret__nothing(rightGameValue);
}
public static void lnbclear(Value rightGameValue)
{
    GameValueMethods.unary__lnbclear__scalar__ret__nothing(rightGameValue);
}
public static Value lnbcolor(Value rightGameValue)
{
    return GameValueMethods.unary__lnbcolor__array__ret__array(rightGameValue);
}
public static Value lnbcolorright(Value rightGameValue)
{
    return GameValueMethods.unary__lnbcolorright__array__ret__array(rightGameValue);
}
public static Value lnbcurselrow(Value rightGameValue)
{
    return GameValueMethods.unary__lnbcurselrow__control__ret__scalar(rightGameValue);
}
public static Value lnbcurselrow(Value rightGameValue)
{
    return GameValueMethods.unary__lnbcurselrow__scalar__ret__scalar(rightGameValue);
}
public static Value lnbdata(Value rightGameValue)
{
    return GameValueMethods.unary__lnbdata__array__ret__string(rightGameValue);
}
public static void lnbdeletecolumn(Value rightGameValue)
{
    GameValueMethods.unary__lnbdeletecolumn__array__ret__nothing(rightGameValue);
}
public static void lnbdeleterow(Value rightGameValue)
{
    GameValueMethods.unary__lnbdeleterow__array__ret__nothing(rightGameValue);
}
public static Value lnbgetcolumnsposition(Value rightGameValue)
{
    return GameValueMethods.unary__lnbgetcolumnsposition__control__ret__array(rightGameValue);
}
public static Value lnbgetcolumnsposition(Value rightGameValue)
{
    return GameValueMethods.unary__lnbgetcolumnsposition__scalar__ret__array(rightGameValue);
}
public static Value lnbpicture(Value rightGameValue)
{
    return GameValueMethods.unary__lnbpicture__array__ret__string(rightGameValue);
}
public static Value lnbpictureright(Value rightGameValue)
{
    return GameValueMethods.unary__lnbpictureright__array__ret__string(rightGameValue);
}
public static void lnbsetcolor(Value rightGameValue)
{
    GameValueMethods.unary__lnbsetcolor__array__ret__nothing(rightGameValue);
}
public static void lnbsetcolorright(Value rightGameValue)
{
    GameValueMethods.unary__lnbsetcolorright__array__ret__nothing(rightGameValue);
}
public static void lnbsetcolumnspos(Value rightGameValue)
{
    GameValueMethods.unary__lnbsetcolumnspos__array__ret__nothing(rightGameValue);
}
public static void lnbsetcurselrow(Value rightGameValue)
{
    GameValueMethods.unary__lnbsetcurselrow__array__ret__nothing(rightGameValue);
}
public static void lnbsetdata(Value rightGameValue)
{
    GameValueMethods.unary__lnbsetdata__array__ret__nothing(rightGameValue);
}
public static void lnbsetpicture(Value rightGameValue)
{
    GameValueMethods.unary__lnbsetpicture__array__ret__nothing(rightGameValue);
}
public static void lnbsetpicturecolor(Value rightGameValue)
{
    GameValueMethods.unary__lnbsetpicturecolor__array__ret__nothing(rightGameValue);
}
public static void lnbsetpicturecolorright(Value rightGameValue)
{
    GameValueMethods.unary__lnbsetpicturecolorright__array__ret__nothing(rightGameValue);
}
public static void lnbsetpicturecolorselected(Value rightGameValue)
{
    GameValueMethods.unary__lnbsetpicturecolorselected__array__ret__nothing(rightGameValue);
}
public static void lnbsetpicturecolorselectedright(Value rightGameValue)
{
    GameValueMethods.unary__lnbsetpicturecolorselectedright__array__ret__nothing(rightGameValue);
}
public static void lnbsetpictureright(Value rightGameValue)
{
    GameValueMethods.unary__lnbsetpictureright__array__ret__nothing(rightGameValue);
}
public static void lnbsettext(Value rightGameValue)
{
    GameValueMethods.unary__lnbsettext__array__ret__nothing(rightGameValue);
}
public static void lnbsettextright(Value rightGameValue)
{
    GameValueMethods.unary__lnbsettextright__array__ret__nothing(rightGameValue);
}
public static void lnbsettooltip(Value rightGameValue)
{
    GameValueMethods.unary__lnbsettooltip__array__ret__nothing(rightGameValue);
}
public static void lnbsetvalue(Value rightGameValue)
{
    GameValueMethods.unary__lnbsetvalue__array__ret__nothing(rightGameValue);
}
public static Value lnbsize(Value rightGameValue)
{
    return GameValueMethods.unary__lnbsize__control__ret__array(rightGameValue);
}
public static Value lnbsize(Value rightGameValue)
{
    return GameValueMethods.unary__lnbsize__scalar__ret__array(rightGameValue);
}
public static void lnbsort(Value rightGameValue)
{
    GameValueMethods.unary__lnbsort__array__ret__nothing(rightGameValue);
}
public static void lnbsortbyvalue(Value rightGameValue)
{
    GameValueMethods.unary__lnbsortbyvalue__array__ret__nothing(rightGameValue);
}
public static Value lnbtext(Value rightGameValue)
{
    return GameValueMethods.unary__lnbtext__array__ret__string(rightGameValue);
}
public static Value lnbtextright(Value rightGameValue)
{
    return GameValueMethods.unary__lnbtextright__array__ret__string(rightGameValue);
}
public static Value lnbvalue(Value rightGameValue)
{
    return GameValueMethods.unary__lnbvalue__array__ret__scalar(rightGameValue);
}
public static Value load(Value rightGameValue)
{
    return GameValueMethods.unary__load__object__ret__scalar(rightGameValue);
}
public static Value loadabs(Value rightGameValue)
{
    return GameValueMethods.unary__loadabs__object__ret__scalar(rightGameValue);
}
public static Value loadbackpack(Value rightGameValue)
{
    return GameValueMethods.unary__loadbackpack__object__ret__scalar(rightGameValue);
}
public static Value loadconfig(Value rightGameValue)
{
    return GameValueMethods.unary__loadconfig__string__ret__config(rightGameValue);
}
public static void loadcuratorselectionpreset(Value rightGameValue)
{
    GameValueMethods.unary__loadcuratorselectionpreset__scalar__ret__nothing(rightGameValue);
}
public static Value loadfile(Value rightGameValue)
{
    return GameValueMethods.unary__loadfile__string__ret__string(rightGameValue);
}
public static Value loaduniform(Value rightGameValue)
{
    return GameValueMethods.unary__loaduniform__object__ret__scalar(rightGameValue);
}
public static Value loadvest(Value rightGameValue)
{
    return GameValueMethods.unary__loadvest__object__ret__scalar(rightGameValue);
}
public static Value local(Value rightGameValue)
{
    return GameValueMethods.unary__local__object__ret__bool(rightGameValue);
}
public static Value local(Value rightGameValue)
{
    return GameValueMethods.unary__local__group__ret__bool(rightGameValue);
}
public static Value localize(Value rightGameValue)
{
    return GameValueMethods.unary__localize__string__ret__string(rightGameValue);
}
public static Value locationposition(Value rightGameValue)
{
    return GameValueMethods.unary__locationposition__location__ret__array(rightGameValue);
}
public static Value locked(Value rightGameValue)
{
    return GameValueMethods.unary__locked__object__ret__scalar(rightGameValue);
}
public static Value lockeddriver(Value rightGameValue)
{
    return GameValueMethods.unary__lockeddriver__object__ret__bool(rightGameValue);
}
public static Value lockedinventory(Value rightGameValue)
{
    return GameValueMethods.unary__lockedinventory__object__ret__bool(rightGameValue);
}
public static Value lockidentity(Value rightGameValue)
{
    return GameValueMethods.unary__lockidentity__object__ret__bool(rightGameValue);
}
public static Value log(Value rightGameValue)
{
    return GameValueMethods.unary__log__scalar_nan__ret__scalar_nan(rightGameValue);
}
public static Value lognetwork(Value rightGameValue)
{
    return GameValueMethods.unary__lognetwork__array__ret__scalar(rightGameValue);
}
public static void lognetworkterminate(Value rightGameValue)
{
    GameValueMethods.unary__lognetworkterminate__scalar__ret__nothing(rightGameValue);
}
public static Value magazinecargo(Value rightGameValue)
{
    return GameValueMethods.unary__magazinecargo__object__ret__array(rightGameValue);
}
public static Value magazines(Value rightGameValue)
{
    return GameValueMethods.unary__magazines__object_array__ret__array(rightGameValue);
}
public static Value magazinesallturrets(Value rightGameValue)
{
    return GameValueMethods.unary__magazinesallturrets__object_array__ret__array(rightGameValue);
}
public static Value magazinesammo(Value rightGameValue)
{
    return GameValueMethods.unary__magazinesammo__object_array__ret__array(rightGameValue);
}
public static Value magazinesammocargo(Value rightGameValue)
{
    return GameValueMethods.unary__magazinesammocargo__object__ret__array(rightGameValue);
}
public static Value magazinesammofull(Value rightGameValue)
{
    return GameValueMethods.unary__magazinesammofull__object_array__ret__array(rightGameValue);
}
public static Value magazinesdetail(Value rightGameValue)
{
    return GameValueMethods.unary__magazinesdetail__object_array__ret__array(rightGameValue);
}
public static Value magazinesdetailbackpack(Value rightGameValue)
{
    return GameValueMethods.unary__magazinesdetailbackpack__object_array__ret__array(rightGameValue);
}
public static Value magazinesdetailuniform(Value rightGameValue)
{
    return GameValueMethods.unary__magazinesdetailuniform__object_array__ret__array(rightGameValue);
}
public static Value magazinesdetailvest(Value rightGameValue)
{
    return GameValueMethods.unary__magazinesdetailvest__object_array__ret__array(rightGameValue);
}
public static void mapanimadd(Value rightGameValue)
{
    GameValueMethods.unary__mapanimadd__array__ret__nothing(rightGameValue);
}
public static Value mapcenteroncamera(Value rightGameValue)
{
    return GameValueMethods.unary__mapcenteroncamera__control__ret__array(rightGameValue);
}
public static Value mapgridposition(Value rightGameValue)
{
    return GameValueMethods.unary__mapgridposition__object_array__ret__string(rightGameValue);
}
public static Value markeralpha(Value rightGameValue)
{
    return GameValueMethods.unary__markeralpha__string__ret__scalar(rightGameValue);
}
public static Value markerbrush(Value rightGameValue)
{
    return GameValueMethods.unary__markerbrush__string__ret__string(rightGameValue);
}
public static Value markerchannel(Value rightGameValue)
{
    return GameValueMethods.unary__markerchannel__string__ret__string(rightGameValue);
}
public static Value markercolor(Value rightGameValue)
{
    return GameValueMethods.unary__markercolor__string__ret__string(rightGameValue);
}
public static Value markerdir(Value rightGameValue)
{
    return GameValueMethods.unary__markerdir__string__ret__scalar(rightGameValue);
}
public static Value markerdrawpriority(Value rightGameValue)
{
    return GameValueMethods.unary__markerdrawpriority__string__ret__scalar(rightGameValue);
}
public static Value markerpolyline(Value rightGameValue)
{
    return GameValueMethods.unary__markerpolyline__string__ret__array(rightGameValue);
}
public static Value markerpos(Value rightGameValue)
{
    return GameValueMethods.unary__markerpos__string__ret__array(rightGameValue);
}
public static Value markerpos(Value rightGameValue)
{
    return GameValueMethods.unary__markerpos__array__ret__array(rightGameValue);
}
public static Value markershadow(Value rightGameValue)
{
    return GameValueMethods.unary__markershadow__string__ret__bool(rightGameValue);
}
public static Value markershape(Value rightGameValue)
{
    return GameValueMethods.unary__markershape__string__ret__string(rightGameValue);
}
public static Value markersize(Value rightGameValue)
{
    return GameValueMethods.unary__markersize__string__ret__array(rightGameValue);
}
public static Value markertext(Value rightGameValue)
{
    return GameValueMethods.unary__markertext__string__ret__string(rightGameValue);
}
public static Value markertype(Value rightGameValue)
{
    return GameValueMethods.unary__markertype__string__ret__string(rightGameValue);
}
public static Value matrixtranspose(Value rightGameValue)
{
    return GameValueMethods.unary__matrixtranspose__array__ret__array(rightGameValue);
}
public static Value maxload(Value rightGameValue)
{
    return GameValueMethods.unary__maxload__object__ret__scalar(rightGameValue);
}
public static Value members(Value rightGameValue)
{
    return GameValueMethods.unary__members__team_member__ret__array(rightGameValue);
}
public static Value menuaction(Value rightGameValue)
{
    return GameValueMethods.unary__menuaction__array__ret__string(rightGameValue);
}
public static Value menuadd(Value rightGameValue)
{
    return GameValueMethods.unary__menuadd__array__ret__scalar(rightGameValue);
}
public static Value menuchecked(Value rightGameValue)
{
    return GameValueMethods.unary__menuchecked__array__ret__bool(rightGameValue);
}
public static void menuclear(Value rightGameValue)
{
    GameValueMethods.unary__menuclear__control__ret__nothing(rightGameValue);
}
public static void menuclear(Value rightGameValue)
{
    GameValueMethods.unary__menuclear__scalar__ret__nothing(rightGameValue);
}
public static void menucollapse(Value rightGameValue)
{
    GameValueMethods.unary__menucollapse__array__ret__nothing(rightGameValue);
}
public static Value menudata(Value rightGameValue)
{
    return GameValueMethods.unary__menudata__array__ret__string(rightGameValue);
}
public static void menudelete(Value rightGameValue)
{
    GameValueMethods.unary__menudelete__array__ret__nothing(rightGameValue);
}
public static void menuenable(Value rightGameValue)
{
    GameValueMethods.unary__menuenable__array__ret__nothing(rightGameValue);
}
public static Value menuenabled(Value rightGameValue)
{
    return GameValueMethods.unary__menuenabled__array__ret__bool(rightGameValue);
}
public static void menuexpand(Value rightGameValue)
{
    GameValueMethods.unary__menuexpand__array__ret__nothing(rightGameValue);
}
public static Value menuhover(Value rightGameValue)
{
    return GameValueMethods.unary__menuhover__control__ret__array(rightGameValue);
}
public static Value menuhover(Value rightGameValue)
{
    return GameValueMethods.unary__menuhover__scalar__ret__array(rightGameValue);
}
public static Value menupicture(Value rightGameValue)
{
    return GameValueMethods.unary__menupicture__array__ret__string(rightGameValue);
}
public static void menusetaction(Value rightGameValue)
{
    GameValueMethods.unary__menusetaction__array__ret__nothing(rightGameValue);
}
public static void menusetcheck(Value rightGameValue)
{
    GameValueMethods.unary__menusetcheck__array__ret__nothing(rightGameValue);
}
public static void menusetdata(Value rightGameValue)
{
    GameValueMethods.unary__menusetdata__array__ret__nothing(rightGameValue);
}
public static void menusetpicture(Value rightGameValue)
{
    GameValueMethods.unary__menusetpicture__array__ret__nothing(rightGameValue);
}
public static void menusetshortcut(Value rightGameValue)
{
    GameValueMethods.unary__menusetshortcut__array__ret__nothing(rightGameValue);
}
public static void menusettext(Value rightGameValue)
{
    GameValueMethods.unary__menusettext__array__ret__nothing(rightGameValue);
}
public static void menuseturl(Value rightGameValue)
{
    GameValueMethods.unary__menuseturl__array__ret__nothing(rightGameValue);
}
public static void menusetvalue(Value rightGameValue)
{
    GameValueMethods.unary__menusetvalue__array__ret__nothing(rightGameValue);
}
public static Value menushortcut(Value rightGameValue)
{
    return GameValueMethods.unary__menushortcut__array__ret__scalar(rightGameValue);
}
public static Value menushortcuttext(Value rightGameValue)
{
    return GameValueMethods.unary__menushortcuttext__array__ret__string(rightGameValue);
}
public static Value menusize(Value rightGameValue)
{
    return GameValueMethods.unary__menusize__array__ret__scalar(rightGameValue);
}
public static void menusort(Value rightGameValue)
{
    GameValueMethods.unary__menusort__array__ret__nothing(rightGameValue);
}
public static Value menutext(Value rightGameValue)
{
    return GameValueMethods.unary__menutext__array__ret__string(rightGameValue);
}
public static Value menuurl(Value rightGameValue)
{
    return GameValueMethods.unary__menuurl__array__ret__string(rightGameValue);
}
public static Value menuvalue(Value rightGameValue)
{
    return GameValueMethods.unary__menuvalue__array__ret__scalar(rightGameValue);
}
public static Value mineactive(Value rightGameValue)
{
    return GameValueMethods.unary__mineactive__object__ret__bool(rightGameValue);
}
public static Value missiletarget(Value rightGameValue)
{
    return GameValueMethods.unary__missiletarget__object__ret__object(rightGameValue);
}
public static Value missiletargetpos(Value rightGameValue)
{
    return GameValueMethods.unary__missiletargetpos__object__ret__array(rightGameValue);
}
public static Value modparams(Value rightGameValue)
{
    return GameValueMethods.unary__modparams__array__ret__array(rightGameValue);
}
public static Value moonphase(Value rightGameValue)
{
    return GameValueMethods.unary__moonphase__array__ret__scalar(rightGameValue);
}
public static Value morale(Value rightGameValue)
{
    return GameValueMethods.unary__morale__object__ret__scalar(rightGameValue);
}
public static void move3dencamera(Value rightGameValue)
{
    GameValueMethods.unary__move3dencamera__array__ret__nothing(rightGameValue);
}
public static void moveout(Value rightGameValue)
{
    GameValueMethods.unary__moveout__object__ret__nothing(rightGameValue);
}
public static Value movetime(Value rightGameValue)
{
    return GameValueMethods.unary__movetime__object__ret__scalar(rightGameValue);
}
public static Value movetocompleted(Value rightGameValue)
{
    return GameValueMethods.unary__movetocompleted__object__ret__bool(rightGameValue);
}
public static Value movetofailed(Value rightGameValue)
{
    return GameValueMethods.unary__movetofailed__object__ret__bool(rightGameValue);
}
public static Value name(Value rightGameValue)
{
    return GameValueMethods.unary__name__object__ret__string(rightGameValue);
}
public static Value name(Value rightGameValue)
{
    return GameValueMethods.unary__name__location__ret__string(rightGameValue);
}
public static Value namedproperties(Value rightGameValue)
{
    return GameValueMethods.unary__namedproperties__object__ret__array(rightGameValue);
}
public static Value namesound(Value rightGameValue)
{
    return GameValueMethods.unary__namesound__object__ret__string(rightGameValue);
}
public static Value nearestbuilding(Value rightGameValue)
{
    return GameValueMethods.unary__nearestbuilding__object__ret__object(rightGameValue);
}
public static Value nearestbuilding(Value rightGameValue)
{
    return GameValueMethods.unary__nearestbuilding__array__ret__object(rightGameValue);
}
public static Value nearestlocation(Value rightGameValue)
{
    return GameValueMethods.unary__nearestlocation__array__ret__location(rightGameValue);
}
public static Value nearestlocations(Value rightGameValue)
{
    return GameValueMethods.unary__nearestlocations__array__ret__array(rightGameValue);
}
public static Value nearestlocationwithdubbing(Value rightGameValue)
{
    return GameValueMethods.unary__nearestlocationwithdubbing__array__ret__location(rightGameValue);
}
public static Value nearestmines(Value rightGameValue)
{
    return GameValueMethods.unary__nearestmines__array__ret__array(rightGameValue);
}
public static Value nearestobject(Value rightGameValue)
{
    return GameValueMethods.unary__nearestobject__array__ret__object(rightGameValue);
}
public static Value nearestobjects(Value rightGameValue)
{
    return GameValueMethods.unary__nearestobjects__array__ret__array(rightGameValue);
}
public static Value nearestterrainobjects(Value rightGameValue)
{
    return GameValueMethods.unary__nearestterrainobjects__array__ret__array(rightGameValue);
}
public static Value needreload(Value rightGameValue)
{
    return GameValueMethods.unary__needreload__object__ret__scalar(rightGameValue);
}
public static Value needservice(Value rightGameValue)
{
    return GameValueMethods.unary__needservice__object__ret__array(rightGameValue);
}
public static Value netid(Value rightGameValue)
{
    return GameValueMethods.unary__netid__object__ret__string(rightGameValue);
}
public static Value netid(Value rightGameValue)
{
    return GameValueMethods.unary__netid__group__ret__string(rightGameValue);
}
public static Value nextmenuitemindex(Value rightGameValue)
{
    return GameValueMethods.unary__nextmenuitemindex__control__ret__scalar(rightGameValue);
}
public static Value not(Value rightGameValue)
{
    return GameValueMethods.unary__not__bool__ret__bool(rightGameValue);
}
public static Value numberofenginesrtd(Value rightGameValue)
{
    return GameValueMethods.unary__numberofenginesrtd__object__ret__scalar(rightGameValue);
}
public static Value numbertodate(Value rightGameValue)
{
    return GameValueMethods.unary__numbertodate__array__ret__array(rightGameValue);
}
public static Value objectcurators(Value rightGameValue)
{
    return GameValueMethods.unary__objectcurators__object__ret__array(rightGameValue);
}
public static Value objectfromnetid(Value rightGameValue)
{
    return GameValueMethods.unary__objectfromnetid__string__ret__object(rightGameValue);
}
public static Value objectparent(Value rightGameValue)
{
    return GameValueMethods.unary__objectparent__object__ret__object(rightGameValue);
}
public static void onbriefinggroup(Value rightGameValue)
{
    GameValueMethods.unary__onbriefinggroup__string__ret__nothing(rightGameValue);
}
public static void onbriefingnotes(Value rightGameValue)
{
    GameValueMethods.unary__onbriefingnotes__string__ret__nothing(rightGameValue);
}
public static void onbriefingplan(Value rightGameValue)
{
    GameValueMethods.unary__onbriefingplan__string__ret__nothing(rightGameValue);
}
public static void onbriefingteamswitch(Value rightGameValue)
{
    GameValueMethods.unary__onbriefingteamswitch__string__ret__nothing(rightGameValue);
}
public static void oncommandmodechanged(Value rightGameValue)
{
    GameValueMethods.unary__oncommandmodechanged__code_string__ret__nothing(rightGameValue);
}
public static void oneachframe(Value rightGameValue)
{
    GameValueMethods.unary__oneachframe__code_string__ret__nothing(rightGameValue);
}
public static void ongroupiconclick(Value rightGameValue)
{
    GameValueMethods.unary__ongroupiconclick__code_string__ret__nothing(rightGameValue);
}
public static void ongroupiconoverenter(Value rightGameValue)
{
    GameValueMethods.unary__ongroupiconoverenter__code_string__ret__nothing(rightGameValue);
}
public static void ongroupiconoverleave(Value rightGameValue)
{
    GameValueMethods.unary__ongroupiconoverleave__code_string__ret__nothing(rightGameValue);
}
public static void onhcgroupselectionchanged(Value rightGameValue)
{
    GameValueMethods.unary__onhcgroupselectionchanged__code_string__ret__nothing(rightGameValue);
}
public static void onmapsingleclick(Value rightGameValue)
{
    GameValueMethods.unary__onmapsingleclick__code_string__ret__nothing(rightGameValue);
}
public static void onplayerconnected(Value rightGameValue)
{
    GameValueMethods.unary__onplayerconnected__code_string__ret__nothing(rightGameValue);
}
public static void onplayerdisconnected(Value rightGameValue)
{
    GameValueMethods.unary__onplayerdisconnected__code_string__ret__nothing(rightGameValue);
}
public static void onpreloadfinished(Value rightGameValue)
{
    GameValueMethods.unary__onpreloadfinished__code_string__ret__nothing(rightGameValue);
}
public static void onpreloadstarted(Value rightGameValue)
{
    GameValueMethods.unary__onpreloadstarted__code_string__ret__nothing(rightGameValue);
}
public static void onteamswitch(Value rightGameValue)
{
    GameValueMethods.unary__onteamswitch__code_string__ret__nothing(rightGameValue);
}
public static Value opendlcpage(Value rightGameValue)
{
    return GameValueMethods.unary__opendlcpage__scalar__ret__bool(rightGameValue);
}
public static Value opengps(Value rightGameValue)
{
    return GameValueMethods.unary__opengps__bool__ret__bool(rightGameValue);
}
public static Value openmap(Value rightGameValue)
{
    return GameValueMethods.unary__openmap__array__ret__bool(rightGameValue);
}
public static Value openmap(Value rightGameValue)
{
    return GameValueMethods.unary__openmap__bool__ret__bool(rightGameValue);
}
public static Value opensteamapp(Value rightGameValue)
{
    return GameValueMethods.unary__opensteamapp__scalar__ret__bool(rightGameValue);
}
public static Value openyoutubevideo(Value rightGameValue)
{
    return GameValueMethods.unary__openyoutubevideo__string__ret__bool(rightGameValue);
}
public static Value owner(Value rightGameValue)
{
    return GameValueMethods.unary__owner__object__ret__scalar(rightGameValue);
}
public static Value param(Value rightGameValue)
{
    return GameValueMethods.unary__param__array__ret__any(rightGameValue);
}
public static Value params(Value rightGameValue)
{
    return GameValueMethods.unary__params__array__ret__bool(rightGameValue);
}
public static Value parsenumber(Value rightGameValue)
{
    return GameValueMethods.unary__parsenumber__string__ret__scalar(rightGameValue);
}
public static Value parsenumber(Value rightGameValue)
{
    return GameValueMethods.unary__parsenumber__bool__ret__scalar(rightGameValue);
}
public static Value parsesimplearray(Value rightGameValue)
{
    return GameValueMethods.unary__parsesimplearray__string__ret__array(rightGameValue);
}
public static Value parsetext(Value rightGameValue)
{
    return GameValueMethods.unary__parsetext__string__ret__text(rightGameValue);
}
public static void pickweaponpool(Value rightGameValue)
{
    GameValueMethods.unary__pickweaponpool__object__ret__nothing(rightGameValue);
}
public static Value pitch(Value rightGameValue)
{
    return GameValueMethods.unary__pitch__object__ret__string(rightGameValue);
}
public static Value playableslotsnumber(Value rightGameValue)
{
    return GameValueMethods.unary__playableslotsnumber__side__ret__scalar(rightGameValue);
}
public static Value playersnumber(Value rightGameValue)
{
    return GameValueMethods.unary__playersnumber__side__ret__scalar(rightGameValue);
}
public static void playmission(Value rightGameValue)
{
    GameValueMethods.unary__playmission__array__ret__nothing(rightGameValue);
}
public static void playmusic(Value rightGameValue)
{
    GameValueMethods.unary__playmusic__string__ret__nothing(rightGameValue);
}
public static void playmusic(Value rightGameValue)
{
    GameValueMethods.unary__playmusic__array__ret__nothing(rightGameValue);
}
public static void playscriptedmission(Value rightGameValue)
{
    GameValueMethods.unary__playscriptedmission__array__ret__nothing(rightGameValue);
}
public static Value playsound(Value rightGameValue)
{
    return GameValueMethods.unary__playsound__string__ret__object(rightGameValue);
}
public static Value playsound(Value rightGameValue)
{
    return GameValueMethods.unary__playsound__array__ret__object(rightGameValue);
}
public static Value playsound3d(Value rightGameValue)
{
    return GameValueMethods.unary__playsound3d__array__ret__scalar(rightGameValue);
}
public static Value playsoundui(Value rightGameValue)
{
    return GameValueMethods.unary__playsoundui__array__ret__scalar(rightGameValue);
}
public static Value pose(Value rightGameValue)
{
    return GameValueMethods.unary__pose__object__ret__string(rightGameValue);
}
public static Value position(Value rightGameValue)
{
    return GameValueMethods.unary__position__object__ret__array(rightGameValue);
}
public static Value position(Value rightGameValue)
{
    return GameValueMethods.unary__position__location__ret__array(rightGameValue);
}
public static Value positioncameratoworld(Value rightGameValue)
{
    return GameValueMethods.unary__positioncameratoworld__array__ret__array(rightGameValue);
}
public static Value ppeffectcommitted(Value rightGameValue)
{
    return GameValueMethods.unary__ppeffectcommitted__string__ret__bool(rightGameValue);
}
public static Value ppeffectcommitted(Value rightGameValue)
{
    return GameValueMethods.unary__ppeffectcommitted__scalar__ret__bool(rightGameValue);
}
public static Value ppeffectcreate(Value rightGameValue)
{
    return GameValueMethods.unary__ppeffectcreate__array__ret__scalar_array(rightGameValue);
}
public static void ppeffectdestroy(Value rightGameValue)
{
    GameValueMethods.unary__ppeffectdestroy__scalar__ret__nothing(rightGameValue);
}
public static void ppeffectdestroy(Value rightGameValue)
{
    GameValueMethods.unary__ppeffectdestroy__array__ret__nothing(rightGameValue);
}
public static Value ppeffectenabled(Value rightGameValue)
{
    return GameValueMethods.unary__ppeffectenabled__scalar__ret__bool(rightGameValue);
}
public static Value ppeffectenabled(Value rightGameValue)
{
    return GameValueMethods.unary__ppeffectenabled__string__ret__bool(rightGameValue);
}
public static Value precision(Value rightGameValue)
{
    return GameValueMethods.unary__precision__object__ret__scalar(rightGameValue);
}
public static Value preloadcamera(Value rightGameValue)
{
    return GameValueMethods.unary__preloadcamera__array__ret__bool(rightGameValue);
}
public static Value preloadsound(Value rightGameValue)
{
    return GameValueMethods.unary__preloadsound__string__ret__bool(rightGameValue);
}
public static Value preloadtitleobj(Value rightGameValue)
{
    return GameValueMethods.unary__preloadtitleobj__array__ret__bool(rightGameValue);
}
public static Value preloadtitlersc(Value rightGameValue)
{
    return GameValueMethods.unary__preloadtitlersc__array__ret__bool(rightGameValue);
}
public static Value preprocessfile(Value rightGameValue)
{
    return GameValueMethods.unary__preprocessfile__string__ret__string(rightGameValue);
}
public static Value preprocessfilelinenumbers(Value rightGameValue)
{
    return GameValueMethods.unary__preprocessfilelinenumbers__string__ret__string(rightGameValue);
}
public static Value primaryweapon(Value rightGameValue)
{
    return GameValueMethods.unary__primaryweapon__object__ret__string(rightGameValue);
}
public static Value primaryweaponitems(Value rightGameValue)
{
    return GameValueMethods.unary__primaryweaponitems__object__ret__array(rightGameValue);
}
public static Value primaryweaponmagazine(Value rightGameValue)
{
    return GameValueMethods.unary__primaryweaponmagazine__object__ret__array(rightGameValue);
}
public static Value priority(Value rightGameValue)
{
    return GameValueMethods.unary__priority__task__ret__scalar(rightGameValue);
}
public static void private (Value rightGameValue)
{
    GameValueMethods.unary__private__string_array__ret__nothing(rightGameValue);
}
public static void processdiarylink(Value rightGameValue)
{
    GameValueMethods.unary__processdiarylink__string__ret__nothing(rightGameValue);
}
public static void progressloadingscreen(Value rightGameValue)
{
    GameValueMethods.unary__progressloadingscreen__scalar__ret__nothing(rightGameValue);
}
public static Value progressposition(Value rightGameValue)
{
    return GameValueMethods.unary__progressposition__control__ret__scalar(rightGameValue);
}
public static void publicvariable(Value rightGameValue)
{
    GameValueMethods.unary__publicvariable__string__ret__nothing(rightGameValue);
}
public static void publicvariableserver(Value rightGameValue)
{
    GameValueMethods.unary__publicvariableserver__string__ret__nothing(rightGameValue);
}
public static void putweaponpool(Value rightGameValue)
{
    GameValueMethods.unary__putweaponpool__object__ret__nothing(rightGameValue);
}
public static Value queryitemspool(Value rightGameValue)
{
    return GameValueMethods.unary__queryitemspool__string__ret__scalar(rightGameValue);
}
public static Value querymagazinepool(Value rightGameValue)
{
    return GameValueMethods.unary__querymagazinepool__string__ret__scalar(rightGameValue);
}
public static Value queryweaponpool(Value rightGameValue)
{
    return GameValueMethods.unary__queryweaponpool__string__ret__scalar(rightGameValue);
}
public static Value rad(Value rightGameValue)
{
    return GameValueMethods.unary__rad__scalar_nan__ret__scalar_nan(rightGameValue);
}
public static Value radiochannelcreate(Value rightGameValue)
{
    return GameValueMethods.unary__radiochannelcreate__array__ret__scalar(rightGameValue);
}
public static Value radiochannelinfo(Value rightGameValue)
{
    return GameValueMethods.unary__radiochannelinfo__scalar__ret__array(rightGameValue);
}
public static Value random(Value rightGameValue)
{
    return GameValueMethods.unary__random__array__ret__scalar_nan(rightGameValue);
}
public static Value random(Value rightGameValue)
{
    return GameValueMethods.unary__random__scalar_nan__ret__scalar_nan(rightGameValue);
}
public static Value rank(Value rightGameValue)
{
    return GameValueMethods.unary__rank__object__ret__string(rightGameValue);
}
public static Value rankid(Value rightGameValue)
{
    return GameValueMethods.unary__rankid__object__ret__scalar(rightGameValue);
}
public static Value rating(Value rightGameValue)
{
    return GameValueMethods.unary__rating__object__ret__scalar(rightGameValue);
}
public static Value rectangular(Value rightGameValue)
{
    return GameValueMethods.unary__rectangular__location__ret__bool(rightGameValue);
}
public static Value registeredtasks(Value rightGameValue)
{
    return GameValueMethods.unary__registeredtasks__team_member__ret__array(rightGameValue);
}
public static void reload(Value rightGameValue)
{
    GameValueMethods.unary__reload__object__ret__nothing(rightGameValue);
}
public static Value reloadenabled(Value rightGameValue)
{
    return GameValueMethods.unary__reloadenabled__object__ret__bool(rightGameValue);
}
public static Value remotecontrolled(Value rightGameValue)
{
    return GameValueMethods.unary__remotecontrolled__object__ret__object(rightGameValue);
}
public static Value remoteexec(Value rightGameValue)
{
    return GameValueMethods.unary__remoteexec__array__ret__string_nothing(rightGameValue);
}
public static Value remoteexeccall(Value rightGameValue)
{
    return GameValueMethods.unary__remoteexeccall__array__ret__string_nothing(rightGameValue);
}
public static void remove3denconnection(Value rightGameValue)
{
    GameValueMethods.unary__remove3denconnection__array__ret__nothing(rightGameValue);
}
public static void remove3deneventhandler(Value rightGameValue)
{
    GameValueMethods.unary__remove3deneventhandler__array__ret__nothing(rightGameValue);
}
public static Value remove3denlayer(Value rightGameValue)
{
    return GameValueMethods.unary__remove3denlayer__scalar__ret__bool(rightGameValue);
}
public static void removeall3deneventhandlers(Value rightGameValue)
{
    GameValueMethods.unary__removeall3deneventhandlers__string__ret__nothing(rightGameValue);
}
public static void removeallactions(Value rightGameValue)
{
    GameValueMethods.unary__removeallactions__object__ret__nothing(rightGameValue);
}
public static void removeallassigneditems(Value rightGameValue)
{
    GameValueMethods.unary__removeallassigneditems__object_array__ret__nothing(rightGameValue);
}
public static void removeallbinocularitems(Value rightGameValue)
{
    GameValueMethods.unary__removeallbinocularitems__object__ret__nothing(rightGameValue);
}
public static void removeallcontainers(Value rightGameValue)
{
    GameValueMethods.unary__removeallcontainers__object__ret__nothing(rightGameValue);
}
public static void removeallcuratoraddons(Value rightGameValue)
{
    GameValueMethods.unary__removeallcuratoraddons__object__ret__nothing(rightGameValue);
}
public static void removeallcuratorcameraareas(Value rightGameValue)
{
    GameValueMethods.unary__removeallcuratorcameraareas__object__ret__nothing(rightGameValue);
}
public static void removeallcuratoreditingareas(Value rightGameValue)
{
    GameValueMethods.unary__removeallcuratoreditingareas__object__ret__nothing(rightGameValue);
}
public static void removeallhandgunitems(Value rightGameValue)
{
    GameValueMethods.unary__removeallhandgunitems__object__ret__nothing(rightGameValue);
}
public static void removeallitems(Value rightGameValue)
{
    GameValueMethods.unary__removeallitems__object__ret__nothing(rightGameValue);
}
public static void removeallitemswithmagazines(Value rightGameValue)
{
    GameValueMethods.unary__removeallitemswithmagazines__object__ret__nothing(rightGameValue);
}
public static void removeallmissioneventhandlers(Value rightGameValue)
{
    GameValueMethods.unary__removeallmissioneventhandlers__string__ret__nothing(rightGameValue);
}
public static void removeallmusiceventhandlers(Value rightGameValue)
{
    GameValueMethods.unary__removeallmusiceventhandlers__string__ret__nothing(rightGameValue);
}
public static void removeallownedmines(Value rightGameValue)
{
    GameValueMethods.unary__removeallownedmines__object__ret__nothing(rightGameValue);
}
public static void removeallprimaryweaponitems(Value rightGameValue)
{
    GameValueMethods.unary__removeallprimaryweaponitems__object__ret__nothing(rightGameValue);
}
public static void removeallsecondaryweaponitems(Value rightGameValue)
{
    GameValueMethods.unary__removeallsecondaryweaponitems__object__ret__nothing(rightGameValue);
}
public static void removealluseractioneventhandlers(Value rightGameValue)
{
    GameValueMethods.unary__removealluseractioneventhandlers__array__ret__nothing(rightGameValue);
}
public static void removeallweapons(Value rightGameValue)
{
    GameValueMethods.unary__removeallweapons__object__ret__nothing(rightGameValue);
}
public static void removebackpack(Value rightGameValue)
{
    GameValueMethods.unary__removebackpack__object__ret__nothing(rightGameValue);
}
public static void removebackpackglobal(Value rightGameValue)
{
    GameValueMethods.unary__removebackpackglobal__object__ret__nothing(rightGameValue);
}
public static void removefromremainscollector(Value rightGameValue)
{
    GameValueMethods.unary__removefromremainscollector__array__ret__nothing(rightGameValue);
}
public static void removegoggles(Value rightGameValue)
{
    GameValueMethods.unary__removegoggles__object__ret__nothing(rightGameValue);
}
public static void removeheadgear(Value rightGameValue)
{
    GameValueMethods.unary__removeheadgear__object__ret__nothing(rightGameValue);
}
public static void removemissioneventhandler(Value rightGameValue)
{
    GameValueMethods.unary__removemissioneventhandler__array__ret__nothing(rightGameValue);
}
public static void removemusiceventhandler(Value rightGameValue)
{
    GameValueMethods.unary__removemusiceventhandler__array__ret__nothing(rightGameValue);
}
public static void removeswitchableunit(Value rightGameValue)
{
    GameValueMethods.unary__removeswitchableunit__object__ret__nothing(rightGameValue);
}
public static void removeuniform(Value rightGameValue)
{
    GameValueMethods.unary__removeuniform__object__ret__nothing(rightGameValue);
}
public static void removeuseractioneventhandler(Value rightGameValue)
{
    GameValueMethods.unary__removeuseractioneventhandler__array__ret__nothing(rightGameValue);
}
public static void removevest(Value rightGameValue)
{
    GameValueMethods.unary__removevest__object__ret__nothing(rightGameValue);
}
public static Value requiredversion(Value rightGameValue)
{
    return GameValueMethods.unary__requiredversion__string__ret__bool(rightGameValue);
}
public static void resetsubgroupdirection(Value rightGameValue)
{
    GameValueMethods.unary__resetsubgroupdirection__object__ret__nothing(rightGameValue);
}
public static Value resources(Value rightGameValue)
{
    return GameValueMethods.unary__resources__team_member__ret__array(rightGameValue);
}
public static void restarteditorcamera(Value rightGameValue)
{
    GameValueMethods.unary__restarteditorcamera__control__ret__nothing(rightGameValue);
}
public static void reverse(Value rightGameValue)
{
    GameValueMethods.unary__reverse__array__ret__nothing(rightGameValue);
}
public static Value reverse(Value rightGameValue)
{
    return GameValueMethods.unary__reverse__string__ret__string(rightGameValue);
}
public static Value roadat(Value rightGameValue)
{
    return GameValueMethods.unary__roadat__object_array__ret__object(rightGameValue);
}
public static Value roadsconnectedto(Value rightGameValue)
{
    return GameValueMethods.unary__roadsconnectedto__object_array__ret__array(rightGameValue);
}
public static Value roledescription(Value rightGameValue)
{
    return GameValueMethods.unary__roledescription__object__ret__string(rightGameValue);
}
public static Value ropeattachedobjects(Value rightGameValue)
{
    return GameValueMethods.unary__ropeattachedobjects__object__ret__array(rightGameValue);
}
public static Value ropeattachedto(Value rightGameValue)
{
    return GameValueMethods.unary__ropeattachedto__object__ret__object(rightGameValue);
}
public static Value ropeattachenabled(Value rightGameValue)
{
    return GameValueMethods.unary__ropeattachenabled__object__ret__bool(rightGameValue);
}
public static Value ropecreate(Value rightGameValue)
{
    return GameValueMethods.unary__ropecreate__array__ret__object(rightGameValue);
}
public static void ropecut(Value rightGameValue)
{
    GameValueMethods.unary__ropecut__array__ret__nothing(rightGameValue);
}
public static void ropedestroy(Value rightGameValue)
{
    GameValueMethods.unary__ropedestroy__object__ret__nothing(rightGameValue);
}
public static Value ropeendposition(Value rightGameValue)
{
    return GameValueMethods.unary__ropeendposition__object__ret__array(rightGameValue);
}
public static Value ropelength(Value rightGameValue)
{
    return GameValueMethods.unary__ropelength__object__ret__scalar(rightGameValue);
}
public static Value ropes(Value rightGameValue)
{
    return GameValueMethods.unary__ropes__object__ret__array(rightGameValue);
}
public static Value ropesattachedto(Value rightGameValue)
{
    return GameValueMethods.unary__ropesattachedto__object__ret__array(rightGameValue);
}
public static Value ropesegments(Value rightGameValue)
{
    return GameValueMethods.unary__ropesegments__object__ret__array(rightGameValue);
}
public static void ropeunwind(Value rightGameValue)
{
    GameValueMethods.unary__ropeunwind__array__ret__nothing(rightGameValue);
}
public static Value ropeunwound(Value rightGameValue)
{
    return GameValueMethods.unary__ropeunwound__object__ret__bool(rightGameValue);
}
public static Value rotorsforcesrtd(Value rightGameValue)
{
    return GameValueMethods.unary__rotorsforcesrtd__object__ret__array(rightGameValue);
}
public static Value rotorsrpmrtd(Value rightGameValue)
{
    return GameValueMethods.unary__rotorsrpmrtd__object__ret__array(rightGameValue);
}
public static Value round(Value rightGameValue)
{
    return GameValueMethods.unary__round__scalar_nan__ret__scalar_nan(rightGameValue);
}
public static void save3deninventory(Value rightGameValue)
{
    GameValueMethods.unary__save3deninventory__array__ret__nothing(rightGameValue);
}
public static void saveoverlay(Value rightGameValue)
{
    GameValueMethods.unary__saveoverlay__control__ret__nothing(rightGameValue);
}
public static void savevar(Value rightGameValue)
{
    GameValueMethods.unary__savevar__string__ret__nothing(rightGameValue);
}
public static void scopename(Value rightGameValue)
{
    GameValueMethods.unary__scopename__string__ret__nothing(rightGameValue);
}
public static Value score(Value rightGameValue)
{
    return GameValueMethods.unary__score__object__ret__scalar(rightGameValue);
}
public static Value scoreside(Value rightGameValue)
{
    return GameValueMethods.unary__scoreside__side__ret__scalar(rightGameValue);
}
public static Value screenshot(Value rightGameValue)
{
    return GameValueMethods.unary__screenshot__string__ret__bool(rightGameValue);
}
public static Value screentoworld(Value rightGameValue)
{
    return GameValueMethods.unary__screentoworld__array__ret__array(rightGameValue);
}
public static Value scriptdone(Value rightGameValue)
{
    return GameValueMethods.unary__scriptdone__script__ret__bool(rightGameValue);
}
public static void scriptname(Value rightGameValue)
{
    GameValueMethods.unary__scriptname__string__ret__nothing(rightGameValue);
}
public static Value scudstate(Value rightGameValue)
{
    return GameValueMethods.unary__scudstate__object__ret__scalar(rightGameValue);
}
public static Value secondaryweapon(Value rightGameValue)
{
    return GameValueMethods.unary__secondaryweapon__object__ret__string(rightGameValue);
}
public static Value secondaryweaponitems(Value rightGameValue)
{
    return GameValueMethods.unary__secondaryweaponitems__object__ret__array(rightGameValue);
}
public static Value secondaryweaponmagazine(Value rightGameValue)
{
    return GameValueMethods.unary__secondaryweaponmagazine__object__ret__array(rightGameValue);
}
public static Value selectbestplaces(Value rightGameValue)
{
    return GameValueMethods.unary__selectbestplaces__array__ret__array(rightGameValue);
}
public static void selectededitorobjects(Value rightGameValue)
{
    GameValueMethods.unary__selectededitorobjects__control__ret__nothing(rightGameValue);
}
public static Value selectionnames(Value rightGameValue)
{
    return GameValueMethods.unary__selectionnames__object__ret__array(rightGameValue);
}
public static Value selectionposition(Value rightGameValue)
{
    return GameValueMethods.unary__selectionposition__array__ret__array(rightGameValue);
}
public static Value selectmax(Value rightGameValue)
{
    return GameValueMethods.unary__selectmax__array__ret__any(rightGameValue);
}
public static Value selectmin(Value rightGameValue)
{
    return GameValueMethods.unary__selectmin__array__ret__any(rightGameValue);
}
public static void selectplayer(Value rightGameValue)
{
    GameValueMethods.unary__selectplayer__object__ret__nothing(rightGameValue);
}
public static Value selectrandom(Value rightGameValue)
{
    return GameValueMethods.unary__selectrandom__array__ret__any(rightGameValue);
}
public static Value selectrandomweighted(Value rightGameValue)
{
    return GameValueMethods.unary__selectrandomweighted__array__ret__any(rightGameValue);
}
public static void sendaumessage(Value rightGameValue)
{
    GameValueMethods.unary__sendaumessage__array__ret__nothing(rightGameValue);
}
public static Value sendudpmessage(Value rightGameValue)
{
    return GameValueMethods.unary__sendudpmessage__array__ret__bool(rightGameValue);
}
public static Value servercommand(Value rightGameValue)
{
    return GameValueMethods.unary__servercommand__string__ret__bool(rightGameValue);
}
public static Value servercommandavailable(Value rightGameValue)
{
    return GameValueMethods.unary__servercommandavailable__string__ret__bool(rightGameValue);
}
public static Value servercommandexecutable(Value rightGameValue)
{
    return GameValueMethods.unary__servercommandexecutable__string__ret__bool(rightGameValue);
}
public static Value set3denattributes(Value rightGameValue)
{
    return GameValueMethods.unary__set3denattributes__array__ret__bool(rightGameValue);
}
public static void set3dengrid(Value rightGameValue)
{
    GameValueMethods.unary__set3dengrid__array__ret__nothing(rightGameValue);
}
public static void set3deniconsvisible(Value rightGameValue)
{
    GameValueMethods.unary__set3deniconsvisible__array__ret__nothing(rightGameValue);
}
public static void set3denlinesvisible(Value rightGameValue)
{
    GameValueMethods.unary__set3denlinesvisible__array__ret__nothing(rightGameValue);
}
public static void set3denmissionattributes(Value rightGameValue)
{
    GameValueMethods.unary__set3denmissionattributes__array__ret__nothing(rightGameValue);
}
public static void set3denmodelsvisible(Value rightGameValue)
{
    GameValueMethods.unary__set3denmodelsvisible__array__ret__nothing(rightGameValue);
}
public static void set3denselected(Value rightGameValue)
{
    GameValueMethods.unary__set3denselected__array__ret__nothing(rightGameValue);
}
public static void setacctime(Value rightGameValue)
{
    GameValueMethods.unary__setacctime__scalar__ret__nothing(rightGameValue);
}
public static void setaperture(Value rightGameValue)
{
    GameValueMethods.unary__setaperture__scalar__ret__nothing(rightGameValue);
}
public static void setaperturenew(Value rightGameValue)
{
    GameValueMethods.unary__setaperturenew__array__ret__nothing(rightGameValue);
}
public static void setarmorypoints(Value rightGameValue)
{
    GameValueMethods.unary__setarmorypoints__scalar__ret__nothing(rightGameValue);
}
public static void setcamshakedefparams(Value rightGameValue)
{
    GameValueMethods.unary__setcamshakedefparams__array__ret__nothing(rightGameValue);
}
public static void setcamshakeparams(Value rightGameValue)
{
    GameValueMethods.unary__setcamshakeparams__array__ret__nothing(rightGameValue);
}
public static void setcompassoscillation(Value rightGameValue)
{
    GameValueMethods.unary__setcompassoscillation__array__ret__nothing(rightGameValue);
}
public static void setcuratorselected(Value rightGameValue)
{
    GameValueMethods.unary__setcuratorselected__array__ret__nothing(rightGameValue);
}
public static Value setcurrentchannel(Value rightGameValue)
{
    return GameValueMethods.unary__setcurrentchannel__scalar__ret__bool(rightGameValue);
}
public static void setcustommissiondata(Value rightGameValue)
{
    GameValueMethods.unary__setcustommissiondata__array__ret__nothing(rightGameValue);
}
public static Value setcustomsoundcontroller(Value rightGameValue)
{
    return GameValueMethods.unary__setcustomsoundcontroller__array__ret__bool(rightGameValue);
}
public static void setdate(Value rightGameValue)
{
    GameValueMethods.unary__setdate__array__ret__nothing(rightGameValue);
}
public static void setdefaultcamera(Value rightGameValue)
{
    GameValueMethods.unary__setdefaultcamera__array__ret__nothing(rightGameValue);
}
public static void setdetailmapblendpars(Value rightGameValue)
{
    GameValueMethods.unary__setdetailmapblendpars__array__ret__nothing(rightGameValue);
}
public static void setgroupiconsselectable(Value rightGameValue)
{
    GameValueMethods.unary__setgroupiconsselectable__bool__ret__nothing(rightGameValue);
}
public static void setgroupiconsvisible(Value rightGameValue)
{
    GameValueMethods.unary__setgroupiconsvisible__array__ret__nothing(rightGameValue);
}
public static void sethorizonparallaxcoef(Value rightGameValue)
{
    GameValueMethods.unary__sethorizonparallaxcoef__scalar__ret__nothing(rightGameValue);
}
public static void sethudmovementlevels(Value rightGameValue)
{
    GameValueMethods.unary__sethudmovementlevels__array__ret__nothing(rightGameValue);
}
public static void sethumidity(Value rightGameValue)
{
    GameValueMethods.unary__sethumidity__scalar__ret__nothing(rightGameValue);
}
public static Value setinfopanel(Value rightGameValue)
{
    return GameValueMethods.unary__setinfopanel__array__ret__bool(rightGameValue);
}
public static void setlocalwindparams(Value rightGameValue)
{
    GameValueMethods.unary__setlocalwindparams__array__ret__nothing(rightGameValue);
}
public static void setmouseposition(Value rightGameValue)
{
    GameValueMethods.unary__setmouseposition__array__ret__nothing(rightGameValue);
}
public static void setmusiceventhandler(Value rightGameValue)
{
    GameValueMethods.unary__setmusiceventhandler__array__ret__nothing(rightGameValue);
}
public static void setobjectviewdistance(Value rightGameValue)
{
    GameValueMethods.unary__setobjectviewdistance__scalar__ret__nothing(rightGameValue);
}
public static void setobjectviewdistance(Value rightGameValue)
{
    GameValueMethods.unary__setobjectviewdistance__array__ret__nothing(rightGameValue);
}
public static void setpipviewdistance(Value rightGameValue)
{
    GameValueMethods.unary__setpipviewdistance__scalar__ret__nothing(rightGameValue);
}
public static void setplayable(Value rightGameValue)
{
    GameValueMethods.unary__setplayable__object__ret__nothing(rightGameValue);
}
public static void setplayerrespawntime(Value rightGameValue)
{
    GameValueMethods.unary__setplayerrespawntime__scalar__ret__nothing(rightGameValue);
}
public static void setrain(Value rightGameValue)
{
    GameValueMethods.unary__setrain__array__ret__nothing(rightGameValue);
}
public static void setrain(Value rightGameValue)
{
    GameValueMethods.unary__setrain__config__ret__nothing(rightGameValue);
}
public static void setshadowdistance(Value rightGameValue)
{
    GameValueMethods.unary__setshadowdistance__scalar__ret__nothing(rightGameValue);
}
public static void setsimulweatherlayers(Value rightGameValue)
{
    GameValueMethods.unary__setsimulweatherlayers__scalar__ret__nothing(rightGameValue);
}
public static void setstaminascheme(Value rightGameValue)
{
    GameValueMethods.unary__setstaminascheme__string__ret__nothing(rightGameValue);
}
public static Value setstatvalue(Value rightGameValue)
{
    return GameValueMethods.unary__setstatvalue__array__ret__bool(rightGameValue);
}
public static void setsystemofunits(Value rightGameValue)
{
    GameValueMethods.unary__setsystemofunits__scalar__ret__nothing(rightGameValue);
}
public static void setterraingrid(Value rightGameValue)
{
    GameValueMethods.unary__setterraingrid__scalar__ret__nothing(rightGameValue);
}
public static void setterrainheight(Value rightGameValue)
{
    GameValueMethods.unary__setterrainheight__array__ret__nothing(rightGameValue);
}
public static void settimemultiplier(Value rightGameValue)
{
    GameValueMethods.unary__settimemultiplier__scalar__ret__nothing(rightGameValue);
}
public static void settiparameter(Value rightGameValue)
{
    GameValueMethods.unary__settiparameter__array__ret__nothing(rightGameValue);
}
public static void settrafficdensity(Value rightGameValue)
{
    GameValueMethods.unary__settrafficdensity__array__ret__nothing(rightGameValue);
}
public static void settrafficdistance(Value rightGameValue)
{
    GameValueMethods.unary__settrafficdistance__scalar__ret__nothing(rightGameValue);
}
public static void settrafficgap(Value rightGameValue)
{
    GameValueMethods.unary__settrafficgap__array__ret__nothing(rightGameValue);
}
public static void settrafficspeed(Value rightGameValue)
{
    GameValueMethods.unary__settrafficspeed__array__ret__nothing(rightGameValue);
}
public static void setviewdistance(Value rightGameValue)
{
    GameValueMethods.unary__setviewdistance__scalar__ret__nothing(rightGameValue);
}
public static void setwind(Value rightGameValue)
{
    GameValueMethods.unary__setwind__array__ret__nothing(rightGameValue);
}
public static void setwinddir(Value rightGameValue)
{
    GameValueMethods.unary__setwinddir__array__ret__nothing(rightGameValue);
}
public static void showchat(Value rightGameValue)
{
    GameValueMethods.unary__showchat__bool__ret__nothing(rightGameValue);
}
public static void showcinemaborder(Value rightGameValue)
{
    GameValueMethods.unary__showcinemaborder__bool__ret__nothing(rightGameValue);
}
public static void showcommandingmenu(Value rightGameValue)
{
    GameValueMethods.unary__showcommandingmenu__string__ret__nothing(rightGameValue);
}
public static void showcompass(Value rightGameValue)
{
    GameValueMethods.unary__showcompass__bool__ret__nothing(rightGameValue);
}
public static void showcuratorcompass(Value rightGameValue)
{
    GameValueMethods.unary__showcuratorcompass__bool__ret__nothing(rightGameValue);
}
public static void showgps(Value rightGameValue)
{
    GameValueMethods.unary__showgps__bool__ret__nothing(rightGameValue);
}
public static void showhud(Value rightGameValue)
{
    GameValueMethods.unary__showhud__bool__ret__nothing(rightGameValue);
}
public static void showhud(Value rightGameValue)
{
    GameValueMethods.unary__showhud__array__ret__nothing(rightGameValue);
}
public static void showmap(Value rightGameValue)
{
    GameValueMethods.unary__showmap__bool__ret__nothing(rightGameValue);
}
public static void showpad(Value rightGameValue)
{
    GameValueMethods.unary__showpad__bool__ret__nothing(rightGameValue);
}
public static void showradio(Value rightGameValue)
{
    GameValueMethods.unary__showradio__bool__ret__nothing(rightGameValue);
}
public static void showscoretable(Value rightGameValue)
{
    GameValueMethods.unary__showscoretable__scalar__ret__nothing(rightGameValue);
}
public static Value showsubtitles(Value rightGameValue)
{
    return GameValueMethods.unary__showsubtitles__bool__ret__bool(rightGameValue);
}
public static void showuavfeed(Value rightGameValue)
{
    GameValueMethods.unary__showuavfeed__bool__ret__nothing(rightGameValue);
}
public static void showwarrant(Value rightGameValue)
{
    GameValueMethods.unary__showwarrant__bool__ret__nothing(rightGameValue);
}
public static void showwatch(Value rightGameValue)
{
    GameValueMethods.unary__showwatch__bool__ret__nothing(rightGameValue);
}
public static void showwaypoints(Value rightGameValue)
{
    GameValueMethods.unary__showwaypoints__bool__ret__nothing(rightGameValue);
}
public static Value side(Value rightGameValue)
{
    return GameValueMethods.unary__side__object__ret__side(rightGameValue);
}
public static Value side(Value rightGameValue)
{
    return GameValueMethods.unary__side__group__ret__side(rightGameValue);
}
public static Value side(Value rightGameValue)
{
    return GameValueMethods.unary__side__location__ret__side(rightGameValue);
}
public static Value simpletasks(Value rightGameValue)
{
    return GameValueMethods.unary__simpletasks__object__ret__array(rightGameValue);
}
public static Value simulationenabled(Value rightGameValue)
{
    return GameValueMethods.unary__simulationenabled__object__ret__bool(rightGameValue);
}
public static Value simulclouddensity(Value rightGameValue)
{
    return GameValueMethods.unary__simulclouddensity__array__ret__scalar(rightGameValue);
}
public static Value simulcloudocclusion(Value rightGameValue)
{
    return GameValueMethods.unary__simulcloudocclusion__array__ret__scalar(rightGameValue);
}
public static Value simulinclouds(Value rightGameValue)
{
    return GameValueMethods.unary__simulinclouds__array__ret__bool(rightGameValue);
}
public static Value sin(Value rightGameValue)
{
    return GameValueMethods.unary__sin__scalar_nan__ret__scalar_nan(rightGameValue);
}
public static Value size(Value rightGameValue)
{
    return GameValueMethods.unary__size__location__ret__array(rightGameValue);
}
public static Value sizeof(Value rightGameValue)
{
    return GameValueMethods.unary__sizeof__string__ret__scalar(rightGameValue);
}
public static Value skill(Value rightGameValue)
{
    return GameValueMethods.unary__skill__object__ret__scalar(rightGameValue);
}
public static void skiptime(Value rightGameValue)
{
    GameValueMethods.unary__skiptime__scalar__ret__nothing(rightGameValue);
}
public static void sleep(Value rightGameValue)
{
    GameValueMethods.unary__sleep__scalar__ret__nothing(rightGameValue);
}
public static Value sliderposition(Value rightGameValue)
{
    return GameValueMethods.unary__sliderposition__control__ret__scalar(rightGameValue);
}
public static Value sliderposition(Value rightGameValue)
{
    return GameValueMethods.unary__sliderposition__scalar__ret__scalar(rightGameValue);
}
public static Value sliderrange(Value rightGameValue)
{
    return GameValueMethods.unary__sliderrange__control__ret__array(rightGameValue);
}
public static Value sliderrange(Value rightGameValue)
{
    return GameValueMethods.unary__sliderrange__scalar__ret__array(rightGameValue);
}
public static void slidersetposition(Value rightGameValue)
{
    GameValueMethods.unary__slidersetposition__array__ret__nothing(rightGameValue);
}
public static void slidersetrange(Value rightGameValue)
{
    GameValueMethods.unary__slidersetrange__array__ret__nothing(rightGameValue);
}
public static void slidersetspeed(Value rightGameValue)
{
    GameValueMethods.unary__slidersetspeed__array__ret__nothing(rightGameValue);
}
public static Value sliderspeed(Value rightGameValue)
{
    return GameValueMethods.unary__sliderspeed__control__ret__array(rightGameValue);
}
public static Value sliderspeed(Value rightGameValue)
{
    return GameValueMethods.unary__sliderspeed__scalar__ret__array(rightGameValue);
}
public static Value soldiermagazines(Value rightGameValue)
{
    return GameValueMethods.unary__soldiermagazines__object__ret__array(rightGameValue);
}
public static Value someammo(Value rightGameValue)
{
    return GameValueMethods.unary__someammo__object__ret__bool(rightGameValue);
}
public static Value soundparams(Value rightGameValue)
{
    return GameValueMethods.unary__soundparams__scalar__ret__array(rightGameValue);
}
public static Value speaker(Value rightGameValue)
{
    return GameValueMethods.unary__speaker__object__ret__string(rightGameValue);
}
public static Value speed(Value rightGameValue)
{
    return GameValueMethods.unary__speed__object__ret__scalar(rightGameValue);
}
public static Value speedmode(Value rightGameValue)
{
    return GameValueMethods.unary__speedmode__object_group__ret__string(rightGameValue);
}
public static Value sqrt(Value rightGameValue)
{
    return GameValueMethods.unary__sqrt__scalar_nan__ret__scalar_nan(rightGameValue);
}
public static Value squadparams(Value rightGameValue)
{
    return GameValueMethods.unary__squadparams__object__ret__array(rightGameValue);
}
public static Value stance(Value rightGameValue)
{
    return GameValueMethods.unary__stance__object__ret__string(rightGameValue);
}
public static void startloadingscreen(Value rightGameValue)
{
    GameValueMethods.unary__startloadingscreen__array__ret__nothing(rightGameValue);
}
public static void stopenginertd(Value rightGameValue)
{
    GameValueMethods.unary__stopenginertd__object__ret__nothing(rightGameValue);
}
public static Value stopped(Value rightGameValue)
{
    return GameValueMethods.unary__stopped__object__ret__bool(rightGameValue);
}
public static void stopsound(Value rightGameValue)
{
    GameValueMethods.unary__stopsound__scalar__ret__nothing(rightGameValue);
}
public static Value str(Value rightGameValue)
{
    return GameValueMethods.unary__str__any__ret__string(rightGameValue);
}
public static Value supportinfo(Value rightGameValue)
{
    return GameValueMethods.unary__supportinfo__string__ret__array(rightGameValue);
}
public static Value surfaceiswater(Value rightGameValue)
{
    return GameValueMethods.unary__surfaceiswater__array__ret__bool(rightGameValue);
}
public static Value surfacenormal(Value rightGameValue)
{
    return GameValueMethods.unary__surfacenormal__array__ret__array(rightGameValue);
}
public static Value surfacetexture(Value rightGameValue)
{
    return GameValueMethods.unary__surfacetexture__array__ret__string(rightGameValue);
}
public static Value surfacetype(Value rightGameValue)
{
    return GameValueMethods.unary__surfacetype__array__ret__string(rightGameValue);
}
public static Value switch (Value rightGameValue)
{
    return GameValueMethods.unary__switch__any__ret__switch(rightGameValue);
}
public static void switchcamera(Value rightGameValue)
{
    GameValueMethods.unary__switchcamera__object__ret__nothing(rightGameValue);
}
public static Value synchronizedobjects(Value rightGameValue)
{
    return GameValueMethods.unary__synchronizedobjects__object__ret__array(rightGameValue);
}
public static Value synchronizedtriggers(Value rightGameValue)
{
    return GameValueMethods.unary__synchronizedtriggers__array__ret__array(rightGameValue);
}
public static Value synchronizedwaypoints(Value rightGameValue)
{
    return GameValueMethods.unary__synchronizedwaypoints__object__ret__array(rightGameValue);
}
public static Value synchronizedwaypoints(Value rightGameValue)
{
    return GameValueMethods.unary__synchronizedwaypoints__array__ret__array(rightGameValue);
}
public static void systemchat(Value rightGameValue)
{
    GameValueMethods.unary__systemchat__string__ret__nothing(rightGameValue);
}
public static Value tan(Value rightGameValue)
{
    return GameValueMethods.unary__tan__scalar_nan__ret__scalar_nan(rightGameValue);
}
public static Value taskalwaysvisible(Value rightGameValue)
{
    return GameValueMethods.unary__taskalwaysvisible__task__ret__bool(rightGameValue);
}
public static Value taskchildren(Value rightGameValue)
{
    return GameValueMethods.unary__taskchildren__task__ret__array(rightGameValue);
}
public static Value taskcompleted(Value rightGameValue)
{
    return GameValueMethods.unary__taskcompleted__task__ret__bool(rightGameValue);
}
public static Value taskcustomdata(Value rightGameValue)
{
    return GameValueMethods.unary__taskcustomdata__task__ret__array(rightGameValue);
}
public static Value taskdescription(Value rightGameValue)
{
    return GameValueMethods.unary__taskdescription__task__ret__array(rightGameValue);
}
public static Value taskdestination(Value rightGameValue)
{
    return GameValueMethods.unary__taskdestination__task__ret__array(rightGameValue);
}
public static void taskhint(Value rightGameValue)
{
    GameValueMethods.unary__taskhint__array__ret__nothing(rightGameValue);
}
public static Value taskmarkeroffset(Value rightGameValue)
{
    return GameValueMethods.unary__taskmarkeroffset__object__ret__array(rightGameValue);
}
public static Value taskname(Value rightGameValue)
{
    return GameValueMethods.unary__taskname__task__ret__string(rightGameValue);
}
public static Value taskparent(Value rightGameValue)
{
    return GameValueMethods.unary__taskparent__task__ret__task(rightGameValue);
}
public static Value taskresult(Value rightGameValue)
{
    return GameValueMethods.unary__taskresult__task__ret__array(rightGameValue);
}
public static Value taskstate(Value rightGameValue)
{
    return GameValueMethods.unary__taskstate__task__ret__string(rightGameValue);
}
public static Value tasktype(Value rightGameValue)
{
    return GameValueMethods.unary__tasktype__task__ret__string(rightGameValue);
}
public static Value teammember(Value rightGameValue)
{
    return GameValueMethods.unary__teammember__object__ret__team_member(rightGameValue);
}
public static Value teamname(Value rightGameValue)
{
    return GameValueMethods.unary__teamname__team_member__ret__string(rightGameValue);
}
public static Value teamtype(Value rightGameValue)
{
    return GameValueMethods.unary__teamtype__team_member__ret__string(rightGameValue);
}
public static void terminate(Value rightGameValue)
{
    GameValueMethods.unary__terminate__script__ret__nothing(rightGameValue);
}
public static Value terrainintersect(Value rightGameValue)
{
    return GameValueMethods.unary__terrainintersect__array__ret__bool(rightGameValue);
}
public static Value terrainintersectasl(Value rightGameValue)
{
    return GameValueMethods.unary__terrainintersectasl__array__ret__bool(rightGameValue);
}
public static Value terrainintersectatasl(Value rightGameValue)
{
    return GameValueMethods.unary__terrainintersectatasl__array__ret__array(rightGameValue);
}
public static Value text(Value rightGameValue)
{
    return GameValueMethods.unary__text__string__ret__text(rightGameValue);
}
public static Value text(Value rightGameValue)
{
    return GameValueMethods.unary__text__location__ret__string(rightGameValue);
}
public static void textlog(Value rightGameValue)
{
    GameValueMethods.unary__textlog__any__ret__nothing(rightGameValue);
}
public static void textlogformat(Value rightGameValue)
{
    GameValueMethods.unary__textlogformat__array__ret__nothing(rightGameValue);
}
public static Value tg(Value rightGameValue)
{
    return GameValueMethods.unary__tg__scalar_nan__ret__scalar_nan(rightGameValue);
}
public static void throw (Value rightGameValue)
{
    GameValueMethods.unary__throw__any__ret__nothing(rightGameValue);
}
public static void titlecut(Value rightGameValue)
{
    GameValueMethods.unary__titlecut__array__ret__nothing(rightGameValue);
}
public static void titlefadeout(Value rightGameValue)
{
    GameValueMethods.unary__titlefadeout__scalar__ret__nothing(rightGameValue);
}
public static void titleobj(Value rightGameValue)
{
    GameValueMethods.unary__titleobj__array__ret__nothing(rightGameValue);
}
public static void titlersc(Value rightGameValue)
{
    GameValueMethods.unary__titlersc__array__ret__nothing(rightGameValue);
}
public static void titletext(Value rightGameValue)
{
    GameValueMethods.unary__titletext__array__ret__nothing(rightGameValue);
}
public static Value toarray(Value rightGameValue)
{
    return GameValueMethods.unary__toarray__string__ret__array(rightGameValue);
}
public static Value toarray(Value rightGameValue)
{
    return GameValueMethods.unary__toarray__hashmap__ret__array(rightGameValue);
}
public static void tofixed(Value rightGameValue)
{
    GameValueMethods.unary__tofixed__scalar__ret__nothing(rightGameValue);
}
public static Value tolower(Value rightGameValue)
{
    return GameValueMethods.unary__tolower__string__ret__string(rightGameValue);
}
public static Value toloweransi(Value rightGameValue)
{
    return GameValueMethods.unary__toloweransi__string__ret__string(rightGameValue);
}
public static Value tostring(Value rightGameValue)
{
    return GameValueMethods.unary__tostring__array__ret__string(rightGameValue);
}
public static Value tostring(Value rightGameValue)
{
    return GameValueMethods.unary__tostring__code__ret__string(rightGameValue);
}
public static Value toupper(Value rightGameValue)
{
    return GameValueMethods.unary__toupper__string__ret__string(rightGameValue);
}
public static Value toupperansi(Value rightGameValue)
{
    return GameValueMethods.unary__toupperansi__string__ret__string(rightGameValue);
}
public static Value triggeractivated(Value rightGameValue)
{
    return GameValueMethods.unary__triggeractivated__object__ret__bool(rightGameValue);
}
public static Value triggeractivation(Value rightGameValue)
{
    return GameValueMethods.unary__triggeractivation__object__ret__array(rightGameValue);
}
public static void triggerammo(Value rightGameValue)
{
    GameValueMethods.unary__triggerammo__object__ret__nothing(rightGameValue);
}
public static Value triggerarea(Value rightGameValue)
{
    return GameValueMethods.unary__triggerarea__object__ret__array(rightGameValue);
}
public static Value triggerattachedvehicle(Value rightGameValue)
{
    return GameValueMethods.unary__triggerattachedvehicle__object__ret__object(rightGameValue);
}
public static Value triggerinterval(Value rightGameValue)
{
    return GameValueMethods.unary__triggerinterval__object__ret__scalar(rightGameValue);
}
public static Value triggerstatements(Value rightGameValue)
{
    return GameValueMethods.unary__triggerstatements__object__ret__array(rightGameValue);
}
public static Value triggertext(Value rightGameValue)
{
    return GameValueMethods.unary__triggertext__object__ret__string(rightGameValue);
}
public static Value triggertimeout(Value rightGameValue)
{
    return GameValueMethods.unary__triggertimeout__object__ret__array(rightGameValue);
}
public static Value triggertimeoutcurrent(Value rightGameValue)
{
    return GameValueMethods.unary__triggertimeoutcurrent__object__ret__scalar(rightGameValue);
}
public static Value triggertype(Value rightGameValue)
{
    return GameValueMethods.unary__triggertype__object__ret__string(rightGameValue);
}
public static Value trim(Value rightGameValue)
{
    return GameValueMethods.unary__trim__string__ret__string(rightGameValue);
}
public static Value try(Value rightGameValue)
{
    return GameValueMethods.unary__try__code__ret__exception(rightGameValue);
}
public static Value tvadd(Value rightGameValue)
{
    return GameValueMethods.unary__tvadd__array__ret__scalar(rightGameValue);
}
public static void tvclear(Value rightGameValue)
{
    GameValueMethods.unary__tvclear__scalar__ret__nothing(rightGameValue);
}
public static void tvclear(Value rightGameValue)
{
    GameValueMethods.unary__tvclear__control__ret__nothing(rightGameValue);
}
public static void tvcollapse(Value rightGameValue)
{
    GameValueMethods.unary__tvcollapse__array__ret__nothing(rightGameValue);
}
public static void tvcollapseall(Value rightGameValue)
{
    GameValueMethods.unary__tvcollapseall__scalar__ret__nothing(rightGameValue);
}
public static void tvcollapseall(Value rightGameValue)
{
    GameValueMethods.unary__tvcollapseall__control__ret__nothing(rightGameValue);
}
public static Value tvcount(Value rightGameValue)
{
    return GameValueMethods.unary__tvcount__array__ret__scalar(rightGameValue);
}
public static Value tvcursel(Value rightGameValue)
{
    return GameValueMethods.unary__tvcursel__scalar__ret__array(rightGameValue);
}
public static Value tvcursel(Value rightGameValue)
{
    return GameValueMethods.unary__tvcursel__control__ret__array(rightGameValue);
}
public static Value tvdata(Value rightGameValue)
{
    return GameValueMethods.unary__tvdata__array__ret__string(rightGameValue);
}
public static void tvdelete(Value rightGameValue)
{
    GameValueMethods.unary__tvdelete__array__ret__nothing(rightGameValue);
}
public static void tvexpand(Value rightGameValue)
{
    GameValueMethods.unary__tvexpand__array__ret__nothing(rightGameValue);
}
public static void tvexpandall(Value rightGameValue)
{
    GameValueMethods.unary__tvexpandall__scalar__ret__nothing(rightGameValue);
}
public static void tvexpandall(Value rightGameValue)
{
    GameValueMethods.unary__tvexpandall__control__ret__nothing(rightGameValue);
}
public static Value tvpicture(Value rightGameValue)
{
    return GameValueMethods.unary__tvpicture__array__ret__string(rightGameValue);
}
public static Value tvpictureright(Value rightGameValue)
{
    return GameValueMethods.unary__tvpictureright__array__ret__string(rightGameValue);
}
public static Value tvselection(Value rightGameValue)
{
    return GameValueMethods.unary__tvselection__control__ret__array(rightGameValue);
}
public static void tvsetcursel(Value rightGameValue)
{
    GameValueMethods.unary__tvsetcursel__array__ret__nothing(rightGameValue);
}
public static void tvsetdata(Value rightGameValue)
{
    GameValueMethods.unary__tvsetdata__array__ret__nothing(rightGameValue);
}
public static void tvsetpicture(Value rightGameValue)
{
    GameValueMethods.unary__tvsetpicture__array__ret__nothing(rightGameValue);
}
public static void tvsetpicturecolor(Value rightGameValue)
{
    GameValueMethods.unary__tvsetpicturecolor__array__ret__nothing(rightGameValue);
}
public static void tvsetpictureright(Value rightGameValue)
{
    GameValueMethods.unary__tvsetpictureright__array__ret__nothing(rightGameValue);
}
public static void tvsetpicturerightcolor(Value rightGameValue)
{
    GameValueMethods.unary__tvsetpicturerightcolor__array__ret__nothing(rightGameValue);
}
public static Value tvsettext(Value rightGameValue)
{
    return GameValueMethods.unary__tvsettext__array__ret__string(rightGameValue);
}
public static void tvsettooltip(Value rightGameValue)
{
    GameValueMethods.unary__tvsettooltip__array__ret__nothing(rightGameValue);
}
public static void tvsetvalue(Value rightGameValue)
{
    GameValueMethods.unary__tvsetvalue__array__ret__nothing(rightGameValue);
}
public static void tvsort(Value rightGameValue)
{
    GameValueMethods.unary__tvsort__array__ret__nothing(rightGameValue);
}
public static void tvsortbyvalue(Value rightGameValue)
{
    GameValueMethods.unary__tvsortbyvalue__array__ret__nothing(rightGameValue);
}
public static Value tvtext(Value rightGameValue)
{
    return GameValueMethods.unary__tvtext__array__ret__string(rightGameValue);
}
public static Value tvtooltip(Value rightGameValue)
{
    return GameValueMethods.unary__tvtooltip__array__ret__string(rightGameValue);
}
public static Value tvvalue(Value rightGameValue)
{
    return GameValueMethods.unary__tvvalue__array__ret__scalar(rightGameValue);
}
public static Value type(Value rightGameValue)
{
    return GameValueMethods.unary__type__task__ret__string(rightGameValue);
}
public static Value type(Value rightGameValue)
{
    return GameValueMethods.unary__type__location__ret__string(rightGameValue);
}
public static Value typename(Value rightGameValue)
{
    return GameValueMethods.unary__typename__any__ret__string(rightGameValue);
}
public static Value typeof(Value rightGameValue)
{
    return GameValueMethods.unary__typeof__object__ret__string(rightGameValue);
}
public static Value uavcontrol(Value rightGameValue)
{
    return GameValueMethods.unary__uavcontrol__object__ret__array(rightGameValue);
}
public static void uisleep(Value rightGameValue)
{
    GameValueMethods.unary__uisleep__scalar__ret__nothing(rightGameValue);
}
public static void unassigncurator(Value rightGameValue)
{
    GameValueMethods.unary__unassigncurator__object__ret__nothing(rightGameValue);
}
public static void unassignteam(Value rightGameValue)
{
    GameValueMethods.unary__unassignteam__object__ret__nothing(rightGameValue);
}
public static void unassignvehicle(Value rightGameValue)
{
    GameValueMethods.unary__unassignvehicle__object__ret__nothing(rightGameValue);
}
public static Value underwater(Value rightGameValue)
{
    return GameValueMethods.unary__underwater__object__ret__bool(rightGameValue);
}
public static Value uniform(Value rightGameValue)
{
    return GameValueMethods.unary__uniform__object__ret__string(rightGameValue);
}
public static Value uniformcontainer(Value rightGameValue)
{
    return GameValueMethods.unary__uniformcontainer__object__ret__object(rightGameValue);
}
public static Value uniformitems(Value rightGameValue)
{
    return GameValueMethods.unary__uniformitems__object__ret__array(rightGameValue);
}
public static Value uniformmagazines(Value rightGameValue)
{
    return GameValueMethods.unary__uniformmagazines__object__ret__array(rightGameValue);
}
public static Value uniqueunititems(Value rightGameValue)
{
    return GameValueMethods.unary__uniqueunititems__object_array__ret__hashmap(rightGameValue);
}
public static Value unitaddons(Value rightGameValue)
{
    return GameValueMethods.unary__unitaddons__string__ret__array(rightGameValue);
}
public static Value unitaimposition(Value rightGameValue)
{
    return GameValueMethods.unary__unitaimposition__object__ret__array(rightGameValue);
}
public static Value unitaimpositionvisual(Value rightGameValue)
{
    return GameValueMethods.unary__unitaimpositionvisual__object__ret__array(rightGameValue);
}
public static Value unitbackpack(Value rightGameValue)
{
    return GameValueMethods.unary__unitbackpack__object__ret__object(rightGameValue);
}
public static Value unitcombatmode(Value rightGameValue)
{
    return GameValueMethods.unary__unitcombatmode__object__ret__string(rightGameValue);
}
public static Value unitisuav(Value rightGameValue)
{
    return GameValueMethods.unary__unitisuav__object__ret__bool(rightGameValue);
}
public static Value unitpos(Value rightGameValue)
{
    return GameValueMethods.unary__unitpos__object__ret__string(rightGameValue);
}
public static Value unitready(Value rightGameValue)
{
    return GameValueMethods.unary__unitready__object_array__ret__bool(rightGameValue);
}
public static Value unitrecoilcoefficient(Value rightGameValue)
{
    return GameValueMethods.unary__unitrecoilcoefficient__object__ret__scalar(rightGameValue);
}
public static Value units(Value rightGameValue)
{
    return GameValueMethods.unary__units__group__ret__array(rightGameValue);
}
public static Value units(Value rightGameValue)
{
    return GameValueMethods.unary__units__object__ret__array(rightGameValue);
}
public static Value units(Value rightGameValue)
{
    return GameValueMethods.unary__units__side__ret__any(rightGameValue);
}
public static Value unlockachievement(Value rightGameValue)
{
    return GameValueMethods.unary__unlockachievement__string__ret__bool(rightGameValue);
}
public static void updateobjecttree(Value rightGameValue)
{
    GameValueMethods.unary__updateobjecttree__control__ret__nothing(rightGameValue);
}
public static void useaiopermapobstructiontest(Value rightGameValue)
{
    GameValueMethods.unary__useaiopermapobstructiontest__bool__ret__nothing(rightGameValue);
}
public static void useaisteeringcomponent(Value rightGameValue)
{
    GameValueMethods.unary__useaisteeringcomponent__bool__ret__nothing(rightGameValue);
}
public static Value values(Value rightGameValue)
{
    return GameValueMethods.unary__values__hashmap__ret__array(rightGameValue);
}
public static Value vectordir(Value rightGameValue)
{
    return GameValueMethods.unary__vectordir__object__ret__array(rightGameValue);
}
public static Value vectordirvisual(Value rightGameValue)
{
    return GameValueMethods.unary__vectordirvisual__object__ret__array(rightGameValue);
}
public static Value vectorlinearconversion(Value rightGameValue)
{
    return GameValueMethods.unary__vectorlinearconversion__array__ret__array(rightGameValue);
}
public static Value vectormagnitude(Value rightGameValue)
{
    return GameValueMethods.unary__vectormagnitude__array__ret__scalar(rightGameValue);
}
public static Value vectormagnitudesqr(Value rightGameValue)
{
    return GameValueMethods.unary__vectormagnitudesqr__array__ret__scalar(rightGameValue);
}
public static Value vectornormalized(Value rightGameValue)
{
    return GameValueMethods.unary__vectornormalized__array__ret__array(rightGameValue);
}
public static Value vectorside(Value rightGameValue)
{
    return GameValueMethods.unary__vectorside__object__ret__array(rightGameValue);
}
public static Value vectorsidevisual(Value rightGameValue)
{
    return GameValueMethods.unary__vectorsidevisual__object__ret__array(rightGameValue);
}
public static Value vectorup(Value rightGameValue)
{
    return GameValueMethods.unary__vectorup__object__ret__array(rightGameValue);
}
public static Value vectorupvisual(Value rightGameValue)
{
    return GameValueMethods.unary__vectorupvisual__object__ret__array(rightGameValue);
}
public static Value vehicle(Value rightGameValue)
{
    return GameValueMethods.unary__vehicle__object__ret__object(rightGameValue);
}
public static Value vehiclecargoenabled(Value rightGameValue)
{
    return GameValueMethods.unary__vehiclecargoenabled__object__ret__bool(rightGameValue);
}
public static Value vehiclemoveinfo(Value rightGameValue)
{
    return GameValueMethods.unary__vehiclemoveinfo__object__ret__array(rightGameValue);
}
public static Value vehiclereceiveremotetargets(Value rightGameValue)
{
    return GameValueMethods.unary__vehiclereceiveremotetargets__object__ret__bool(rightGameValue);
}
public static Value vehiclereportownposition(Value rightGameValue)
{
    return GameValueMethods.unary__vehiclereportownposition__object__ret__bool(rightGameValue);
}
public static Value vehiclereportremotetargets(Value rightGameValue)
{
    return GameValueMethods.unary__vehiclereportremotetargets__object__ret__bool(rightGameValue);
}
public static Value vehiclevarname(Value rightGameValue)
{
    return GameValueMethods.unary__vehiclevarname__object__ret__string(rightGameValue);
}
public static Value velocity(Value rightGameValue)
{
    return GameValueMethods.unary__velocity__object__ret__array(rightGameValue);
}
public static Value velocitymodelspace(Value rightGameValue)
{
    return GameValueMethods.unary__velocitymodelspace__object__ret__array(rightGameValue);
}
public static Value verifysignature(Value rightGameValue)
{
    return GameValueMethods.unary__verifysignature__string__ret__bool(rightGameValue);
}
public static Value vest(Value rightGameValue)
{
    return GameValueMethods.unary__vest__object__ret__string(rightGameValue);
}
public static Value vestcontainer(Value rightGameValue)
{
    return GameValueMethods.unary__vestcontainer__object__ret__object(rightGameValue);
}
public static Value vestitems(Value rightGameValue)
{
    return GameValueMethods.unary__vestitems__object__ret__array(rightGameValue);
}
public static Value vestmagazines(Value rightGameValue)
{
    return GameValueMethods.unary__vestmagazines__object__ret__array(rightGameValue);
}
public static Value visibleposition(Value rightGameValue)
{
    return GameValueMethods.unary__visibleposition__object__ret__array(rightGameValue);
}
public static Value visiblepositionasl(Value rightGameValue)
{
    return GameValueMethods.unary__visiblepositionasl__object__ret__array(rightGameValue);
}
public static void waituntil(Value rightGameValue)
{
    GameValueMethods.unary__waituntil__code__ret__nothing(rightGameValue);
}
public static Value waterdamaged(Value rightGameValue)
{
    return GameValueMethods.unary__waterdamaged__object__ret__bool(rightGameValue);
}
public static Value waypointattachedobject(Value rightGameValue)
{
    return GameValueMethods.unary__waypointattachedobject__array__ret__object(rightGameValue);
}
public static Value waypointattachedvehicle(Value rightGameValue)
{
    return GameValueMethods.unary__waypointattachedvehicle__array__ret__object(rightGameValue);
}
public static Value waypointbehaviour(Value rightGameValue)
{
    return GameValueMethods.unary__waypointbehaviour__array__ret__string(rightGameValue);
}
public static Value waypointcombatmode(Value rightGameValue)
{
    return GameValueMethods.unary__waypointcombatmode__array__ret__string(rightGameValue);
}
public static Value waypointcompletionradius(Value rightGameValue)
{
    return GameValueMethods.unary__waypointcompletionradius__array__ret__scalar(rightGameValue);
}
public static Value waypointdescription(Value rightGameValue)
{
    return GameValueMethods.unary__waypointdescription__array__ret__string(rightGameValue);
}
public static Value waypointforcebehaviour(Value rightGameValue)
{
    return GameValueMethods.unary__waypointforcebehaviour__array__ret__bool(rightGameValue);
}
public static Value waypointformation(Value rightGameValue)
{
    return GameValueMethods.unary__waypointformation__array__ret__string(rightGameValue);
}
public static Value waypointhouseposition(Value rightGameValue)
{
    return GameValueMethods.unary__waypointhouseposition__array__ret__scalar(rightGameValue);
}
public static Value waypointloiteraltitude(Value rightGameValue)
{
    return GameValueMethods.unary__waypointloiteraltitude__array__ret__scalar(rightGameValue);
}
public static Value waypointloiterradius(Value rightGameValue)
{
    return GameValueMethods.unary__waypointloiterradius__array__ret__scalar(rightGameValue);
}
public static Value waypointloitertype(Value rightGameValue)
{
    return GameValueMethods.unary__waypointloitertype__array__ret__string(rightGameValue);
}
public static Value waypointname(Value rightGameValue)
{
    return GameValueMethods.unary__waypointname__array__ret__string(rightGameValue);
}
public static Value waypointposition(Value rightGameValue)
{
    return GameValueMethods.unary__waypointposition__array__ret__array(rightGameValue);
}
public static Value waypoints(Value rightGameValue)
{
    return GameValueMethods.unary__waypoints__object_group__ret__array(rightGameValue);
}
public static Value waypointscript(Value rightGameValue)
{
    return GameValueMethods.unary__waypointscript__array__ret__string(rightGameValue);
}
public static Value waypointsenableduav(Value rightGameValue)
{
    return GameValueMethods.unary__waypointsenableduav__object__ret__bool(rightGameValue);
}
public static Value waypointshow(Value rightGameValue)
{
    return GameValueMethods.unary__waypointshow__array__ret__string(rightGameValue);
}
public static Value waypointspeed(Value rightGameValue)
{
    return GameValueMethods.unary__waypointspeed__array__ret__string(rightGameValue);
}
public static Value waypointstatements(Value rightGameValue)
{
    return GameValueMethods.unary__waypointstatements__array__ret__array(rightGameValue);
}
public static Value waypointtimeout(Value rightGameValue)
{
    return GameValueMethods.unary__waypointtimeout__array__ret__array(rightGameValue);
}
public static Value waypointtimeoutcurrent(Value rightGameValue)
{
    return GameValueMethods.unary__waypointtimeoutcurrent__group__ret__scalar(rightGameValue);
}
public static Value waypointtype(Value rightGameValue)
{
    return GameValueMethods.unary__waypointtype__array__ret__string(rightGameValue);
}
public static Value waypointvisible(Value rightGameValue)
{
    return GameValueMethods.unary__waypointvisible__array__ret__scalar(rightGameValue);
}
public static Value weaponcargo(Value rightGameValue)
{
    return GameValueMethods.unary__weaponcargo__object__ret__array(rightGameValue);
}
public static Value weapondisassemblyenabled(Value rightGameValue)
{
    return GameValueMethods.unary__weapondisassemblyenabled__object__ret__bool(rightGameValue);
}
public static Value weaponinertia(Value rightGameValue)
{
    return GameValueMethods.unary__weaponinertia__object__ret__array(rightGameValue);
}
public static Value weaponlowered(Value rightGameValue)
{
    return GameValueMethods.unary__weaponlowered__object__ret__bool(rightGameValue);
}
public static Value weapons(Value rightGameValue)
{
    return GameValueMethods.unary__weapons__object__ret__array(rightGameValue);
}
public static Value weaponsitems(Value rightGameValue)
{
    return GameValueMethods.unary__weaponsitems__object_array__ret__array(rightGameValue);
}
public static Value weaponsitemscargo(Value rightGameValue)
{
    return GameValueMethods.unary__weaponsitemscargo__object_array__ret__array(rightGameValue);
}
public static Value weaponstate(Value rightGameValue)
{
    return GameValueMethods.unary__weaponstate__object__ret__array(rightGameValue);
}
public static Value weaponstate(Value rightGameValue)
{
    return GameValueMethods.unary__weaponstate__array__ret__array(rightGameValue);
}
public static Value weightrtd(Value rightGameValue)
{
    return GameValueMethods.unary__weightrtd__object__ret__array(rightGameValue);
}
public static Value wfsidetext(Value rightGameValue)
{
    return GameValueMethods.unary__wfsidetext__side__ret__string(rightGameValue);
}
public static Value wfsidetext(Value rightGameValue)
{
    return GameValueMethods.unary__wfsidetext__object__ret__string(rightGameValue);
}
public static Value wfsidetext(Value rightGameValue)
{
    return GameValueMethods.unary__wfsidetext__group__ret__string(rightGameValue);
}
public static Value while (Value rightGameValue)
{
    return GameValueMethods.unary__while__code__ret__while(rightGameValue);
}
public static Value wingsforcesrtd(Value rightGameValue)
{
    return GameValueMethods.unary__wingsforcesrtd__object__ret__array(rightGameValue);
}
public static Value with(Value rightGameValue)
{
    return GameValueMethods.unary__with__namespace__ret__with(rightGameValue);
}
public static Value worldtoscreen(Value rightGameValue)
{
    return GameValueMethods.unary__worldtoscreen__array__ret__array(rightGameValue);
}
public static void action(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__action__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value actionparams(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__actionparams__object__scalar__ret__array(leftGameValue, rightGameValue);
}
public static Value add3denlayer(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__add3denlayer__scalar__string__ret__scalar(leftGameValue, rightGameValue);
}
public static Value addaction(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__addaction__object__array__ret__nothing_scalar(leftGameValue, rightGameValue);
}
public static void addbackpack(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addbackpack__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void addbackpackcargo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addbackpackcargo__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addbackpackcargoglobal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addbackpackcargoglobal__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addbackpackglobal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addbackpackglobal__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void addbinocularitem(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addbinocularitem__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void addcuratoraddons(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addcuratoraddons__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addcuratorcameraarea(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addcuratorcameraarea__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addcuratoreditableobjects(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addcuratoreditableobjects__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addcuratoreditingarea(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addcuratoreditingarea__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addcuratorpoints(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addcuratorpoints__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static Value addeditorobject(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__addeditorobject__control__array__ret__string(leftGameValue, rightGameValue);
}
public static Value addeventhandler(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__addeventhandler__object__array__ret__nothing_scalar(leftGameValue, rightGameValue);
}
public static Value addeventhandler(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__addeventhandler__group__array__ret__nothing_scalar(leftGameValue, rightGameValue);
}
public static void addforce(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addforce__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addgoggles(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addgoggles__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value addgroupicon(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__addgroupicon__group__array__ret__scalar(leftGameValue, rightGameValue);
}
public static void addhandgunitem(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addhandgunitem__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void addheadgear(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addheadgear__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void additem(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__additem__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void additemcargo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__additemcargo__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void additemcargoglobal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__additemcargoglobal__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void additemtobackpack(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__additemtobackpack__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void additemtouniform(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__additemtouniform__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void additemtovest(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__additemtovest__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void addlivestats(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addlivestats__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void addmagazine(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addmagazine__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void addmagazine(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addmagazine__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addmagazineammocargo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addmagazineammocargo__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addmagazinecargo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addmagazinecargo__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addmagazinecargoglobal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addmagazinecargoglobal__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addmagazineglobal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addmagazineglobal__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void addmagazines(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addmagazines__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addmagazineturret(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addmagazineturret__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value addmenu(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__addmenu__control__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value addmenuitem(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__addmenuitem__control__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value addmpeventhandler(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__addmpeventhandler__object__array__ret__nothing_scalar(leftGameValue, rightGameValue);
}
public static void addownedmine(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addownedmine__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void addplayerscores(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addplayerscores__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addprimaryweaponitem(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addprimaryweaponitem__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void addpublicvariableeventhandler(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addpublicvariableeventhandler__string__code__ret__nothing(leftGameValue, rightGameValue);
}
public static void addpublicvariableeventhandler(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addpublicvariableeventhandler__string__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addrating(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addrating__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void addresources(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addresources__team_member__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addscore(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addscore__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void addscoreside(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addscoreside__side__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void addsecondaryweaponitem(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addsecondaryweaponitem__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void addteammember(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addteammember__team_member__team_member__ret__nothing(leftGameValue, rightGameValue);
}
public static void addtorque(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addtorque__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void adduniform(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__adduniform__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void addvehicle(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addvehicle__group__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void addvest(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addvest__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value addwaypoint(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__addwaypoint__group__array__ret__array(leftGameValue, rightGameValue);
}
public static void addweapon(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addweapon__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void addweaponcargo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addweaponcargo__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addweaponcargoglobal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addweaponcargoglobal__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addweaponglobal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addweaponglobal__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void addweaponitem(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addweaponitem__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addweaponturret(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addweaponturret__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addweaponwithattachmentscargo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addweaponwithattachmentscargo__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void addweaponwithattachmentscargoglobal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__addweaponwithattachmentscargoglobal__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value aimedattarget(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__aimedattarget__object__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value alldiaryrecords(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__alldiaryrecords__object__string__ret__array(leftGameValue, rightGameValue);
}
public static Value allobjects(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__allobjects__scalar__scalar__ret__array(leftGameValue, rightGameValue);
}
public static Value allobjects(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__allobjects__string__scalar__ret__array(leftGameValue, rightGameValue);
}
public static void allow3dmode(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__allow3dmode__control__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void allowcrewinimmobile(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__allowcrewinimmobile__object__bool_array__ret__nothing(leftGameValue, rightGameValue);
}
public static void allowcuratorlogicignoreareas(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__allowcuratorlogicignoreareas__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void allowdamage(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__allowdamage__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void allowdammage(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__allowdammage__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void allowfileoperations(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__allowfileoperations__control__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void allowfleeing(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__allowfleeing__object_group__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void allowgetin(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__allowgetin__array__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void allowservice(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__allowservice__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void allowsprint(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__allowsprint__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static Value ammo(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__ammo__object__string__ret__scalar(leftGameValue, rightGameValue);
}
public static Value ammoonpylon(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__ammoonpylon__object__string_scalar__ret__scalar(leftGameValue, rightGameValue);
}
public static Value and(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__and__bool__bool__ret__bool(leftGameValue, rightGameValue);
}
public static Value and(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__and__bool__code__ret__bool(leftGameValue, rightGameValue);
}
public static void animate(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__animate__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void animatebay(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__animatebay__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void animatedoor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__animatedoor__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void animatepylon(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__animatepylon__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void animatesource(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__animatesource__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value animationphase(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__animationphase__object__string__ret__scalar(leftGameValue, rightGameValue);
}
public static Value animationsourcephase(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__animationsourcephase__object__string__ret__scalar(leftGameValue, rightGameValue);
}
public static void append(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__append__array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value apply(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__apply__array__code__ret__array(leftGameValue, rightGameValue);
}
public static Value apply(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__apply__hashmap__code__ret__array(leftGameValue, rightGameValue);
}
public static Value arrayintersect(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__arrayintersect__array__array__ret__array(leftGameValue, rightGameValue);
}
public static void assignascargo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__assignascargo__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void assignascargoindex(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__assignascargoindex__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void assignascommander(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__assignascommander__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void assignasdriver(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__assignasdriver__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void assignasgunner(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__assignasgunner__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void assignasturret(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__assignasturret__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void assigncurator(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__assigncurator__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void assignitem(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__assignitem__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void assignteam(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__assignteam__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void assigntoairport(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__assigntoairport__object__object_scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static Value atan2(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__atan2__scalar_nan__scalar_nan__ret__scalar_nan(leftGameValue, rightGameValue);
}
public static void attachobject(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__attachobject__location__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void attachto(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__attachto__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void awake(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__awake__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static Value backpackspacefor(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__backpackspacefor__object__string__ret__array(leftGameValue, rightGameValue);
}
public static Value bezierinterpolation(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__bezierinterpolation__scalar__array__ret__array(leftGameValue, rightGameValue);
}
public static Value boundingbox(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__boundingbox__scalar__object__ret__array(leftGameValue, rightGameValue);
}
public static Value boundingboxreal(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__boundingboxreal__scalar__object__ret__array(leftGameValue, rightGameValue);
}
public static Value breakout(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__breakout__any__string__ret__any(leftGameValue, rightGameValue);
}
public static Value buildingexit(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__buildingexit__object__scalar__ret__array(leftGameValue, rightGameValue);
}
public static Value buildingpos(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__buildingpos__object__scalar__ret__array(leftGameValue, rightGameValue);
}
public static void buttonsetaction(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__buttonsetaction__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value call(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__call__any__code__ret__any(leftGameValue, rightGameValue);
}
public static Value call(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__call__hashmap__array__ret__any(leftGameValue, rightGameValue);
}
public static Value callextension(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__callextension__string__string__ret__string(leftGameValue, rightGameValue);
}
public static Value callextension(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__callextension__string__array__ret__array(leftGameValue, rightGameValue);
}
public static void camcommand(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__camcommand__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void camcommit(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__camcommit__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void camcommitprepared(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__camcommitprepared__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void camconstuctionsetparams(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__camconstuctionsetparams__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value camcreate(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__camcreate__string__array__ret__object(leftGameValue, rightGameValue);
}
public static void cameraeffect(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__cameraeffect__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void campreload(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__campreload__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void campreparebank(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__campreparebank__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void campreparedir(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__campreparedir__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void campreparedive(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__campreparedive__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void campreparefocus(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__campreparefocus__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void campreparefov(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__campreparefov__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void campreparefovrange(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__campreparefovrange__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void campreparepos(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__campreparepos__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void campreparerelpos(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__campreparerelpos__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void campreparetarget(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__campreparetarget__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void campreparetarget(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__campreparetarget__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void camsetbank(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__camsetbank__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void camsetdir(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__camsetdir__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void camsetdive(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__camsetdive__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void camsetfocus(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__camsetfocus__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void camsetfov(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__camsetfov__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void camsetfovrange(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__camsetfovrange__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void camsetpos(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__camsetpos__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void camsetrelpos(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__camsetrelpos__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void camsettarget(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__camsettarget__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void camsettarget(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__camsettarget__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value canadd(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__canadd__object__string_array__ret__bool(leftGameValue, rightGameValue);
}
public static Value canadd(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__canadd__string__string_array__ret__bool(leftGameValue, rightGameValue);
}
public static Value canadditemtobackpack(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__canadditemtobackpack__object__string_array__ret__bool(leftGameValue, rightGameValue);
}
public static Value canadditemtouniform(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__canadditemtouniform__object__string_array__ret__bool(leftGameValue, rightGameValue);
}
public static Value canadditemtovest(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__canadditemtovest__object__string_array__ret__bool(leftGameValue, rightGameValue);
}
public static Value canslingload(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__canslingload__object__object__ret__bool(leftGameValue, rightGameValue);
}
public static Value canslingload(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__canslingload__string__string__ret__bool(leftGameValue, rightGameValue);
}
public static Value canvehiclecargo(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__canvehiclecargo__object__object__ret__array(leftGameValue, rightGameValue);
}
public static Value catch(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__catch__exception__code__ret__any(leftGameValue, rightGameValue);
}
public static void cbsetchecked(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__cbsetchecked__control__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static Value checkaifeature(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__checkaifeature__object__string__ret__bool(leftGameValue, rightGameValue);
}
public static Value checkvisibility(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__checkvisibility__array__array__ret__scalar(leftGameValue, rightGameValue);
}
public static void clear3denattribute(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__clear3denattribute__any__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void closedisplay(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__closedisplay__display__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void collect3denhistory(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__collect3denhistory__array__code__ret__nothing(leftGameValue, rightGameValue);
}
public static void commandartilleryfire(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__commandartilleryfire__object_array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void commandchat(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__commandchat__object_array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void commandfire(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__commandfire__object_array__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void commandfollow(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__commandfollow__object_array__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void commandfsm(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__commandfsm__object_array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void commandmove(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__commandmove__object_array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void commandradio(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__commandradio__object_array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void commandsuppressivefire(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__commandsuppressivefire__object_array__object_array__ret__nothing(leftGameValue, rightGameValue);
}
public static void commandtarget(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__commandtarget__object_array__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void commandwatch(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__commandwatch__object_array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void commandwatch(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__commandwatch__object_array__object__ret__nothing(leftGameValue, rightGameValue);
}
public static Value configaccessor(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__configaccessor__config__string__ret__config(leftGameValue, rightGameValue);
}
public static Value configclasses(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__configclasses__string__config__ret__array(leftGameValue, rightGameValue);
}
public static void confirmsensortarget(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__confirmsensortarget__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value connectterminaltouav(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__connectterminaltouav__object__object__ret__bool(leftGameValue, rightGameValue);
}
public static Value controlsgroupctrl(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__controlsgroupctrl__control__scalar__ret__control(leftGameValue, rightGameValue);
}
public static void copywaypoints(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__copywaypoints__group__group__ret__nothing(leftGameValue, rightGameValue);
}
public static Value count(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__count__code__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value countenemy(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__countenemy__object__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value countfriendly(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__countfriendly__object__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value countside(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__countside__side__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value counttype(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__counttype__string__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value countunknown(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__countunknown__object__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value create3denentity(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__create3denentity__group__array__ret__any(leftGameValue, rightGameValue);
}
public static Value creatediaryrecord(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__creatediaryrecord__object__array__ret__diary_record(leftGameValue, rightGameValue);
}
public static Value creatediarysubject(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__creatediarysubject__object__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value createdisplay(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__createdisplay__display__string__ret__display(leftGameValue, rightGameValue);
}
public static Value createhashmapfromarray(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__createhashmapfromarray__array__array__ret__hashmap(leftGameValue, rightGameValue);
}
public static void createmenu(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__createmenu__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static Value createmissiondisplay(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__createmissiondisplay__display__string__ret__display(leftGameValue, rightGameValue);
}
public static Value createmissiondisplay(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__createmissiondisplay__display__array__ret__display(leftGameValue, rightGameValue);
}
public static void creatempcampaigndisplay(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__creatempcampaigndisplay__display__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value createsimpletask(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__createsimpletask__object__array__ret__task(leftGameValue, rightGameValue);
}
public static Value createsite(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__createsite__string__array__ret__object(leftGameValue, rightGameValue);
}
public static Value createtask(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__createtask__team_member__array__ret__task(leftGameValue, rightGameValue);
}
public static void createunit(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__createunit__string__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value createunit(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__createunit__group__array__ret__object(leftGameValue, rightGameValue);
}
public static Value createvehicle(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__createvehicle__string__array__ret__object(leftGameValue, rightGameValue);
}
public static Value createvehiclecrew(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__createvehiclecrew__group__object__ret__group(leftGameValue, rightGameValue);
}
public static Value createvehiclecrew(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__createvehiclecrew__side__object__ret__group(leftGameValue, rightGameValue);
}
public static Value createvehiclelocal(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__createvehiclelocal__string__array__ret__object(leftGameValue, rightGameValue);
}
public static Value ctdata(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__ctdata__control__scalar__ret__string(leftGameValue, rightGameValue);
}
public static Value ctfindheaderrows(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__ctfindheaderrows__control__scalar__ret__array(leftGameValue, rightGameValue);
}
public static Value ctfindrowheader(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__ctfindrowheader__control__scalar__ret__scalar(leftGameValue, rightGameValue);
}
public static Value ctheadercontrols(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__ctheadercontrols__control__scalar__ret__array(leftGameValue, rightGameValue);
}
public static void ctremoveheaders(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctremoveheaders__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctremoverows(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctremoverows__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value ctrladdeventhandler(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__ctrladdeventhandler__control__array__ret__scalar(leftGameValue, rightGameValue);
}
public static void ctrlanimatemodel(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlanimatemodel__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value ctrlanimationphasemodel(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__ctrlanimationphasemodel__control__string__ret__scalar(leftGameValue, rightGameValue);
}
public static Value ctrlat(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__ctrlat__display__array__ret__control(leftGameValue, rightGameValue);
}
public static Value ctrlchecked(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__ctrlchecked__control__scalar__ret__bool(leftGameValue, rightGameValue);
}
public static void ctrlcommit(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlcommit__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static Value ctrlcreate(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__ctrlcreate__display__array__ret__control(leftGameValue, rightGameValue);
}
public static void ctrlenable(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlenable__control__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlmapanimadd(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlmapanimadd__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlmapcursor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlmapcursor__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value ctrlmapscreentoworld(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__ctrlmapscreentoworld__control__array__ret__array(leftGameValue, rightGameValue);
}
public static void ctrlmapsetposition(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlmapsetposition__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value ctrlmapworldtoscreen(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__ctrlmapworldtoscreen__control__array__ret__array(leftGameValue, rightGameValue);
}
public static void ctrlremovealleventhandlers(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlremovealleventhandlers__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlremoveeventhandler(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlremoveeventhandler__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetactivecolor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetactivecolor__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetangle(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetangle__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetautoscrolldelay(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetautoscrolldelay__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetautoscrollrewind(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetautoscrollrewind__control__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetautoscrollspeed(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetautoscrollspeed__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetbackgroundcolor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetbackgroundcolor__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetchecked(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetchecked__control__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetchecked(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetchecked__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetdisabledcolor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetdisabledcolor__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlseteventhandler(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlseteventhandler__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfade(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfade__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfont(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfont__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfonth1(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfonth1__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfonth1b(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfonth1b__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfonth2(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfonth2__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfonth2b(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfonth2b__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfonth3(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfonth3__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfonth3b(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfonth3b__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfonth4(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfonth4__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfonth4b(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfonth4b__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfonth5(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfonth5__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfonth5b(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfonth5b__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfonth6(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfonth6__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfonth6b(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfonth6b__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfontheight(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfontheight__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfontheighth1(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfontheighth1__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfontheighth2(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfontheighth2__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfontheighth3(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfontheighth3__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfontheighth4(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfontheighth4__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfontheighth5(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfontheighth5__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfontheighth6(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfontheighth6__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfontheightsecondary(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfontheightsecondary__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfontp(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfontp__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfontp(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfontp__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfontpb(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfontpb__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetfontsecondary(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetfontsecondary__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetforegroundcolor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetforegroundcolor__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetmodel(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetmodel__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetmodeldirandup(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetmodeldirandup__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetmodelscale(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetmodelscale__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetmouseposition(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetmouseposition__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetpixelprecision(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetpixelprecision__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetpixelprecision(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetpixelprecision__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetposition(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetposition__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetpositionh(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetpositionh__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetpositionw(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetpositionw__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetpositionx(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetpositionx__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetpositiony(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetpositiony__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetscale(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetscale__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetscrollvalues(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetscrollvalues__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetshadow(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetshadow__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsetstructuredtext(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsetstructuredtext__control__text__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsettext(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsettext__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsettextcolor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsettextcolor__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsettextcolorsecondary(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsettextcolorsecondary__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsettextsecondary(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsettextsecondary__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsettextselection(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsettextselection__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsettooltip(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsettooltip__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsettooltipcolorbox(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsettooltipcolorbox__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsettooltipcolorshade(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsettooltipcolorshade__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlsettooltipcolortext(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlsettooltipcolortext__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value ctrlsettooltipmaxwidth(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__ctrlsettooltipmaxwidth__control__scalar__ret__scalar(leftGameValue, rightGameValue);
}
public static void ctrlseturl(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlseturl__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlseturloverlaymode(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlseturloverlaymode__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctrlshow(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctrlshow__control__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static Value ctrowcontrols(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__ctrowcontrols__control__scalar__ret__array(leftGameValue, rightGameValue);
}
public static void ctsetcursel(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctsetcursel__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctsetdata(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctsetdata__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctsetheadertemplate(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctsetheadertemplate__control__config__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctsetrowtemplate(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctsetrowtemplate__control__config__ret__nothing(leftGameValue, rightGameValue);
}
public static void ctsetvalue(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ctsetvalue__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value ctvalue(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__ctvalue__control__scalar__ret__scalar(leftGameValue, rightGameValue);
}
public static Value curatorcoef(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__curatorcoef__object__string__ret__scalar(leftGameValue, rightGameValue);
}
public static Value currentmagazinedetailturret(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__currentmagazinedetailturret__object__array__ret__string(leftGameValue, rightGameValue);
}
public static Value currentmagazineturret(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__currentmagazineturret__object__array__ret__string(leftGameValue, rightGameValue);
}
public static Value currentvisionmode(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__currentvisionmode__object__array__ret__array(leftGameValue, rightGameValue);
}
public static Value currentvisionmode(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__currentvisionmode__object__string__ret__array(leftGameValue, rightGameValue);
}
public static Value currentweaponturret(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__currentweaponturret__object__array__ret__string(leftGameValue, rightGameValue);
}
public static Value currentzeroing(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__currentzeroing__object__array__ret__array(leftGameValue, rightGameValue);
}
public static void customchat(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__customchat__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void customradio(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__customradio__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value cutfadeout(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__cutfadeout__string__scalar__ret__scalar(leftGameValue, rightGameValue);
}
public static void cutfadeout(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__cutfadeout__scalar__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static Value cutobj(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__cutobj__string__array__ret__scalar(leftGameValue, rightGameValue);
}
public static void cutobj(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__cutobj__scalar__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value cutrsc(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__cutrsc__string__array__ret__scalar(leftGameValue, rightGameValue);
}
public static void cutrsc(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__cutrsc__scalar__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value cuttext(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__cuttext__string__array__ret__scalar(leftGameValue, rightGameValue);
}
public static void cuttext(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__cuttext__scalar__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void debugfsm(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__debugfsm__scalar__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static Value deleteat(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__deleteat__array__scalar__ret__any(leftGameValue, rightGameValue);
}
public static Value deleteat(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__deleteat__hashmap__side_config__ret__any(leftGameValue, rightGameValue);
}
public static Value deleteeditorobject(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__deleteeditorobject__control__string__ret__any(leftGameValue, rightGameValue);
}
public static void deletegroupwhenempty(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__deletegroupwhenempty__group__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void deleterange(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__deleterange__array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void deleteresources(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__deleteresources__team_member__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void deletevehiclecrew(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__deletevehiclecrew__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void diag_enable(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__diag_enable__string__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static Value diarysubjectexists(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__diarysubjectexists__object__string__ret__bool(leftGameValue, rightGameValue);
}
public static Value directionstabilizationenabled(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__directionstabilizationenabled__object__array__ret__bool(leftGameValue, rightGameValue);
}
public static void directsay(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__directsay__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void disableai(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__disableai__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void disablebrakes(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__disablebrakes__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void disablecollisionwith(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__disablecollisionwith__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void disableconversation(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__disableconversation__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void disablenvgequipment(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__disablenvgequipment__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void disabletiequipment(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__disabletiequipment__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void disableuavconnectability(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__disableuavconnectability__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value displayaddeventhandler(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__displayaddeventhandler__display__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value displayctrl(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__displayctrl__display__scalar__ret__control(leftGameValue, rightGameValue);
}
public static void displayremovealleventhandlers(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__displayremovealleventhandlers__display__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void displayremoveeventhandler(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__displayremoveeventhandler__display__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void displayseteventhandler(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__displayseteventhandler__display__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value distance(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__distance__object_array__object_array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value distance(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__distance__location__location__ret__scalar(leftGameValue, rightGameValue);
}
public static Value distance(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__distance__location__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value distance(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__distance__array__location__ret__scalar(leftGameValue, rightGameValue);
}
public static Value distance2d(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__distance2d__object_array__object_array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value distancesqr(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__distancesqr__object_array__object_array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value distancesqr(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__distancesqr__location__location__ret__scalar(leftGameValue, rightGameValue);
}
public static Value distancesqr(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__distancesqr__location__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value distancesqr(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__distancesqr__array__location__ret__scalar(leftGameValue, rightGameValue);
}
public static void do (Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__do__while__code__ret__nothing(leftGameValue, rightGameValue);
}
public static void do (Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__do__with__code__ret__nothing(leftGameValue, rightGameValue);
}
public static Value do (Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__do__for__code__ret__any(leftGameValue, rightGameValue);
}
public static Value do (Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__do__switch__code__ret__any(leftGameValue, rightGameValue);
}
public static void doartilleryfire(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__doartilleryfire__object_array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void dofire(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__dofire__object_array__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void dofollow(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__dofollow__object_array__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void dofsm(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__dofsm__object_array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void domove(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__domove__object_array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value doorphase(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__doorphase__object__string__ret__scalar(leftGameValue, rightGameValue);
}
public static void dosuppressivefire(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__dosuppressivefire__object_array__object_array__ret__nothing(leftGameValue, rightGameValue);
}
public static void dotarget(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__dotarget__object_array__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void dowatch(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__dowatch__object_array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void dowatch(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__dowatch__object_array__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void drawarrow(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__drawarrow__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void drawellipse(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__drawellipse__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void drawicon(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__drawicon__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void drawline(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__drawline__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void drawlink(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__drawlink__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void drawlocation(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__drawlocation__control__location__ret__nothing(leftGameValue, rightGameValue);
}
public static void drawpolygon(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__drawpolygon__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void drawrectangle(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__drawrectangle__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void drawtriangle(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__drawtriangle__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value editobject(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__editobject__control__string__ret__any(leftGameValue, rightGameValue);
}
public static void editorseteventhandler(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__editorseteventhandler__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void elevateperiscope(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__elevateperiscope__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value else (Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__else__code__code__ret__array(leftGameValue, rightGameValue);
}
public static Value emptypositions(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__emptypositions__object__string__ret__scalar(leftGameValue, rightGameValue);
}
public static void enableai(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enableai__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void enableaifeature(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enableaifeature__string__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void enableaifeature(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enableaifeature__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void enableaimprecision(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enableaimprecision__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void enableattack(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enableattack__object_group__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static Value enableaudiofeature(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__enableaudiofeature__object__array__ret__bool(leftGameValue, rightGameValue);
}
public static void enableautostartuprtd(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enableautostartuprtd__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static Value enableautotrimrtd(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__enableautotrimrtd__object__bool__ret__bool(leftGameValue, rightGameValue);
}
public static void enablechannel(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enablechannel__scalar__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void enablechannel(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enablechannel__scalar__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void enablecollisionwith(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enablecollisionwith__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void enablecopilot(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enablecopilot__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void enabledirectionstabilization(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enabledirectionstabilization__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void enabledynamicsimulation(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enabledynamicsimulation__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void enabledynamicsimulation(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enabledynamicsimulation__group__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void enablefatigue(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enablefatigue__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void enablegunlights(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enablegunlights__object_group__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value enableinfopanelcomponent(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__enableinfopanelcomponent__object_array__array__ret__bool(leftGameValue, rightGameValue);
}
public static void enableirlasers(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enableirlasers__object_group__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void enablemimics(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enablemimics__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void enablepersonturret(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enablepersonturret__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void enablereload(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enablereload__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void enableropeattach(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enableropeattach__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void enablesimulation(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enablesimulation__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void enablesimulationglobal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enablesimulationglobal__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void enablestamina(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enablestamina__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void enableuavconnectability(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enableuavconnectability__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void enableuavwaypoints(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enableuavwaypoints__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void enablevehiclecargo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enablevehiclecargo__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void enablevehiclesensor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enablevehiclesensor__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void enableweapondisassembly(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__enableweapondisassembly__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void engineon(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__engineon__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static Value evalobjectargument(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__evalobjectargument__control__array__ret__any(leftGameValue, rightGameValue);
}
public static void exec(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__exec__any__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value execeditorscript(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__execeditorscript__control__array__ret__any(leftGameValue, rightGameValue);
}
public static Value execfsm(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__execfsm__any__string__ret__scalar(leftGameValue, rightGameValue);
}
public static Value execvm(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__execvm__any__string__ret__script(leftGameValue, rightGameValue);
}
public static Value exitwith(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__exitwith__if__code__ret__any(leftGameValue, rightGameValue);
}
public static void fadeenvironment(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__fadeenvironment__scalar__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void fademusic(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__fademusic__scalar__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void faderadio(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__faderadio__scalar__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void fadesound(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__fadesound__scalar__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void fadespeech(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__fadespeech__scalar__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static Value find(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__find__array__any__ret__scalar(leftGameValue, rightGameValue);
}
public static Value find(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__find__string__string__ret__scalar(leftGameValue, rightGameValue);
}
public static Value find(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__find__string__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value findany(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__findany__array__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value findcover(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__findcover__object__array__ret__object(leftGameValue, rightGameValue);
}
public static Value findeditorobject(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__findeditorobject__control__array__ret__string(leftGameValue, rightGameValue);
}
public static Value findeditorobject(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__findeditorobject__control__any__ret__string(leftGameValue, rightGameValue);
}
public static Value findemptyposition(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__findemptyposition__array__array__ret__array(leftGameValue, rightGameValue);
}
public static Value findemptypositionready(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__findemptypositionready__array__array__ret__bool(leftGameValue, rightGameValue);
}
public static Value findif(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__findif__array__code__ret__scalar(leftGameValue, rightGameValue);
}
public static Value findnearestenemy(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__findnearestenemy__object__object_array__ret__object(leftGameValue, rightGameValue);
}
public static void fire(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__fire__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void fire(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__fire__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value fireattarget(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__fireattarget__object__array__ret__bool(leftGameValue, rightGameValue);
}
public static void flyinheight(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__flyinheight__object__scalar_array__ret__nothing(leftGameValue, rightGameValue);
}
public static void flyinheightasl(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__flyinheightasl__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void forceadduniform(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__forceadduniform__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void forceflagtexture(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__forceflagtexture__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void forcefollowroad(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__forcefollowroad__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void forcespeed(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__forcespeed__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void forcewalk(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__forcewalk__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void forceweaponfire(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__forceweaponfire__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void foreach (Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__foreach__code__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value foreach (Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__foreach__code__hashmap__ret__any(leftGameValue, rightGameValue);
}
public static void foreachmember(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__foreachmember__code__team_member__ret__nothing(leftGameValue, rightGameValue);
}
public static void foreachmemberagent(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__foreachmemberagent__code__team_member__ret__nothing(leftGameValue, rightGameValue);
}
public static void foreachmemberteam(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__foreachmemberteam__code__team_member__ret__nothing(leftGameValue, rightGameValue);
}
public static void foreachreversed(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__foreachreversed__code__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void forgettarget(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__forgettarget__object_group__object__ret__nothing(leftGameValue, rightGameValue);
}
public static Value from(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__from__for__scalar__ret__for(leftGameValue, rightGameValue);
}
public static Value get(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__get__hashmap__side_config__ret__any(leftGameValue, rightGameValue);
}
public static Value get3denattribute(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__get3denattribute__object__string__ret__array(leftGameValue, rightGameValue);
}
public static Value get3denattribute(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__get3denattribute__group__string__ret__array(leftGameValue, rightGameValue);
}
public static Value get3denattribute(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__get3denattribute__array__string__ret__array(leftGameValue, rightGameValue);
}
public static Value get3denattribute(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__get3denattribute__string__string__ret__array(leftGameValue, rightGameValue);
}
public static Value get3denattribute(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__get3denattribute__scalar__string__ret__array(leftGameValue, rightGameValue);
}
public static Value get3denmissionattribute(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__get3denmissionattribute__string__string__ret__any(leftGameValue, rightGameValue);
}
public static Value getartilleryeta(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getartilleryeta__object__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value getcargoindex(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getcargoindex__object__object__ret__scalar(leftGameValue, rightGameValue);
}
public static Value getcompatiblepylonmagazines(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getcompatiblepylonmagazines__object__string_scalar__ret__array(leftGameValue, rightGameValue);
}
public static Value getcompatiblepylonmagazines(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getcompatiblepylonmagazines__string__string_scalar__ret__array(leftGameValue, rightGameValue);
}
public static Value getdir(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getdir__object_array__object_array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value getdirvisual(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getdirvisual__object_array__object_array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value geteditorobjectscope(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__geteditorobjectscope__control__string__ret__string(leftGameValue, rightGameValue);
}
public static Value getenv3dsoundcontroller(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getenv3dsoundcontroller__object__string__ret__scalar(leftGameValue, rightGameValue);
}
public static Value getenvsoundcontroller(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getenvsoundcontroller__array__string__ret__scalar(leftGameValue, rightGameValue);
}
public static Value geteventhandlerinfo(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__geteventhandlerinfo__object_group__array__ret__array(leftGameValue, rightGameValue);
}
public static Value getfriend(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getfriend__side__side__ret__scalar(leftGameValue, rightGameValue);
}
public static Value getfsmvariable(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getfsmvariable__scalar__string_array__ret__any(leftGameValue, rightGameValue);
}
public static Value getgroupicon(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getgroupicon__group__scalar__ret__array(leftGameValue, rightGameValue);
}
public static Value gethidefrom(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__gethidefrom__object__object__ret__array(leftGameValue, rightGameValue);
}
public static Value gethit(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__gethit__object__string__ret__scalar(leftGameValue, rightGameValue);
}
public static Value gethitindex(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__gethitindex__object__scalar__ret__scalar(leftGameValue, rightGameValue);
}
public static Value gethitpointdamage(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__gethitpointdamage__object__string__ret__scalar(leftGameValue, rightGameValue);
}
public static Value getobjectargument(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getobjectargument__control__array__ret__string(leftGameValue, rightGameValue);
}
public static Value getobjectchildren(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getobjectchildren__control__string__ret__array(leftGameValue, rightGameValue);
}
public static Value getobjectproxy(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getobjectproxy__control__string__ret__object(leftGameValue, rightGameValue);
}
public static Value getopticsmode(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getopticsmode__object__scalar__ret__string(leftGameValue, rightGameValue);
}
public static Value getordefault(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getordefault__hashmap__array__ret__any(leftGameValue, rightGameValue);
}
public static Value getordefaultcall(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getordefaultcall__hashmap__array__ret__any(leftGameValue, rightGameValue);
}
public static Value getpos(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getpos__object_array__array__ret__array(leftGameValue, rightGameValue);
}
public static Value getreldir(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getreldir__object__object_array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value getrelpos(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getrelpos__object__array__ret__array(leftGameValue, rightGameValue);
}
public static Value getrelpos(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getrelpos__object__object__ret__array(leftGameValue, rightGameValue);
}
public static Value getslotitemname(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getslotitemname__object__scalar__ret__string(leftGameValue, rightGameValue);
}
public static Value getsoundcontroller(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getsoundcontroller__object__string__ret__scalar(leftGameValue, rightGameValue);
}
public static Value getsoundcontrollerresult(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getsoundcontrollerresult__object__config__ret__scalar(leftGameValue, rightGameValue);
}
public static Value getspeed(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getspeed__object__string__ret__scalar(leftGameValue, rightGameValue);
}
public static Value gettextwidth(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__gettextwidth__string__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value getturretlimits(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getturretlimits__object__array__ret__array(leftGameValue, rightGameValue);
}
public static void getturretopticsmode(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__getturretopticsmode__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value getunittrait(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getunittrait__object__string__ret__nothing_bool(leftGameValue, rightGameValue);
}
public static Value getvariable(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getvariable__display__string_array__ret__any(leftGameValue, rightGameValue);
}
public static Value getvariable(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getvariable__control__string_array__ret__any(leftGameValue, rightGameValue);
}
public static Value getvariable(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getvariable__object__string__ret__any(leftGameValue, rightGameValue);
}
public static Value getvariable(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getvariable__object__array__ret__any(leftGameValue, rightGameValue);
}
public static Value getvariable(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getvariable__group__string__ret__any(leftGameValue, rightGameValue);
}
public static Value getvariable(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getvariable__group__array__ret__any(leftGameValue, rightGameValue);
}
public static Value getvariable(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getvariable__namespace__string__ret__any(leftGameValue, rightGameValue);
}
public static Value getvariable(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getvariable__namespace__array__ret__any(leftGameValue, rightGameValue);
}
public static Value getvariable(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getvariable__team_member__string__ret__any(leftGameValue, rightGameValue);
}
public static Value getvariable(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getvariable__team_member__array__ret__any(leftGameValue, rightGameValue);
}
public static Value getvariable(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getvariable__task__string__ret__any(leftGameValue, rightGameValue);
}
public static Value getvariable(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getvariable__task__array__ret__any(leftGameValue, rightGameValue);
}
public static Value getvariable(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getvariable__location__string__ret__any(leftGameValue, rightGameValue);
}
public static Value getvariable(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__getvariable__location__array__ret__any(leftGameValue, rightGameValue);
}
public static void glanceat(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__glanceat__object_array__object_array__ret__nothing(leftGameValue, rightGameValue);
}
public static void globalchat(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__globalchat__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void globalradio(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__globalradio__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void groupchat(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__groupchat__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void groupradio(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__groupradio__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void groupselectunit(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__groupselectunit__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value hasweapon(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__hasweapon__object__string__ret__bool(leftGameValue, rightGameValue);
}
public static Value hcgroupparams(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__hcgroupparams__object__group__ret__array(leftGameValue, rightGameValue);
}
public static void hcremovegroup(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__hcremovegroup__object__group__ret__nothing(leftGameValue, rightGameValue);
}
public static void hcselectgroup(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__hcselectgroup__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void hcsetgroup(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__hcsetgroup__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void hideobject(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__hideobject__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void hideobjectglobal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__hideobjectglobal__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void hideselection(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__hideselection__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void hintc(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__hintc__string__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void hintc(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__hintc__string__text__ret__nothing(leftGameValue, rightGameValue);
}
public static void hintc(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__hintc__string__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void htmlload(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__htmlload__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value in(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__in__any__array__ret__bool(leftGameValue, rightGameValue);
}
public static Value in(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__in__string__string__ret__bool(leftGameValue, rightGameValue);
}
public static Value in(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__in__object__object__ret__bool(leftGameValue, rightGameValue);
}
public static Value in(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__in__side_config__hashmap__ret__bool(leftGameValue, rightGameValue);
}
public static Value in(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__in__array__location__ret__bool(leftGameValue, rightGameValue);
}
public static Value inarea(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__inarea__object_array__object__ret__bool(leftGameValue, rightGameValue);
}
public static Value inarea(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__inarea__object_array__string__ret__bool(leftGameValue, rightGameValue);
}
public static Value inarea(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__inarea__object_array__array__ret__bool(leftGameValue, rightGameValue);
}
public static Value inarea(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__inarea__object__location__ret__bool(leftGameValue, rightGameValue);
}
public static Value inarea(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__inarea__array__location__ret__bool(leftGameValue, rightGameValue);
}
public static Value inareaarray(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__inareaarray__array__object__ret__array(leftGameValue, rightGameValue);
}
public static Value inareaarray(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__inareaarray__array__string__ret__array(leftGameValue, rightGameValue);
}
public static Value inareaarray(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__inareaarray__array__array__ret__array(leftGameValue, rightGameValue);
}
public static Value inareaarray(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__inareaarray__array__location__ret__array(leftGameValue, rightGameValue);
}
public static Value inareaarrayindexes(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__inareaarrayindexes__array__object__ret__array(leftGameValue, rightGameValue);
}
public static Value inareaarrayindexes(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__inareaarrayindexes__array__string__ret__array(leftGameValue, rightGameValue);
}
public static Value inareaarrayindexes(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__inareaarrayindexes__array__array__ret__array(leftGameValue, rightGameValue);
}
public static Value inareaarrayindexes(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__inareaarrayindexes__array__location__ret__array(leftGameValue, rightGameValue);
}
public static void inflame(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__inflame__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static Value infopanelcomponentenabled(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__infopanelcomponentenabled__object_array__array__ret__bool(leftGameValue, rightGameValue);
}
public static Value infopanelcomponents(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__infopanelcomponents__object_array__string__ret__array(leftGameValue, rightGameValue);
}
public static Value inpolygon(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__inpolygon__object_array__array__ret__bool(leftGameValue, rightGameValue);
}
public static Value inrangeofartillery(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__inrangeofartillery__array__array__ret__bool(leftGameValue, rightGameValue);
}
public static void insert(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__insert__array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value insert(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__insert__string__array__ret__string(leftGameValue, rightGameValue);
}
public static void insert(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__insert__hashmap__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value inserteditorobject(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__inserteditorobject__control__array__ret__string(leftGameValue, rightGameValue);
}
public static Value intersect(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__intersect__array__array__ret__array(leftGameValue, rightGameValue);
}
public static Value isequalref(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__isequalref__any__any__ret__bool(leftGameValue, rightGameValue);
}
public static Value isequalto(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__isequalto__any__any__ret__bool(leftGameValue, rightGameValue);
}
public static Value isequaltype(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__isequaltype__any__any__ret__bool(leftGameValue, rightGameValue);
}
public static Value isequaltypeall(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__isequaltypeall__any__any__ret__bool(leftGameValue, rightGameValue);
}
public static Value isequaltypeany(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__isequaltypeany__any__array__ret__bool(leftGameValue, rightGameValue);
}
public static Value isequaltypearray(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__isequaltypearray__any__array__ret__bool(leftGameValue, rightGameValue);
}
public static Value isequaltypeparams(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__isequaltypeparams__any__array__ret__bool(leftGameValue, rightGameValue);
}
public static Value isflashlighton(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__isflashlighton__object__string__ret__bool(leftGameValue, rightGameValue);
}
public static Value isflatempty(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__isflatempty__array__array__ret__array(leftGameValue, rightGameValue);
}
public static Value isirlaseron(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__isirlaseron__object__string__ret__bool(leftGameValue, rightGameValue);
}
public static Value iskindof(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__iskindof__string__string__ret__bool(leftGameValue, rightGameValue);
}
public static Value iskindof(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__iskindof__string__array__ret__bool(leftGameValue, rightGameValue);
}
public static Value iskindof(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__iskindof__object__string__ret__bool(leftGameValue, rightGameValue);
}
public static Value islaseron(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__islaseron__object__array__ret__bool(leftGameValue, rightGameValue);
}
public static Value isnotequalref(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__isnotequalref__any__any__ret__bool(leftGameValue, rightGameValue);
}
public static Value isnotequalto(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__isnotequalto__any__any__ret__bool(leftGameValue, rightGameValue);
}
public static Value issensortargetconfirmed(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__issensortargetconfirmed__object__side__ret__bool(leftGameValue, rightGameValue);
}
public static Value isuavconnectable(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__isuavconnectable__object__array__ret__bool(leftGameValue, rightGameValue);
}
public static Value isuniformallowed(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__isuniformallowed__object__string__ret__bool(leftGameValue, rightGameValue);
}
public static Value isvehiclesensorenabled(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__isvehiclesensorenabled__object__string__ret__array(leftGameValue, rightGameValue);
}
public static void join(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__join__array__object_group__ret__nothing(leftGameValue, rightGameValue);
}
public static void joinas(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__joinas__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void joinassilent(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__joinassilent__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void joinsilent(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__joinsilent__array__object_group__ret__nothing(leftGameValue, rightGameValue);
}
public static Value joinstring(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__joinstring__array__string__ret__string(leftGameValue, rightGameValue);
}
public static Value kbadddatabase(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__kbadddatabase__object__string__ret__bool(leftGameValue, rightGameValue);
}
public static Value kbadddatabasetargets(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__kbadddatabasetargets__object__string__ret__bool(leftGameValue, rightGameValue);
}
public static void kbaddtopic(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__kbaddtopic__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value kbhastopic(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__kbhastopic__object__string__ret__bool(leftGameValue, rightGameValue);
}
public static void kbreact(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__kbreact__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void kbremovetopic(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__kbremovetopic__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void kbtell(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__kbtell__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value kbwassaid(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__kbwassaid__object__array__ret__bool(leftGameValue, rightGameValue);
}
public static Value knowsabout(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__knowsabout__object_group__object__ret__scalar(leftGameValue, rightGameValue);
}
public static Value knowsabout(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__knowsabout__side__object__ret__scalar(leftGameValue, rightGameValue);
}
public static void land(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__land__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void landat(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__landat__object__object_scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static Value lasertarget(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lasertarget__object__array__ret__object(leftGameValue, rightGameValue);
}
public static Value lbadd(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lbadd__control__string__ret__scalar(leftGameValue, rightGameValue);
}
public static Value lbcolor(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lbcolor__control__scalar__ret__array(leftGameValue, rightGameValue);
}
public static Value lbcolorright(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lbcolorright__control__scalar__ret__array(leftGameValue, rightGameValue);
}
public static Value lbdata(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lbdata__control__scalar__ret__string(leftGameValue, rightGameValue);
}
public static void lbdelete(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbdelete__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static Value lbisselected(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lbisselected__control__scalar__ret__bool(leftGameValue, rightGameValue);
}
public static Value lbpicture(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lbpicture__control__scalar__ret__string(leftGameValue, rightGameValue);
}
public static Value lbpictureright(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lbpictureright__control__scalar__ret__string(leftGameValue, rightGameValue);
}
public static void lbsetcolor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsetcolor__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsetcolorright(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsetcolorright__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsetcursel(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsetcursel__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsetdata(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsetdata__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsetpicture(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsetpicture__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsetpicturecolor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsetpicturecolor__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsetpicturecolordisabled(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsetpicturecolordisabled__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsetpicturecolorselected(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsetpicturecolorselected__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsetpictureright(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsetpictureright__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsetpicturerightcolor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsetpicturerightcolor__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsetpicturerightcolordisabled(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsetpicturerightcolordisabled__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsetpicturerightcolorselected(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsetpicturerightcolorselected__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsetselectcolor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsetselectcolor__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsetselectcolorright(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsetselectcolorright__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsetselected(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsetselected__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsettext(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsettext__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsettextright(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsettextright__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsettooltip(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsettooltip__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsetvalue(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsetvalue__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lbsortby(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lbsortby__control_scalar__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value lbtext(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lbtext__control__scalar__ret__string(leftGameValue, rightGameValue);
}
public static Value lbtextright(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lbtextright__control__scalar__ret__string(leftGameValue, rightGameValue);
}
public static Value lbtooltip(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lbtooltip__control__scalar__ret__string(leftGameValue, rightGameValue);
}
public static Value lbvalue(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lbvalue__control__scalar__ret__scalar(leftGameValue, rightGameValue);
}
public static void leavevehicle(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__leavevehicle__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void leavevehicle(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__leavevehicle__group__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void lightattachobject(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lightattachobject__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void limitspeed(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__limitspeed__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void linkitem(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__linkitem__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value listobjects(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__listobjects__control__string__ret__array(leftGameValue, rightGameValue);
}
public static Value lnbaddcolumn(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lnbaddcolumn__control__scalar__ret__scalar(leftGameValue, rightGameValue);
}
public static Value lnbaddrow(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lnbaddrow__control__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value lnbcolor(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lnbcolor__control__array__ret__array(leftGameValue, rightGameValue);
}
public static Value lnbcolorright(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lnbcolorright__control__array__ret__array(leftGameValue, rightGameValue);
}
public static Value lnbdata(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lnbdata__control__array__ret__string(leftGameValue, rightGameValue);
}
public static void lnbdeletecolumn(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbdeletecolumn__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void lnbdeleterow(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbdeleterow__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static Value lnbpicture(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lnbpicture__control__array__ret__string(leftGameValue, rightGameValue);
}
public static Value lnbpictureright(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lnbpictureright__control__array__ret__string(leftGameValue, rightGameValue);
}
public static void lnbsetcolor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbsetcolor__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lnbsetcolorright(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbsetcolorright__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lnbsetcolumnspos(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbsetcolumnspos__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lnbsetcurselrow(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbsetcurselrow__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void lnbsetdata(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbsetdata__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lnbsetpicture(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbsetpicture__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lnbsetpicturecolor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbsetpicturecolor__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lnbsetpicturecolorright(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbsetpicturecolorright__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lnbsetpicturecolorselected(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbsetpicturecolorselected__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lnbsetpicturecolorselectedright(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbsetpicturecolorselectedright__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lnbsetpictureright(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbsetpictureright__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lnbsettext(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbsettext__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lnbsettextright(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbsettextright__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lnbsettooltip(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbsettooltip__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lnbsetvalue(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbsetvalue__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lnbsort(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbsort__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lnbsortby(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbsortby__array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lnbsortbyvalue(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lnbsortbyvalue__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value lnbtext(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lnbtext__control__array__ret__string(leftGameValue, rightGameValue);
}
public static Value lnbtextright(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lnbtextright__control__array__ret__string(leftGameValue, rightGameValue);
}
public static Value lnbvalue(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lnbvalue__control__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value loadidentity(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__loadidentity__object__string__ret__bool(leftGameValue, rightGameValue);
}
public static void loadmagazine(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__loadmagazine__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void loadoverlay(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__loadoverlay__control__config__ret__nothing(leftGameValue, rightGameValue);
}
public static Value loadstatus(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__loadstatus__object__string__ret__bool(leftGameValue, rightGameValue);
}
public static void lock (Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lock__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void lock (Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lock__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void lockcamerato(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lockcamerato__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lockcargo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lockcargo__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lockcargo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lockcargo__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void lockdriver(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lockdriver__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static Value lockedcamerato(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lockedcamerato__object__array__ret__nothing_object(leftGameValue, rightGameValue);
}
public static Value lockedcargo(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lockedcargo__object__scalar__ret__bool(leftGameValue, rightGameValue);
}
public static Value lockedturret(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__lockedturret__object__array__ret__bool(leftGameValue, rightGameValue);
}
public static void lockinventory(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lockinventory__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void lockturret(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lockturret__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lockwp(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lockwp__object_group__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void lookat(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lookat__object_array__object_array__ret__nothing(leftGameValue, rightGameValue);
}
public static void lookatpos(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__lookatpos__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value magazinesturret(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__magazinesturret__object__array__ret__array(leftGameValue, rightGameValue);
}
public static Value magazineturretammo(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__magazineturretammo__object__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value mapcenteroncamera(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__mapcenteroncamera__control__bool__ret__array(leftGameValue, rightGameValue);
}
public static Value matrixmultiply(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__matrixmultiply__array__array__ret__array(leftGameValue, rightGameValue);
}
public static Value max(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__max__scalar_nan__scalar_nan__ret__scalar_nan(leftGameValue, rightGameValue);
}
public static Value menuaction(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__menuaction__control__array__ret__string(leftGameValue, rightGameValue);
}
public static Value menuadd(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__menuadd__control__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value menuchecked(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__menuchecked__control__array__ret__bool(leftGameValue, rightGameValue);
}
public static void menucollapse(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__menucollapse__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value menudata(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__menudata__control__array__ret__string(leftGameValue, rightGameValue);
}
public static void menudelete(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__menudelete__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void menuenable(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__menuenable__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value menuenabled(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__menuenabled__control__array__ret__bool(leftGameValue, rightGameValue);
}
public static void menuexpand(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__menuexpand__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value menupicture(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__menupicture__control__array__ret__string(leftGameValue, rightGameValue);
}
public static void menusetaction(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__menusetaction__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void menusetcheck(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__menusetcheck__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void menusetdata(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__menusetdata__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void menusetpicture(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__menusetpicture__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void menusetshortcut(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__menusetshortcut__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void menusettext(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__menusettext__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void menuseturl(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__menuseturl__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void menusetvalue(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__menusetvalue__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value menushortcut(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__menushortcut__control__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value menushortcuttext(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__menushortcuttext__control__array__ret__string(leftGameValue, rightGameValue);
}
public static Value menusize(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__menusize__control__array__ret__scalar(leftGameValue, rightGameValue);
}
public static void menusort(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__menusort__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value menutext(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__menutext__control__array__ret__string(leftGameValue, rightGameValue);
}
public static Value menuurl(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__menuurl__control__array__ret__string(leftGameValue, rightGameValue);
}
public static Value menuvalue(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__menuvalue__control__array__ret__scalar(leftGameValue, rightGameValue);
}
public static void merge(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__merge__hashmap__hashmap_array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value min(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__min__scalar_nan__scalar_nan__ret__scalar_nan(leftGameValue, rightGameValue);
}
public static Value minedetectedby(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__minedetectedby__object__side__ret__bool(leftGameValue, rightGameValue);
}
public static Value mod(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__mod__scalar_nan__scalar_nan__ret__scalar_nan(leftGameValue, rightGameValue);
}
public static Value modeltoworld(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__modeltoworld__object__array__ret__array(leftGameValue, rightGameValue);
}
public static Value modeltoworldvisual(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__modeltoworldvisual__object__array__ret__array(leftGameValue, rightGameValue);
}
public static Value modeltoworldvisualworld(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__modeltoworldvisualworld__object__array__ret__array(leftGameValue, rightGameValue);
}
public static Value modeltoworldworld(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__modeltoworldworld__object__array__ret__array(leftGameValue, rightGameValue);
}
public static void move(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__move__object_group__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value moveinany(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__moveinany__object__object__ret__bool(leftGameValue, rightGameValue);
}
public static void moveincargo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__moveincargo__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void moveincargo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__moveincargo__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void moveincommander(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__moveincommander__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void moveindriver(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__moveindriver__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void moveingunner(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__moveingunner__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void moveinturret(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__moveinturret__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void moveobjecttoend(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__moveobjecttoend__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void moveout(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__moveout__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void moveto(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__moveto__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value namedproperties(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__namedproperties__object__array__ret__hashmap(leftGameValue, rightGameValue);
}
public static Value nearentities(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__nearentities__object_array__scalar_array__ret__array(leftGameValue, rightGameValue);
}
public static Value nearestobject(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__nearestobject__array__string__ret__object(leftGameValue, rightGameValue);
}
public static Value nearestobject(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__nearestobject__array__scalar__ret__object(leftGameValue, rightGameValue);
}
public static Value nearobjects(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__nearobjects__object_array__scalar_array__ret__array(leftGameValue, rightGameValue);
}
public static Value nearobjectsready(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__nearobjectsready__object_array__scalar__ret__bool(leftGameValue, rightGameValue);
}
public static Value nearroads(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__nearroads__object_array__scalar__ret__array(leftGameValue, rightGameValue);
}
public static Value nearsupplies(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__nearsupplies__object_array__scalar_array__ret__array(leftGameValue, rightGameValue);
}
public static Value neartargets(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__neartargets__object__scalar__ret__array(leftGameValue, rightGameValue);
}
public static void newoverlay(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__newoverlay__control__config__ret__nothing(leftGameValue, rightGameValue);
}
public static Value nmenuitems(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__nmenuitems__control__string_scalar__ret__scalar(leftGameValue, rightGameValue);
}
public static void objstatus(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__objstatus__string__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value ondoubleclick(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__ondoubleclick__control__string__ret__any(leftGameValue, rightGameValue);
}
public static void onmapsingleclick(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__onmapsingleclick__any__code_string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value onshownewobject(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__onshownewobject__control__string__ret__any(leftGameValue, rightGameValue);
}
public static Value or(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__or__bool__bool__ret__bool(leftGameValue, rightGameValue);
}
public static Value or(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__or__bool__code__ret__bool(leftGameValue, rightGameValue);
}
public static void ordergetin(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ordergetin__array__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static Value param(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__param__any__array__ret__any(leftGameValue, rightGameValue);
}
public static Value params(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__params__any__array__ret__bool(leftGameValue, rightGameValue);
}
public static void periscopeelevation(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__periscopeelevation__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void playaction(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__playaction__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void playactionnow(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__playactionnow__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void playgesture(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__playgesture__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void playmove(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__playmove__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void playmovenow(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__playmovenow__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value posscreentoworld(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__posscreentoworld__control__array__ret__array(leftGameValue, rightGameValue);
}
public static Value posworldtoscreen(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__posworldtoscreen__control__array__ret__array(leftGameValue, rightGameValue);
}
public static void ppeffectadjust(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ppeffectadjust__string__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ppeffectadjust(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ppeffectadjust__scalar__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void ppeffectcommit(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ppeffectcommit__string__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ppeffectcommit(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ppeffectcommit__scalar__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ppeffectcommit(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ppeffectcommit__array__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void ppeffectenable(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ppeffectenable__string__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void ppeffectenable(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ppeffectenable__array__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void ppeffectenable(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ppeffectenable__scalar__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void ppeffectforceinnvg(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ppeffectforceinnvg__scalar__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static Value preloadobject(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__preloadobject__scalar__object_string__ret__bool(leftGameValue, rightGameValue);
}
public static void progresssetposition(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__progresssetposition__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void publicvariableclient(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__publicvariableclient__scalar__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value pushback(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__pushback__array__any__ret__scalar(leftGameValue, rightGameValue);
}
public static Value pushbackunique(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__pushbackunique__array__any__ret__scalar(leftGameValue, rightGameValue);
}
public static void radiochanneladd(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__radiochanneladd__scalar__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void radiochannelremove(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__radiochannelremove__scalar__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void radiochannelsetcallsign(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__radiochannelsetcallsign__scalar__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void radiochannelsetlabel(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__radiochannelsetlabel__scalar__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value random(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__random__scalar__scalar_array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value regexfind(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__regexfind__string__array__ret__array(leftGameValue, rightGameValue);
}
public static Value regexmatch(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__regexmatch__string__string__ret__bool(leftGameValue, rightGameValue);
}
public static Value regexreplace(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__regexreplace__string__array__ret__string(leftGameValue, rightGameValue);
}
public static Value registertask(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__registertask__team_member__string__ret__bool(leftGameValue, rightGameValue);
}
public static Value reload(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__reload__object__array__ret__bool(leftGameValue, rightGameValue);
}
public static void remotecontrol(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__remotecontrol__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static Value remoteexec(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__remoteexec__any__array__ret__string_nothing(leftGameValue, rightGameValue);
}
public static Value remoteexeccall(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__remoteexeccall__any__array__ret__string_nothing(leftGameValue, rightGameValue);
}
public static void removeaction(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removeaction__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void removealleventhandlers(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removealleventhandlers__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void removealleventhandlers(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removealleventhandlers__group__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void removeallmpeventhandlers(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removeallmpeventhandlers__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void removebinocularitem(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removebinocularitem__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void removecuratoraddons(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removecuratoraddons__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void removecuratorcameraarea(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removecuratorcameraarea__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void removecuratoreditableobjects(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removecuratoreditableobjects__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void removecuratoreditingarea(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removecuratoreditingarea__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void removediaryrecord(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removediaryrecord__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void removediarysubject(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removediarysubject__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void removedrawicon(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removedrawicon__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void removedrawlinks(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removedrawlinks__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void removeeventhandler(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removeeventhandler__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void removeeventhandler(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removeeventhandler__group__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void removegroupicon(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removegroupicon__group__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void removehandgunitem(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removehandgunitem__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void removeitem(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removeitem__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void removeitemfrombackpack(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removeitemfrombackpack__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void removeitemfromuniform(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removeitemfromuniform__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void removeitemfromvest(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removeitemfromvest__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void removeitems(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removeitems__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void removemagazine(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removemagazine__object__string_array__ret__nothing(leftGameValue, rightGameValue);
}
public static void removemagazineglobal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removemagazineglobal__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void removemagazines(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removemagazines__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void removemagazinesturret(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removemagazinesturret__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void removemagazineturret(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removemagazineturret__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void removemenuitem(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removemenuitem__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void removemenuitem(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removemenuitem__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void removempeventhandler(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removempeventhandler__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void removeownedmine(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removeownedmine__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void removeprimaryweaponitem(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removeprimaryweaponitem__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void removesecondaryweaponitem(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removesecondaryweaponitem__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void removesimpletask(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removesimpletask__object__task__ret__nothing(leftGameValue, rightGameValue);
}
public static void removeteammember(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removeteammember__team_member__team_member__ret__nothing(leftGameValue, rightGameValue);
}
public static void removeweapon(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removeweapon__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void removeweaponattachmentcargo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removeweaponattachmentcargo__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void removeweaponcargo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removeweaponcargo__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void removeweaponglobal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removeweaponglobal__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void removeweaponturret(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__removeweaponturret__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void reportremotetarget(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__reportremotetarget__side__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void resize(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__resize__array__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void resize(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__resize__array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void respawnvehicle(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__respawnvehicle__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void reveal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__reveal__object_group__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void reveal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__reveal__object_group__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void revealmine(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__revealmine__side__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void ropeattachto(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ropeattachto__object_array__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void ropedetach(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__ropedetach__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static Value saveidentity(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__saveidentity__object__string__ret__bool(leftGameValue, rightGameValue);
}
public static Value savestatus(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__savestatus__object__string__ret__bool(leftGameValue, rightGameValue);
}
public static void say(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__say__object_array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void say(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__say__object_array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void say2d(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__say2d__object_array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void say2d(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__say2d__object_array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value say3d(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__say3d__object_array__string__ret__object(leftGameValue, rightGameValue);
}
public static Value say3d(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__say3d__object_array__array__ret__object(leftGameValue, rightGameValue);
}
public static Value select(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__select__array__scalar__ret__any(leftGameValue, rightGameValue);
}
public static Value select(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__select__array__bool__ret__any(leftGameValue, rightGameValue);
}
public static Value select(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__select__array__array__ret__array(leftGameValue, rightGameValue);
}
public static Value select(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__select__array__code__ret__array(leftGameValue, rightGameValue);
}
public static Value select(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__select__config__scalar__ret__config(leftGameValue, rightGameValue);
}
public static Value select(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__select__string__array__ret__string(leftGameValue, rightGameValue);
}
public static Value selectdiarysubject(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__selectdiarysubject__object__string__ret__bool(leftGameValue, rightGameValue);
}
public static Value selecteditorobject(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__selecteditorobject__control__string__ret__any(leftGameValue, rightGameValue);
}
public static Value selectionnames(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__selectionnames__object__string_scalar__ret__array(leftGameValue, rightGameValue);
}
public static Value selectionposition(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__selectionposition__object__string__ret__array(leftGameValue, rightGameValue);
}
public static Value selectionposition(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__selectionposition__object__array__ret__array(leftGameValue, rightGameValue);
}
public static Value selectionvectordirandup(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__selectionvectordirandup__object__array__ret__array(leftGameValue, rightGameValue);
}
public static void selectleader(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__selectleader__group__object__ret__nothing(leftGameValue, rightGameValue);
}
public static Value selectrandomweighted(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__selectrandomweighted__array__array__ret__any(leftGameValue, rightGameValue);
}
public static void selectweapon(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__selectweapon__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value selectweapon(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__selectweapon__object__array__ret__bool_nothing(leftGameValue, rightGameValue);
}
public static void selectweaponturret(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__selectweaponturret__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void sendsimplecommand(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__sendsimplecommand__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value sendtask(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__sendtask__team_member__array__ret__task(leftGameValue, rightGameValue);
}
public static void sendtaskresult(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__sendtaskresult__task__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value servercommand(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__servercommand__string__string__ret__bool(leftGameValue, rightGameValue);
}
public static void set(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__set__array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value set(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__set__hashmap__array__ret__bool(leftGameValue, rightGameValue);
}
public static Value set3denattribute(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__set3denattribute__any__array__ret__bool(leftGameValue, rightGameValue);
}
public static Value set3denlayer(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__set3denlayer__any__scalar__ret__bool(leftGameValue, rightGameValue);
}
public static void set3denlogictype(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__set3denlogictype__array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void set3denmissionattribute(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__set3denmissionattribute__string__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void set3denobjecttype(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__set3denobjecttype__array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setactualcollectivertd(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setactualcollectivertd__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setairplanethrottle(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setairplanethrottle__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setairportside(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setairportside__object_scalar__side__ret__nothing(leftGameValue, rightGameValue);
}
public static void setammo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setammo__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setammocargo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setammocargo__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setammoonpylon(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setammoonpylon__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setanimspeedcoef(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setanimspeedcoef__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static Value setattributes(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__setattributes__text_string__array__ret__text(leftGameValue, rightGameValue);
}
public static Value setautonomous(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__setautonomous__object__bool__ret__bool(leftGameValue, rightGameValue);
}
public static void setbehaviour(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setbehaviour__object_group__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setbehaviourstrong(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setbehaviourstrong__object_group__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setbleedingremaining(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setbleedingremaining__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setbrakesrtd(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setbrakesrtd__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcamerainterest(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcamerainterest__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcamuseti(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcamuseti__bool__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcaptive(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcaptive__object__bool_scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcenterofmass(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcenterofmass__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcollisionlight(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcollisionlight__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcombatbehaviour(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcombatbehaviour__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcombatbehaviour(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcombatbehaviour__group__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcombatmode(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcombatmode__object_group__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcombatmode(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcombatmode__team_member__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setconvoyseparation(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setconvoyseparation__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcruisecontrol(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcruisecontrol__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcuratorcameraareaceiling(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcuratorcameraareaceiling__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcuratorcoef(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcuratorcoef__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcuratoreditingareatype(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcuratoreditingareatype__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcuratorselectionpreset(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcuratorselectionpreset__scalar__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcuratorwaypointcost(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcuratorwaypointcost__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcurrenttask(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcurrenttask__object__task__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcurrentwaypoint(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcurrentwaypoint__group__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcustomaimcoef(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcustomaimcoef__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setcustomweightrtd(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setcustomweightrtd__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setdamage(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setdamage__object__scalar_array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setdammage(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setdammage__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setdebriefingtext(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setdebriefingtext__string__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setdestination(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setdestination__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setdiaryrecordtext(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setdiaryrecordtext__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setdiarysubjectpicture(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setdiarysubjectpicture__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setdir(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setdir__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setdirection(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setdirection__location__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setdrawicon(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setdrawicon__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setdriveonpath(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setdriveonpath__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setdropinterval(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setdropinterval__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setdynamicsimulationdistance(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setdynamicsimulationdistance__string__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setdynamicsimulationdistancecoef(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setdynamicsimulationdistancecoef__string__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void seteditormode(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__seteditormode__control__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void seteditorobjectscope(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__seteditorobjectscope__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void seteffectcondition(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__seteffectcondition__object_array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void seteffectivecommander(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__seteffectivecommander__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void setenginerpmrtd(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setenginerpmrtd__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setface(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setface__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setfaceanimation(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setfaceanimation__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setfatigue(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setfatigue__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static Value setfeaturetype(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__setfeaturetype__object__scalar__ret__bool(leftGameValue, rightGameValue);
}
public static void setflaganimationphase(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setflaganimationphase__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setflagowner(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setflagowner__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void setflagside(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setflagside__object__side__ret__nothing(leftGameValue, rightGameValue);
}
public static void setflagtexture(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setflagtexture__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setfog(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setfog__scalar__scalar_array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setforcegeneratorrtd(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setforcegeneratorrtd__scalar__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setformation(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setformation__object_group__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setformation(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setformation__team_member__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setformationtask(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setformationtask__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setformdir(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setformdir__object_group__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setfriend(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setfriend__side__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setfromeditor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setfromeditor__team_member__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void setfsmvariable(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setfsmvariable__scalar__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setfuel(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setfuel__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setfuelcargo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setfuelcargo__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setgroupicon(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setgroupicon__group__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setgroupiconparams(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setgroupiconparams__group__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setgroupid(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setgroupid__object_group__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setgroupidglobal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setgroupidglobal__object_group__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value setgroupowner(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__setgroupowner__group__scalar__ret__bool(leftGameValue, rightGameValue);
}
public static void setgusts(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setgusts__scalar__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void sethidebehind(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__sethidebehind__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void sethit(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__sethit__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void sethitindex(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__sethitindex__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void sethitpointdamage(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__sethitpointdamage__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setidentity(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setidentity__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setimportance(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setimportance__location__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setleader(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setleader__team_member__team_member__ret__nothing(leftGameValue, rightGameValue);
}
public static void setlightambient(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setlightambient__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setlightattenuation(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setlightattenuation__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setlightbrightness(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setlightbrightness__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setlightcolor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setlightcolor__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setlightconepars(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setlightconepars__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setlightdaylight(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setlightdaylight__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void setlightflaremaxdistance(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setlightflaremaxdistance__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setlightflaresize(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setlightflaresize__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setlightintensity(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setlightintensity__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setlightir(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setlightir__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void setlightnings(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setlightnings__scalar__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setlightuseflare(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setlightuseflare__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void setlightvolumeshape(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setlightvolumeshape__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmagazineturretammo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmagazineturretammo__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkeralpha(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkeralpha__string__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkeralphalocal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkeralphalocal__string__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkerbrush(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkerbrush__string__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkerbrushlocal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkerbrushlocal__string__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkercolor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkercolor__string__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkercolorlocal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkercolorlocal__string__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkerdir(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkerdir__string__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkerdirlocal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkerdirlocal__string__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkerdrawpriority(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkerdrawpriority__string__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkerpolyline(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkerpolyline__string__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkerpolylinelocal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkerpolylinelocal__string__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkerpos(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkerpos__string__object_array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkerposlocal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkerposlocal__string__object_array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkershadow(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkershadow__string__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkershadowlocal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkershadowlocal__string__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkershape(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkershape__string__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkershapelocal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkershapelocal__string__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkersize(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkersize__string__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkersizelocal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkersizelocal__string__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkertext(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkertext__string__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkertextlocal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkertextlocal__string__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkertype(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkertype__string__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmarkertypelocal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmarkertypelocal__string__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmass(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmass__object__scalar_array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmaxload(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmaxload__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmimic(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmimic__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value setmissiletarget(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__setmissiletarget__object__object__ret__bool(leftGameValue, rightGameValue);
}
public static void setmissiletargetpos(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmissiletargetpos__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setmusiceffect(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setmusiceffect__object_array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setname(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setname__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setname(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setname__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setname(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setname__location__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setnamesound(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setnamesound__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value setobjectarguments(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__setobjectarguments__control__array__ret__any(leftGameValue, rightGameValue);
}
public static void setobjectmaterial(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setobjectmaterial__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setobjectmaterialglobal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setobjectmaterialglobal__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value setobjectproxy(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__setobjectproxy__control__array__ret__any(leftGameValue, rightGameValue);
}
public static void setobjectscale(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setobjectscale__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setobjecttexture(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setobjecttexture__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setobjecttextureglobal(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setobjecttextureglobal__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setopticsmode(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setopticsmode__object__array_string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setovercast(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setovercast__scalar__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static Value setowner(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__setowner__object__scalar__ret__bool(leftGameValue, rightGameValue);
}
public static void setoxygenremaining(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setoxygenremaining__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setparticlecircle(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setparticlecircle__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setparticleclass(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setparticleclass__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setparticlefire(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setparticlefire__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setparticleparams(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setparticleparams__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setparticlerandom(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setparticlerandom__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setpilotcameradirection(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setpilotcameradirection__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value setpilotcameraopticsmode(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__setpilotcameraopticsmode__object__scalar__ret__bool(leftGameValue, rightGameValue);
}
public static void setpilotcamerarotation(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setpilotcamerarotation__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value setpilotcameratarget(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__setpilotcameratarget__object__object_array__ret__bool(leftGameValue, rightGameValue);
}
public static void setpilotlight(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setpilotlight__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void setpipeffect(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setpipeffect__string__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setpitch(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setpitch__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setplatenumber(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setplatenumber__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setplayervonvolume(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setplayervonvolume__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setpos(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setpos__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setposasl(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setposasl__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setposasl2(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setposasl2__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setposaslw(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setposaslw__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setposatl(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setposatl__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setposition(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setposition__location__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setposworld(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setposworld__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value setpylonloadout(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__setpylonloadout__object__array__ret__bool(leftGameValue, rightGameValue);
}
public static void setpylonspriority(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setpylonspriority__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setradiomsg(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setradiomsg__scalar__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setrain(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setrain__scalar__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setrainbow(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setrainbow__scalar__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setrandomlip(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setrandomlip__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void setrank(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setrank__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setrectangular(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setrectangular__location__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void setrepaircargo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setrepaircargo__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setrotorbrakertd(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setrotorbrakertd__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setshotparents(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setshotparents__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setside(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setside__location__side__ret__nothing(leftGameValue, rightGameValue);
}
public static void setsimpletaskalwaysvisible(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setsimpletaskalwaysvisible__task__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void setsimpletaskcustomdata(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setsimpletaskcustomdata__task__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setsimpletaskdescription(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setsimpletaskdescription__task__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setsimpletaskdestination(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setsimpletaskdestination__task__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setsimpletasktarget(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setsimpletasktarget__task__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setsimpletasktype(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setsimpletasktype__task__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setsize(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setsize__location__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setskill(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setskill__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setskill(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setskill__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static Value setslingload(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__setslingload__object__object__ret__bool(leftGameValue, rightGameValue);
}
public static void setsoundeffect(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setsoundeffect__object_array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setspeaker(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setspeaker__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setspeech(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setspeech__location__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setspeedmode(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setspeedmode__object_group__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setstamina(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setstamina__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setsuppression(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setsuppression__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void settargetage(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__settargetage__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void settaskmarkeroffset(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__settaskmarkeroffset__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void settaskresult(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__settaskresult__task__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void settaskstate(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__settaskstate__task__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void settext(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__settext__location__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void settitleeffect(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__settitleeffect__object_array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void settowparent(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__settowparent__object__object__ret__nothing(leftGameValue, rightGameValue);
}
public static void settriggeractivation(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__settriggeractivation__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void settriggerarea(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__settriggerarea__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void settriggerinterval(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__settriggerinterval__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void settriggerstatements(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__settriggerstatements__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void settriggertext(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__settriggertext__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void settriggertimeout(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__settriggertimeout__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void settriggertype(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__settriggertype__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setturretlimits(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setturretlimits__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setturretopticsmode(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setturretopticsmode__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setturretopticsmode(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setturretopticsmode__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void settype(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__settype__location__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setunconscious(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setunconscious__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void setunitability(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setunitability__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setunitcombatmode(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setunitcombatmode__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setunitfreefallheight(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setunitfreefallheight__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setunitloadout(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setunitloadout__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setunitloadout(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setunitloadout__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setunitloadout(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setunitloadout__object__config__ret__nothing(leftGameValue, rightGameValue);
}
public static void setunitpos(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setunitpos__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setunitposweak(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setunitposweak__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setunitrank(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setunitrank__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setunitrecoilcoefficient(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setunitrecoilcoefficient__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setunittrait(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setunittrait__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setunloadincombat(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setunloadincombat__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setuseractiontext(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setuseractiontext__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setusermfdtext(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setusermfdtext__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setusermfdvalue(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setusermfdvalue__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvariable(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvariable__display__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvariable(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvariable__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvariable(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvariable__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvariable(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvariable__group__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvariable(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvariable__namespace__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvariable(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvariable__team_member__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvariable(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvariable__task__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvariable(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvariable__location__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvectordir(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvectordir__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvectordirandup(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvectordirandup__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvectorup(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvectorup__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvehicleammo(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvehicleammo__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvehicleammodef(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvehicleammodef__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvehiclearmor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvehiclearmor__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static Value setvehiclecargo(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__setvehiclecargo__object__object__ret__bool(leftGameValue, rightGameValue);
}
public static void setvehicleid(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvehicleid__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvehiclelock(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvehiclelock__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value setvehicleposition(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__setvehicleposition__object__array__ret__bool(leftGameValue, rightGameValue);
}
public static void setvehicleradar(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvehicleradar__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvehiclereceiveremotetargets(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvehiclereceiveremotetargets__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvehiclereportownposition(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvehiclereportownposition__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvehiclereportremotetargets(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvehiclereportremotetargets__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvehicletipars(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvehicletipars__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvehiclevarname(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvehiclevarname__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvelocity(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvelocity__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvelocitymodelspace(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvelocitymodelspace__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvelocitytransformation(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvelocitytransformation__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setvisibleiftreecollapsed(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setvisibleiftreecollapsed__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwantedrpmrtd(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwantedrpmrtd__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaves(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaves__scalar__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaypointbehaviour(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaypointbehaviour__array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaypointcombatmode(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaypointcombatmode__array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaypointcompletionradius(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaypointcompletionradius__array__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaypointdescription(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaypointdescription__array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaypointforcebehaviour(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaypointforcebehaviour__array__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaypointformation(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaypointformation__array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaypointhouseposition(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaypointhouseposition__array__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaypointloiteraltitude(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaypointloiteraltitude__array__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaypointloiterradius(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaypointloiterradius__array__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaypointloitertype(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaypointloitertype__array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaypointname(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaypointname__array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaypointposition(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaypointposition__array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaypointscript(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaypointscript__array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaypointspeed(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaypointspeed__array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaypointstatements(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaypointstatements__array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaypointtimeout(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaypointtimeout__array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaypointtype(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaypointtype__array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwaypointvisible(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwaypointvisible__array__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static Value setweaponreloadingtime(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__setweaponreloadingtime__object__array__ret__bool(leftGameValue, rightGameValue);
}
public static Value setweaponzeroing(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__setweaponzeroing__object__array__ret__bool(leftGameValue, rightGameValue);
}
public static void setwinddir(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwinddir__scalar__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwindforce(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwindforce__scalar__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwindstr(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwindstr__scalar__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwingforcescalertd(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwingforcescalertd__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void setwppos(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__setwppos__array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void show3dicons(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__show3dicons__control__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void showlegend(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__showlegend__control__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static Value showneweditorobject(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__showneweditorobject__control__array__ret__any(leftGameValue, rightGameValue);
}
public static void showwaypoint(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__showwaypoint__array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void sidechat(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__sidechat__object_array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void sideradio(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__sideradio__object_array__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value skill(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__skill__object__string__ret__scalar(leftGameValue, rightGameValue);
}
public static Value skillfinal(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__skillfinal__object__string__ret__scalar(leftGameValue, rightGameValue);
}
public static void slidersetposition(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__slidersetposition__control__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void slidersetrange(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__slidersetrange__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void slidersetspeed(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__slidersetspeed__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void sort(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__sort__array__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static Value spawn(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__spawn__any__code__ret__script(leftGameValue, rightGameValue);
}
public static Value splitstring(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__splitstring__string__string__ret__array(leftGameValue, rightGameValue);
}
public static Value step(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__step__for__scalar__ret__for(leftGameValue, rightGameValue);
}
public static void stop(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__stop__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static void suppressfor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__suppressfor__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void swimindepth(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__swimindepth__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void switchaction(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__switchaction__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void switchcamera(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__switchcamera__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void switchgesture(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__switchgesture__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void switchlight(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__switchlight__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void switchmove(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__switchmove__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void synchronizeobjectsadd(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__synchronizeobjectsadd__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void synchronizeobjectsremove(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__synchronizeobjectsremove__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void synchronizetrigger(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__synchronizetrigger__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void synchronizewaypoint(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__synchronizewaypoint__array__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void synchronizewaypoint(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__synchronizewaypoint__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value targetknowledge(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__targetknowledge__object__object__ret__array(leftGameValue, rightGameValue);
}
public static Value targets(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__targets__object__array__ret__array(leftGameValue, rightGameValue);
}
public static Value targets(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__targets__group__array__ret__array(leftGameValue, rightGameValue);
}
public static Value targetsaggregate(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__targetsaggregate__array__array__ret__array(leftGameValue, rightGameValue);
}
public static Value targetsquery(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__targetsquery__object__array__ret__array(leftGameValue, rightGameValue);
}
public static Value then(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__then__if__code__ret__any(leftGameValue, rightGameValue);
}
public static Value then(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__then__if__array__ret__any(leftGameValue, rightGameValue);
}
public static void throw (Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__throw__if__any__ret__nothing(leftGameValue, rightGameValue);
}
public static Value to(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__to__for__scalar__ret__for(leftGameValue, rightGameValue);
}
public static Value toarray(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__toarray__hashmap__bool__ret__array(leftGameValue, rightGameValue);
}
public static Value tofixed(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__tofixed__scalar__scalar__ret__string(leftGameValue, rightGameValue);
}
public static void triggerattachobject(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__triggerattachobject__object__scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void triggerattachvehicle(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__triggerattachvehicle__object__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void triggerdynamicsimulation(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__triggerdynamicsimulation__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static Value trim(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__trim__string__array__ret__string(leftGameValue, rightGameValue);
}
public static Value try(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__try__any__code__ret__exception(leftGameValue, rightGameValue);
}
public static Value turretlocal(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__turretlocal__object__array__ret__bool(leftGameValue, rightGameValue);
}
public static Value turretowner(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__turretowner__object__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value turretunit(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__turretunit__object__array__ret__object(leftGameValue, rightGameValue);
}
public static Value tvadd(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__tvadd__control__array__ret__scalar(leftGameValue, rightGameValue);
}
public static void tvcollapse(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvcollapse__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value tvcount(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__tvcount__control__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value tvdata(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__tvdata__control__array__ret__string(leftGameValue, rightGameValue);
}
public static void tvdelete(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvdelete__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvexpand(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvexpand__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value tvisselected(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__tvisselected__control__array__ret__bool(leftGameValue, rightGameValue);
}
public static Value tvpicture(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__tvpicture__control__array__ret__string(leftGameValue, rightGameValue);
}
public static Value tvpictureright(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__tvpictureright__control__array__ret__string(leftGameValue, rightGameValue);
}
public static void tvsetcolor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsetcolor__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsetcursel(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsetcursel__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsetdata(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsetdata__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsetpicture(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsetpicture__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsetpicturecolor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsetpicturecolor__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsetpicturecolordisabled(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsetpicturecolordisabled__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsetpicturecolorselected(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsetpicturecolorselected__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsetpictureright(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsetpictureright__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsetpicturerightcolor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsetpicturerightcolor__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsetpicturerightcolordisabled(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsetpicturerightcolordisabled__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsetpicturerightcolorselected(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsetpicturerightcolorselected__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsetselectcolor(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsetselectcolor__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsetselected(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsetselected__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsettext(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsettext__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsettooltip(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsettooltip__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsetvalue(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsetvalue__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsort(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsort__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsortall(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsortall__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsortbyvalue(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsortbyvalue__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void tvsortbyvalueall(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__tvsortbyvalueall__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static Value tvtext(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__tvtext__control__array__ret__string(leftGameValue, rightGameValue);
}
public static Value tvtooltip(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__tvtooltip__control__array__ret__string(leftGameValue, rightGameValue);
}
public static Value tvvalue(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__tvvalue__control__array__ret__scalar(leftGameValue, rightGameValue);
}
public static void unassignitem(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__unassignitem__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value unitsbelowheight(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__unitsbelowheight__group__scalar__ret__array(leftGameValue, rightGameValue);
}
public static Value unitsbelowheight(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__unitsbelowheight__array__scalar__ret__array(leftGameValue, rightGameValue);
}
public static Value unitturret(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__unitturret__object__object__ret__array(leftGameValue, rightGameValue);
}
public static void unlinkitem(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__unlinkitem__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static Value unregistertask(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__unregistertask__team_member__string__ret__bool(leftGameValue, rightGameValue);
}
public static void updatedrawicon(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__updatedrawicon__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void updatemenuitem(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__updatemenuitem__control__array__ret__nothing(leftGameValue, rightGameValue);
}
public static void useaudiotimeformoves(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__useaudiotimeformoves__object__bool__ret__nothing(leftGameValue, rightGameValue);
}
public static Value vectoradd(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__vectoradd__array__array__ret__array(leftGameValue, rightGameValue);
}
public static Value vectorcos(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__vectorcos__array__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value vectorcrossproduct(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__vectorcrossproduct__array__array__ret__array(leftGameValue, rightGameValue);
}
public static Value vectordiff(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__vectordiff__array__array__ret__array(leftGameValue, rightGameValue);
}
public static Value vectordistance(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__vectordistance__array__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value vectordistancesqr(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__vectordistancesqr__array__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value vectordotproduct(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__vectordotproduct__array__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value vectorfromto(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__vectorfromto__array__array__ret__array(leftGameValue, rightGameValue);
}
public static Value vectormodeltoworld(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__vectormodeltoworld__object__array__ret__array(leftGameValue, rightGameValue);
}
public static Value vectormodeltoworldvisual(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__vectormodeltoworldvisual__object__array__ret__array(leftGameValue, rightGameValue);
}
public static Value vectormultiply(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__vectormultiply__array__scalar_array__ret__array(leftGameValue, rightGameValue);
}
public static Value vectorworldtomodel(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__vectorworldtomodel__object__array__ret__array(leftGameValue, rightGameValue);
}
public static Value vectorworldtomodelvisual(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__vectorworldtomodelvisual__object__array__ret__array(leftGameValue, rightGameValue);
}
public static void vehiclechat(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__vehiclechat__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void vehicleradio(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__vehicleradio__object__string__ret__nothing(leftGameValue, rightGameValue);
}
public static void waypointattachobject(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__waypointattachobject__array__object_scalar__ret__nothing(leftGameValue, rightGameValue);
}
public static void waypointattachvehicle(Value leftGameValue, Value rightGameValue)
{
    GameValueMethods.binary__waypointattachvehicle__array__object__ret__nothing(leftGameValue, rightGameValue);
}
public static Value weaponaccessories(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__weaponaccessories__object__string__ret__array(leftGameValue, rightGameValue);
}
public static Value weaponaccessoriescargo(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__weaponaccessoriescargo__object__array__ret__array(leftGameValue, rightGameValue);
}
public static Value weapondirection(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__weapondirection__object__string__ret__array(leftGameValue, rightGameValue);
}
public static Value weaponreloadingtime(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__weaponreloadingtime__object__array__ret__scalar(leftGameValue, rightGameValue);
}
public static Value weaponsinfo(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__weaponsinfo__object__array__ret__array(leftGameValue, rightGameValue);
}
public static Value weaponstate(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__weaponstate__object__string__ret__array(leftGameValue, rightGameValue);
}
public static Value weaponsturret(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__weaponsturret__object__array__ret__array(leftGameValue, rightGameValue);
}
public static Value worldtomodel(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__worldtomodel__object__array__ret__array(leftGameValue, rightGameValue);
}
public static Value worldtomodelvisual(Value leftGameValue, Value rightGameValue)
{
    return GameValueMethods.binary__worldtomodelvisual__object__array__ret__array(leftGameValue, rightGameValue);
}
public static Value acctime()
{
    return GameValueMethods.nular__acctime__ret__scalar();
}
public static Value activatedaddons()
{
    return GameValueMethods.nular__activatedaddons__ret__array();
}
public static Value agents()
{
    return GameValueMethods.nular__agents__ret__array();
}
public static Value airdensitycurvertd()
{
    return GameValueMethods.nular__airdensitycurvertd__ret__array();
}
public static Value all3denentities()
{
    return GameValueMethods.nular__all3denentities__ret__array();
}
public static Value allactivetitleeffects()
{
    return GameValueMethods.nular__allactivetitleeffects__ret__array();
}
public static Value alladdonsinfo()
{
    return GameValueMethods.nular__alladdonsinfo__ret__array();
}
public static Value allairports()
{
    return GameValueMethods.nular__allairports__ret__array();
}
public static Value allcurators()
{
    return GameValueMethods.nular__allcurators__ret__array();
}
public static Value allcutlayers()
{
    return GameValueMethods.nular__allcutlayers__ret__array();
}
public static Value alldead()
{
    return GameValueMethods.nular__alldead__ret__array();
}
public static Value alldeadmen()
{
    return GameValueMethods.nular__alldeadmen__ret__array();
}
public static Value alldisplays()
{
    return GameValueMethods.nular__alldisplays__ret__array();
}
public static Value allenv3dsoundsources()
{
    return GameValueMethods.nular__allenv3dsoundsources__ret__array();
}
public static Value allgroups()
{
    return GameValueMethods.nular__allgroups__ret__array();
}
public static Value allmapmarkers()
{
    return GameValueMethods.nular__allmapmarkers__ret__array();
}
public static Value allmines()
{
    return GameValueMethods.nular__allmines__ret__array();
}
public static Value allplayers()
{
    return GameValueMethods.nular__allplayers__ret__array();
}
public static Value allsites()
{
    return GameValueMethods.nular__allsites__ret__array();
}
public static Value allunits()
{
    return GameValueMethods.nular__allunits__ret__array();
}
public static Value allunitsuav()
{
    return GameValueMethods.nular__allunitsuav__ret__array();
}
public static Value allusers()
{
    return GameValueMethods.nular__allusers__ret__array();
}
public static Value ambienttemperature()
{
    return GameValueMethods.nular__ambienttemperature__ret__array();
}
public static Value apertureparams()
{
    return GameValueMethods.nular__apertureparams__ret__array();
}
public static Value armorypoints()
{
    return GameValueMethods.nular__armorypoints__ret__scalar();
}
public static Value benchmark()
{
    return GameValueMethods.nular__benchmark__ret__scalar();
}
public static Value blufor()
{
    return GameValueMethods.nular__blufor__ret__side();
}
public static void break()
{
    GameValueMethods.nular__break__ret__nothing();
}
public static Value briefingname()
{
    return GameValueMethods.nular__briefingname__ret__string();
}
public static Value buldozer_isenabledroaddiag()
{
    return GameValueMethods.nular__buldozer_isenabledroaddiag__ret__bool();
}
public static void buldozer_reloadopermap()
{
    GameValueMethods.nular__buldozer_reloadopermap__ret__nothing();
}
public static Value cadetmode()
{
    return GameValueMethods.nular__cadetmode__ret__bool();
}
public static Value cameraon()
{
    return GameValueMethods.nular__cameraon__ret__object();
}
public static Value cameraview()
{
    return GameValueMethods.nular__cameraview__ret__string();
}
public static Value campaignconfigfile()
{
    return GameValueMethods.nular__campaignconfigfile__ret__config();
}
public static Value cansuspend()
{
    return GameValueMethods.nular__cansuspend__ret__bool();
}
public static Value cheatsenabled()
{
    return GameValueMethods.nular__cheatsenabled__ret__bool();
}
public static Value civilian()
{
    return GameValueMethods.nular__civilian__ret__side();
}
public static void clearforcesrtd()
{
    GameValueMethods.nular__clearforcesrtd__ret__nothing();
}
public static void clearitempool()
{
    GameValueMethods.nular__clearitempool__ret__nothing();
}
public static void clearmagazinepool()
{
    GameValueMethods.nular__clearmagazinepool__ret__nothing();
}
public static void clearradio()
{
    GameValueMethods.nular__clearradio__ret__nothing();
}
public static void clearweaponpool()
{
    GameValueMethods.nular__clearweaponpool__ret__nothing();
}
public static Value clientowner()
{
    return GameValueMethods.nular__clientowner__ret__scalar();
}
public static Value commandingmenu()
{
    return GameValueMethods.nular__commandingmenu__ret__string();
}
public static Value configfile()
{
    return GameValueMethods.nular__configfile__ret__config();
}
public static Value confignull()
{
    return GameValueMethods.nular__confignull__ret__config();
}
public static void continue()
{
    GameValueMethods.nular__continue__ret__nothing();
}
public static Value controlnull()
{
    return GameValueMethods.nular__controlnull__ret__control();
}
public static Value copyfromclipboard()
{
    return GameValueMethods.nular__copyfromclipboard__ret__string();
}
public static Value createhashmap()
{
    return GameValueMethods.nular__createhashmap__ret__hashmap();
}
public static Value curatorcamera()
{
    return GameValueMethods.nular__curatorcamera__ret__object();
}
public static Value curatormouseover()
{
    return GameValueMethods.nular__curatormouseover__ret__object();
}
public static Value curatorselected()
{
    return GameValueMethods.nular__curatorselected__ret__array();
}
public static Value current3denoperation()
{
    return GameValueMethods.nular__current3denoperation__ret__string();
}
public static Value currentchannel()
{
    return GameValueMethods.nular__currentchannel__ret__scalar();
}
public static Value currentnamespace()
{
    return GameValueMethods.nular__currentnamespace__ret__namespace();
}
public static Value cursorobject()
{
    return GameValueMethods.nular__cursorobject__ret__object();
}
public static Value cursortarget()
{
    return GameValueMethods.nular__cursortarget__ret__object();
}
public static Value customwaypointposition()
{
    return GameValueMethods.nular__customwaypointposition__ret__array();
}
public static Value date()
{
    return GameValueMethods.nular__date__ret__array();
}
public static Value daytime()
{
    return GameValueMethods.nular__daytime__ret__scalar();
}
public static Value diag_activemissionfsms()
{
    return GameValueMethods.nular__diag_activemissionfsms__ret__array();
}
public static Value diag_activescripts()
{
    return GameValueMethods.nular__diag_activescripts__ret__array();
}
public static Value diag_activesqfscripts()
{
    return GameValueMethods.nular__diag_activesqfscripts__ret__array();
}
public static Value diag_activesqsscripts()
{
    return GameValueMethods.nular__diag_activesqsscripts__ret__array();
}
public static Value diag_allmissioneventhandlers()
{
    return GameValueMethods.nular__diag_allmissioneventhandlers__ret__array();
}
public static Value diag_deltatime()
{
    return GameValueMethods.nular__diag_deltatime__ret__scalar();
}
public static Value diag_dumpcalltracetolog()
{
    return GameValueMethods.nular__diag_dumpcalltracetolog__ret__bool();
}
public static Value diag_dumpterrainsynth()
{
    return GameValueMethods.nular__diag_dumpterrainsynth__ret__array();
}
public static Value diag_fps()
{
    return GameValueMethods.nular__diag_fps__ret__scalar();
}
public static Value diag_fpsmin()
{
    return GameValueMethods.nular__diag_fpsmin__ret__scalar();
}
public static Value diag_frameno()
{
    return GameValueMethods.nular__diag_frameno__ret__scalar();
}
public static void diag_resetfsm()
{
    GameValueMethods.nular__diag_resetfsm__ret__nothing();
}
public static void diag_resetshapes()
{
    GameValueMethods.nular__diag_resetshapes__ret__nothing();
}
public static Value diag_scope()
{
    return GameValueMethods.nular__diag_scope__ret__scalar();
}
public static Value diag_stacktrace()
{
    return GameValueMethods.nular__diag_stacktrace__ret__array();
}
public static Value diag_ticktime()
{
    return GameValueMethods.nular__diag_ticktime__ret__scalar();
}
public static Value dialog()
{
    return GameValueMethods.nular__dialog__ret__bool();
}
public static Value diaryrecordnull()
{
    return GameValueMethods.nular__diaryrecordnull__ret__task();
}
public static Value didjip()
{
    return GameValueMethods.nular__didjip__ret__bool();
}
public static Value difficulty()
{
    return GameValueMethods.nular__difficulty__ret__scalar();
}
public static Value difficultyenabledrtd()
{
    return GameValueMethods.nular__difficultyenabledrtd__ret__bool();
}
public static void disabledebriefingstats()
{
    GameValueMethods.nular__disabledebriefingstats__ret__nothing();
}
public static void disableserialization()
{
    GameValueMethods.nular__disableserialization__ret__nothing();
}
public static Value displaynull()
{
    return GameValueMethods.nular__displaynull__ret__display();
}
public static Value distributionregion()
{
    return GameValueMethods.nular__distributionregion__ret__scalar();
}
public static Value dynamicsimulationsystemenabled()
{
    return GameValueMethods.nular__dynamicsimulationsystemenabled__ret__bool();
}
public static Value east()
{
    return GameValueMethods.nular__east__ret__side();
}
public static void enableenddialog()
{
    GameValueMethods.nular__enableenddialog__ret__nothing();
}
public static Value endl()
{
    return GameValueMethods.nular__endl__ret__string();
}
public static void endloadingscreen()
{
    GameValueMethods.nular__endloadingscreen__ret__nothing();
}
public static Value environmentenabled()
{
    return GameValueMethods.nular__environmentenabled__ret__array();
}
public static Value environmentvolume()
{
    return GameValueMethods.nular__environmentvolume__ret__scalar();
}
public static Value estimatedendservertime()
{
    return GameValueMethods.nular__estimatedendservertime__ret__scalar();
}
public static void exit()
{
    GameValueMethods.nular__exit__ret__nothing();
}
public static Value false()
{
    return GameValueMethods.nular__false__ret__bool();
}
public static void finishmissioninit()
{
    GameValueMethods.nular__finishmissioninit__ret__nothing();
}
public static Value fog()
{
    return GameValueMethods.nular__fog__ret__scalar();
}
public static Value fogforecast()
{
    return GameValueMethods.nular__fogforecast__ret__scalar();
}
public static Value fogparams()
{
    return GameValueMethods.nular__fogparams__ret__array();
}
public static Value forcedmap()
{
    return GameValueMethods.nular__forcedmap__ret__array();
}
public static void forceend()
{
    GameValueMethods.nular__forceend__ret__nothing();
}
public static void forceweatherchange()
{
    GameValueMethods.nular__forceweatherchange__ret__nothing();
}
public static Value freelook()
{
    return GameValueMethods.nular__freelook__ret__bool();
}
public static Value get3dencamera()
{
    return GameValueMethods.nular__get3dencamera__ret__object();
}
public static Value get3deniconsvisible()
{
    return GameValueMethods.nular__get3deniconsvisible__ret__array();
}
public static Value get3denlinesvisible()
{
    return GameValueMethods.nular__get3denlinesvisible__ret__array();
}
public static Value get3denmouseover()
{
    return GameValueMethods.nular__get3denmouseover__ret__array();
}
public static Value getartillerycomputersettings()
{
    return GameValueMethods.nular__getartillerycomputersettings__ret__array();
}
public static Value getaudiooptionvolumes()
{
    return GameValueMethods.nular__getaudiooptionvolumes__ret__array();
}
public static Value getcalculateplayervisibilitybyfriendly()
{
    return GameValueMethods.nular__getcalculateplayervisibilitybyfriendly__ret__bool();
}
public static Value getclientstate()
{
    return GameValueMethods.nular__getclientstate__ret__string();
}
public static Value getclientstatenumber()
{
    return GameValueMethods.nular__getclientstatenumber__ret__string();
}
public static Value getcursorobjectparams()
{
    return GameValueMethods.nular__getcursorobjectparams__ret__array();
}
public static Value getdlcassetsusage()
{
    return GameValueMethods.nular__getdlcassetsusage__ret__array();
}
public static Value getelevationoffset()
{
    return GameValueMethods.nular__getelevationoffset__ret__scalar();
}
public static Value getlighting()
{
    return GameValueMethods.nular__getlighting__ret__array();
}
public static Value getloadedmodsinfo()
{
    return GameValueMethods.nular__getloadedmodsinfo__ret__array();
}
public static Value getmissiondlcs()
{
    return GameValueMethods.nular__getmissiondlcs__ret__array();
}
public static Value getmissionlayers()
{
    return GameValueMethods.nular__getmissionlayers__ret__array();
}
public static Value getmouseposition()
{
    return GameValueMethods.nular__getmouseposition__ret__array();
}
public static Value getmusicplayedtime()
{
    return GameValueMethods.nular__getmusicplayedtime__ret__scalar();
}
public static Value getobjectviewdistance()
{
    return GameValueMethods.nular__getobjectviewdistance__ret__array();
}
public static Value getpipviewdistance()
{
    return GameValueMethods.nular__getpipviewdistance__ret__scalar();
}
public static Value getremotesensorsdisabled()
{
    return GameValueMethods.nular__getremotesensorsdisabled__ret__bool();
}
public static Value getresolution()
{
    return GameValueMethods.nular__getresolution__ret__array();
}
public static Value getshadowdistance()
{
    return GameValueMethods.nular__getshadowdistance__ret__scalar();
}
public static Value getsteamfriendsservers()
{
    return GameValueMethods.nular__getsteamfriendsservers__ret__array();
}
public static Value getsubtitleoptions()
{
    return GameValueMethods.nular__getsubtitleoptions__ret__array();
}
public static Value getterraingrid()
{
    return GameValueMethods.nular__getterraingrid__ret__scalar();
}
public static Value getterraininfo()
{
    return GameValueMethods.nular__getterraininfo__ret__array();
}
public static Value gettiparameters()
{
    return GameValueMethods.nular__gettiparameters__ret__hashmap();
}
public static Value gettotaldlcusagetime()
{
    return GameValueMethods.nular__gettotaldlcusagetime__ret__scalar();
}
public static Value getvideooptions()
{
    return GameValueMethods.nular__getvideooptions__ret__hashmap();
}
public static Value groupiconselectable()
{
    return GameValueMethods.nular__groupiconselectable__ret__bool();
}
public static Value groupiconsvisible()
{
    return GameValueMethods.nular__groupiconsvisible__ret__array();
}
public static Value grpnull()
{
    return GameValueMethods.nular__grpnull__ret__group();
}
public static Value gusts()
{
    return GameValueMethods.nular__gusts__ret__scalar();
}
public static void halt()
{
    GameValueMethods.nular__halt__ret__nothing();
}
public static Value hasinterface()
{
    return GameValueMethods.nular__hasinterface__ret__bool();
}
public static Value hcshownbar()
{
    return GameValueMethods.nular__hcshownbar__ret__bool();
}
public static Value hudmovementlevels()
{
    return GameValueMethods.nular__hudmovementlevels__ret__array();
}
public static Value humidity()
{
    return GameValueMethods.nular__humidity__ret__scalar();
}
public static Value independent()
{
    return GameValueMethods.nular__independent__ret__side();
}
public static void initambientlife()
{
    GameValueMethods.nular__initambientlife__ret__nothing();
}
public static Value is3den()
{
    return GameValueMethods.nular__is3den__ret__bool();
}
public static Value is3denmultiplayer()
{
    return GameValueMethods.nular__is3denmultiplayer__ret__bool();
}
public static Value is3denpreview()
{
    return GameValueMethods.nular__is3denpreview__ret__bool();
}
public static Value isactionmenuvisible()
{
    return GameValueMethods.nular__isactionmenuvisible__ret__bool();
}
public static Value isautotest()
{
    return GameValueMethods.nular__isautotest__ret__bool();
}
public static Value isdedicated()
{
    return GameValueMethods.nular__isdedicated__ret__bool();
}
public static Value isfilepatchingenabled()
{
    return GameValueMethods.nular__isfilepatchingenabled__ret__bool();
}
public static Value isgamefocused()
{
    return GameValueMethods.nular__isgamefocused__ret__bool();
}
public static Value isgamepaused()
{
    return GameValueMethods.nular__isgamepaused__ret__bool();
}
public static Value isinstructorfigureenabled()
{
    return GameValueMethods.nular__isinstructorfigureenabled__ret__bool();
}
public static Value ismissionprofilenamespaceloaded()
{
    return GameValueMethods.nular__ismissionprofilenamespaceloaded__ret__bool();
}
public static Value ismultiplayer()
{
    return GameValueMethods.nular__ismultiplayer__ret__bool();
}
public static Value ismultiplayersolo()
{
    return GameValueMethods.nular__ismultiplayersolo__ret__bool();
}
public static Value ispipenabled()
{
    return GameValueMethods.nular__ispipenabled__ret__bool();
}
public static Value isremoteexecuted()
{
    return GameValueMethods.nular__isremoteexecuted__ret__bool();
}
public static Value isremoteexecutedjip()
{
    return GameValueMethods.nular__isremoteexecutedjip__ret__bool();
}
public static Value issaving()
{
    return GameValueMethods.nular__issaving__ret__bool();
}
public static Value isserver()
{
    return GameValueMethods.nular__isserver__ret__bool();
}
public static Value issteammission()
{
    return GameValueMethods.nular__issteammission__ret__bool();
}
public static Value issteamoverlayenabled()
{
    return GameValueMethods.nular__issteamoverlayenabled__ret__bool();
}
public static Value isstreamfriendlyuienabled()
{
    return GameValueMethods.nular__isstreamfriendlyuienabled__ret__bool();
}
public static Value isstressdamageenabled()
{
    return GameValueMethods.nular__isstressdamageenabled__ret__bool();
}
public static Value istuthintsenabled()
{
    return GameValueMethods.nular__istuthintsenabled__ret__bool();
}
public static Value isuicontext()
{
    return GameValueMethods.nular__isuicontext__ret__bool();
}
public static Value language()
{
    return GameValueMethods.nular__language__ret__string();
}
public static Value librarycredits()
{
    return GameValueMethods.nular__librarycredits__ret__array();
}
public static Value librarydisclaimers()
{
    return GameValueMethods.nular__librarydisclaimers__ret__array();
}
public static Value lightnings()
{
    return GameValueMethods.nular__lightnings__ret__scalar();
}
public static Value linebreak()
{
    return GameValueMethods.nular__linebreak__ret__text();
}
public static void loadgame()
{
    GameValueMethods.nular__loadgame__ret__nothing();
}
public static Value localnamespace()
{
    return GameValueMethods.nular__localnamespace__ret__namespace();
}
public static Value locationnull()
{
    return GameValueMethods.nular__locationnull__ret__location();
}
public static void logentities()
{
    GameValueMethods.nular__logentities__ret__nothing();
}
public static void mapanimclear()
{
    GameValueMethods.nular__mapanimclear__ret__nothing();
}
public static void mapanimcommit()
{
    GameValueMethods.nular__mapanimcommit__ret__nothing();
}
public static Value mapanimdone()
{
    return GameValueMethods.nular__mapanimdone__ret__bool();
}
public static Value markasfinishedonsteam()
{
    return GameValueMethods.nular__markasfinishedonsteam__ret__bool();
}
public static Value missionconfigfile()
{
    return GameValueMethods.nular__missionconfigfile__ret__config();
}
public static Value missiondifficulty()
{
    return GameValueMethods.nular__missiondifficulty__ret__scalar();
}
public static Value missionend()
{
    return GameValueMethods.nular__missionend__ret__array();
}
public static Value missionname()
{
    return GameValueMethods.nular__missionname__ret__string();
}
public static Value missionnamesource()
{
    return GameValueMethods.nular__missionnamesource__ret__string();
}
public static Value missionnamespace()
{
    return GameValueMethods.nular__missionnamespace__ret__namespace();
}
public static Value missionprofilenamespace()
{
    return GameValueMethods.nular__missionprofilenamespace__ret__namespace();
}
public static Value missionstart()
{
    return GameValueMethods.nular__missionstart__ret__array();
}
public static Value missionversion()
{
    return GameValueMethods.nular__missionversion__ret__scalar();
}
public static Value moonintensity()
{
    return GameValueMethods.nular__moonintensity__ret__scalar();
}
public static Value musicvolume()
{
    return GameValueMethods.nular__musicvolume__ret__scalar();
}
public static Value netobjnull()
{
    return GameValueMethods.nular__netobjnull__ret__netobject();
}
public static Value nextweatherchange()
{
    return GameValueMethods.nular__nextweatherchange__ret__scalar();
}
public static Value nil()
{
    return GameValueMethods.nular__nil__ret__any();
}
public static Value objnull()
{
    return GameValueMethods.nular__objnull__ret__object();
}
public static void opencuratorinterface()
{
    GameValueMethods.nular__opencuratorinterface__ret__nothing();
}
public static Value opfor()
{
    return GameValueMethods.nular__opfor__ret__side();
}
public static Value overcast()
{
    return GameValueMethods.nular__overcast__ret__scalar();
}
public static Value overcastforecast()
{
    return GameValueMethods.nular__overcastforecast__ret__scalar();
}
public static Value parsingnamespace()
{
    return GameValueMethods.nular__parsingnamespace__ret__namespace();
}
public static Value particlesquality()
{
    return GameValueMethods.nular__particlesquality__ret__scalar();
}
public static Value pi()
{
    return GameValueMethods.nular__pi__ret__scalar();
}
public static Value pixelgrid()
{
    return GameValueMethods.nular__pixelgrid__ret__scalar();
}
public static Value pixelgridbase()
{
    return GameValueMethods.nular__pixelgridbase__ret__scalar();
}
public static Value pixelgridnouiscale()
{
    return GameValueMethods.nular__pixelgridnouiscale__ret__scalar();
}
public static Value pixelh()
{
    return GameValueMethods.nular__pixelh__ret__scalar();
}
public static Value pixelw()
{
    return GameValueMethods.nular__pixelw__ret__scalar();
}
public static Value playableunits()
{
    return GameValueMethods.nular__playableunits__ret__array();
}
public static Value player()
{
    return GameValueMethods.nular__player__ret__object();
}
public static Value playerrespawntime()
{
    return GameValueMethods.nular__playerrespawntime__ret__scalar();
}
public static Value playerside()
{
    return GameValueMethods.nular__playerside__ret__side();
}
public static Value productversion()
{
    return GameValueMethods.nular__productversion__ret__array();
}
public static Value profilename()
{
    return GameValueMethods.nular__profilename__ret__string();
}
public static Value profilenamespace()
{
    return GameValueMethods.nular__profilenamespace__ret__namespace();
}
public static Value profilenamesteam()
{
    return GameValueMethods.nular__profilenamesteam__ret__string();
}
public static Value radioenabled()
{
    return GameValueMethods.nular__radioenabled__ret__bool();
}
public static Value radiovolume()
{
    return GameValueMethods.nular__radiovolume__ret__scalar();
}
public static Value rain()
{
    return GameValueMethods.nular__rain__ret__scalar();
}
public static Value rainbow()
{
    return GameValueMethods.nular__rainbow__ret__scalar();
}
public static Value rainparams()
{
    return GameValueMethods.nular__rainparams__ret__array();
}
public static Value remoteexecutedowner()
{
    return GameValueMethods.nular__remoteexecutedowner__ret__scalar();
}
public static void resetcamshake()
{
    GameValueMethods.nular__resetcamshake__ret__nothing();
}
public static Value resistance()
{
    return GameValueMethods.nular__resistance__ret__side();
}
public static Value reversedmousey()
{
    return GameValueMethods.nular__reversedmousey__ret__bool();
}
public static void runinitscript()
{
    GameValueMethods.nular__runinitscript__ret__nothing();
}
public static Value safezoneh()
{
    return GameValueMethods.nular__safezoneh__ret__scalar();
}
public static Value safezonew()
{
    return GameValueMethods.nular__safezonew__ret__scalar();
}
public static Value safezonewabs()
{
    return GameValueMethods.nular__safezonewabs__ret__scalar();
}
public static Value safezonex()
{
    return GameValueMethods.nular__safezonex__ret__scalar();
}
public static Value safezonexabs()
{
    return GameValueMethods.nular__safezonexabs__ret__scalar();
}
public static Value safezoney()
{
    return GameValueMethods.nular__safezoney__ret__scalar();
}
public static void savegame()
{
    GameValueMethods.nular__savegame__ret__nothing();
}
public static void savejoysticks()
{
    GameValueMethods.nular__savejoysticks__ret__nothing();
}
public static Value savemissionprofilenamespace()
{
    return GameValueMethods.nular__savemissionprofilenamespace__ret__bool();
}
public static void saveprofilenamespace()
{
    GameValueMethods.nular__saveprofilenamespace__ret__nothing();
}
public static Value savingenabled()
{
    return GameValueMethods.nular__savingenabled__ret__bool();
}
public static Value scriptnull()
{
    return GameValueMethods.nular__scriptnull__ret__script();
}
public static void selectnoplayer()
{
    GameValueMethods.nular__selectnoplayer__ret__nothing();
}
public static Value sentencesenabled()
{
    return GameValueMethods.nular__sentencesenabled__ret__bool();
}
public static Value servername()
{
    return GameValueMethods.nular__servername__ret__string();
}
public static Value servernamespace()
{
    return GameValueMethods.nular__servernamespace__ret__namespace();
}
public static Value servertime()
{
    return GameValueMethods.nular__servertime__ret__scalar();
}
public static Value shownartillerycomputer()
{
    return GameValueMethods.nular__shownartillerycomputer__ret__bool();
}
public static Value shownchat()
{
    return GameValueMethods.nular__shownchat__ret__bool();
}
public static Value showncompass()
{
    return GameValueMethods.nular__showncompass__ret__bool();
}
public static Value showncuratorcompass()
{
    return GameValueMethods.nular__showncuratorcompass__ret__bool();
}
public static Value showngps()
{
    return GameValueMethods.nular__showngps__ret__bool();
}
public static Value shownhud()
{
    return GameValueMethods.nular__shownhud__ret__array();
}
public static Value shownmap()
{
    return GameValueMethods.nular__shownmap__ret__bool();
}
public static Value shownpad()
{
    return GameValueMethods.nular__shownpad__ret__bool();
}
public static Value shownradio()
{
    return GameValueMethods.nular__shownradio__ret__bool();
}
public static Value shownscoretable()
{
    return GameValueMethods.nular__shownscoretable__ret__scalar();
}
public static Value shownsubtitles()
{
    return GameValueMethods.nular__shownsubtitles__ret__bool();
}
public static Value shownuavfeed()
{
    return GameValueMethods.nular__shownuavfeed__ret__bool();
}
public static Value shownwarrant()
{
    return GameValueMethods.nular__shownwarrant__ret__bool();
}
public static Value shownwatch()
{
    return GameValueMethods.nular__shownwatch__ret__bool();
}
public static Value sideambientlife()
{
    return GameValueMethods.nular__sideambientlife__ret__side();
}
public static Value sideempty()
{
    return GameValueMethods.nular__sideempty__ret__side();
}
public static Value sideenemy()
{
    return GameValueMethods.nular__sideenemy__ret__side();
}
public static Value sidefriendly()
{
    return GameValueMethods.nular__sidefriendly__ret__side();
}
public static Value sidelogic()
{
    return GameValueMethods.nular__sidelogic__ret__side();
}
public static Value sideunknown()
{
    return GameValueMethods.nular__sideunknown__ret__side();
}
public static void simulweathersync()
{
    GameValueMethods.nular__simulweathersync__ret__nothing();
}
public static Value slingloadassistantshown()
{
    return GameValueMethods.nular__slingloadassistantshown__ret__bool();
}
public static Value soundvolume()
{
    return GameValueMethods.nular__soundvolume__ret__scalar();
}
public static Value speechvolume()
{
    return GameValueMethods.nular__speechvolume__ret__scalar();
}
public static Value sunormoon()
{
    return GameValueMethods.nular__sunormoon__ret__scalar();
}
public static Value switchableunits()
{
    return GameValueMethods.nular__switchableunits__ret__array();
}
public static Value systemofunits()
{
    return GameValueMethods.nular__systemofunits__ret__scalar();
}
public static Value systemtime()
{
    return GameValueMethods.nular__systemtime__ret__array();
}
public static Value systemtimeutc()
{
    return GameValueMethods.nular__systemtimeutc__ret__array();
}
public static Value tasknull()
{
    return GameValueMethods.nular__tasknull__ret__task();
}
public static Value teammembernull()
{
    return GameValueMethods.nular__teammembernull__ret__team_member();
}
public static Value teams()
{
    return GameValueMethods.nular__teams__ret__array();
}
public static void teamswitch()
{
    GameValueMethods.nular__teamswitch__ret__nothing();
}
public static Value teamswitchenabled()
{
    return GameValueMethods.nular__teamswitchenabled__ret__bool();
}
public static Value time()
{
    return GameValueMethods.nular__time__ret__scalar();
}
public static Value timemultiplier()
{
    return GameValueMethods.nular__timemultiplier__ret__scalar();
}
public static Value true()
{
    return GameValueMethods.nular__true__ret__bool();
}
public static Value uinamespace()
{
    return GameValueMethods.nular__uinamespace__ret__namespace();
}
public static Value userinputdisabled()
{
    return GameValueMethods.nular__userinputdisabled__ret__bool();
}
public static Value vehicles()
{
    return GameValueMethods.nular__vehicles__ret__array();
}
public static Value viewdistance()
{
    return GameValueMethods.nular__viewdistance__ret__scalar();
}
public static Value visiblecompass()
{
    return GameValueMethods.nular__visiblecompass__ret__bool();
}
public static Value visiblegps()
{
    return GameValueMethods.nular__visiblegps__ret__bool();
}
public static Value visiblemap()
{
    return GameValueMethods.nular__visiblemap__ret__bool();
}
public static Value visiblescoretable()
{
    return GameValueMethods.nular__visiblescoretable__ret__bool();
}
public static Value visiblewatch()
{
    return GameValueMethods.nular__visiblewatch__ret__bool();
}
public static Value waves()
{
    return GameValueMethods.nular__waves__ret__scalar();
}
public static Value west()
{
    return GameValueMethods.nular__west__ret__side();
}
public static Value wind()
{
    return GameValueMethods.nular__wind__ret__array();
}
public static Value winddir()
{
    return GameValueMethods.nular__winddir__ret__scalar();
}
public static Value windrtd()
{
    return GameValueMethods.nular__windrtd__ret__array();
}
public static Value windstr()
{
    return GameValueMethods.nular__windstr__ret__scalar();
}
public static Value worldname()
{
    return GameValueMethods.nular__worldname__ret__string();
}
public static Value worldsize()
{
    return GameValueMethods.nular__worldsize__ret__scalar();
}

        }
    }

    public class BadTypeException : Exception
{
    public BadTypeException()
    {
    }

    public BadTypeException(string message) : base(message)
    {
    }

    public BadTypeException(string message, Exception inner) : base(message, inner)
    {
    }
}
}