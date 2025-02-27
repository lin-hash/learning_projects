

Transformer
===========

.. image:: https://img.shields.io/badge/PyTorch-EE4C2C?style=flat&logo=pytorch&logoColor=white
    :target: https://pytorch.org
    :alt: PyTorch Dependency

**手动实现Transformer中的Self-Attention机制**

本仓库包含一个手动计算Self-Attention的Python实现示例，用于理解Transformer核心机制。代码展示了如何从输入向量逐步计算注意力分数、Softmax归一化及加权求和过程。

Usage
-----

在本项目中，我们通过一个简单的例子展示了如何手动实现自注意力机制。以下是核心步骤：

1. **准备输入（词嵌入向量）**：首先定义输入张量 `x`，表示词嵌入向量。
2. **初始化参数（Q、K、V矩阵）**：分别初始化查询（Query）、键（Key）和值（Value）矩阵。
3. **获取Q、K、V矩阵**：通过输入与权重矩阵的矩阵乘法来计算查询、键和值。
4. **计算注意力分数**：计算查询与键的点积以得到注意力分数。
5. **Softmax处理**：对注意力分数进行 Softmax 运算，得到每个输入的权重。
6. **加权求和**：通过将值矩阵与注意力权重相乘并求和来得到最终输出。

直接运行示例脚本查看Self-Attention计算过程：
    python self_attention_1.py

Installation
------------
     pip install torch
Requirements
^^^^^^^^^^^^
- Python 3.6+
- PyTorch 1.0+

Compatibility
-------------
已在以下环境验证：

- Linux/Windows/macOS
- PyTorch CPU版本

Licence
-------
MIT License. See LICENSE for more details.

Authors
-------

`transformer` was written by `lin-hash <2532206252@qq.com>`_.

Reference
-------
1. https://developer.aliyun.com/article/1635093
2. https://zhuanlan.zhihu.com/p/681532180
3. https://blog.csdn.net/weixin_42475060/article/details/121101749
