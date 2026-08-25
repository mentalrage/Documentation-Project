** TARGET-REPORT-UID:0002FX **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002-goal2-chatting-color-pane-source-quality-0002FX-0002GB-0002GC-20260617

Agent: Agent-B002  
Date: 2026-06-17  
Assignment type: B-agent report-only research. No by-* docs, generated files, or coverage reports were edited.

Primary targets:

- [UID:0002FX] `by-memory/0x004824e0-0x00482b01.ChattingColorPaneConstructor.md`
- [UID:0002GB] `by-memory/0x004832c0-0x00483414.ChattingColorListPaneDrawItem.md`
- [UID:0002GC] `by-memory/0x00483420-0x00483487.ChattingColorListPaneOnItemSelected.md`

Support checked:

- Exact children [UID:0002FY], [UID:0002FZ], [UID:0002G0], [UID:0002G1], [UID:0002G2]-[UID:0002GA].
- Class/file docs: `by-class/ChattingColorPane.md`, `by-class/ChattingColorSelectPane.md`, `by-class/ChattingColorListPane.md`, `by-class/ColorStringChattingMessage.md`, `by-file/Chatting.md`.
- Config/global docs: `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`, `by-type/by-struct/RegistryConfigUserProfileBlock.md`.
- Read-only data docs: `by-memory/0x00614cdc-0x00615284.ChattingVtableData.md`, `by-memory/0x00615284-0x00615460.ChattingStringResourceData.md`, `by-memory/0x00615460-0x00615560.ChattingColorTableConstants.md`.
- Message/color consumers: `by-memory/0x0047ff80-0x00480640.ChatPacketType10Handler.md`, `by-memory/0x00483490-0x00483541.ColorStringChattingMessageConstructor.md`, `by-memory/0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md`.
- Generated evidence: `auto-generated/-ag-memory-coverage.md`, `auto-generated/NexusTK/social/Chatting.cpp`, and polluted `simroot_v2/class_ChattingColorPane.cpp`.
- Local PE: `E:\NTK\Resources\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.

## Executive Recommendations

| UID | Current | Recommended | Owner | Emitter | Reconstructable | C++ recommendation |
| --- | ---: | ---: | --- | --- | --- | --- |
| 0002FX `ChattingColorPaneConstructor` | `82/90` | `86/91` | keep `00001T` | keep `00001T` | keep `TRUE` | Populate first-draft formal C++ now. |
| 0002GB `ChattingColorListPaneDrawItem` | `82/90` | `86/91` | keep `00001S` | keep `00001S` | keep `TRUE` | Populate first-draft formal C++ now. |
| 0002GC `ChattingColorListPaneOnItemSelected` | `82/90` | `87/92` | keep `00001S` | keep `00001S` | keep `TRUE` | Populate first-draft formal C++ now. |

The active first-draft code gate is satisfied for all three targets after this reanalysis: each is reconstructable, has a nonblank emitter route, emits to `auto-generated/NexusTK/social/Chatting.cpp`, and clears the combined-score threshold. The old "blank below 95/95" wording in these target docs is stale for first-draft formal C++ entry. `95/95` remains useful as a final-audit quality target, not as the blocker for first-draft code.

Best source-facing names and layout:

- `ChattingColorPane::ChattingColorPane()` for [UID:0002FX]. No source arguments.
- `void ChattingColorListPane::DrawItem(int row, const ChattingColorSwatchItem *item, const RectBounds *bounds)` for [UID:0002GB].
- `void ChattingColorListPane::OnItemSelected(int row, int notify)` for [UID:0002GC].
- Owner fields:
  - `+0x26c`: `m_pCategorySelector`
  - `+0x270`: `m_pForegroundColorList`
  - `+0x274`: `m_pBackgroundColorList`
  - `+0x278`: `m_chatColorForeground[6]`, 32-bit dialog/list working slots containing persisted byte palette ids
  - `+0x290`: `m_chatColorBackground[6]`, 32-bit dialog/list working slots containing persisted byte palette ids
  - `+0x2a8`: `m_selectedChatColorCategory`
- `ChattingColorListPane` fields:
  - `+0x14c`: `m_pColorPane`
  - `+0x150`: `m_isForegroundList`
  - inherited/list selected row: base offset `+0x134`
  - item record `+0x04`: `ChattingColorSwatchItem::colorValue`
- Persisted config declaration policy:
  - Treat `g_pConfig + 0x28de82..0x28de8d` as an indexed `RegistryConfig` chat color pair block.
  - Recommended source-facing field model:

```cpp
enum ChatColorCategory
{
    ChatColorCategory_Talk = 0,
    ChatColorCategory_Shout = 1,
    ChatColorCategory_Whisper = 2,
    ChatColorCategory_Group = 3,
    ChatColorCategory_Clan = 4,
    ChatColorCategory_System = 5,
    ChatColorCategory_Count = 6
};

struct ChatColorPair
{
    unsigned char foreground;
    unsigned char background;
};

// RegistryConfig, offset +0x28de82.
ChatColorPair m_chatColorPairs[ChatColorCategory_Count];
```

The exact original member spelling is not recovered. The role-based names `foreground` and `background` are now stronger than generic `primary`/`secondary`, because `ColorStringChattingMessage` stores the first id as foreground at object `+0x08` and the second id as background at object `+0x0c`, and its draw method switches/draws from that background id in the legacy path.

Source placement:

- Keep the current owner/emitter route through `Chatting.cpp` now.
- A future `social/ChatColorDialog.cpp` split is plausible but not proven strongly enough to change owner/emitter. If a split is later created, it should contain `ChattingColorPane`, `ChattingColorSelectPane`, `ChattingColorListPane`, and the chat color table constants, not unrelated message packet handlers or polluted generated methods.

## Heuristic / Inference Reanalysis And Validation

### Evidence state

The configured MCP resource layer exposed no IDA resources during this run, and no local listening IDA/MCP service was visible from the two Python processes. I therefore treated current live-IDA statements in the checked by-* docs as prior evidence and added fresh local PE scans from `E:\NTK\Resources\NexusTK\NexusTK.exe`.

Fresh PE scan results:

- PE MD5: `4247e04e20b65d6414c7238aa8ff5515`; image base `0x00400000`.
- `0x004824e0` has one direct rel32 call, `0x00481386 call`, matching the color row path in `ChattingVarietySelectPane::OnMouseEvent`.
- `0x004832c0` has one absolute pointer reference at `0x00615228`, and no direct rel32 calls. This validates `ChattingColorListPane::DrawItem` as vtable-only.
- `0x00483420` has one absolute pointer reference at `0x00615220`, and no direct rel32 calls. This validates `ChattingColorListPane::OnItemSelected` as vtable-only.
- `0x00482fb0` has two direct rel32 calls, `0x00482837 call` and `0x0048295d call`, both inside the owner constructor.
- `0x00483210` has four rel32 references: `0x00482c8c call`, `0x00482c98 jmp`, `0x00482f90 call`, and `0x00482f9b call`, matching the raw owner sync helper and selector virtual handler.
- `0x00483270` has two direct calls, `0x00483236 call` and `0x0048324d call`, both inside `SelectCurrentColor`.
- `0x00482ca0` had no direct rel32 call in the bounded follow-up scan, matching docs that the standalone selector constructor is not directly reached and the owner constructor inlines the construction sequence.
- Vtable slot reads:
  - `0x00615090 -> 0x00482b30` (`ChattingColorPane::OnButtonResponse`)
  - `0x0061515c -> 0x00482f50` (`ChattingColorSelectPane::OnSelectionChanged`)
  - `0x00615164 -> 0x00482d60` (`ChattingColorSelectPane::DrawItem`)
  - `0x00615220 -> 0x00483420` (`ChattingColorListPane::OnItemSelected`)
  - `0x00615228 -> 0x004832c0` (`ChattingColorListPane::DrawItem`)
  - `0x00615048 -> 0x00483b40` (`ChattingColorPane` scalar deleting destructor)
  - `0x006151a8 -> 0x00483b00` (`ChattingColorListPane` scalar deleting destructor)
- Boundary padding:
  - `0x00482b01-0x00482b10`: fifteen `0xcc` bytes after [UID:0002FX].
  - `0x004832b9-0x004832c0`: seven `0xcc` bytes before [UID:0002GB].
  - `0x00483414-0x00483420`: twelve `0xcc` bytes between [UID:0002GB] and [UID:0002GC].
  - `0x00483487-0x00483490`: nine `0xcc` bytes after [UID:0002GC].

### Claim reanalysis by target

[UID:0002FX] constructor:

- Validated: exact `0x004824e0-0x00482b01` body, single direct caller at `0x00481386`, constructor role, three `ChattingColorPane` vtable stores, import of twelve persisted bytes from `g_pConfig + 2678402..2678413` / `+0x28de82..+0x28de8d`, creation of selector/list children, and fifteen-byte alignment after the function.
- Validated: selector child pointer at owner `+0x26c`, foreground color-list child at `+0x270`, background color-list child at `+0x274`, and selected/current category cache at `+0x2a8`.
- Refined: the two owner color tables should not remain merely "primary" and "secondary" in source-facing docs. `ColorStringChattingMessage` constructor/draw docs resolve the pair as foreground/background palette ids, so `+0x278` is `m_chatColorForeground[6]` and `+0x290` is `m_chatColorBackground[6]`.
- Validated: the stored working slots in the pane are 32-bit stride slots (`+0x278`, `+0x27c`, ... and `+0x290`, `+0x294`, ...), but only the byte palette id is persisted to `RegistryConfig`.
- Refined: constructor constants `14` and `22` are not the source action ids passed to `OnButtonResponse`. The action ids are `1` and `2`, because [UID:0002FZ] branches on button id `1` for save/close and `2` for close-only, and constructor-side registration/defaulting helpers receive `1` and `2`. The constants `14` and `22` are best treated as button skin/resource/template ids.
- Resolved: source title should be `Chatting Color`. The string data is split in `.rdata` as `Ch` plus `atting Color`; treating only `"Ch"` as the title is an artifact of string splitting.
- Rejected: immediate source split to `ChatColorDialog.cpp`. The generated emitter route and `by-file/Chatting.md` still support `social/Chatting.cpp`, with `ChatColorDialog.cpp` only a plausible future split.

[UID:0002GB] draw item:

- Validated: exact `0x004832c0-0x00483414` body, vtable-only slot `0x00615228`, no direct callers, stack-cookie shape, and twelve-byte alignment before [UID:0002GC].
- Validated: argument roles are row/index, swatch item pointer, and draw rectangle. The item field at `+0x04` is the swatch `colorValue`.
- Validated: zero color is special-cased before selected-row handling and final swatch fill. The best behavior description is "default/empty swatch entry" rather than a normal black swatch. This is reinforced by [UID:0002G7], where the secondary/background list zeroes swatch index `0`.
- Validated: selected row draws full rect palette `128`, then inset-2 palette `143`; zero/default draws inset-2 palette `136`; all rows finally draw inset-3 with `item->colorValue`.
- Refined: return type is `void`. There is no evidence for a success/failure return.
- Remaining nonblocking uncertainty: exact names for generic drawing helpers (`sub_4B7C50`, `sub_5446B0`, `sub_4B9660`, `dword_69B3FC`) are not recovered. This affects final polish but does not block first-draft C++.

[UID:0002GC] selected item handler:

- Validated: exact `0x00483420-0x00483487` body, vtable-only slot `0x00615220`, no direct callers, and nine-byte alignment before `ColorStringChattingMessage` constructor.
- Validated: source order is base list selection update first, then selected item lookup, then owner table update, then guarded selector refresh.
- Validated: selected item field `+0x04` is `ChattingColorSwatchItem::colorValue`, by cross-checking [UID:0002G9], [UID:0002GA], [UID:0002GB], and [UID:0002GC].
- Resolved: `this+0x150 != 0` writes owner `+0x278 + category * 4`, so mode true is foreground list. `this+0x150 == 0` writes owner `+0x290 + category * 4`, so mode false is background list.
- Validated: selector refresh uses owner `+0x26c` only when non-null, passes child `+0x44`, and dispatches vtable slot `+0x20`. Best source-facing action is invalidating/refreshing the category selector so its row text/swatch reflects the new foreground/background pair.
- Refined: return type is `void`; two arguments after `this`.
- Remaining nonblocking uncertainty: exact inherited base selection handler name and exact refresh virtual name are still generic pane/list names, but their behavior and ownership are sufficient for first-draft C++.

### Support child reanalysis

- [UID:0002FZ] `ChattingColorPane::OnButtonResponse` is the save/cancel proof. Button `1` saves the twelve bytes back to `g_pConfig + 0x28de82..0x28de8d` and closes; button `2` closes without saving.
- [UID:0002G0] and [UID:0002G1] remain raw no-route owner helpers. Their behavior validates names and field layout, but they should stay blank C++ until an inbound source call/signature is recovered.
- [UID:0002G2] standalone selector constructor remains no-direct-xref. The owner constructor appears to inline this sequence. The class and source-facing type remain valid.
- [UID:0002G5] selector draw item validates categories and foreground/background reads through owner `+0x278/+0x290`.
- [UID:0002G6] selector selection handler mirrors [UID:0002G1], copying selector base selected value `+0x134` to owner `+0x2a8`, then refreshing both lists through [UID:0002G8].
- [UID:0002G7] list constructor validates `ChattingColorListPane(ChattingColorPane *owner, bool isForegroundList)`, owner pointer at `+0x14c`, mode flag at `+0x150`, base list setup with 18-pixel cells, 80 color entries, and the secondary/background list's index-zero clear.
- [UID:0002G8] `SelectCurrentColor` validates category-indexed table access from owner `+0x278/+0x290` selected by mode flag, then selection through list virtual slot `+0x78`.
- [UID:0002G9] raw selected-color accessor validates `ChattingColorSwatchItem::colorValue`, but remains a no-route raw helper; no formal C++ recommended for that raw helper yet.
- [UID:0002GA] `FindIndexByColorValue` validates item `+0x04` and zero fallback.

### Config and global reanalysis

`dword_67A7C8` is now `g_pConfig`, a process-global config pointer documented at [UID:00028Q]. The target docs should use `g_pConfig` instead of `dword_67A7C8` in source-facing text, while retaining the raw name only as historical/IDA evidence when useful.

The persisted chat color block is adjacent to, but not part of, the profile string slice:

| Config offsets | Category | Packet consumer |
| --- | --- | --- |
| `+0x28de82/+0x28de83` | Talk foreground/background | Imported/saved by dialog; not used by type-10 packet handler. |
| `+0x28de84/+0x28de85` | Shout foreground/background | Type-10 subtype `4`. |
| `+0x28de86/+0x28de87` | Whisper foreground/background | Type-10 subtype `0`. |
| `+0x28de88/+0x28de89` | Group foreground/background | Type-10 subtype `11`. |
| `+0x28de8a/+0x28de8b` | Clan foreground/background | Type-10 subtype `12`. |
| `+0x28de8c/+0x28de8d` | System foreground/background | Type-10 subtypes `5` and `17`. |

Rejected alternatives:

- `primary`/`secondary`: acceptable as fallback but less source-facing than `foreground`/`background`.
- `text`/`shadow` or `outline`: not the best field names. The message object stores the second value as background id, and the legacy draw path uses it as the background switch key. High-resolution outlined text is controlled by a separate flag/custom-color path, not by the second persisted byte.
- Individual field names like `m_talkColor1` / `m_talkColor2`: too ad hoc and lower quality than an indexed category-pair model.

### Source split and generated output

`auto-generated/-ag-memory-coverage.md` currently routes all three primary targets to `auto-generated/NexusTK/social/Chatting.cpp`:

- [UID:0002FX] emits through `00001T`, `has cpp` is `no`.
- [UID:0002GB] emits through `00001S`, `has cpp` is `no`.
- [UID:0002GC] emits through `00001S`, `has cpp` is `no`.

The current generated `auto-generated/NexusTK/social/Chatting.cpp` only has a forward declaration for `ChattingColorPane` in the visible color-dialog area; there is no formal code for the primary target methods to preserve. `simroot_v2/class_ChattingColorPane.cpp` is polluted with unrelated `SpellInventoryPane`, `HistoryViewingPane`, and music-control methods, and should not be used as source placement evidence except as a negative owner-pollution example.

Recommendation: keep by-memory owner/emitter metadata unchanged and add first-draft C++ to the target pages. Do not create or assign a new `ChatColorDialog.cpp` by-file page yet.

## First-Draft Formal C++ Recommendations

These are intended as the exact formal blocks to place between each target page's `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END`. Helper names such as `AddDialogButton`, `AddChildPane`, `FillPaletteRect`, and `InvalidateRect` are source-facing placeholders for already-documented base UI helpers; they are not `sub_` placeholders.

### [UID:0002FX] recommended C++ block

```cpp
ChattingColorPane::ChattingColorPane()
    : DialogPane(L"Chatting Color", 330, 397),
      m_pCategorySelector(NULL),
      m_pForegroundColorList(NULL),
      m_pBackgroundColorList(NULL),
      m_selectedChatColorCategory(ChatColorCategory_Talk)
{
    for (int category = 0; category < ChatColorCategory_Count; ++category) {
        const ChatColorPair &colors = g_pConfig->m_chatColorPairs[category];
        m_chatColorForeground[category] = colors.foreground;
        m_chatColorBackground[category] = colors.background;
    }

    RectBounds bounds;

    InitRectBounds(&bounds, 100, 363, 163, 387);
    AddDialogButton(1, 14, bounds);

    InitRectBounds(&bounds, 175, 363, 238, 387);
    AddDialogButton(2, 22, bounds);

    InitRectBounds(&bounds, 77, 57, 327, 107);
    m_pCategorySelector = new ChattingColorSelectPane(this);
    AddChildPane(m_pCategorySelector, bounds);
    m_pCategorySelector->SetSelectedIndex(ChatColorCategory_Talk, false);

    InitRectBounds(&bounds, 20, 134, 325, 229);
    m_pForegroundColorList = new ChattingColorListPane(this, true);
    AddChildPane(m_pForegroundColorList, bounds);
    m_pForegroundColorList->SelectCurrentColor();

    InitRectBounds(&bounds, 20, 253, 325, 348);
    m_pBackgroundColorList = new ChattingColorListPane(this, false);
    AddChildPane(m_pBackgroundColorList, bounds);
    m_pBackgroundColorList->SelectCurrentColor();

    SetDefaultButton(1);
    SetCancelButton(2);
    CenterDialog();
}
```

Notes for the supervisor applying this block:

- The constructor's selector construction is inlined in the binary; the source-level constructor call remains appropriate.
- The button action ids are `1` and `2`; `14` and `22` are retained as resource/style ids.
- If the final base dialog constructor spelling differs, update the helper names at integration time but preserve the dimensions, child rectangles, action ids, config import, child construction order, and list mode arguments.

### [UID:0002GB] recommended C++ block

```cpp
void ChattingColorListPane::DrawItem(
    int row,
    const ChattingColorSwatchItem *item,
    const RectBounds *drawBounds)
{
    RectBounds fillBounds;

    if (item->colorValue == 0) {
        fillBounds = *drawBounds;
        InsetRectBounds(&fillBounds, 2, 2);
        FillPaletteRect(fillBounds, 136);
    }

    if (IsItemSelected(row)) {
        FillPaletteRect(*drawBounds, 128);

        fillBounds = *drawBounds;
        InsetRectBounds(&fillBounds, 2, 2);
        FillPaletteRect(fillBounds, 143);
    }

    fillBounds = *drawBounds;
    InsetRectBounds(&fillBounds, 3, 3);
    FillPaletteRect(fillBounds, item->colorValue);
}
```

Notes for the supervisor applying this block:

- `ChattingColorSwatchItem::colorValue` is item offset `+0x04`.
- The zero-color branch should stay before the selected-row branch.
- `FillPaletteRect` stands for the documented draw-state/palette/fill-callback sequence; do not replace it with a raw `dword_69B3FC` name in source-facing code.

### [UID:0002GC] recommended C++ block

```cpp
void ChattingColorListPane::OnItemSelected(int row, int notify)
{
    ListPane::OnItemSelected(row, notify);

    ChattingColorSwatchItem *item =
        static_cast<ChattingColorSwatchItem *>(GetSelectedItem());
    const int category = m_pColorPane->m_selectedChatColorCategory;

    if (m_isForegroundList)
        m_pColorPane->m_chatColorForeground[category] = item->colorValue;
    else
        m_pColorPane->m_chatColorBackground[category] = item->colorValue;

    if (m_pColorPane->m_pCategorySelector != NULL)
        m_pColorPane->m_pCategorySelector->InvalidateRect(
            m_pColorPane->m_pCategorySelector->m_rect);
}
```

Notes for the supervisor applying this block:

- Do not add item/owner null guards unless surrounding reconstructed `ListPane` policy proves the original source did. The binary dereferences the selected item and owner unconditionally after the base selection call.
- Keep the selector child null guard. That guard is explicit in the binary.
- If the final pane refresh API is named differently, preserve the semantic: invalidate/refresh selector bounds at child offset `+0x44` through the pane virtual refresh slot.

## Recommended By-Doc Metadata And Text Changes

These are report-only recommendations for supervisor execution. I did not edit these docs.

### Target: `by-memory/0x004824e0-0x00482b01.ChattingColorPaneConstructor.md`

Metadata:

- Change `COMPLETION:82` to `COMPLETION:86`.
- Change `CONFIDENCE:90` to `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:00001T`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:00001T`.
- Replace the blank content between `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END` with the [UID:0002FX] C++ block above.

Replace the paragraph beginning `Not final C++:` and the following paragraph beginning `Final reconstruction C++ remains blank` with:

```text
First-draft C++ readiness: preserve the base dialog setup with title `Chatting Color`, dimensions `330 x 397`, foreground/background chat-color imports from `g_pConfig->m_chatColorPairs[ChatColorCategory_Count]`, current category initialization to `Talk`, dialog action ids `1` and `2`, button resource/style ids `14` and `22`, inline/source construction of the category selector at owner `+0x26c`, foreground/background color-list children at owner `+0x270/+0x274`, list mode arguments `true` and `false`, initial row selection through `SelectCurrentColor`, default/cancel registration, and centering. Under the active combined-score/emitter gate this method should now receive first-draft formal C++; exact base-dialog helper names remain integration details, not a blank-C++ blocker.
```

Replace the `Score Rationale` row text for completion/confidence with:

```text
Completion is `86` because the reanalysis resolves source-facing owner fields, foreground/background color-pair names, button action/resource-id split, category enum order, source placement, generated emitter route, and first-draft C++ readiness while retaining documented exact bounds/caller/config/child-construction evidence.

Confidence is `91` because function identity, caller, child stores, config byte imports, field layout, and source owner are corroborated by existing live-IDA docs plus fresh section-mapped PE scans. It remains below final audit because exact base-dialog helper spellings and exact original `RegistryConfig` member spelling are still not recovered.
```

### Target: `by-memory/0x004832c0-0x00483414.ChattingColorListPaneDrawItem.md`

Metadata:

- Change `COMPLETION:82` to `COMPLETION:86`.
- Change `CONFIDENCE:90` to `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:00001S`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:00001S`.
- Replace the blank content between `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END` with the [UID:0002GB] C++ block above.

Replace the `Autogen handling` sentence:

```text
Autogen handling: attached to [UID:00001S][ChattingColorListPane](by-class/ChattingColorListPane.md); under the active combined-score/emitter gate this vtable-owned method should now carry first-draft formal C++.
```

Replace the paragraph beginning `Source-shape notes, not final C++:` with:

```text
First-draft C++ readiness: use `void ChattingColorListPane::DrawItem(int row, const ChattingColorSwatchItem *item, const RectBounds *drawBounds)`. `row` is the list row/index, `item+0x04` is `ChattingColorSwatchItem::colorValue`, and `drawBounds` is the row rectangle. The method draws the zero/default swatch inset with palette `136`, draws selected rows with full palette `128` and inset palette `143`, then always draws the final inset-3 swatch with `item->colorValue`. Generic rectangle, palette, and fill helper names remain integration details; they no longer justify blank formal C++ for this target.
```

Replace the `Score Rationale` rows with:

```text
| Completion | 86 | The page now has exact range, vtable-only reachability, no direct callers, row/item/rect argument style, item `colorValue` type inference, zero/default swatch behavior, selected-row palette sequence, final fill behavior, generated emitter route, and first-draft C++ readiness. |
| Confidence | 91 | Vtable slot evidence, modeled function boundaries, local PE references, and cross-checks with the list constructor/find/select/OnItemSelected helpers strongly support the behavior. Remaining uncertainty is limited to generic draw-helper names. |
```

### Target: `by-memory/0x00483420-0x00483487.ChattingColorListPaneOnItemSelected.md`

Metadata:

- Change `COMPLETION:82` to `COMPLETION:87`.
- Change `CONFIDENCE:90` to `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:00001S`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:00001S`.
- Replace the blank content between `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END` with the [UID:0002GC] C++ block above.

Replace the `Autogen handling` sentence:

```text
Autogen handling: attached to [UID:00001S][ChattingColorListPane](by-class/ChattingColorListPane.md); under the active combined-score/emitter gate this vtable-owned method should now carry first-draft formal C++.
```

Replace the paragraph beginning `Source-shape notes, not final C++:` with:

```text
First-draft C++ readiness: use `void ChattingColorListPane::OnItemSelected(int row, int notify)`. The method calls the inherited list selection handler first, retrieves the selected `ChattingColorSwatchItem`, reads `item->colorValue`, indexes the owner by `m_selectedChatColorCategory`, writes foreground when `this+0x150` is nonzero and background when it is zero, and refreshes the owner selector child only when owner `+0x26c` is non-null. Exact inherited helper names remain integration details; the owner fields, item type, mode meaning, write targets, and selector refresh behavior are source-ready.
```

Replace the `Score Rationale` rows with:

```text
| Completion | 87 | The page now has exact range, vtable-only reachability, no direct callers, base-selection ordering, selected-item accessor semantics, item `colorValue` type inference, owner field names, mode-to-foreground/background resolution, selector refresh behavior, generated emitter route, and first-draft C++ readiness. |
| Confidence | 92 | Vtable slot evidence, modeled function boundaries, local PE references, and cross-checks with `SelectCurrentColor`, `FindIndexByColorValue`, `GetSelectedColorValueRaw`, selector draw, and config/message consumers strongly support the behavior. Remaining uncertainty is limited to inherited helper spellings. |
```

### Support doc field-name updates

For `by-class/ChattingColorPane.md`, in the data notes section, replace the current generic color-table wording with:

```text
- `+0x26c`: `m_pCategorySelector`, the `ChattingColorSelectPane` child.
- `+0x270`: `m_pForegroundColorList`, the color-list child whose mode flag is nonzero and which writes `m_chatColorForeground`.
- `+0x274`: `m_pBackgroundColorList`, the color-list child whose mode flag is zero and which writes `m_chatColorBackground`.
- `+0x278..+0x28c`: `m_chatColorForeground[ChatColorCategory_Count]`, six 32-bit working palette-id slots initialized from and saved to the first byte of each persisted config pair.
- `+0x290..+0x2a4`: `m_chatColorBackground[ChatColorCategory_Count]`, six 32-bit working palette-id slots initialized from and saved to the second byte of each persisted config pair.
- `+0x2a8`: `m_selectedChatColorCategory`, copied from the selector list selected entry at base offset `+0x134`.
```

For `by-class/ChattingColorListPane.md`, in the data notes section, add:

```text
- `+0x14c`: `m_pColorPane`, owning `ChattingColorPane`.
- `+0x150`: `m_isForegroundList`; nonzero selects/writes owner `m_chatColorForeground`, zero selects/writes owner `m_chatColorBackground`.
- List item offset `+0x04`: `ChattingColorSwatchItem::colorValue`.
- The secondary/background list deliberately zeroes swatch index `0`, making that entry the default/empty background color choice.
```

For `by-type/by-struct/RegistryConfigUserProfileBlock.md`, under `Adjacent Chat Color Block`, replace the sentence beginning `Use an indexed role model such as` with:

```text
For source-facing reconstruction, use an indexed role model:
`ChatColorPair m_chatColorPairs[ChatColorCategory_Count]` at `+0x28de82`, where each pair has `unsigned char foreground` followed by `unsigned char background`. Category order is `Talk`, `Shout`, `Whisper`, `Group`, `Clan`, `System`. The exact original member spelling is not proven, but `foreground/background` is stronger than `primary/secondary` because `ColorStringChattingMessage` stores the two values as foreground and background palette ids.
```

For `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`, optionally add this row to `Known Field Clusters`:

```text
| `+0x28de82..+0x28de8d` | Persisted chat color pair block: six `ChatColorPair { foreground, background }` entries in category order `Talk`, `Shout`, `Whisper`, `Group`, `Clan`, `System`; consumed by `ChattingColorPane` and `ChatPacketType10Handler`. |
```

For `by-file/Chatting.md`, keep the current source placement but refine the possible split note with:

```text
Keep `ChattingColorPane`, `ChattingColorSelectPane`, `ChattingColorListPane`, and `ChattingColorTableConstants` in `social/Chatting.cpp` for current emission. A future `social/ChatColorDialog.cpp` split is plausible if the final source tree is reorganized, but current evidence does not justify changing owner/emitter metadata.
```

## Exact Replacement Rows For `by-memory/-coverage-report.md`

Supervisor-owned file only. Do not apply from B-agent report work.

Replace the current [UID:0002FX] row with:

```text
        - [UID:0002FX][0x004824e0-0x00482b01.ChattingColorPaneConstructor](by-memory/0x004824e0-0x00482b01.ChattingColorPaneConstructor.md) 0x004824e0-0x00482b01 | constructor | ChattingColorPaneConstructor : reconstructable : 86% : very strong : B002 2026-06-17 source-quality reanalysis verifies exact constructor bounds, sole color-row caller 0x00481386, persisted chat color imports from g_pConfig +0x28de82..+0x28de8d, source-facing foreground/background color-pair layout, selector/list child fields +0x26c/+0x270/+0x274, selected category +0x2a8, action ids 1/2 versus button resource ids 14/22, current Chatting.cpp emitter route, local PE reachability/padding, and first-draft formal C++ readiness under the active combined-score/emitter gate.
```

Replace the current [UID:0002GB] row with:

```text
        - [UID:0002GB][0x004832c0-0x00483414.ChattingColorListPaneDrawItem](by-memory/0x004832c0-0x00483414.ChattingColorListPaneDrawItem.md) 0x004832c0-0x00483414 | class method | ChattingColorListPaneDrawItem : reconstructable : 86% : very strong : B002 2026-06-17 source-quality reanalysis verifies exact DrawItem bounds, vtable-only slot 0x00615228, no direct callers, row/item/rect argument style, ChattingColorSwatchItem::colorValue at item +4, zero/default swatch branch, selected-row palette sequence 128/143, final inset-3 swatch fill, current Chatting.cpp emitter route, local PE vtable/padding evidence, and first-draft formal C++ readiness under the active combined-score/emitter gate.
```

Replace the current [UID:0002GC] row with:

```text
        - [UID:0002GC][0x00483420-0x00483487.ChattingColorListPaneOnItemSelected](by-memory/0x00483420-0x00483487.ChattingColorListPaneOnItemSelected.md) 0x00483420-0x00483487 | class method | ChattingColorListPaneOnItemSelected : reconstructable : 87% : very strong : B002 2026-06-17 source-quality reanalysis verifies exact OnItemSelected bounds, vtable-only slot 0x00615220, no direct callers, base-selection-first behavior, selected-item lookup, ChattingColorSwatchItem::colorValue at item +4, owner pointer +0x14c, foreground/background mode flag +0x150, selected category +0x2a8, owner write targets +0x278/+0x290, guarded selector invalidation through owner +0x26c, current Chatting.cpp emitter route, local PE vtable/padding evidence, and first-draft formal C++ readiness under the active combined-score/emitter gate.
```

## C++ Readiness And Gate Resolution

The primary blockers in the old target docs were source names, exact helper names, source split, and "below 95/95" final C++ gate language. Reanalysis changes their status:

- Source-facing class/method names are now sufficient: `ChattingColorPane::ChattingColorPane`, `ChattingColorListPane::DrawItem`, and `ChattingColorListPane::OnItemSelected`.
- Field/type names are now sufficient for first draft: `m_pCategorySelector`, `m_pForegroundColorList`, `m_pBackgroundColorList`, `m_chatColorForeground`, `m_chatColorBackground`, `m_selectedChatColorCategory`, `m_pColorPane`, `m_isForegroundList`, and `ChattingColorSwatchItem::colorValue`.
- `g_pConfig` and the `RegistryConfig` chat color pair block are source-ready as role-based names. Exact original member spelling remains unproven but no longer blocks formal C++.
- Generic base helper names remain integration details. They do not justify blank C++ for the primary targets because behavior, arguments, owner, and emitter route are known.
- The generated `has cpp` flag is currently `no` for all three targets, so adding the formal blocks is an actual improvement and will not overwrite existing method bodies.

Targets that should still stay blank C++ for now:

- Raw no-route helper islands such as [UID:0002G0], [UID:0002G1], [UID:0002G3], [UID:0002G4], and [UID:0002G9] should not be forced into formal C++ merely because their behavior is understood. They have no modeled function or inbound source call/signature, so their exposure in final source remains unresolved.
- Standalone [UID:0002G2] can remain blank for now because its construction sequence is inlined inside [UID:0002FX]; source can still use `new ChattingColorSelectPane(this)` in [UID:0002FX]'s constructor block.

## Validation

Actions performed:

- Read Agent-B002 goal rules and supervisor instructions before work.
- Read all primary target docs and exact child/support docs listed in the assignment.
- Scoped searches to project documentation by-* / auto-generated areas and avoided editing by-* docs.
- Checked generated routing in `auto-generated/-ag-memory-coverage.md`.
- Checked generated `auto-generated/NexusTK/social/Chatting.cpp`; no formal color-dialog code exists for the three primary targets.
- Checked polluted `simroot_v2/class_ChattingColorPane.cpp` only as negative generated-owner evidence.
- Attempted local MCP/resource discovery; no usable IDA MCP resource was available in this run.
- Ran fresh section-mapped PE scans against local `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, to validate direct calls, vtable-only reachability, vtable slots, and padding.

Files intentionally not edited:

- `by-memory/-coverage-report.md`
- All by-memory/by-class/by-file/by-type docs
- Generated/project-level files

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002FX-0002GB-0002GC-chatting-color-pane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002FX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
