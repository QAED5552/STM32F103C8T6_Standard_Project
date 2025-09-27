### 本工程文件结构如下：
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


### 目录说明

| 目录层级 | 用途说明 |
|---------|---------|
| **app** | 应用程序核心代码，包含业务逻辑实现 |
| **cmsis** | ARM Cortex-M微控制器标准接口，提供硬件抽象层 |
| **driver** | 硬件驱动程序分层实现 |
| **custom** | 用户自定义驱动，如传感器、外设驱动 |
| **system** | 官方系统驱动，如GPIO、UART、SPI等基础驱动 |
| **project** | 工程配置与构建系统 |
| **startup** | 系统启动文件，包含复位处理和中断向量表 |
| **eide** | Embedded IDE配置文件，支持VSCode开发环境 |
| **keil** | Keil MDK工程专用配置文件 |

> 注：此结构支持Keil MDK和EIDE双开发环境，其中 `.cmsis` 和 `.eide` 目录为EIDE专用配置，`keil` 目录为Keil MDK专用配置。
