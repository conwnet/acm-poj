# Exponentiation

题意很简单，计算 a 的 n 次方

a 可以是小数，n 不会超过 25，总之 double 存不下就是了，显然一道挺麻烦的高精度的题

需要注意的有以下两点：

结尾不要有多余的 0，比如： 1.23400 要输出 1.234

结果小于 1 不要输出前面的 0，比如： 0.001 要输出 .001
