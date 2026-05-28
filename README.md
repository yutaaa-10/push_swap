ゴール
引数で受け取った整数列を11個の操作だけを使って、
少ない operation 数でソートする命令列を出力するプログラム


全体の流れ
main
↓
input_parser
↓
stack生成
↓
strategy選択
↓
sort実行
↓
operation出力
↓
bench表示(optional)
↓
free


実行例
./push_swap 3 2 1
./push_swap --complex 3 2 1
./push_swap --bench --adaptive 3 2 1


詳細
•返り値はoperationたち
•操作は \n のみで区切られ、それ以外の区切り文字は使用してはならない。
•各アルゴリズムに対して主張される計算量クラスは、このモデルにおいて有効でなければならない。
•戦略の選択は、すべての有効な入力に対して機能しなければならない。選択フラグは、
入力のサイズや順序に関係なく機能しなければならない。
•パラメータが指定されていない場合、プログラムは何も表示せず、プロンプトを返すものとする。
•エラーが発生した場合は、標準エラー出力に「Error」と表示し、その後に\nを付加する
	エラーの例としては、引数が整数でない場合、整数が有効範囲外である場合、または値が重複してい	る場合などが挙げられます。
•選択された戦略名と計算量クラスは、--benchモードで取得可能でなければなりません。
	オプションのベンチマークモード（--bench）では、ソート後に以下を表示する必要があります：
	・計算された無秩序度（小数点以下2桁の%）。
	・使用された戦略名とその理論上の計算量クラス。
	・演算の総数。
	・各演算タイプのカウント（sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb,rrr）。
	・ベンチマーク出力は stderr に出力され、このフラグが指定された場合にのみ表示される必要がある
• 100個の乱数に対して、プログラムは以下の演算回数以下で処理する必要があります：
	◦ 合格基準：2000回未満（最低要件）
	◦ 良好な性能：1500回未満
	◦優れたパフォーマンス：700 演算未満
• 500 個の乱数に対して、プログラムは以下の演算数を使用する必要があります：
	◦合格：12000 演算未満（最低要件）
	◦良好なパフォーマンス：8000 演算未満
	◦優れたパフォーマンス：5500 演算未満


sort/
simplesort　(O(n^2))
	・挿入ソート
	・選択ソート
	・バブルソート
	・単純な最小値最大値抽出法

mediumsort O(n√n)
	・チャンクベースのソート
	・ブロックベースのパーティショニング方式
	・n個のバケットを用いたバケットソートの応用
	・範囲ベースのソート戦略


complexsort O(n log n)
	•基数ソートの適応 (LSD または MSD)
	•2つのスタックを使用したマージソートの適応
	•スタック分割を使用したクイックソートの適応
	•ヒープソートの適応
	•バイナリインデックスツリーによるアプローチ


ファイル構成
push_swap /
	Makefile
	pushs_swap
	README.md

	libft /
	ft_printf /

	input_parser /
	stack /
	disorder /
	operation /
	sort /
	bench /

	main.c

・main.c
引数を受け取り、parser、sort、benchを呼んでfreeをする
init_option
オプション設定を初期状態にする関数。
初期値を0に設定することで、--benchがないときはそのままにしてプログラムを進めることができる
main
引数解析、ソート実行、メモリ解放


・input_parser
引数解析、flag確認、int範囲、重複確認、stack生成を行う。
parse_args
コマンドライン引数を数字やフラグ、として読み取る関数
handle_flag
--benchやソートのフラグを処理する関数
is_strategy_flag
文字れるが戦略フラグかどうかを判定する

・error
print_error
標準エラーにerrorを出力する
number_check
文字列が整数として正しい形かを確認する関数
ft_atol
文字列をlong型にする
一度ロングで受け取って、そのあとintを超える範囲ならreturnする
has_duplicate
スタックないに同じ値があるか確認する関数

・stack
linked list補助関数
stack_new
新しいスタックノードを作る関数。
stack_add_back
スタックの末尾にノードを追加する関数。
free_stack
スタック全体のメモリを解放する関数。
stack_size
スタックの要素数を数える関数。

・operation
sa
stack A の先頭2つを入れ替える関数。
sb
stack B の先頭2つを入れ替える関数。
ss
sa と sb を同時に行う関数。
pa
stack B の先頭を stack A に移す関数。
pb
stack A の先頭を stack B に移す関数。
ra
stack A を上方向に1つ回転する関数。
rb
stack B を上方向に1つ回転する関数。
rr
ra と rb を同時に行う関数。
rra
stack A を下方向に1つ回転する関数。
rrb
stack B を下方向に1つ回転する関数。
rrr
rra と rrb を同時に行う関数。

route_sort
要素数や戦略に応じて使うソート関数を選ぶ関数。
sort_two
2個用のソート関数
sort_three
3個用のソート関数
sort_five
5個以下用のソート関数
simple_sort
simple戦略のソート関数、今は仮実装
medium_sort
medium戦略のソート関数
complex_sort
complex戦略のソート関数
adaptive_sortadaptive戦略のソート関数

disorder/
入力の乱れ具合を計算
初期のスタックがどれだけ綺麗に並べられているか
0に近いほど順番通りに、1に近いほど複雑な並びになる
大きい数値が小さい数値用も前にあると、カウントされてカウントの数が大きいほど複雑になる仕組み

disorder < 0.2 → simple
0.2 <= disorder < 0.5 → medium
0.5 <= disorder → complex


bench/
-bench 時のみ表示。
strategy
complexity
operation
operation回数

