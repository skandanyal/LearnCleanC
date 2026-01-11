# Profiling results

Experiments conducted on AMD Ryzen 5 6600H.
Compiler flags used to debug: `-g -O0`
Compiler flags used to benchmark: `-O3 -ffast-math -march=native`

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

* FLOPs per iteration = FLOPs * iteration = 2 * total_number_of_rows_in_x(OR)y
* FLOPS per second = 2 * n / T  
* Memory Bandwidth in gbps = 12 * n / T / 1e9  
```


|                Attributes                 | `plain_kernel` | `restrict_kernel` | `parallel_kernel`<br>threads=1 | `parallel_kernel`<br>threads=2 | `parallel_kernel`<br>threads=3 | `parallel_kernel`<br>threads=4 |
|:-----------------------------------------:|:--------------:|:-----------------:|:------------------------------:|:------------------------------:|:------------------------------:|:------------------------------:|
|                Iterations                 |      100       |        100        |              100               |              1000              |              100               |              100               |
| Time taken per iteration `T`<br>(seconds) |    0.005033    |     0.012175      |            0.005154            |            0.005134            |               -                |               -                |
|          Instructions per Cycle           |      1.77      |       0.54        |              0.67              |               -                |               -                |               -                |
|           Frontend cycles idle            |     4.10%      |       4.28%       |             62.71%             |               -                |               -                |               -                |
|          Memory bandwidth (GBps)          |     23.84      |       9.85        |             23.28              |             23.37              |               -                |               -                |
|             GFLOPs per second             |      3.97      |       1.64        |              3.88              |              3.89              |               -                |               -                |
|            Kernel overhead (%)            |     92.48%     |      91.56%       |             91.98%             |             97.76%             |               -                |               -                |
|               CPUs utilized               |     0.999      |       0.997       |             0.999              |             0.999              |               -                |               -                |


