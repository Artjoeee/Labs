using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Control
{
    public class Point : IComparable, IGraph
    {
        public int X { get; set; }
        public int Y { get; set; }
        public int Z { get; set; }

        public int Sum { get; set; }

        public Point(int x, int y, int z)
        {
            X = x;
            Y = y;
            Z = z;
        }

        public static string operator +(Point a, Point b)
        {
            var sumX = a.X + b.X;
            var sumY = a.Y + b.Y;
            var sumZ = a.Z + b.Z;

            return $"X: {sumX}, Y: {sumY}, Z: {sumZ}";
        }

        public static string operator -(Point a, Point b)
        {
            var sumX = a.X - b.X;
            var sumY = a.Y - b.Y;
            var sumZ = a.Z - b.Z;

            return $"X: {sumX}, Y: {sumY}, Z: {sumZ}";
        }

        public int CompareTo(object b)
        {
            return Sum.CompareTo(b);
        }

        public int First()
        {
            return (X > 0 && Y > 0 && Z > 0) ? 1 : 0;
        }
    }

    public class Line : IGraph
    {
        public Point Point1 { get; set; }
        public Point Point2 { get; set; }

        public Line(Point point1, Point point2)
        {
            Point1 = point1;
            Point2 = point2;
        }

        public int First()
        {
            return Point1.First() + Point2.First();
        }
    }
}