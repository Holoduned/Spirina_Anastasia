﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programming.Programming.Домашние__2_семестр.Homework_07_03_2022
{
    public interface ICustomCollection<T>
    {
        int Size();
        bool isEmpty();
        bool Contains(T elem);
        void Add(T elem);
        void AddRange(T[] elems);
        void Remove(T elem);
        void RemoveAll(T elem);
        void RemoveAt(int index);
        void Clear();
        void Reverse();
        int IndexOf(T elem);
        void Print();
    }

    public class CustomArrayCollection<T> : ICustomCollection<T>
    {
        private T[] array = Array.Empty<T>();

        public int Size()
        {
            return array.Length;
        }

        public bool isEmpty()
        {
            if (array.Length == 0 && array == null)
            {
                return true;
            }
            return false;
        }

        public bool Contains(T element)
        {
            if (array.Contains(element))
            {
                return true;
            }
            return false;
        }

        public void Add(T element)
        {
            array.Append(element).ToArray();

        }

        public void AddRange(params T[] mas)
        {
            array = array.Concat(mas).ToArray();
        }

        public int IndexOf(T element)
        {
            return Array.IndexOf(array, element);
        }

        public void Reverse()
        {
            Array.Reverse(array);
        }

        public void Clear()
        {
            array = Array.Empty<T>();
        }

        public void Remove(T element)
        {
            var index = IndexOf(element);
            if (index < 0) { return; }
            array = array[0..IndexOf(element)].Concat(IndexOf(element) == array.Length ? Array.Empty<T>() : array[(IndexOf(element) + 1)..array.Length]).ToArray();
        }

        public void RemoveAll(T element)
        {
            T[] mas = new T[array.Length];
            int count = 0;

            foreach (T item in array)
            {
                if (!item.Equals(element))
                {
                    mas[count] = item;
                    count++;
                }
            }
            array = mas[0..count];
        }

        public void RemoveAt(int index)
        {

        }

        public void Print()
        {
            Console.WriteLine(String.Join(" ", array));
        }
    }

}
