0.54# Profiling results

Kernel : `saxpy`
```
[y] <- a*[x] + [y] 

where: 
    a = scalar constant
    x, y = vectors
```

```
* FLOPs = 2 
* Arithmatic intensity = FLOPs / Bytes = 2 / 12 = 0.166

* FLOPs per iteration = FLOPs * iteration = 2 * n 
* FLOPS per second = 2 * n / T  
* Memory Bandwidth in gbps = 12 * n / T / 1e9  
```


|                Attributes                 | `plain_kernel` | `restrict_kernel` | `parallel_kernel`<br>threads=1 | `parallel_kernel`<br>threads=2 | `parallel_kernel`<br>threads=3 | `parallel_kernel`<br>threads=4 |
|:-----------------------------------------:|---------------:|:-----------------:|:------------------------------:|:------------------------------:|:------------------------------:|:------------------------------:|
|                Iterations                 |            100 |        100        |              100               |              100               |              100               |              100               |
| Time taken per iteration `T`<br>(seconds) |       0.005033 |     0.012175      |               0.005154         |                               |               -                |               -                |
|          Instructions per Cycle           |           1.77 |       0.54        |               0.67             |               -                |               -                |               -                |
|           Frontend cycles idle            |         4.10%  |       4.28%       |               62.71%           |               -                |               -                |               -                |
|          Memory bandwidth (GBps)          |    0.000238426 |    0.000098563    |               -                |               -                |               -                |               -                |
|             FLOPs per second              |       39737.73 |     16427.104     |                                |                                |                                |                                |
|            Kernel overhead (%)            |        92.48%  |      91.56%       |               91.98%           |               91.71%                 |                                |                                |
|               CPUs utilized               |        0.999   |       0.997       |               0.999            |                0.999                |                                |                                |
