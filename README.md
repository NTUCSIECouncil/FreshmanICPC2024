# Freshman ICPC 2024

**Host by CSIE Academic 47th**

## Judge

https://academic-judge.csie.ntu.edu.tw/

## Problem content

### Problem ID

- 2024[A-P]：正式賽題目
- test[A-Z]：測試用題目

branch 的命名請用年份加題號，例如 `2024A`、`2024O`。題目資料夾的命名請單用題號，例如 `A`、`O`。

### What you need to do

```
git branch <PROBLEM_ID>
git checkout <PROBLEM_ID>
# do something
git add <something>
git commit 		# Commit on branch PROBLEM_ID
git push origin <PROBLEM_ID>
```

### File Hierarchy

```
<PROBLEM_ID>
├── problem.json
├── subtasks.json
├── solutions.json
├── gen/
│   ├── Makefile
│   ├── manual/
│   │   ├── sample1.in
│   │   ├── sample2.in
│   │   └── ......
│   ├── gen.cpp
│   ├── data
│   └── ......
├── solution
│   ├── sol.cpp
│   ├── another_ac_sol.cpp (optional)
│   ├── wa_corner_case.cpp (optional)
│   ├── tle_infinite_loop.cpp (optional)
│   └── ......
├── scripts -> ../tps_scripts
├── statement
│   ├── description.md
│   ├── input.md
│   ├── output.md
│   ├── hints.md (optional)
│   └── ......
├── checker/ (optional)
└── validator/
    ├── Makefile
    └── val.cpp
```

反正就是 [tps](https://github.com/ioi-2017/tps) 格式，你可以直接複製 `template` 這個資料夾以獲得**不需要 checker**的題目格式，如果需要使用 checker，請複製 `template_with_checker` 這個資料夾。

以下簡單說明題目資料夾中每個東西的功用：
- `problem.json`: 大多數都不用動，只要改裡面的 `code`（改成 `<PROBLEM ID>`）跟 `title`（顯示在題目敘述的題目名稱）就好，如有需要的話可以改 `time_limit`（單位是秒）和 `memory_limit`（單位是 MiB）。
- `subtasks.json`：不用動。
- `solutions.json`：用來描述 `solution/` 裡每個 solution 的預期 verdict，不用改也沒關係。
- `gen/`：用來放生測資相關的東西
  - `Makefile`：用來編譯出任何生成器，並以 `.exe` 為副檔名。
  - `manual`：用來放手生的測資。
  - `gen.cpp`：生成器的 code（也可以是別的檔名或有很多檔案），不一定要用 C++ 寫。
  - `data`：用來敘述該怎麼生成你的測資們，詳細的說：
    - `gen 123 123 123` 代表執行 `gen.exe 123 123 123`
    - `QAQ qqqq 123 456` 代表執行 `QAQ.exe qqqq 123 456`
    - 也就是說，工具會在第一個字串加上 .exe 後，把後面的東西當成 argument 貼在後面執行
    - 特別的是，以 manual 開頭的指令代表著直接複製在 manual 資料夾內手生的測資
    - 例如：`manual sample1.in` 代表這筆測資輸入是直接複製 `manual/sample1.in`。
- `solution`：用來存放任何解
  - `sol.cpp`：標準程式碼，如果你換了檔名，記得去 `solutions.json` 裡面改一下。
    - 注意到由於我懶得把它改成可以跑 C，所以 `.c` 是不能跑的，但請盡量讓純 C 可以不太麻煩地過。
  - 這個資料夾內可以放其他解、假解、驗題者的解……等等。
- `statement`：用來放題目敘述的地方，每個檔案分別對到 TIOJ 題敘的每個框框，Markdown 格式，支援 LaTeX。
- `checker`：放 checker 的地方，`checker.cpp` 是 checker 本人。（沒有 checker 就不需要有這個資料夾）
- `validator`：用來放**測資檢查器**.
  - `Makefile`：用來編譯出任何檢查器，並以 `.exe` 為副檔名。
  - `val.cpp`：檢查器的 code，不一定要用 C++ 寫，但如果你換了檔名，記得去 `subtasks.json` 裡面改一下。

一些可以參考的教學：
- [程式解題社 20240304 社課](https://hackmd.io/@wiwiho/20240304)
- [TPS document](https://github.com/ioi-2017/tps/tree/master/docs)
- [Briefly about testlib.h](https://codeforces.com/testlib)
- [Polygon 使用指北](https://hackmd.io/@omeletwithoutegg/HJtQcQ0vB)（有一些 testlib 的使用教學）

如果你覺得以上的東西很麻煩，你可以：
- 把所有測資 input 檔案放進 manual，然後寫進 data 裡面。
- 把標程放在 `sol.cpp`。
- **強烈建議要有 validator**，但如果你真的暫時不想寫，可以去 `subtasks.json` 裡把 `global_validators` 改成空的。

### 出題工具

如果你照著建議的格式出題，那可以在 Linux 環境下使用酷酷的工具幫助你測試：

如果你還沒安裝 TPS，可以打
```
bash -c "$(curl -fsSL https://raw.githubusercontent.com/ioi-2017/tps/master/online-installer/install.sh)"
```
如果有缺少的 package，反正就缺什麼裝什麼。

在你的 problem directory 裡面下：
```
tps gen
```
就會有測資被生出來。

在你的 problem directory 裡面下：
```
tps invoke ${path-to-code}
```
就可以在測資已經生好的前提下，對位於 `path-to-code` 這個路徑的程式碼進行測試。

## 格式檢查與自動上傳

_[Note：discord 系統頻道尚未啟用]_

只要題目 push 到這個 repo，所有有修改的題目資料夾就會被自動檢查格式並嘗試上傳到 judge，基本上只要按照上述的格式就沒問題。檢查和上傳成功與否會回報在 discord 系統頻道，同時附上執行紀錄。比較需要注意的是，如果你有自己編譯任何東西的執行檔，並且它沒有副檔名，請記得不要把它 push 上來。

通過格式檢查的題目會被自動上傳到 judge，每個題目在 `contest_config.json` 裡會有自己的設定，例如：
```json
"template": {
    "auto-upload": true,
    "id": 1,
    "type": "test"
}
```
`template` 對應題目資料夾的名字。`auto-upload` 代表是否要自動上傳，取消的話不會上傳也不會檢查格式。`type` 有：
- `test`：純測試用題目。
- `practice`：測機用題目。
- `contest`：比賽題目。
`id` 代表在 judge 上的題目編號，這裡可以看到上傳到 judge 後你的題目應該要出現在哪一題。這個檔案應該已經寫好了，不需要自己去改。

如果你發現 discord bot 有收到你的 commit，但過很久之後 judge 上的題目都沒有更新，bot 也不講話，那可能代表：
- 跑一次 `tps gen` 要花太多時間（目前設的時限是 10 分鐘，超過應該不太正常）。
- `tps gen` 中有 fail。
- 自動上傳的 server 因為不明原因死了。

### 強制上傳

_[Note：discord 系統頻道尚未啟用]_

手動檢查題目資料夾格式並嘗試上傳到 judge。在 Discord 的系統頻道打
```
!force-update ${commit or branch} ${problem ID}
```

## 生題本工具

（todo）

## Credit

- 這份文件抄自過去的新生盃 ICPC repo，感謝過去的負責人。
