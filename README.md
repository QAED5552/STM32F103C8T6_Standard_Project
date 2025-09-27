本工程文件结构如下：
├─app   <--用于存放应用代码
├─cmsis  <--官方硬件抽象层
├─driver
│  ├─custom  <--用户驱动层
│  │  ├─inc
│  │  └─src
│  └─system  <--官方驱动层
│      ├─inc
│      └─src
├─project  <--项目配置文件/信息
│  ├─eide
│  │  ├─.cmsis
│  │  │  └─include
│  │  ├─.eide
│  │  ├─.vscode
│  │  └─build
│  │      └─stm32f103c8t6
│  │          └─.obj
│  │              └─__
│  │                  └─__
│  │                      ├─app
│  │                      ├─cmsis
│  │                      ├─driver
│  │                      │  ├─custom
│  │                      │  │  └─src
│  │                      │  └─system
│  │                      │      └─src
│  │                      └─startup
│  └─keil
│      ├─DebugConfig
│      ├─Listings
│      └─Objects
└─startup  <--官方启动文件