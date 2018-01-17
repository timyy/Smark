# 机器人编程 ROS

## 学习ROS by Samples
### 参考文章
1. [ROS探索总结](http://www.guyuehome.com/column/ros-explore)
2. [Ros by sample](https://github.com/pirobot) 

### 安装示例代码和数据
``` bash
mkdir -p ~/dev/catkin_ws/src
cd ~/dev/catkin_ws/src
catkin_init_workspace
git clone https://github.com/pirobot/rbx1
git clone  https://github.com/vanadiumlabs/arbotix_ros.git
cd ~/catkin_ws #
catkin_make
source ~/catkin_ws/devel/setup.bash
rospack profile
 # 如果想重启动后也有效，就会下面这个，修改用户启动配置文件，相当于autobat或者config.sys?
echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc
 #也可以sudo gedit ~/.bashrc

```

过程中有错误会是因为有几个cfg文件中的命令是windows格式的，另存为unix风格文件就行了。
安装模拟器。
``` bash
cd ~/catkin_ws/src
 
// 在arbotix_ros文件夹下新建文件夹src,将arbotix_ros目录下的所有文件剪切放到src文件夹下;
 
cd ..
catkin_mak
```

### 升级到kinetic
原版是在indigo平台下的，升级到kinetic.修改
rbx1-prereq-kinetic.sh

``` bash
 # Install the prerequisites for the ROS By Example code, Volume 1
sudo apt-get install ros-kinetic-turtlebot-bringup
sudo apt-get install ros-kinetic-turtlebot-create-desktop 
sudo apt-get install ros-kinetic-openni-* 
sudo apt-get install ros-kinetic-openni2-* 
sudo apt-get install ros-kinetic-freenect-* 
sudo apt-get install ros-kinetic-usb-cam 
sudo apt-get install ros-kinetic-laser-* 
sudo apt-get install ros-kinetic-hokuyo-node 
sudo apt-get install ros-kinetic-audio-common
sudo apt-get install gstreamer0.10-pocketsphinx
sudo apt-get install ros-kinetic-pocketsphinx
sudo apt-get install ros-kinetic-slam-gmapping
sudo apt-get install ros-kinetic-joystick-drivers 
sudo apt-get install python-rosinstall
sudo apt-get install ros-kinetic-orocos-kdl 
sudo apt-get install ros-kinetic-python-orocos-kdl 
sudo apt-get install python-setuptools 
sudo apt-get install ros-kinetic-dynamixel-motor-* 
sudo apt-get install libopencv-dev 
sudo apt-get install python-opencv 
sudo apt-get install ros-kinetic-vision-opencv 
sudo apt-get install ros-kinetic-depthimage-to-laserscan 
sudo apt-get install ros-kinetic-arbotix-* 
sudo apt-get install ros-kinetic-turtlebot-teleop
sudo apt-get install ros-kinetic-move-base
sudo apt-get install ros-kinetic-map-server
sudo apt-get install ros-kinetic-fake-localization
sudo apt-get install ros-kinetic-amcl
sudo apt-get install git
sudo apt-get install subversion 
sudo apt-get install mercurial
```

### 运行示例

``` bash
    roscore  
    roslaunch rbx1_bringup fake_pi_robot.launch  
    rosrun rviz rviz -d "rospack find rbx1_nav" /sim_fuerte.vcg 
 #这句话会错，是因为kinetic已经不支持vcg格式了。
    rosrun rviz rviz -d "rospack find rbx1_nav" /sim.rviz 
```
    此时的机器人是静止的，需要发布一个消息才能让它动起来。
```
    rostopic pub -r 10 /cmd_vel geometry_msgs/Twist '{linear: {x: 0.2, y: 0, z: 0}, angular: {x: 0, y: 0, z: 0.5}}'  
```
机器人真的动起来了：） 
如果要让机器人停下来，需要在中断中按下“Ctrl+c”，然后输入：
```
    rostopic pub -1 /cmd_vel geometry_msgs/Twist '{}'  
```

## 日本 [Autoware](http://www.tier4.jp/) 
1. [autoware github](https://github.com/CPFL/Autoware)
2. [autoware的中文](http://blog.csdn.net/zhangrelay/article/details/71750863)

### 安装相关组件


# 位置感知
## 谷歌 [Cartographer]() ， lidar
1. [谷歌Cartographer学习](https://www.cnblogs.com/hitcm/p/5939507.html)
2. [hitcm github](https://github.com/hitcm)

##  slam
## rtkgps 
# 机器视觉 opencv
# 人工智能 tensorflow 


# 各种markdown的示例

## 代码
``` python
# -*- coding: utf-8 -*-  
  
import hashlib  
import os
  
def md5hex(word):  
    """ MD5加密算法，返回32位小写16进制符号 """  
    if isinstance(word, unicode):  
        word = word.encode("utf-8")  
    elif not isinstance(word, str):  
        word = str(word)  
    m = hashlib.md5()  
    m.update(word)  
    return m.hexdigest()  
```

## 公式

这是个inline [E = MC^2 ]
$$ 
E = MC^2
$$ 



$$ x = {-b \pm \sqrt{b^2-4ac} \over 2a}. $$.

## 绘制流程图 Flowchart

### 流程图 Flowchart1

<pre name="flow">
st=>start: 用户登陆
op=>operation: 登陆操作
cond=>condition: 登陆成功 Yes or No?
e=>end: 进入后台

st->op->cond
cond(yes)->e
cond(no)->op
</pre>

### 流程图 Flowchart2

<pre name="flow">
st=>start: Start|past:>http://www.google.com[blank]
e=>end: End:>http://www.google.com
op1=>operation: My Operation|past
op2=>operation: Stuff|current
sub1=>subroutine: My Subroutine|invalid
cond=>condition: Yes
or No?|approved:>http://www.google.com
c2=>condition: Good idea|rejected
io=>inputoutput: catch something...|request

st->op1(right)->cond
cond(yes, right)->c2
cond(no)->sub1(left)->op1
c2(yes)->io->e
c2(no)->op2->e

st@>op1({"stroke":"Red"})@>cond({"stroke":"Red","stroke-width":6,"arrow-end":"classic-wide-long"})@>c2({"stroke":"Red"})@>op2({"stroke":"Red"})@>e({"stroke":"Red"})
</pre>

