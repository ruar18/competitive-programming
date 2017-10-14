using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace vera
{
    class Program
    {
        static long[,] g = new long[5001,2];
        static void Main(string[] args)
        {
            long k, cur=0, v=0, e=0, m=0, num=1, cnt=0, last=1;
            Int64.TryParse(Console.ReadLine(), out k);
            for(int i = 5000; i >= 2; i--)
            {
                cur = i * (i - 1) / 2;
                m = k / cur;
                if (m == 0) continue;
                k -= (m * cur);
                v += (m * i);
                while (m-- != 0)
                {
                    for(long j = num; j < num + i - 1; j++, cnt++)
                    {
                        g[cnt, 0] = j;
                        g[cnt, 1] = j + 1;
                        e++;
                    }
                    g[cnt, 0] = num;
                    g[cnt, 1] = num + i - 1;
                    cnt++;
                    e++;
                    if (num != last)
                    {
                        g[cnt, 0] = num;
                        g[cnt, 1] = last;
                        e++;
                        cnt++;
                    }
                    last = num;
                    num += i;
                }
            }
            Console.WriteLine(string.Format("{0} {1}", v, e));
            for(int i = 0; i < e; i++)
                Console.WriteLine(string.Format("{0} {1}", g[i, 0], g[i, 1]));
        }
    }
}