# 手动实现计算Self-Attention的实现
# source: https://blog.csdn.net/weixin_42475060/article/details/121101749
# https://www.cnblogs.com/miners/p/15101283.html

import torch
from torch.nn.functional import softmax

# 1. 准备输入（词嵌入向量）
x = [
  [1, 0, 1, 0], # Input 1
  [0, 2, 0, 2], # Input 2
  [1, 1, 1, 1]  # Input 3
 ]
x = torch.tensor(x, dtype=torch.float32) #3*4

# 2. 初始化参数（Q、K、V矩阵）
'''
Q、K、V矩阵在神经网络初始化的过程中，一般都是随机采样完成并且比较小，
可以根据想要输出的维度来确定 Q、K、V矩阵的维度
这里是 4*3
'''
w_key = [
    [0, 0, 1],
    [1, 1, 0],
    [0, 1, 0],
    [1, 1, 0]
]
w_query = [
    [1, 0, 1],
    [1, 0, 0],
    [0, 0, 1],
    [0, 1, 1]
]
w_value = [
    [0, 2, 0],
    [0, 3, 0],
    [1, 0, 3],
    [1, 1, 0]
]
w_key = torch.tensor(w_key, dtype=torch.float32)
w_query = torch.tensor(w_query, dtype=torch.float32)
w_value = torch.tensor(w_value, dtype=torch.float32)

# 3. 获取key，query和value
keys = x @ w_key
querys = x @ w_query
values = x @ w_value

print("Keys: \n", keys)
# tensor([[0., 1., 1.],
#         [4., 4., 0.],
#         [2., 3., 1.]])

print("Querys: \n", querys)
# tensor([[1., 0., 2.],
#         [2., 2., 2.],
#         [2., 1., 3.]])
print("Values: \n", values)
# tensor([[1., 2., 3.],
#         [2., 8., 0.],
#         [2., 6., 3.]])

# 4. 计算注意力分数
attn_scores = querys @ keys.T
print(attn_scores)

# 5. 计算softmax
attn_scores_softmax = softmax(attn_scores, dim=-1)
print(attn_scores_softmax)
# tensor([[6.3379e-02, 4.6831e-01, 4.6831e-01],
#         [6.0337e-06, 9.8201e-01, 1.7986e-02],
#         [2.9539e-04, 8.8054e-01, 1.1917e-01]])

# 为了使得后续方便，这里简略将计算后得到的分数赋予了一个新的值
# For readability, approximate the above as follows
attn_scores_softmax = [
    [0.0, 0.5, 0.5],
    [0.0, 1.0, 0.0],
    [0.0, 0.9, 0.1]
]
attn_scores_softmax = torch.tensor(attn_scores_softmax)
print(attn_scores_softmax)

# 6. value乘上score
weighted_values = values[:,None] * attn_scores_softmax.T[:,:,None]
print(weighted_values)

# 7. 给value加权求和获取output(得到input1的结果向量)
outputs = weighted_values.sum(dim=0)
print(outputs)

# tensor([[2.0000, 7.0000, 1.5000],  # Output 1
#         [2.0000, 8.0000, 0.0000],  # Output 2
#         [2.0000, 7.8000, 0.3000]]) # Output 3