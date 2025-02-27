
#一个简单的Transformer模型的PyTorch实现示例
# source: https://developer.aliyun.com/article/1635093

import torch
import torch.nn as nn

class PositionalEncoding(nn.Module):
    def __init__(self, d_model, max_len=5000):
        super(PositionalEncoding, self).__init__()
        pe = torch.zeros(max_len, d_model)
        position = torch.arange(0, max_len, dtype=torch.float).unsqueeze(1)
        div_term = torch.exp(torch.arange(0, d_model, 2).float() * (-torch.log(torch.tensor(10000.0)) / d_model))
        pe[:, 0::2] = torch.sin(position * div_term)
        pe[:, 1::2] = torch.cos(position * div_term)
        pe = pe.unsqueeze(0).transpose(0, 1)
        self.register_buffer('pe', pe)

    def forward(self, x):
        x = x + self.pe[:x.size(0), :]
        return x

class TransformerModel(nn.Module):
    def __init__(self, ntoken, d_model, nhead, nhid, nlayers, dropout=0.5):
        super(TransformerModel, self).__init__()
        self.model_type = 'Transformer'
        self.src_mask = None
        self.pos_encoder = PositionalEncoding(d_model)
        self.encoder = nn.Embedding(ntoken, d_model)
        self.transformer = nn.Transformer(d_model, nhead, nlayers, nlayers, nhid, dropout)
        self.decoder = nn.Linear(d_model, ntoken)

        self.init_weights()

    def init_weights(self):
        initrange = 0.1
        self.encoder.weight.data.uniform_(-initrange, initrange)
        self.decoder.bias.data.zero_()
        self.decoder.weight.data.uniform_(-initrange, initrange)

    def generate_square_subsequent_mask(self, sz):
        mask = (torch.triu(torch.ones(sz, sz)) == 1).transpose(0, 1)
        mask = mask.float().masked_fill(mask == 0, float('-inf')).masked_fill(mask == 1, float(0.0))
        return mask

    def forward(self, src, has_mask=True):
        if has_mask:
            device = src.device
            if self.src_mask is None or self.src_mask.size(0) != len(src):
                mask = self.generate_square_subsequent_mask(len(src)).to(device)
                self.src_mask = mask
        else:
            self.src_mask = None

        src = self.encoder(src) * math.sqrt(self.d_model)
        src = self.pos_encoder(src)
        output = self.transformer(src, src, self.src_mask)
        output = self.decoder(output)
        return output

# 示例使用
ntokens = 10000  # 词汇表大小
d_model = 512    # 嵌入维度
nhead = 8        # 多头注意力机制的头数
nhid = 2048      # 前馈网络的维度
nlayers = 6      # 编码器和解码器的层数
dropout = 0.5    # Dropout概率

model = TransformerModel(ntokens, d_model, nhead, nhid, nlayers, dropout)
src = torch.randint(0, ntokens, (10, 32))  # (序列长度, 批量大小)
output = model(src)
print(output.shape)  # 输出形状应为 (序列长度, 批量大小, 词汇表大小)
