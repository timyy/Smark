# Markdown 语法

[在线编辑器](https://pandao.github.io)
[smark]()

# 标题

# 1
## 2
### 3
#### 4

`
# 1
## 2
### 3
#### 4`

# 列表

- 列表1
- 列表2
- 列表3 

1. 列表1
2. 列表2

# 链接
[126.com](http://www.126.com)

<p align="center">
    <img src="http://www.126.com" width="60%">
    <small> tittle </small>
</p>

# 引用

> 这里是*李商隐*的诗

# 代码

```
 code in here #1
```

# 表格

| Tables        | Are           | Cool  |
| ------------- |:-------------:| -----:|
| col 3 is      | right-aligned | $1600 |
| col 2 is      | centered      |   $12 |
| zebra stripes | are neat      |    $1 |

# 流程图 表格
<pre name="flow">
st=>start: Improve your l10n process! 
e=>end: Continue to have fun!:>https://youtu.be/YQryHo1iHb8[blank] 
op1=>operation: Go to locize.com:>https://locize.com[blank] 
sub1=>subroutine: Read the awesomeness 
cond(align-next=no)=>condition: Interested to getting started? 
io=>inputoutput: Register:>https://www.locize.io/register[blank] 
sub2=>subroutine: Read about improving your localization workflow or another source:>https://medium.com/@adrai/8-signs-you-should-improve-your-localization-process-3dc075d53998[blank] 
op2=>operation: Login:>https://www.locize.io/login[blank] 
cond2=>condition: valid password? 
cond3=>condition: reset password? 
op3=>operation: send email 
sub3=>subroutine: Create a demo project 
sub4=>subroutine: Start your real project 
io2=>inputoutput: Subscribe 
st->op1->sub1->cond 
cond(yes)->io->op2->cond2 
cond2(no)->cond3 
cond3(no,bottom)->op2 
cond3(yes)->op3 
op3(right)->op2 
cond2(yes)->sub3 
sub3->sub4->io2->e 
cond(no)->sub2(right)->op1 st@>op1({"stroke":"Red"})@>sub1({"stroke":"Red"})@>cond({"stroke":"Red"})@>io({"stroke":"Red"})@>op2({"stroke":"Red"})@>cond2({"stroke":"Red"})@>sub3({"stroke":"Red"})@>sub4({"stroke":"Red"})@>io2({"stroke":"Red"})@>e({"stroke":"Red","stroke-width":6,"arrow-end":"classic-wide-long"})

</pre>

