# 机器人编程 ROS

---
标签：ROS Kinetic， Ubuntu 16.04, 

# 机器人设计
## 机器人总体设计
- [如何设计一款基于ROS的移动机器人](http://blog.exbot.net/archives/2713)
- [ROS教程：视觉传感器使用漫谈](http://blog.exbot.net/archives/2669)
- [百度apollo一站式部署](http://blog.exbot.net/archives/3488)
- [百度资深架构师首次解密Apollo ROS有何不同](http://blog.exbot.net/archives/3437)
- [大学本科《机器人程序设计课程》配套系统镜像使用说明](http://blog.exbot.net/archives/3001)
- [ROS机器人程序设计（第2版）](http://blog.exbot.net/archives/2891)
- [如何使用Qt插件在Qt中进行ROS开发](http://blog.exbot.net/archives/2744)
- [ROS与Matlab系列：一个简单的运动控制](http://blog.exbot.net/archives/2594)
- [ROS与Matlab系列2：连接vrep仿真器](http://blog.exbot.net/archives/2619)
- [拿ROS navigation 玩自主导航攻略（1)](http://blog.exbot.net/archives/1129)
- [拿ROS玩移动机器人自主导航攻略(2) ](http://blog.exbot.net/archives/2308)
- [ROS 新手问题Q&A粗略合集](http://blog.exbot.net/archives/1838)
- [ROS探索总结（十五）——amcl（导航与定位）](http://blog.exbot.net/archives/2147)
- []()





# 基础学习
## [安装ROS在Ubuntu 16.04](http://blog.csdn.net/softimite_zifeng/article/details/78632211)
[ROS kinetic官网](http://wiki.ros.org/kinetic/Installation/Ubuntu)


1. 配置Ubuntu的资源库："restricted"，"universe"和"multiverse"。一般情况是不用配置的，参考下图红色框部分。

2. 设置Ubuntu的sources.list

```
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'  
```

3. 设置key

```
sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116  
```

如果无法连接上述服务器，可以尝试hkp://pgp.mit.edu:80或者hkp://keyserver.ubuntu.com:80


4. 更新package

```
sudo apt-get update  
```

5. 安装ROS kinetic完整版 

```
sudo apt-get install ros-kinetic-desktop-full  
```

安装完可以查看可用的package：

```
apt-cache search ros-kinetic  
```

6. 初始化rosdep
在使用ROS之前必须要初始化rosdep

```
sudo rosdep init  
rosdep update  
```

7. 配置环境




[plain] view plain copy 
01.echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc  
02.source ~/.bashrc  


8. 安装building package的依赖 



[plain] view plain copy 
01.sudo apt-get install python-rosinstall python-rosinstall-generator python-wstool build-essential  


9. 测试ROS安装成功
1) 打开Termial，输入以下命令，初始化ROS环境：




[plain] view plain copy 
01.roscore  




2) 打开新的Termial，输入以下命令，弹出一个小乌龟窗口：



[plain] view plain copy 
01.rosrun turtlesim turtlesim_node  







3) 打开新的Termial，输入以下命令，可以在Termial中通过方向键控制小乌龟的移动：



[plain] view plain copy 
01.rosrun turtlesim turtle_teleop_key  







4) 打开新的Termial，输入以下命令，弹出新的窗口查看ROS节点信息：

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
 # 在arbotix_ros文件夹下新建文件夹src,将arbotix_ros目录下的所有文件剪切放到src文件夹下;
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
编译时出错。有opengl时。
```
sudo rm /usr/lib/x86_64-linux-gnu/libEGL.so; sudo ln /usr/lib/x86_64-linux-gnu/libEGL.so.1 /usr/lib/x86_64-linux-gnu/libEGL.so
sudo rm /usr/lib/x86_64-linux-gnu/libGL.so; sudo ln /usr/lib/x86_64-linux-gnu/libGL.so.1 /usr/lib/x86_64-linux-gnu/libGL.so

```
### 用cudn 9.1 出错
***大坑，这个事我花了四天。差点重装了机器。***

9。1改了个参数，有些软件不认。https://github.com/CPFL/Autoware/issues/1009

解决方法。https://devtalk.nvidia.com/default/topic/1023476/boost-under-cuda-9/

```
After removing this macro from CUDA9 header file(/usr/local/cuda/include/crt/common_functions.h), then this error don't occur.
#define __CUDACC_VER__ "__CUDACC_VER__ is no longer supported. Use __CUDACC_VER_MAJOR__, __CUDACC_VER_MINOR__, and __CUDACC_VER_BUILD__ instead."
Note that if you want to use Boost under CUDA 9 it is necessary to put:

#define __CUDACC_VER__ 90000 
```

## 安装百度机器人[apollo]( http://apollo.auto/)

```
docker pull apolloauto/apollo:dev-x86_64-20180123_1329
```

### Installation

We strongly recommend building Apollo in our pre-specified Docker environment. See the following instructions on how to set up the docker environment and build from source. The steps are:

- Run a machine that runs linux (tested on Ubuntu 16.04 with and without an nVidia GPU)
- Create a docker environment
- Build Apollo from source
- Bootstrap start Apollo
- Download the demonstration loop and run it
- Start a browser session and see the Dreamview user interface

```
sudo usermod -aG docker "$USER"
docker ps
docker pull registry.docker-cn.com/apolloauto/apollo:dev-x86_64-20180123_1329
```

### 
## Unbuntu 16.04安装

### 官网下载.iso文件
### UtraISO刻到U盘
### U盘启动
thinkpad 笔记本会出现错误。

按TAB键，按提示输入：

    live 或者live-install.
其它安装方式。一下主分区，其它都扩展。也可以用**gparts**进行分区或者激活分区。
安装各种更新和驱动，否则可能不能继续安装。如果出现不能继续的情况，退出到桌面再进一次安装程序。
    
分区分三个：

- 主分区建议40G，/，系统分区。
- swap分区格式放交换文件， 单独，不用备份。
- 子分区建议20G，/home， 用户分区，一般只用备份/home就行。

### [设置分辨率](http://blog.sina.com.cn/s/blog_612aec5d0102wsei.html)

```
cvt 1600 900
sudo gedit ~/.profile
xrandr --newmode "1600x900_60.00" 118.25 1600 1696 1856 2112 900 903 908 934 -hsync +vsync
xrandr --addmode Virtual1 "1600x900_60.00"
xrandr -s "1600x900_60.00"
```
### Unbuntu 基本命令

- 启动命令窗口
 
```
ctr alt t 
```

- 更新系统 
``` 
sudo apt update
sudo apt upgrade
```
- 查看系统信息:
```
gnome-system-monitor
```

- 查看分区信息，并调整 分区。 **gpart**
- 查ip
```
ifconfig
```
- 设置su。
```
sudo passwd root
su
```


### 安装远程访问

[使用Windows 10远程控制Ubuntu 16.04](http://www.linuxidc.com/Linux/2016-12/138600.htm)，网上很多需要安装xfce桌面的。今天介绍一下，不需要安装其他桌面，使用Ubuntu 16.04自带桌面，漂亮美观。

Ubuntu16.04端：

1、打开终端，安装xrdp,vncserver

```
sudo apt-get install xrdp vnc4server xbase-clients
```

2、安装desktop sharing（Ubuntu16.04默认已经安装），可以到应用商店下载。打开desktop sharing，设置如下：

```
cd /usr/share/applications
 
```

3、安装安装dconf-editor，取消权限限制：

```
sudo apt-get install dconf-editor
```

dconf-editor设置：org > gnome > desktop > remote-access，取消 “requlre-encryption”

Windows 10端：

搜索远程桌面连接，输入Ubuntu的ip地址，点击连接。

选择(console)vnc-any，输入Ubuntu的ip地址，端口不变（5900），桌面共享设定的密码，即可远程连接到ubuntu 16.04桌面。

### 安装samba用于共享

1、在Ubuntu 15.04系统下面安装samba服务：
```
安装samba：sudo apt-get install samba
安装smbclient：sudo apt-get install smbclient
sudo apt-get install system-config-samba
sudo touch /etc/libuser.conf
```

2、关闭Ubuntu的防火墙
sudo service ufw stop

3、配置smb.conf文件

step 1 先进入配置文件的目录，然后切换到管理员权限
cd /etc/samba/
su
Password: 

step 2 先把 smb.conf备份一下，以防操作不当，还可以把该文件恢复回来
root@www.linuxidc.com:/etc/samba# cp smb.conf smb.conf.bak

step 3 用vim打开smb.conf,把193行到200行修改成如下图所示：

这里写图片描述

4、添加samba添加一个root用户
root@www.linuxidc.com:/etc/samba# smbpasswd -a root
New SMB password:
Retype new SMB password:

输入密码，我这里输入的是root用户，也可以输入其他的存在用户名。

5、重启sam服务
service smbd restart


访问方式为用户，加密。 如果选用共享，会出错。
1、win10无法访问，也不让输密码。调用 control userpasswords2 ， 设置windows凭据。

### docker

#### [Ubuntu下安装](https://doc.docker.com/install/linux/docker-ce/ubuntu) 

```
sudo apt-get install apt-transport-https ca-certificates   curl     software-properties-common

curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo apt-key fingerprint 0EBFCD88

sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"

sudo apt-get update
sudo apt-get install docker-ce
apt-cache madison docker-ce
```

#### Ubuntu 使用中国镜像
直接在设置里选择服务器，有

Ubuntu 的软件源配置文件是 /etc/apt/sources.list。将系统自带的该文件做个备份，将该文件替换为下面内容，即可使用 TUNA 的软件源镜像。


选择你的ubuntu版本:  12.04 LTS 14.04 LTS 16.04 LTS 15.04 15.10 16.10 17.04  


```  
# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-updates main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-backports main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-backports main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-security main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-security main restricted universe multiverse
```

#### docker 加速

国内因为不可描述的原因，下镜像很慢。所以在setting的daemon加

- https://docker.mirrors.ustc.edu.cn
- https://registry.docker-cn.com

设置docker不用sudo运行，需要重新logout/login
```
sudo usermod -aG docker "$USER"
```
设置镜像，果然很快。
```
sudo gedit /etc/docker/daemon.json
{  
     "registry-mirrors": ["https://docker.mirrors.ustc.edu.cn","https://registry.docker-cn.com"]  
}

sudo systemctl daemon-reload
sudo systemctl restart docker  

```

#### 做一个web服务器
```
docker run -d -p 8080:80 --name webserver nginx
```
注意前面是在外面访问的端口，后面是系统提供服务的端口，通常是80。
Run the app, mapping your machine’s port 4000 to the container’s published port 80 using -p:

#### https://download.docker.com/linux/ubuntu/dists/

### [Ubuntu 16.04安装CUDA9+Docker CE+NVIDIA-Docker+TensorFlow/XGBoost](http://blog.csdn.net/baobei0112/article/details/79031621)
### 在HP xps 8930上安装双系统

#### 认硬盘

插入ubuntu安装U盘，选择U盘启动，安装系统，找不到机器自带的硬盘。dell用的是raid模式，没有驱动。启动时按ESC，按F2进入bios。要在bios中改为acpi模式，就可以了硬盘。

##### windows认硬盘
dell的硬盘是raid的，在bios改为acpi后，windows启不来。要在改前让windows进为安全模式。在bios改为acpi后，进入安全模式后，启动后，改为正常模式，就没问题了。
```
msconfig
``` 

#### 安显卡[ubuntu认显卡](http://blog.csdn.net/baidu_37071386/article/details/78882062)

安装完成后，不认双显卡，启不来。
```
启动菜单时按e， quiet splash nomodeset， f10
```
安装了nvidia 384后，关闭uefi的安全模式。可能会造成windows重装。
 看到最新版是375，然后： 
1、在你的用户登录界面按ctrl+alt+F1进入tty模式 
2、输入你的账户名和密码 
3、依次运行如下语句(需要联网)：
```
sudo apt-get purge nvidia-*  //删除现有驱动
sudo add-apt-repository ppa:graphics-drivers/ppa
sudo apt-get update
sudo apt-get install nvidia-375   //nvidia-后面的数字是版本号
sudo reboot //重启
sudo sh cuda_8.0.44_linux.run --override --tmpdir=/home/user/tmp

```
安装
去nvidi http://www.geforce.cn/drivers
```
http://mirrors.163.com/ubuntu/pool/main/l/linux-hwe/linux-headers-4.13.0-36-generic_4.13.0-36.40~16.04.1_amd64.deb
sudo dpki -i 
sudo apt-get purge nvidia-* 
sudo gedit /etc/modprobe.d/blacklist-nouveau.conf
#with the following contents:
blacklist nouveau
options nouveau modeset=0

#Regenerate the kernel initramfs:
sudo update-initramfs -u
#and finally: reboot
sudo reboot

6、使用“Ctrl + Alt + F1”进入终端界面，登录
# 停止显示器
sudo service lightdm stop
# 检查是否还有nvidia的进程
lsmod | grep nouveau

7、在当前目录下安装显卡驱动

sudo ./NVIDIA-Linux-x86_64-381.22.run -no-opengl-files -no-x-check -no-nouveau-check
nvidia-smi

```

# 位置感知
## lidar 谷歌 [Cartographer]()
1. [谷歌Cartographer学习](https://www.cnblogs.com/hitcm/p/5939507.html)
2. [hitcm github](https://github.com/hitcm)

## rgb slam (simultaneous localization and mapping)
## vio 视觉惯性里程计（Visual-Inertial Odometry [VIO]）
[ref:vio的示例](www.cnblogs.com/hitcm/p/6327442.html)

## rtkgps 
## imu
## 数据融合， 卡尔曼滤波

# 机器视觉 opencv
# 人工智能 tensorflow 
## 安装UBuntu GPU tensorflow
http://blog.csdn.net/tengxing007/article/details/53941466

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









































