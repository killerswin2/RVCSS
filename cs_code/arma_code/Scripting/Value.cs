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
                if(Type() == VTablePtrs.GameDataString)
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
        }
    }

    public class BadTypeException: Exception
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