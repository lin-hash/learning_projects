pip install cookiecutter
git clone https://github.com/kragniz/cookiecutter-pypackage-minimal.git
默认使用模板：
cookiecutter cookiecutter-pypackage-minimal/

备选：
cookiecutter https://github.com/pytest-dev/cookiecutter-pytest-plugin

一般目录结构：
ProjectName
│ readme 项目说明文档
│ requirements.txt 存放依赖的外部Python包列表
│ setup.py 安装、部署、打包的脚本
├─ bin 存放脚本，执行文件等
│ └─ projectname
├─ docs 文档和配置
│ └─ abc.rst
│ └─ conf.py 配置文件
└─ projectname 工程源码（包括源码、测试代码等）
│ main.py 程序入口
│ init.py
└─ tests 测试代码
└─ test_main.py
└─ init.py