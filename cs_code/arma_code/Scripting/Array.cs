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
        public class RVArray : IEnumerable
        {
            public AutoArray _array;
            public RVArray()
            {
                _array = AutoArrayMethods.CreateAutoArray();
            }

            public RVArray(AutoArray array)
            {
                _array = array;
            }

            ~RVArray()
            {
                AutoArrayMethods.DeleteAutoArray(_array);
            }

            // Conversions
            public static implicit operator GameValue(RVArray value) => new Value(value).Data;

            public Value ToValue()
            {
                return new Value(_array);
            }

            public void ShrinkToFit()
            {
                int currentBytes = Marshal.SizeOf<GameValue>() * _array._count;
                IntPtr newMemory = Allocator.Allocate(currentBytes);

                unsafe
                {
                    Buffer.MemoryCopy(_array._data.ToPointer(), newMemory.ToPointer(), currentBytes, currentBytes);
                }

                if (_array._data != IntPtr.Zero)
                {
                    Allocator.Deallocate(_array._data);
                }
                _array._data = newMemory;
                _array._maxItems = _array._count;
            }

            // resize to exactly size
            public unsafe void Resize(int size)
            {
                if (size <= 0)
                {
                    throw new ArgumentException("size can't be less than 1");
                }

                if (size == _array._count)
                {
                    return;
                }

                if (size > _array._maxItems)
                {
                    Grow(size - _array._maxItems);
                }
                else
                {
                    GameValue* array = (GameValue*)_array._data.ToPointer();
                    // call the delete function here.
                    for (int i = size; i < _array._maxItems; i++)
                    {
                        GameValueMethods.DeleteGameValue(array[i].data);
                    }

                    // allocate memory of the new size
                    int numBytesAllocate = Marshal.SizeOf<GameValue>() * (size);
                    IntPtr newMemory = Allocator.Allocate(numBytesAllocate);

                    // only copy the memory of that new size, we have already deleted everything after the last byte
                    Buffer.MemoryCopy(_array._data.ToPointer(), newMemory.ToPointer(), numBytesAllocate, numBytesAllocate);


                    if (_array._data != IntPtr.Zero)
                    {
                        Allocator.Deallocate(_array._data);
                    }
                    _array._data = newMemory;
                    _array._count = size;
                    _array._maxItems = size;

                }
            }

            public unsafe void Reserve(int size)
            {
                if (size <= 0)
                {
                    throw new ArgumentException("size can't be less than 1");
                }

                // if the size is the same, or less don't do anything
                if (size <= _array._maxItems)
                {
                    return;
                }

                Grow(size);

            }

            public void Add(Value instance)
            {
                /* if the count + 1 is greater than the maxItems in array or the array pointer is
                * null, then allocate more memory.
                */
                if (_array._count + 1 > _array._maxItems || _array._data == IntPtr.Zero)
                {
                    Grow(1);
                }
                GameValue value = instance.Data;

                unsafe
                {
                    GameValue* pointer = (GameValue*)_array._data.ToPointer();
                    var location = &pointer[_array._count];
                    Buffer.MemoryCopy(&value, location, Marshal.SizeOf<GameValue>(), Marshal.SizeOf<GameValue>());
                }
                _array._count++;
            }

            public void Grow(int size)
            {
                int numBytesAllocate = Marshal.SizeOf<GameValue>() * (_array._count + size);
                int currentBytes = Marshal.SizeOf<GameValue>() * _array._count;
                IntPtr newMemory = Allocator.Allocate(numBytesAllocate);

                unsafe
                {
                    Buffer.MemoryCopy(_array._data.ToPointer(), newMemory.ToPointer(), currentBytes, currentBytes);
                }

                if (_array._data != IntPtr.Zero)
                {
                    Allocator.Deallocate(_array._data);
                }
                _array._data = newMemory;
                _array._maxItems = _array._count + size;
            }

            public void Erase()
            {
                if (_array._data != IntPtr.Zero)
                {
                    Allocator.Deallocate(_array._data);
                }
                // memory leak here, techinally
                _array._maxItems = 0;
                _array._count = 0;
            }

            public void Erase(int index, int count)
            {
                if (index < 0 || count <= 0)
                {
                    String message = String.Empty;
                    if (index < 0)
                    {
                        message = String.Format("index {0} is less than 0", index);
                    }
                    else
                    {
                        message = String.Format("count {0} is less than 1", count);
                    }
                    throw new ArgumentOutOfRangeException(message);
                }


                if (index > _array._count)
                {
                    throw new ArgumentOutOfRangeException("Index was out of range.");
                }
                else if (index + count > _array._count)
                {
                    throw new ArgumentException();
                }

                int indexRemoveEnd = index + count - 1;
                int indexStartMemcopy = index + count;
                int newSize = _array._count - count;
                unsafe
                {
                    GameValue* buffer = (GameValue*)_array._data.ToPointer();

                    for (int i = index; i < newSize; i++)
                    {
                        buffer[i] = buffer[i + count];
                    }

                }
                _array._count = newSize;
            }

            public void Insert(int index, Value element)
            {
                if (index > _array._count)
                {
                    throw new ArgumentOutOfRangeException("index is greater than count");
                }

                if (_array._count + 1 > _array._maxItems)
                {
                    Grow(1);
                }

                unsafe
                {
                    GameValue* buffer = (GameValue*)_array._data.ToPointer();

                    for (int i = index; i < _array._count + 1; i++)
                    {
                        buffer[i + 1] = buffer[i];
                    }

                    buffer[index] = element.Data;

                }

                _array._count++;
            }

            public Value Get(int index)
            {
                if (index > _array._count)
                {
                    throw new ArgumentOutOfRangeException(string.Format("index {0} is bigger than count {1}", index, _array._count));
                }

                unsafe
                {
                    GameValue* buffer = (GameValue*)_array._data.ToPointer();
                    return new Value(buffer[index]);
                }
            }

            public int Size()
            {
                return _array._count;
            }

            public Boolean IsEmpty()
            {
                return _array._count == 0;
            }

            IEnumerator IEnumerable.GetEnumerator()
            {
                return (IEnumerator)GetEnumerator();
            }

            RVArrayEnum GetEnumerator()
            {
                return new RVArrayEnum(_array);
            }
        }

        public class RVArrayEnum : IEnumerator
        {
            public AutoArray _array;
            int position = -1;

            public RVArrayEnum(AutoArray array)
            {
                _array = array;
            }

            public bool MoveNext()
            {
                position++;
                return (position < _array._count);
            }

            public void Reset()
            {
                position = -1;
            }

            object IEnumerator.Current
            {
                get
                {
                    return Current;
                }
            }

            public Value Current
            {
                get
                {
                    try
                    {
                        unsafe
                        {
                            GameValue* buffer = (GameValue*)_array._data.ToPointer();
                            return new Value(buffer[position]);
                        }
                    }
                    catch (NullReferenceException)
                    {
                        throw new InvalidOperationException();
                    }
                }
            }

        }
    }
}