# Laboratory work #1

## Build

```sh
$ make release
```

## Usage

### View command list with usage

```sh
$ ./lab1_cpp -h
```

### Random matrix

Generate random 20x20 matrix and solve it

```sh
$ ./lab1_cpp -g 20
```
### Input from file

```sh
$ ./lab1_cpp -f input1.txt
```

### User input

```sh
$ ./lab1_cpp -i
```


## Input file format
```
percision // first line
matrix size // second line
n n n n n ... n
n n n n n ... n
n n n n n ... n
...
n n n n n ... n
```

## Example

- **Percision**: 3
- **Size**: 3
- **Matrix**:

| a   | b   | c   | B   |
| --- | --- | --- | --- |
| 10  | -7  | 0   | 7   |
| -3  | 2   | 6   | 4   |
| 5   | -1  | 5   | 6   |


```
3
3
10 -7 0 7
-3 2 6 4
5 -1 5 6
```