using System;
					
public class Program
{
	public static void Main()
	{
        // giải phương trình bậc 2
        // ax^2 + bx + c = 0
        Console.Write("Nhap a: ");
        float a = float.Parse(Console.ReadLine());
        Console.Write("Nhap b: ");
        float b = float.Parse(Console.ReadLine());
        Console.Write("Nhap c: ");
        float c = float.Parse(Console.ReadLine());
        float delta = b * b - 4 * a * c;
        if (delta < 0)
        {
            Console.WriteLine("Phuong trinh vo nghiem");
        }
        else if (delta == 0)
        {
            float x = -b / (2 * a);
            Console.WriteLine("Phuong trinh co nghiem kep x1 = x2 = {0}", x);
        }
        else
        {
            float x1 = (-b + (float)Math.Sqrt(delta)) / (2 * a);
            float x2 = (-b -(float) Math.Sqrt(delta)) / (2 * a);
            Console.WriteLine("Phuong trinh co 2 nghiem phan biet: x1 = {0}, x2 = {1}", x1, x2);
        }
	}
}