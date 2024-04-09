"""
行に並べられた0からN-1までのN個のブロックがあります。ある日、一緒にいたカエルのペアが大喧嘩をしました。今では、お互いからできるだけ距離を置きたいと思っています。ブロック番号JとK（J<K）の間の距離はK - J + 1として計算されます。カエルは上方向にしかジャンプできません、つまり、2つのブロックが隣接しており、2つ目のブロックが1つ目と同じかそれ以上の高さでなければ、1つのブロックから別のブロックに移動することはできません。初めに最適なブロックを選んだ場合、彼らはお互いに可能な限り最長の距離を作り出すことができますか？

以下のような関数を書いてください：
def solution(blocks)
これは、ブロックの高さを示すN個の整数からなる配列blocksを与えると、一つのブロックから始まってカエルがお互いに作り出すことができる最長の距離を返す関数です。

例：

blocks = [2, 6, 8, 5]の場合、関数は3を返します。blocks[0]から始まると、最初のカエルはその場に留まり、2番目のカエルはblocks[2]にジャンプすることができます（ただしblocks[3]にはジャンプできません）。
blocks = [1, 5, 5, 2, 6]の場合、関数は4を返します。blocks[3]から始まると、最初のカエルはblocks[1]にジャンプすることができますが、blocks[0]にはジャンプできません。2番目のカエルはblocks[4]にジャンプできます。
blocks = [1, 1]の場合、関数は2を返します。blocks[1]から始めると、最初のカエルはblocks[0]にジャンプし、2番目のカエルはその場に留まります。blocks[0]から始めても同じ距離になります。
以下の仮定に基づいた効率的なアルゴリズムを書いてください：
• Nは[2..200,000]の範囲内の整数です。
• 配列blocksの各要素は[1 .. 1,000,000,000]の範囲内の整数です。
"""

def solution(blocks):
    N = len(blocks)

    # Initialize arrays to store the maximum jumping distance.
    max_jump = [1] * N

    # Compute the maximum jumping distance from both sides.
    for i in range(1, N):
        if blocks[i - 1] <= blocks[i]:
            max_jump[i] = max(max_jump[i], max_jump[i - 1] + 1)

    for i in range(N - 2, -1, -1):
        if blocks[i] >= blocks[i + 1]:
            max_jump[i] = max(max_jump[i], max_jump[i + 1] + 1)

    return max(max_jump)
