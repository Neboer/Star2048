# STAR 2048

一个用C语言实现的2048小游戏。

## 构建方法

```bash
gcc src/2048_swap_merge.c  src/direct_table.c  src/game.c  src/main.c -o Star2048
```
在Windows中构建请输出.exe后缀的文件。

本项目还支持使用CMake构建。

## 玩法介绍

```
Score: 0
    -     -     -     - 
    -     -     -     - 
    2     2     -     - 
    -     -     -     - 
Please input your move: Down(1), Left(2), Up(3), Right(4)
2
Score: 0
    -     -     -     - 
    -     2     -     2 
    4     -     -     - 
    -     -     -     - 
Please input your move: Down(1), Left(2), Up(3), Right(4)
2
Score: 0
    -     -     -     - 
    4     -     2     - 
    4     2     -     - 
    -     -     -     - 
Please input your move: Down(1), Left(2), Up(3), Right(4)
```

经典的2048玩法。