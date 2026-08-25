** TARGET-REPORT-UID:0000BQ **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000BQ] RankingUserListPane Class Source-Quality Report

Agent: B005
Target: [UID:0000BQ] `by-class/RankingUserListPane.md`
Required report path: `tools/leaser/Agents/Agent-B005/research/0000BQ-RankingUserListPane-class-source-quality.md`
Assignment type: report-only B-preferred source-quality / heuristic-inference pass.

## Final Recommendation

Path to the code-entry gate is available. Recommend raising [UID:0000BQ] `RankingUserListPane` from `84/88` to `87/90`, preserving `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000MZ`, and `EMITTER_UIDS:0000MZ`.

The class belongs in [UID:0000MZ][RankingDialog](../../../by-file/RankingDialog.md) / `ui/dialogs/RankingDialog.cpp`. It is a private ranking-dialog child control constructed from the `RankingDialog` constructor at `0x0045875f`, not a standalone control module and not part of the category collection data model. The remaining uncertainty is original spelling of helper/member names, not source route or class identity.

Formal first-draft C++ should be populated on [UID:0000BQ], but as a class declaration only. Exact method bodies should remain on current/future exact by-memory children because the class page is an aggregate class surface. Include an `OnPaint` source-shape snippet in support docs or a future exact `0x0045f3a0-0x0045f945.RankingUserListPaneOnPaint` child; do not put the full paint body in the class declaration block unless the supervisor decides to keep the class page as the combined method emitter.

The important correction from this pass: older B002 ranking-category evidence is mostly valid, but the current docs overstate `RankingCategoryRecord +0x26c` as a proved `wchar_t localPlayerName[32]`. Parser and paint evidence do not support that. `RankingUserListPane::OnPaint` draws the footer name from global local-player name storage `word_69BEE0` via `0x005a2dc0`, then destroys the temporary wide-string wrapper. The `+0x26c-+0x2ab` record tail is copied by record deep-copy but is not written by the checked parsers and is not read by this class. Best current name is `m_reservedLocalPlayerFooter[0x40]` or `m_reservedLocalPlayerName[32]` only if the supervisor wants to preserve the likely planned wide-name shape with an explicit "reserved/unconsumed" qualifier.

No direct edits were made to `by-memory/-coverage-report.md`, generated files, target docs, or support docs.

## Evidence Checked

Guidance reread: `Agent-B005/goal.md`, `Agent-B005/notes.md`, `Supervisor.md`, `by-structure.md`, and `inference_research.md`. The B005 goal/notes file still recorded the previous paired input-handler assignment, so this report follows the user's latest supervisor assignment for [UID:0000BQ].

Live IDA MCP at the local endpoint was attempted and was unavailable (`Unable to connect to the remote server`). I used the current by-* docs plus the local IDA export under `C:\Users\admin\Desktop\CTools\Output\ida` (`decompile`, `memory`, function metadata). Existing docs that record earlier live IDA checks were treated as leads and revalidated where the local export allowed.

Docs and reports checked:

- Target [UID:0000BQ][RankingUserListPane](../../../by-class/RankingUserListPane.md).
- Owner/support docs [UID:0000MZ][RankingDialog](../../../by-file/RankingDialog.md), [UID:0000BM][RankingDialog](../../../by-class/RankingDialog.md), [UID:0000BL][RankingCategoryRecord](../../../by-class/RankingCategoryRecord.md), [UID:0000BK][RankingCategoryCollection](../../../by-class/RankingCategoryCollection.md), [UID:0001ZC][0x0045c260-0x0045d4f8.RankingCategoryCollection](../../../by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md), and [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](../../../by-memory/0x00458610-0x0045f9f5.RankingDialog.md).
- Data/vtable support [UID:0002ON][0x00610980-0x00610e38.RankingDialogReadOnlyData](../../../by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md), [UID:0001YJ][RankingDialogVtableFamily](../../../by-type/by-vtable/RankingDialogVtableFamily.md), and [UID:0001VN][RankingCategoryRecordLayout](../../../by-type/by-struct/RankingCategoryRecordLayout.md).
- Ignored compiler/runtime support [UID:0000YC][0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks](../../../by-memory/0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks.md), [UID:0000VN][-ignored](../../../by-memory/-ignored.md), and current coverage rows.
- Generated coverage/status docs: `project-level/-auto-completion-stats.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, `by-type/by-struct/-coverage-report.md`, `by-memory/-coverage-report.md`, and `by-memory/-ignored.md`.
- Required older report lead: `Agent-B002/research/executed/older/0001ZC-ranking-category-collection-source-quality.md`.

Local IDA export checked:

- Decompile JSON for `0x0045f340`, `0x0045f380`, `0x0045f3a0`, `0x0045f950`, `0x0045f9a0`, `0x0045c560`, `0x0045cb10`, `0x0045d420`, and `0x005a2dc0`.
- `memory.bin` byte windows around `0x0045f330-0x0045f3a8` and `0x0045f930-0x0045f9a8`.
- UTF-16 strings at `0x00610c5c`, `0x00610d70`, `0x00610d88`, `0x00610dd8`, `0x00610e20`, and `0x00610e2c`.

## Exact Range, Bytes, And Boundary

`RankingUserListPane` executable surface inside the ranking aggregate is:

| Range | Status | Role |
| --- | --- | --- |
| `0x0045f340-0x0045f377` | modeled function | Constructor; calls `ControlPane` constructor with control id `8`, then writes primary/secondary/tertiary vtables. |
| `0x0045f377-0x0045f380` | padding | Nine `0xcc` bytes. |
| `0x0045f380-0x0045f39f` | modeled function | Non-deleting destructor-shaped body; restores three vtables and jumps to base `Pane` teardown `0x00544580`; no direct callers in local export. |
| `0x0045f39f-0x0045f3a0` | padding | One `0xcc` byte. |
| `0x0045f3a0-0x0045f945` | modeled function | `OnPaint`; vtable-only reachability; no direct callers in local export. |
| `0x0045f945-0x0045f950` | padding | Eleven `0xcc` bytes. |
| `0x0045f950-0x0045f97d` | modeled function | Fixed `0x40`-wide-character CRT formatter wrapper; exactly nine call sites from `OnPaint`. |
| `0x0045f97d-0x0045f993` | code bytes / thunks | Two destructor adjustor thunks at `0x0045f97d` and `0x0045f988`; subtract `0xa0` / `0xa4`, jump to `0x0045f9a0`. |
| `0x0045f993-0x0045f9a0` | padding | Thirteen `0xcc` bytes. |
| `0x0045f9a0-0x0045f9f5` | modeled function | Scalar deleting destructor wrapper; restores vtables, runs base teardown, conditionally frees through `0x004f4ac0`. |
| `0x0045f9f5-0x0045fa00` | padding | Eleven `0xcc` bytes before the next ranking/render helper. |

Local byte checks confirm two half-open range corrections for support docs:

```text
0x0045f950-0x0045f97d:
55 8b ec 8d 45 10 50 6a 00 ff 75 0c 6a 40 ff 75
08 e8 3a c0 fb ff ff 70 04 ff 30 e8 a5 29 17 00
83 c9 ff 83 c4 1c 85 c0 0f 48 c1 5d c3

0x0045f97d-0x0045f993:
81 e9 a0 00 00 00 e9 18 00 00 00
81 e9 a4 00 00 00 e9 0d 00 00 00
```

The current target page already uses the correct formatter and thunk half-open ranges, but the ignored ledger and coverage row still use `0x0045f950-0x0045f97c` and `0x0045f97d-0x0045f992`. Those should be corrected to half-open `0x0045f950-0x0045f97d` and `0x0045f97d-0x0045f993`. [UID:0000YC] also has a filename/path mismatch if the supervisor chooses to rename it.

## Reachability, Vtables, And Read-Only Data

Constructor evidence:

- Local decompile metadata for `0x0045f340` reports one caller at `0x0045875f` in `sub_458610`, the `RankingDialog` constructor path.
- Constructor calls `0x004949e0` (`ControlPane` constructor) with control id `8` and then stores vtables `0x00610cd0`, `0x00610d38`, and `0x00610d68`.
- This proves the class is a `ControlPane` child and not a record/collection object.

Paint reachability:

- `0x0045f3a0` has no direct callers in local metadata because it is a virtual paint method.
- [UID:0001YJ] records the primary `RankingUserListPane` vtable slot `0x00610cd0 + 0x44 -> 0x0045f3a0`.
- The absence of ordinary callers is therefore expected and should not lower class/source confidence.

Destructor and thunk evidence:

- `0x0045f380` and `0x0045f9a0` both restore the same three vtable views, tying the ordinary destructor body and scalar deleting destructor wrapper to this class.
- Secondary and tertiary vtable slot-zero entries route through adjustor thunks at `0x0045f97d` and `0x0045f988`.
- The scalar deleting destructor and adjustor thunks should remain compiler-generated binary artifacts; source should declare a virtual destructor and let the compiler reproduce equivalent ABI glue.

Read-only data:

- `0x00610ccc-0x00610d70` is `RankingUserListPane` RTTI/vtable data in [UID:0002ON].
- `0x00610d70-0x00610e38` is label/format data consumed by `OnPaint`, not more vtable slots.
- Local UTF-16 decode confirms:
  - `0x00610c5c`: `Rank`
  - `0x00610d70`: `Total : %d`
  - `0x00610d88`: `From : %02d/%02d/%04d %02d:%02d:%02d`
  - `0x00610dd8`: `To : %02d/%02d/%04d %02d:%02d:%02d`
  - `0x00610e20`: `Name`
  - `0x00610e2c`: `Score`

## OnPaint Behavior And Source Names

Recommended source-facing method names:

| Address | Best source-facing name | Notes |
| --- | --- | --- |
| `0x0045f340` | `RankingUserListPane::RankingUserListPane(const RectBounds *bounds)` | Constructor passes `8` as the `ControlPane` id. If the project standardizes the bounds type as `Rect` or `RECT`, use that typedef; the source role is a pane bounds/layout pointer. |
| `0x0045f380` | `RankingUserListPane::~RankingUserListPane()` ordinary/non-deleting destructor body | Source destructor likely empty/default; binary emits vtable reset and base teardown. |
| `0x0045f3a0` | `RankingUserListPane::OnPaint()` | Vtable paint slot; source-authored behavior. |
| `0x0045f950` | `FormatWide64` / direct `swprintf_s(buffer, 64, ...)` | File-local formatting convenience or compiler CRT wrapper; do not hand-author the raw `__stdio_common_vswprintf_s` wrapper as a product method. |
| `0x0045f9a0` | scalar deleting destructor | Compiler-generated wrapper; source declaration of the virtual destructor is enough. |

`OnPaint` source behavior:

1. Initializes a local EPF/tile context (`0x00457a60`) and local region/object (`0x00554680`).
2. Loads the ranking background/layout resource through `g_pEPFLib` / `dword_67A744` and `off_60DB5C`, then draws the tiled background with `0x004ba6b0(..., off_60DB78)`.
3. Releases the local region/object with `0x004f4a90`.
4. Reads selected ranking category from `g_pRankingDialog + 0x26c` through `0x0045ce70`, best named `RankingCategoryCollection::GetSelectedRecord()`.
5. If no selected record exists, only the background is drawn.
6. Sets text colors with generic GrafPort/control helpers (`0x004b9680`, `0x004b9690`) and draws the category title at `(30,24)`.
7. Formats/draws total count from `record + 0x254` at `(380,24)`.
8. Copies and formats start/end time parts through `0x0045bf90` and `0x0045bfb0`, drawing `From` at `(30,50)` and `To` at `(210,50)`.
9. Draws headers `Rank`, `Name`, `Score` at x positions `50`, `150`, and `390`, y `78`.
10. Loops for ten rows. For each `RankingUserEntry *row = record->GetUserEntryAt(i)`, draws `row->rank` (`+0x04`), `row->name` (`+0x08`), and `row->score` (`+0x48`) at y values starting `100` and advancing by `30`.
11. Draws a three-pixel separator line at y `384..386` from x `30` to `490`.
12. If `record->localPlayerRank` (`+0x268`) is positive, draws that rank, formats the global local-player name via `0x005a2dc0` / `word_69BEE0`, and draws `record->localPlayerScore` (`+0x2ac`).

Best helper role names:

| Address | Role/name recommendation |
| --- | --- |
| `0x004bacd0` | `DrawOutlinedText` / `DrawTextWithShadow`, generic control/GrafPort dependency. |
| `0x004b9680` | `SetTextColor` / foreground color setter, generic dependency. |
| `0x004b9690` | `SetTextShadowColor` / outline color setter, generic dependency. |
| `0x004b9660` | `SetDrawColor`, generic dependency used before separator lines. |
| `0x004b9600` | `MoveTo` / current draw cursor setter. |
| `0x004b98f0` | `LineTo` / relative draw callback line helper. |
| `0x004b7c30` | `SetPoint` / point helper. |
| `0x005a2dc0` | `MakeLocalPlayerNameString` / `GetLocalPlayerNameString`, constructs a temporary wide-string wrapper from `word_69BEE0`. |

Rejected names:

- `RankingCategoryRecord::GetLocalPlayerName()` for the footer path: rejected. `OnPaint` calls `0x005a2dc0`, whose decompile is `sub_582560(a1, word_69BEE0); return a1;`, with callers outside Ranking as well. It does not read the record.
- Ranking-owned `LineTo`, `DrawOutlinedText`, or `SetColor` methods: rejected as direct ownership. Those helpers are generic drawing/control dependencies used elsewhere and should remain in GrafPort/control support docs.
- Standalone `RankingUserListPane.cpp`: rejected as primary route for now. Current ranking docs consistently place the private ranking child controls in one `RankingDialog.cpp` feature module, and there is no contrary string/path/class export evidence proving a separate original file.

## B002 Ranking-Category Claims Revalidated

The older B002 report `0001ZC-ranking-category-collection-source-quality.md` was useful but not authority. Current validation result:

| Claim area | Result | Evidence |
| --- | --- | --- |
| Record stride `0x2b0` / 688 bytes | Validated | Collection/deep-copy helpers and docs use record stride 688. |
| Date/time part blocks | Validated | `0x0045bf90` / `0x0045bfb0` copy 36 bytes; packed setters write second/minute/hour/day/month/year order plus three reserved copied dwords. |
| Title and total count | Validated | `0x0045bfd0` returns `+0x54`; OnPaint formats `record[149]` / `+0x254` with `Total : %d`. |
| User-entry vector at `+0x258/+0x25c/+0x260` | Validated | `GetUserEntryAt`, append, reset, clone, and destroy helpers use these pointers. |
| User-entry row stride `0x4c` | Validated | Parser stack row and append copy move 76 bytes; `GetUserEntryAt` returns `begin + index * 0x4c`. |
| User-entry fields `+0x00 categoryId`, `+0x04 rank`, `+0x08 wchar_t name[32]`, `+0x48 score` | Validated | Parser stores category/rank/name/score in that order; OnPaint consumes rank/name/score. |
| Loaded/current rows category id at `+0x264` | Validated | Parsers write active category id to `v52[153]` / `v5[153]`; source-facing name `m_loadedRowsCategoryId` or `m_currentRowsCategoryId`. |
| Local-player rank at `+0x268` | Validated | Reset writes `-1`; parsers write rank; OnPaint displays footer when positive. |
| Local-player score at `+0x2ac` | Validated | Parsers write score/value; OnPaint displays it in the footer. |
| Local-player name at `+0x26c` | Rejected as proved | No checked parser writes the `+0x26c` tail, reset does not touch it, and OnPaint does not read it. Deep-copy preserves the tail, so it is real storage, but current evidence only supports copied/reserved footer storage. |

The correction does not block [UID:0000BQ] from moving above the gate. It improves source quality: the class's footer-name data source is now specific and the record tail uncertainty is isolated to [UID:0000BL]/[UID:0001VN].

## Owner And Source Route Ranking

| Candidate | Ranking | Decision |
| --- | --- | --- |
| [UID:0000MZ] `RankingDialog` file | 1 | Accepted canonical owner/emitter. The constructor caller, dialog-owned selected category collection at `RankingDialog + 0x26c`, vtable/read-only-data grouping, packet/resource model, and existing source-family docs place this class in `RankingDialog.cpp`. |
| [UID:0000BM] `RankingDialog` class | 2 | Related owner but not canonical for this class page. The dialog constructs/contains the pane, but the class itself is a sibling/private feature type routed through the file. |
| [UID:0000BL] `RankingCategoryRecord` / [UID:0000BK] `RankingCategoryCollection` | 3 | Data providers only. `OnPaint` consumes selected record and user rows; the pane is not part of the record/collection source model. |
| Generic control/GrafPort/EPF modules | 4 | Dependencies only. They own text drawing, line drawing, resource loading, and base control construction helpers. |
| UserPane/local-player module | 5 | Dependency for global local-player name only; not the pane owner. |
| Standalone narrow `RankingUserListPane.cpp` | 6 | Possible if original project split private controls, but no current evidence outranks the documented `RankingDialog.cpp` grouping. Leave only as a lower-probability source split note. |
| No-owner / ignored / non-reconstructable | 7 | Rejected. The class has constructor reachability, vtables, a source-authored paint method, and a valid file emitter. Only compiler thunks/CRT wrapper are ignored. |

## First-Draft C++ Recommendation

Populate [UID:0000BQ]'s formal C++ with a declaration-only block:

```cpp
struct RectBounds;

class RankingUserListPane : public ControlPane
{
public:
    explicit RankingUserListPane(const RectBounds *bounds);
    virtual ~RankingUserListPane();

protected:
    virtual void OnPaint();

    [[CHILDREN]]
};
```

If the project's UI declarations standardize the bounds argument name as `Rect`, `RECT`, or a project-specific `PaneRect`, substitute that type. The source shape is proven as an optional pane-bounds/layout pointer passed through to `ControlPane(8, bounds)`.

Recommended source-shape snippet for a future exact `OnPaint` child:

```cpp
void RankingUserListPane::OnPaint()
{
    RankingPaintTile tile;
    Region dirtyRegion;

    tile.Initialize();
    dirtyRegion.Initialize();
    g_pEPFLib->LoadFrame(kRankingBoardBackground, 0, &tile);
    DrawTiledBackground(GetBounds(), tile, kRankingBoardPalette);
    dirtyRegion.Release();

    RankingCategoryRecord *record = g_pRankingDialog->m_categories.GetSelectedRecord();
    if (record == 0)
        return;

    wchar_t text[64];
    SetTextColor(143);
    SetTextShadowColor(128);

    DrawOutlinedText(30, 24, record->GetTitleText());

    swprintf_s(text, 64, L"Total : %d", record->m_totalRankCount);
    DrawOutlinedText(380, 24, text);

    RankingDateTimeParts startTime;
    RankingDateTimeParts endTime;
    record->CopyStartTimeParts(&startTime);
    record->CopyEndTimeParts(&endTime);

    swprintf_s(text, 64, L"From : %02d/%02d/%04d %02d:%02d:%02d",
               startTime.month, startTime.day, startTime.year,
               startTime.hour, startTime.minute, startTime.second);
    DrawOutlinedText(30, 50, text);

    swprintf_s(text, 64, L"To : %02d/%02d/%04d %02d:%02d:%02d",
               endTime.month, endTime.day, endTime.year,
               endTime.hour, endTime.minute, endTime.second);
    DrawOutlinedText(210, 50, text);

    DrawOutlinedText(50, 78, L"Rank");
    DrawOutlinedText(150, 78, L"Name");
    DrawOutlinedText(390, 78, L"Score");

    int y = 100;
    for (int i = 0; i < 10; ++i)
    {
        RankingUserEntry *entry = record->GetUserEntryAt(i);
        if (entry == 0)
            continue;

        swprintf_s(text, 64, L"%d", entry->rank);
        DrawOutlinedText(50, y, text);

        swprintf_s(text, 64, L"%s", entry->name);
        DrawOutlinedText(150, y, text);

        swprintf_s(text, 64, L"%d", entry->score);
        DrawOutlinedText(390, y, text);

        y += 30;
    }

    SetDrawColor(143);
    for (int line = 0; line < 3; ++line)
    {
        MoveTo(30, 384 + line);
        LineTo(490, 384 + line);
    }

    if (record->m_localPlayerRank > 0)
    {
        y = 412;

        swprintf_s(text, 64, L"%d", record->m_localPlayerRank);
        DrawOutlinedText(50, y, text);

        SimpleUString localName(GetLocalPlayerName());
        swprintf_s(text, 64, L"%s", localName.c_str());
        DrawOutlinedText(150, y, text);

        swprintf_s(text, 64, L"%d", record->m_localPlayerScore);
        DrawOutlinedText(390, y, text);
    }
}
```

This is intentionally a source-shape draft, not an instruction to invent exact helper classes today. The crucial source-quality decisions are: use `swprintf_s` or a source-local safe formatter instead of the raw CRT wrapper; use global local-player name state for the footer name; and keep drawing helpers as generic GrafPort/control dependencies.

## Metadata And Coverage Recommendations

### Target [UID:0000BQ]

Header changes:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Formal C++ block:

```cpp
struct RectBounds;

class RankingUserListPane : public ControlPane
{
public:
    explicit RankingUserListPane(const RectBounds *bounds);
    virtual ~RankingUserListPane();

protected:
    virtual void OnPaint();

    [[CHILDREN]]
};
```

Class coverage replacement row for `by-class/-coverage-report.md`, replacing the current [UID:0000BQ] row:

```text
- [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md) : reconstructable : 87% : very strong : B005 2026-06-18 source-quality pass resolves the class C++ blocker: RankingDialog-owned ControlPane child id `8` with constructor caller `0x0045875f`, vtables `0x00610cd0`/`0x00610d38`/`0x00610d68`, vtable-only `OnPaint` at `0x0045f3a0`, exact row/footer consumers (`+0x254` total, user row `+0x04/+0x08/+0x48`, local rank `+0x268`, local score `+0x2ac`), footer name from global local-player name via `0x005a2dc0`/`word_69BEE0` rather than record `+0x26c`, fixed formatter/thunk/compiler-output exclusions, and declaration-only first-draft class C++ readiness.
```

No by-file coverage row replacement is required for [UID:0000MZ]. Add a support note but keep `86/88`; the file route was already correct.

### Support Layout Corrections

[UID:0000BL] `RankingCategoryRecord` C++ should replace:

```cpp
    wchar_t m_localPlayerName[32];
```

with either:

```cpp
    unsigned char m_reservedLocalPlayerFooter[0x40];
```

or, if preserving the likely wide-string field shape is preferred:

```cpp
    wchar_t m_reservedLocalPlayerName[32];
```

I recommend the first form because it does not imply a name string that current code reads or writes.

Replace the [UID:0000BL] evidence bullets:

```text
- `+0x268` is `localPlayerRank`, reset to `-1` and displayed by `RankingUserListPane::OnPaint` when positive.
- `+0x26c-+0x2ab` is best modeled as copied/reserved local-player footer tail storage. Its 64-byte size matches a possible wide name buffer, and record deep-copy preserves it, but the checked subcommand `2`/`3` parsers do not write it and `RankingUserListPane::OnPaint` obtains the displayed footer name from global `word_69BEE0` via `0x005a2dc0`.
- `+0x2ac` is `localPlayerScore` / `localPlayerValue`, displayed in the local-player footer.
```

Replace the [UID:0001VN] layout row for `+0x26c`:

```text
| `+0x26c` | 64 | copied/reserved local-player footer tail (`m_reservedLocalPlayerFooter[0x40]`) | Deep-copy preserves this tail between `localPlayerRank` and `localPlayerScore`, and its size matches a possible wide-name buffer; however, checked row parsers do not write it and `RankingUserListPane::OnPaint` reads the displayed footer name from global `word_69BEE0` through `0x005a2dc0`, not from this record field. |
```

Recommended class coverage replacement row for [UID:0000BL] if the supervisor updates the class declaration:

```text
- [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md) : reconstructable : 86% : strong : Fixed ranking category record with first-draft declaration C++, exact child method bodies for [UID:0002K0][0x0045bf60-0x0045bf63.RankingCategoryRecordGetListIndex](by-memory/0x0045bf60-0x0045bf63.RankingCategoryRecordGetListIndex.md)-[UID:0002K6][0x0045bfe0-0x0045c01a.RankingCategoryRecordGetUserEntryAt](by-memory/0x0045bfe0-0x0045c01a.RankingCategoryRecordGetUserEntryAt.md)/[UID:0002KA][0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries](by-memory/0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries.md), `RankingDateTimeParts`, `RankingUserEntry`, 688-byte record stride, 76-byte row stride, local-player rank/score metadata, corrected copied/reserved `+0x26c` footer tail, and record-owned [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md) helper split children [UID:0003YT][0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy](by-memory/0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy.md)/[UID:0003YV][0x0045d6e0-0x0045d740.RankingUserEntryVectorAllocateStorage](by-memory/0x0045d6e0-0x0045d740.RankingUserEntryVectorAllocateStorage.md) documented.
```

Recommended struct coverage replacement row for [UID:0001VN]:

```text
- [UID:0001VN][RankingCategoryRecordLayout](by-type/by-struct/RankingCategoryRecordLayout.md) : reconstructable : 87% : very strong : Ranking category record layout documents `RankingDateTimeParts`, `RankingUserEntry`, 688-byte record offsets, eleven helper/accessor starts and xrefs, date/time copy/setter blocks, user-entry vector begin/current/capacity/reset fields, 76-byte append stride, user row rank/name/score consumers, local-player rank/score metadata, corrected copied/reserved `+0x26c` footer tail, and [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md) helper split support.
```

### Ignored / By-Memory Boundary Corrections

Replace the ignored ledger entry for `0x0045f950` with:

```text
- `0x0045f950-0x0045f97d` - `FormatWide64_45F950` fixed-size wide-formatting wrapper.
  - Why ignored: CRT/stdio varargs wrapper around `__stdio_common_vswprintf_s` with a fixed `0x40` wide-character destination bound; it is only formatting glue used by ranking drawing code.
  - Evidence: local IDA export reports `sub_45F950` `addr_end: 0x0045f97d`, size `45`, and decompilation forwards to `__stdio_common_vswprintf_s(*sub_41B9A0(), buffer, 0x40, format, 0, va)` with `-1` on negative results. Caller xrefs are exactly the nine `RankingUserListPane::OnPaint` formatting calls.
  - Replacement/procurement: MSVC/UCRT formatting support; final source can express the call sites as a local safe-format helper or direct `swprintf_s` use inside [UID:0000MZ][RankingDialog](by-file/RankingDialog.md).
  - Owner docs: [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md), [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).
```

Replace the ignored ledger entry for the thunks with:

```text
- `0x0045f97d-0x0045f993` - `RankingUserListPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `RankingUserListPane` scalar deleting destructor `0x0045f9a0`; not handwritten ranking user-list behavior.
  - Evidence: local bytes decode two 0x0b-byte thunks: `0x0045f97d` subtracts `0xa0` and jumps to `0x0045f9a0`, while `0x0045f988` subtracts `0xa4` and jumps to `0x0045f9a0`; the second thunk's last byte is at `0x0045f992`, so the half-open range ends at `0x0045f993`. [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md) records the owning vtable slots.
  - Replacement/procurement: no external dependency; generated by the compiler from the `RankingUserListPane` inheritance/vtable layout.
  - Owner docs: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md), [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md).
```

Replace the two nested by-memory coverage rows under the ranking aggregate with:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) : ignored : 90% : very strong : Recorded in -ignored.md: `0x0045f950-0x0045f97d` - `FormatWide64_45F950` fixed 64-wide-character CRT formatting wrapper used by exactly nine `RankingUserListPane::OnPaint` call sites; final source should use `swprintf_s`/a local source helper and not hand-author the raw CRT wrapper.
    - [UID:0000YC][0x0045f97d-0x0045f993.RankingUserListPaneAdjustorThunks](by-memory/0x0045f97d-0x0045f993.RankingUserListPaneAdjustorThunks.md) : ignored : 88% : very strong : Compiler-generated secondary/tertiary destructor adjustor thunks; exact bytes show two 0x0b-byte thunks ending at half-open `0x0045f993`, subtracting `0xa0`/`0xa4` before jumping to scalar deleting destructor `0x0045f9a0`.
```

If the supervisor does not rename the [UID:0000YC] file immediately, keep the current path in the link but update the body text and coverage note to say the exact half-open range is `0x0045f97d-0x0045f993`.

## Heuristic / Inference Reanalysis And Validation

### Class identity and owner

Evidence checked: target class page, RankingDialog file/class/aggregate docs, constructor decompile, vtable support, read-only-data support, and coverage rows. Rejected alternatives: category record/collection ownership, generic GrafPort/control ownership, UserPane/local-player ownership, no-owner/non-emitting status, and standalone file as the best current route.

Best inference: `RankingUserListPane` is a private ranking-dialog control class emitted through `RankingDialog.cpp`. Score effect: raises target to `87/90`. Source placement: unchanged owner/emitter [UID:0000MZ]. Split/range effect: no required class split, but future exact method pages would improve method-body placement. C++ readiness: declaration-only class block is safe.

### Constructor and base signature

Evidence checked: `0x0045f340` local decompile; caller `0x0045875f`; ControlPane constructor docs. Rejected alternatives: no-argument constructor and record/collection constructor. The second parameter is a bounds/layout pointer forwarded to `ControlPane`, not ranking data.

Best inference: source signature is `RankingUserListPane(const RectBounds *bounds)` or equivalent project rect typedef, with `ControlPane(8, bounds)`. Effect: no metadata blocker; exact typedef spelling caps confidence below final-source but does not block declaration C++.

### OnPaint method name and signature

Evidence checked: primary vtable slot in [UID:0001YJ], local decompile at `0x0045f3a0`, string xrefs, no direct callers. Rejected alternatives: `Draw`, `Render`, or ordinary caller-only helper. The virtual slot and paint-like callee set make `OnPaint()` the strongest name.

Best inference: `virtual void OnPaint()` protected override. Effect: supports C++ declaration and future method body.

### Row/category field names

Evidence checked: OnPaint row reads, B002 report, parser decompiles `0x0045c560` and `0x0045cb10`, append/get helpers, [UID:0001VN]. Rejected alternatives: generic `value` for row `+0x48` as primary name and treating row `+0x00` as the displayed rank. The UI labels and parser order support `score` and `rank`.

Best inference: `RankingUserEntry { int categoryId; int rank; wchar_t name[32]; int score; }`. Effect: resolves the target's row-layout naming blocker and supports score increase.

### Total and date/time fields

Evidence checked: `record[149]` in OnPaint, `0x0045bf90`/`0x0045bfb0`, date format string order, parser setter docs. Rejected alternatives: raw packed-date storage consumed directly by paint. Paint uses copied expanded dwords.

Best inference: use `m_totalRankCount` and `RankingDateTimeParts { second, minute, hour, day, month, year, reserved0, reserved1, reserved2 }`. Effect: supports first-draft source shape; exact original type/member spellings remain confidence-only caveats.

### Local-player footer name

Evidence checked: OnPaint at `0x0045f85f`, local decompile of `0x005a2dc0`, parser writes, reset helper, deep-copy helper, [UID:0000BL]/[UID:0001VN], older B002 report. Rejected alternative: `RankingCategoryRecord::m_localPlayerName` as a proved consumed field. The footer name path constructs a temporary wide-string from `word_69BEE0` and destroys it with `0x00582b70`; no record read occurs.

Best inference: footer rank and score are record fields; footer name is the global current/local-player name. The record `+0x26c` tail is real copied storage but unconsumed by checked code, best named reserved. Effect: target score rises because the blocker is resolved; support docs need correction; [UID:0000BL]/[UID:0001VN] confidence should not rely on a false field name.

### Formatter helper

Evidence checked: `0x0045f950` metadata, local bytes, nine callers, ignored ledger. Rejected alternatives: handwritten ranking business method or shared `StringUtil` method that should emit from this target. It is a fixed-count CRT wrapper adjacent to paint.

Best inference: ignore raw wrapper, express source as `swprintf_s(buffer, 64, ...)` or a file-local safe-format helper. Effect: no class C++ blocker; update half-open range in ignored/coverage docs.

### Destructor and thunks

Evidence checked: `0x0045f380`, `0x0045f97d`, `0x0045f988`, `0x0045f9a0`, vtable slots, local bytes. Rejected alternatives: source-authored methods for adjustor thunks or scalar deleting destructor. They are compiler-generated ABI glue from class inheritance/vtable layout.

Best inference: source declares a virtual destructor; leave thunk/scalar wrapper docs as ignored/compiler-generated. Effect: no C++ blocker, but by-memory ignored row must use correct half-open endpoints.

### Source route / split decisions

Evidence checked: RankingDialog file inventory, by-memory aggregate, read-only data, vtable family, target page, and current coverage. Rejected alternatives: creating a new standalone file as a necessary change, moving to category collection, moving to GrafPort/control, or reclassifying as ignored.

Best inference: keep [UID:0000MZ] owner/emitter. Optional future split into exact method children is useful but not required to raise the class page. Effect: no direct split/rename needed except the ignored thunk page boundary recommendation.

### Score and metadata

Evidence checked: current `84/88`, current code-entry policy, target open issue, and resolved row/category/layout/name blockers. Rejected alternatives: leave at `84/88` because original helper spellings are not final; reclassify non-reconstructable because method bodies are not split.

Best inference: `87/90` is defensible. The class has a proved owner/emitter, constructor/vtable/reachability, stable paint behavior, resolved row/footer data-source questions, and declaration-only C++ readiness. Confidence remains below final audit due exact original typedef/helper/member spelling and because full method bodies should live on exact by-memory children.

## Changed Files And Validation Notes

Changed file:

- `tools/leaser/Agents/Agent-B005/research/0000BQ-RankingUserListPane-class-source-quality.md`

No target/support/coverage docs were edited. No generated files were edited. No validator was run because this report-only assignment changes only the research report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0000BQ-RankingUserListPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0000BQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
