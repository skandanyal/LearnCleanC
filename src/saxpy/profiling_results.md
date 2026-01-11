# Profiling results

Kernel : `saxpy`
```
[y] <- a*[x] + [y] 

where: 
    a = scalar constant
    x, y = vectors
```

```
* FLOPs = 2 
* FLOPs per iteration = FLOPs * iteration = 2 * n 
* Memory Bandwidth in gbps = 12 * n / T / 1e9  
* Arithmatic intensity = FLOPs / Bytes = 2 / 12 = 0.166
```


|                  Attributes                  | `plain_kernel` | `restrict_kernel` | `parallel_kernel`<br>threads=1 | `parallel_kernel`<br>threads=2 | `parallel_kernel`<br>threads=3 | `parallel_kernel`<br>threads=4 |
|:--------------------------------------------:|---------------:|:-----------------:|:------------------------------:|:------------------------------:|:------------------------------:|:------------------------------:|
|                  Iterations                  |            100 |        100        |              100               |              100               |              100               |              100               |
|  Time taken per iteration `T`<br>(seconds)   |              - |     0.012175      |               -                |               -                |               -                |               -                |
|            Instructions per Cycle            |           1.77 |         -         |               -                |               -                |               -                |               -                |
|             Frontend cycles idle             |         16.98% |         -         |               -                |               -                |               -                |               -                |
|                    FLOPS                     |              2 |         2         |               2                |               2                |               2                |               2                |
| FLOPS per second<br>`FLOPS * iterations / T` |                |         -         |               -                |               -                |               -                |               -                |
| 
