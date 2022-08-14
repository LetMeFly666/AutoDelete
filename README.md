# AutoDelete

Automatically Delete files according to your settings By [LetMeFly](https://letmefly.xyz)

Project URL: [https://autodelete.letmefly.xyz/](https://autodelete.letmefly.xyz/)

## 程序说明

### 执行自动删除

双击程序即可运行，程序将会默认每300秒执行一次，依据您的设置删除已至删除日期的文件。

### 添加自动删除

选择你想要定时删除的文件，```右键 -> 打开方式 -> AutoDelete```

<small>首次使用时打开方式中没有“AutoDelete”，需要<kbd>右键 -> 打开方式 -> 更多应用 -> 在这台电脑上查找其他应用 -> 找到并选择AutoDelete.exe</kbd>。注意，如果系统默认勾选了“始终使用此应用打开xx文件”，最好手动取消勾选</small>

然后输入你想要自动删除的时间即可。

**时间格式：** 您可以使用以下格式设置自动删除的时间：

|格式|示例|说明|
|:--:|:--:|:--:|
|_h|5h|5小时后删除|
|_d|5d|5天后删除|
|_w|1w|1周后删除(1w=7d)|
|_m|3m|3月后删除(1m=30d)|
|_y|1y|1年后删除(1y=365d)|
|yyyy-mm-dd|2022-08-14|2022年08月14日0时删除|

注意，该程序中1年就是365天，1月就是30天。如果您在```7月7日```设置了```一个月后删除```，那么实际删除日期将会是```8月6日```而不是```8月7日```（7月有31天）
