# About
ただのCUI Tetrisとくに凝ったところもない
しいて言うならマップのサイズを調整できたり,新たなブロックを手動で追加できるくらい.

# Setting
- ブロックの追加
-- tetrisPattern.cpp のinitPatternメソッドに使用するサイズにリサイズしてvstrcpyで代入してください.

- マップのリサイズ
-- tetris.h の MAP_WIDTHで横幅, MAP_HIGHで縦幅を指定してください.

