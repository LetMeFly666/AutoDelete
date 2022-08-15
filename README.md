# AutoDelete

Automatically Delete files according to your settings By [LetMeFly](https://letmefly.xyz)

Project URL: [https://autodelete.letmefly.xyz/](https://autodelete.letmefly.xyz/)

Download: [Click Me](#Download666)

## 程序说明

### 执行自动删除

双击程序即可运行，程序将会默认每300秒执行一次，依据您的设置删除已至删除日期的文件。

### 添加自动删除

选择你想要定时删除的文件，```右键 -> 打开方式 -> AutoDelete```

<small>首次使用时打开方式中没有“AutoDelete”，需要<kbd>右键 -> 打开方式 -> 更多应用 -> 在这台电脑上查找其他应用 -> 找到并选择AutoDelete.exe</kbd>。注意，如果系统默认勾选了“始终使用此应用打开xx文件”，最好手动取消勾选</small>

<small>或者你也可以在<kbd>计算机\HKEY_CLASSES_ROOT\*\shell\</kbd>下新建<kbd>设置定时删除(AutoDelete)\command</kbd>，并把默认值设置为<kbd>程序路径 %1</kbd>（如<kbd>F:\LetMeFly\TFpath\AutoDelete.exe %1</kbd>）。这样，在某个文件上，就可以直接```右键 -> 设置定时删除```</small>

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

## 下载

<a id="Download666"></a>

+ 下载地址页面：[https://github.com/LetMeFly666/AutoDelete/releases/tag/v0.0.1](https://github.com/LetMeFly666/AutoDelete/releases/tag/v0.0.1)
+ 下载地址镜像：[https://hub.fastgit.xyz/LetMeFly666/AutoDelete/releases/tag/v0.0.1](https://hub.fastgit.xyz/LetMeFly666/AutoDelete/releases/tag/v0.0.1)
+ **单文件下载地址**：[https://github.com/LetMeFly666/AutoDelete/releases/download/v0.0.1/AutoDelete.exe](https://github.com/LetMeFly666/AutoDelete/releases/download/v0.0.1/AutoDelete.exe)
+ 单文件下载镜像：[https://hub.fastgit.xyz/LetMeFly666/AutoDelete/releases/download/v0.0.1/AutoDelete.exe](https://hub.fastgit.xyz/LetMeFly666/AutoDelete/releases/download/v0.0.1/AutoDelete.exe)
+ DLL文件下载地址（若提示**找不到DLL文件**，则可下载并解压至程序所在目录）：[https://github.com/LetMeFly666/AutoDelete/releases/download/v0.0.1/Dlls.Because.of.Visual.Sutdio.zip](https://github.com/LetMeFly666/AutoDelete/releases/download/v0.0.1/Dlls.Because.of.Visual.Sutdio.zip)
+ DLL文件下载镜像：[https://hub.fastgit.xyz/LetMeFly666/AutoDelete/releases/download/v0.0.1/Dlls.Because.of.Visual.Sutdio.zip](https://hub.fastgit.xyz/LetMeFly666/AutoDelete/releases/download/v0.0.1/Dlls.Because.of.Visual.Sutdio.zip)
+ 32位版本下载地址：[https://github.com/LetMeFly666/AutoDelete/releases/download/v0.0.1/AutoDelete-v0.0.1-x86.zip](https://github.com/LetMeFly666/AutoDelete/releases/download/v0.0.1/AutoDelete-v0.0.1-x86.zip)
+ 32位版本下载镜像：[https://hub.fastgit.xyz/LetMeFly666/AutoDelete/releases/download/v0.0.1/AutoDelete-v0.0.1-x86.zip](https://hub.fastgit.xyz/LetMeFly666/AutoDelete/releases/download/v0.0.1/AutoDelete-v0.0.1-x86.zip)


## TODO:

+ [ ] 设置命令行传参机制，支持多种运行方式：缓存位置、间隔运行时长、运行次数等。
+ [ ] 设置支持配置文件的读取，可以保持配置，以便日后使用时不传参而直接运行
+ [ ] 设置待删除文件转移机制，如：移动待删除文件到临时文件夹，并发送快捷方式至原文件处，快捷方式命名为“原文件名-xxx时删”
+ [ ] 添加图形化界面
+ [ ] 其他系统的支持
+ [ ] 时间范围：2038年1月19日11:14:07，32位UNIX时间戳将会用尽，因此此程序暂不支持之后的时间设置。并且程序中限定时间戳是10位数字，因此2001年9月9日09:46:40之前的时间也不支持设置（都过去了还定啥时呢）

## Warn:

+ 尽量不要设置太久之后的时间，否则到时候可能忘了。比如：设置了“某小H文1年后自动删”，但是过了半年后给这件事情忘了，又在原有基础上进行了二次创作，辛辛苦苦写了半年。结果一年了，再次运行这个程序时，程序遵循你之前的设定，把这个文件删了，那就hh了。
+ 程序需要执行时才会删除文件。
+ 该删除程序具有一定的危险性，请谨慎使用。开发者没有承担可能造成的损失的义务。但是可以放心的是，我作为开发者已经进行了很多测试（但未Fuzz），并且我自己也在使用。
