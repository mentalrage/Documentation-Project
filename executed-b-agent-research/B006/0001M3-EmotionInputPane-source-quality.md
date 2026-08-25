** TARGET-REPORT-UID:0001M3 **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001M3 EmotionInputPane Source-Quality Report

## Status

FINISHED report-only research pass for [UID:0001M3] `by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md`.

The original report-only pass used the project-level `ntk-b-agent-workflow` instructions and `tools/leaser/Agents/Agent-B006/goal.md`. During that report-only pass I edited only this report file, did not edit target/support `by-*` docs, generated files, project-level generated files, validator/tool state, IDA DB state, `by-memory/-coverage-report.md`, or any `-coverage-report.md`, took no leases, and spawned no subagents. Post-acceptance implementation-callback proof is recorded in the checklist at the end of this report.

IDA MCP was available and mandatory evidence was gathered from the active session:

- endpoint: `http://127.0.0.1:13337/mcp`
- session id: `80de0a67`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- module: `NexusTK.exe`
- imagebase: `0x400000`
- `server_health`: `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`
- protocol version reported by `initialize`/`tools/list`: `2025-06-18`

No validators were run during the original report-only pass. Post-acceptance scoped validator results for the implemented by-* edits are recorded in the implementation checklist below.

## Target And Current State

- Assignment id: `B006-report-0001M3-emotion-input-pane-source-quality-20260626`
- Target: [UID:0001M3] `by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md`
- Report path: `tools/leaser/Agents/Agent-B006/research/0001M3-EmotionInputPane-source-quality.md`
- Live target metadata before implementation:
  - `COMPLETION:87`
  - `CONFIDENCE:89`
  - `CANONICAL_OWNER:00004B`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:00004B`
  - blank `EMITTER_POSITION_OPTIONAL`
  - blank formal `RECONSTRUCTION_CPP CODE`
  - `Nested:0`

The generated tracker is stale for this UID. `auto-generated/-ag-research-tracker.md` still lists [UID:0001M3] at `78/84` with no executed report, and `auto-generated/-ag-coverage-report-by-memory.md` still says `emits_code:false`, `78%`, updated `2026-06-24 16:05:41`. The live by-memory target is authoritative for this pass; generated artifacts must refresh only through validator/supervisor execution, not manual edits.

## Executive Recommendation

Update [UID:0001M3] to `COMPLETION:90`, `CONFIDENCE:91`; preserve `CANONICAL_OWNER:00004B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004B`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.

Populate the target's formal `RECONSTRUCTION_CPP CODE` block with the exact formal marker/block content in this report. The prior blank-C++ rationale is now stale: current MCP confirms exact constructor/handler boundaries, vtable route, one-character input helpers, uppercase normalization, exact selector arithmetic, the already accepted `SendEmotionPacket` helper, and the current/legacy SystemMessagePane menu helper roles strongly enough for first-draft method-cluster C++.

Keep [UID:0001M3] as a method cluster rather than splitting before implementation. The target contains two class-owned source methods with the same direct owner and no internal non-source span: constructor `0x005b29c0-0x005b2a70` and virtual handler `0x005b2a70-0x005b2f68`. The adjacent [UID:0001M4] `SendEmotionPacket` helper begins after eight `0xcc` bytes at `0x005b2f70` and remains separate.

Required support updates after supervisor acceptance:

- `by-class/EmotionInputPane.md`: raise to `88/90`; keep owner/emitter route; state [UID:0001M3] now carries method-body C++ while the class page stays declaration/layout only.
- `by-file/CommandInputPanes.md`: keep score `86/86`; update the Emotion row/evidence with first-draft target C++ readiness, exact selector arithmetic, current/legacy menu helper names, `m_refreshOnAppend`, and generated tracker staleness.
- `by-class/SystemMessagePane.md`: keep score `86/87`; add the accepted source-facing helper spellings used by the target C++ for `0x005854b0`, `0x005854d0`, `0x00585560`, and `0x00585360`, plus the inferred `m_refreshOnAppend` byte at `+0x130`.
- `by-class/OldSystemMessagePane.md`: keep score `85/88`; add the analogous legacy helper spellings for `0x00589330`, `0x00589350`, `0x00589470`, and `0x005892a0`, plus `m_refreshOnAppend` at `+0x130`.
- `by-global/g_useEpfAssets.md`: keep score `88/90`; add [UID:0001M3] as a direct read consumer where `byte_66DA97 == 1` chooses the current SystemMessagePane menu branch and the else branch chooses OldSystemMessagePane.
- `by-global/g_pChattingViewport.md`: keep score `87/90`; add [UID:0001M3] current-branch read at `0x005b2b35`, the `+0x130` batch-refresh clear, and helper family calls as consumer evidence only.
- `by-global/g_pOldSystemMessagePane.md`: keep score `86/90`; add [UID:0001M3] legacy-branch read at `0x005b2d5a`, the `+0x130` batch-refresh clear, and helper family calls as consumer evidence only.
- `by-global/g_packetSender.md`: keep score `86/88`; add [UID:0001M4] `SendEmotionPacket` as the Emotion feature packet-builder consumer: opcode `0x1d`, selector byte `selector - 0x0b`, local-only zero, send length `2`, and `QueueAndSendPacket` through `g_packetSender`; no Socket ownership change.
- `by-item/ScopedMarkerMissingMethodBodies.md`: update the `EmotionInputPane::OnCharInput` row so it no longer says the handler body remains missing once [UID:0001M3] receives formal method-cluster C++. Keep the page non-reconstructable and historical/generated-output oriented.

No edit is required for [UID:0001M4] `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md`: it is already `88/91`, has accepted first-draft helper C++, and current MCP confirms it is called only by [UID:0001M3]. No edit is required for the Emotion vtable pages, `g_pLanguageMan`, or the line/char input helper pages unless implementation finds a direct contradiction; current docs already carry equal-or-greater support detail for those dependencies.

## Local Documentation Checked

Primary and support pages read during this pass:

- target [UID:0001M3] `by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md`
- helper [UID:0001M4] `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md`
- [UID:00004B] `by-class/EmotionInputPane.md`
- [UID:0000ID] `by-file/CommandInputPanes.md`
- [UID:0001XA] `by-type/by-vtable/CommandInputPaneVtableFamily.md`
- [UID:0003HI] `by-type/by-vtable/EmotionInputPaneVtables.md`
- [UID:0000RC] `by-global/g_pLanguageMan.md`
- [UID:0000SW] `by-global/g_useEpfAssets.md`
- [UID:0002WV] `by-global/g_pChattingViewport.md`
- [UID:0003ED] `by-global/g_pOldSystemMessagePane.md`
- [UID:0000Q5] `by-global/g_packetSender.md`
- [UID:0000EA] `by-class/SystemMessagePane.md`
- [UID:00009T] `by-class/OldSystemMessagePane.md`
- [UID:0000OE] `by-file/SystemMessagePanes.md`
- [UID:0001J6] `by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md`
- [UID:00035R] `by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md`
- [UID:00035S] `by-memory/0x004f2310-0x004f231b.LineInputPaneTextLength.md`
- [UID:000363] `by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md`
- [UID:00018Y] `by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md`
- [UID:0000VD] `by-item/ScopedMarkerMissingMethodBodies.md`
- generated tracker/coverage rows for staleness only; no generated file was edited
- executed B009 reports for Emotion class and `SendEmotionPacket` as historical context; current MCP evidence below controls this recommendation

Key stale or superseded content found:

- Target [UID:0001M3] still says C++ is blocked by generated empty handler body and inferred SystemMessagePane helper spellings. Current MCP and support docs resolve those to a first-draft C++ level.
- [UID:00004B] still says final source names remain medium because the current generated `OnCharInput` body is empty and final menu helper names remain inferred. That remains a class-page confidence cap, but not a target child C++ blocker.
- [UID:0000VD] still says the virtual handler body remains missing until [UID:0001M3] is split or an inferred-helper draft is accepted. This report recommends accepting the inferred-helper target draft directly, so that row must be revised during implementation.
- `g_packetSender.md` does not yet list [UID:0001M4] as an Emotion feature packet-builder consumer, even though [UID:0001M4] now emits accepted helper C++ through `g_packetSender`.

## IDA MCP Evidence

### Function And Boundary Checks

Current `lookup_funcs` results:

| Address | Result | Meaning |
| --- | --- | --- |
| `0x005b29c0` | `sub_5B29C0`, size `0xb0` / 176 (Verified with int_convert.py) | `EmotionInputPane::EmotionInputPane()` constructor |
| `0x005b2a70` | `sub_5B2A70`, size `0x4f8` / 1272 (Verified with int_convert.py) | virtual `EmotionInputPane::OnCharInput()` handler |
| `0x005b2f68` | not a function | target end, followed by alignment |
| `0x005b2f70` | `sub_5B2F70`, size `0x5b` / 91 (Verified with int_convert.py) | separate [UID:0001M4] `SendEmotionPacket` helper |
| `0x005b2fcb` | not a function | helper end |
| `0x005b2fd0` | not a function | next raw-constructor neighborhood boundary |

Constructor `0x005b29c0` callees:

- `0x004f28a0`: `CharInputPane::CharInputPane(const wchar_t *promptText)`
- `0x004f0350`: `LanguageMan::GetLocalizedString`
- `0x0041b9b0`: wide-format helper used with a 128-wchar local prompt buffer
- `0x004f20a0`: `LineInputPane::SetPromptText`
- security-cookie helper

Handler `0x005b2a70` callees:

- `0x004f2310`: one-character text-length helper, source-facing `TextLength()`
- `0x004f2300`: one-character text copy helper, source-facing `CopyText(...)`
- `0x005b2f70`: [UID:0001M4] `SendEmotionPacket`
- current SystemMessagePane helper family `0x005854b0`, `0x005854d0`, `0x00585560`, `0x00585360`
- legacy OldSystemMessagePane helper family `0x00589330`, `0x00589350`, `0x00589470`, `0x005892a0`
- `0x004f0350`: `LanguageMan::GetLocalizedString`
- `0x004f4aa0`: operator-new wrapper, used to allocate `0x108` / 264 bytes (Verified with int_convert.py)
- `0x005b29c0`: constructor reopen path after the `?` menu

### Xrefs, Vtables, And Route Checks

Current `xrefs_to` results:

- `0x005b29c0`: direct construction calls at `0x005a6138`, `0x005a9390`, and `0x005b2f38`. The last one is the `?` menu reopen path inside `OnCharInput`.
- `0x005b2a70`: one data xref at vtable slot `0x0062fa00`; no ordinary direct code callers.
- `0x005b2f70`: direct calls only from `0x005b2aef`, `0x005b2b15`, and `0x005b2f52`, all inside `0x005b2a70`.
- `0x0062f9b8`: constructor vtable store xref at `0x005b2a03`.
- `0x0062fa08`: constructor vtable store xref at `0x005b2a09`.
- `0x0062fa38`: constructor vtable store xref at `0x005b2a13`.
- `0x0067adc4`: 16 xrefs; the Emotion current-branch read is at `0x005b2b35`.
- `0x0069b4c8`: 7 xrefs; the Emotion legacy-branch read is at `0x005b2d5a`.
- `0x0066da97`: broad one-byte mode global with 200 returned refs and more available; existing global page records 366 total xrefs.

Pointer-pattern checks:

- `find_bytes` found exactly one absolute VA pointer for handler `0x005b2a70`: slot `0x0062fa00`.
- Constructor pointer patterns for `0x005b29c0` returned no VA/RVA/raw-offset hits.
- Helper pointer patterns for `0x005b2f70` returned no VA/RVA/raw-offset hits, consistent with [UID:0001M4]'s file-local helper treatment.

Raw-byte checks:

- `0x005b2f68-0x005b2f70`: eight `0xcc` bytes. This separates [UID:0001M3] from [UID:0001M4].
- `0x005b2fcb-0x005b2fd0`: five `0xcc` bytes after [UID:0001M4].
- `0x0062f9b8-0x0062fa40`: 136-byte vtable data span (Verified with int_convert.py) containing slot `0x0062fa00 -> 0x005b2a70`.
- `0x0066da97`: byte value `0x01`.
- `0x0067adc4`: current zero-filled dword storage for `g_pChattingViewport`.
- `0x0069b4c8`: current zero-filled dword storage for `g_pOldSystemMessagePane`.

### Constructor Behavior

`analyze_function` and `decompile 0x005b29c0` show:

- constructs the `CharInputPane` base with a null initial prompt argument;
- installs the three `EmotionInputPane` vtable views at object offsets `+0`, `+0xa0` / 160, and `+0xa4` / 164 (Verified with int_convert.py);
- looks up localized string id `0x20` / 32 through `g_pLanguageMan` (Verified with int_convert.py);
- formats a local `wchar_t[128]` prompt buffer (128 Verified with int_convert.py) with max emotion count `0x70` / 112 (Verified with int_convert.py);
- applies the prompt with `LineInputPane::SetPromptText`;
- returns `this`.

The constructor is ready as first-draft `EmotionInputPane::EmotionInputPane() : CharInputPane(0)` followed by prompt formatting and `SetPromptText`.

### OnCharInput Behavior

`decompile` and `disasm 0x005b2a70` confirm the target handler:

- first checks `g_useEpfAssets` / historical `byte_66DA97` against `1`;
- in each branch, requires `TextLength() == 1` before copying one input character;
- copies one wide character through the inherited copy helper;
- normalizes `A-Z` to lowercase by adding `0x20` / 32 (Verified with int_convert.py);
- accepts only `a-p` for emotion sends and `?` for the menu; all other one-character input returns without packet/menu action;
- preserves exact selector split arithmetic:
  - `a-l`: calls `SendEmotionPacket(ch - 0x56)` / subtract decimal 86 (Verified with int_convert.py);
  - `m-n`: calls `SendEmotionPacket(ch - 0x64)` / subtract decimal 100 (Verified with int_convert.py);
  - `o-p`: calls `SendEmotionPacket(ch - 0x58)` / subtract decimal 88 (Verified with int_convert.py);
- for `?`, builds a localized menu title with string id `0x1f` / 31 (Verified with int_convert.py);
- appends localized emotion entries string ids `0x0f-0x1e` / 15 through 30 (Verified with int_convert.py);
- uses title color/style arguments `4` and `0x24` / 36 (Verified with int_convert.py), and entry color/style arguments `0x84` / 132 and `0x24` / 36 (Verified with int_convert.py);
- clears byte `+0x130` / 304 (Verified with int_convert.py) on the selected message pane before batching menu appends;
- refreshes/prunes at the end through the selected pane's refresh helper;
- allocates `0x108` / 264 bytes (Verified with int_convert.py) and calls the constructor again to reopen the prompt after displaying the menu.

Current branch details:

- Branch condition: `g_useEpfAssets == 1`.
- Message pane global: `g_pChattingViewport` / historical `dword_67ADC4`.
- Read site: `0x005b2b35`.
- Helper names recommended for support docs and formal C++:
  - `SystemMessagePane::AppendHeaderMarker()` for `0x005854b0`;
  - `SystemMessagePane::AppendColoredText(...)` for `0x005854d0`;
  - `SystemMessagePane::AppendFooterMarker()` for `0x00585560`;
  - `SystemMessagePane::RefreshAndPruneMessages()` for `0x00585360`;
  - `m_refreshOnAppend` for byte `+0x130`, cleared before a batch and set/enforced by refresh/insert helpers.

Legacy branch details:

- Branch condition: `g_useEpfAssets != 1`.
- Message pane global: `g_pOldSystemMessagePane` / historical `dword_69B4C8`.
- Read site: `0x005b2d5a`.
- Helper names recommended for support docs and formal C++:
  - `OldSystemMessagePane::AppendHeaderMarker()` for `0x00589330`;
  - `OldSystemMessagePane::AppendColoredText(...)` for `0x00589350`;
  - `OldSystemMessagePane::AppendFooterMarker()` for `0x00589470`;
  - `OldSystemMessagePane::RefreshAndPruneMessages()` for `0x005892a0`;
  - `m_refreshOnAppend` for the same batch-refresh byte at `+0x130`.

Helper decompiles support these names:

- `0x005854b0` and `0x00589330` construct and submit a `HeaderSystemMessage`.
- `0x00585560` and `0x00589470` construct and submit a `FooterSystemMessage`.
- `0x005854d0` and `0x00589350` construct a `ColorStringSystemMessage` from text/color/style arguments and insert it into the message list.
- `0x00585360` and `0x005892a0` set the `+0x130` byte back to true, recompute scroll/list geometry, and prune the message list over 200 entries.

### SendEmotionPacket Relationship

[UID:0001M4] remains the separate file-local/static helper:

- exact range: `0x005b2f70-0x005b2fcb`;
- direct callers only from target [UID:0001M3] at `0x005b2aef`, `0x005b2b15`, and `0x005b2f52`;
- no pointer-table route to helper start;
- body ignores `ecx`;
- opcode `0x1d` / 29 (Verified with int_convert.py);
- helper subtracts `0x0b` / 11 (Verified with int_convert.py) from the selector argument before writing the packet byte;
- source-shaped 128-byte packet scratch buffer already accepted in [UID:0001M4];
- sends exactly length `2` through `g_packetSender` / `QueueAndSendPacket`;
- local `packet[2]` zero is not transmitted.

Do not fold [UID:0001M4] into [UID:0001M3], and do not move the [UID:0001M4] formal helper body into the target. The target should call `SendEmotionPacket(...)`; the helper page remains the owner for packet serialization.

## int_convert.py Evidence

The numeric conversions used in this report were verified from `E:\NTK\GhidraBridge\source-3\project-documentation` with:

> Executable block R001 was removed from this report and preserved verbatim in [0001M3-EmotionInputPane-source-quality-removed.md](0001M3-EmotionInputPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Every returned entry had `error:null`. Values inherited into the recommendation:

- `0xb0` = `176`
- `0x4f8` = `1272`
- `0x5b` = `91`
- `0x108` = `264`
- `0x80` = `128`
- `0x70` = `112`
- `0x20` = `32`
- `0x1f` = `31`
- `0x0f` = `15`
- `0x1e` = `30`
- `0x84` = `132`
- `0x24` = `36`
- `0x56` = `86`
- `0x64` = `100`
- `0x58` = `88`
- `0x0b` = `11`
- `0x130` = `304`
- `0x88` = `136`
- `0xa0` = `160`
- `0xa4` = `164`
- `0x1d` = `29`
- `0x3f` = `63`

## Source-Quality Decisions

### Target Ownership And Source Placement

Keep [UID:0001M3] owned by [UID:00004B] `EmotionInputPane`, emitted through [UID:00004B], with source-route support through [UID:0000ID] `CommandInputPanes`.

Positive evidence:

- constructor installs the `EmotionInputPane` vtable triplet;
- virtual handler is reached through `0x0062fa00` in the `EmotionInputPane` vtable data;
- constructor callers and `?` reopen path all create `EmotionInputPane`;
- handler's only packet helper calls target the accepted Emotion helper [UID:0001M4];
- target behavior is the Emotion command prompt, not generic line/char input, chat, packet buffer, or system-message pane logic.

Rejected owners:

- `SystemMessagePanes`: owns display/list helper mechanics only. The target is an input command handler that consumes message-pane append helpers on `?`.
- `PacketBuffer`, `Socket`, or central protocol send code: dependencies for [UID:0001M4] only; they do not own the Emotion command UI.
- `ChatInputPane` or `Chatting`: rejected because this route uses opcode `0x1d` through [UID:0001M4], not ChatInputPane opcode `0x0e`.
- `LineInputPane` / `CharInputPane`: base/helper dependencies only; derived vtables and command behavior identify `EmotionInputPane`.
- A standalone `EmotionInputPane.cpp`: plausible original source split, but not proven by current project source-route evidence. Keeping `CommandInputPanes.cpp` as the current route is less invented than moving it to a new file.

### Split Decision

No split is required for this implementation callback.

[UID:0001M3] covers two source-authored methods with one owner/emitter and no internal alignment gap. A future exact-child split into constructor and `OnCharInput` pages would be mechanically possible, but it is not required to resolve the current source-quality blockers. If a future supervisor chooses that split, the constructor and handler bodies in the formal block can be moved unchanged to the exact child pages.

[UID:0001M4] remains separate because the eight `0xcc` bytes at `0x005b2f68-0x005b2f70` mark the helper boundary and [UID:0001M4] has its own accepted helper C++.

### Source-Facing Names

Accepted or recommended names:

| Binary / old label | Source-facing decision | Evidence |
| --- | --- | --- |
| `sub_5B29C0` | `EmotionInputPane::EmotionInputPane()` | constructor shape, vtable stores, constructor callers |
| `sub_5B2A70` | `EmotionInputPane::OnCharInput()` | vtable slot `0x0062fa00`, single-character handler behavior |
| `sub_4F2310` | `TextLength()` | inherited line-input helper; existing Say target C++ style |
| `sub_4F2300` | `CopyText(...)` | inherited line-input copy helper; existing Say target C++ style |
| uppercase block | inline normalization | direct character arithmetic; no helper needed |
| `sub_5B2F70` | `SendEmotionPacket(int selector)` | accepted [UID:0001M4] helper C++ |
| `byte_66DA97` | `g_useEpfAssets` | by-global canonical alias, one-byte current-vs-legacy selector |
| `unk_67ADC4` / `dword_67ADC4` | `g_pChattingViewport` | by-global canonical current system-message pointer |
| `unk_69B4C8` / `dword_69B4C8` | `g_pOldSystemMessagePane` | by-global canonical legacy system-message pointer |
| `+0x130` byte on message panes | `m_refreshOnAppend` | clear-before-batch/set-by-refresh behavior |
| `0x005854b0` / `0x00589330` | `AppendHeaderMarker()` | constructs/submits `HeaderSystemMessage` |
| `0x005854d0` / `0x00589350` | `AppendColoredText(...)` | constructs/submits `ColorStringSystemMessage` with text/color/style |
| `0x00585560` / `0x00589470` | `AppendFooterMarker()` | constructs/submits `FooterSystemMessage` |
| `0x00585360` / `0x005892a0` | `RefreshAndPruneMessages()` | refreshes geometry and prunes message list over 200 entries |

These names are source-facing first-draft names, not recovered debug symbols. Confidence stays below final because exact original spellings for the message-pane helper methods and `m_refreshOnAppend` are inferred. They are strong enough for target first-draft C++ because the helper roles are decompile-proven and already documented on the owning SystemMessagePane/OldSystemMessagePane pages.

### Selector Arithmetic

The target must preserve the exact three-way selector split. Do not flatten the mapping to a single `ch - 'a'` source shape.

The current binary sends:

- `a-l`: `SendEmotionPacket(ch - 0x56)`;
- `m-n`: `SendEmotionPacket(ch - 0x64)`;
- `o-p`: `SendEmotionPacket(ch - 0x58)`.

Because [UID:0001M4] subtracts `0x0b` again, these caller arguments produce the exact transmitted selector behavior documented on the helper page. The unusual `m-n` arithmetic is current evidence and must not be "corrected" to a linear mapping without new source metadata.

## Exact Formal RECONSTRUCTION_CPP CODE For [UID:0001M3]

The following fenced text is the exact formal reconstruction header/block content recommended for [UID:0001M3]. During implementation, replace the target's formal `RECONSTRUCTION_CPP CODE` marker/block with this exact marker/block content, preserving the surrounding non-C++ metadata lines. Do not treat this as an illustrative snippet, do not omit the marker lines in the report-derived insertion, and do not place this code in prose, support pages, generated files, or [UID:0001M4].

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
EmotionInputPane::EmotionInputPane()
    : CharInputPane(0)
{
    wchar_t promptText[128];

    swprintf_s(promptText, _countof(promptText), g_pLanguageMan->GetLocalizedString(32), 112);
    SetPromptText(promptText);
}

void EmotionInputPane::OnCharInput()
{
    if (g_useEpfAssets == 1) {
        if (TextLength() != 1) {
            return;
        }

        wchar_t ch = 0;
        CopyText(&ch, 1);

        if (ch >= L'A' && ch <= L'Z') {
            ch = static_cast<wchar_t>(ch + 0x20);
        }

        if (ch >= L'a' && ch <= L'p') {
            if (ch <= L'l') {
                SendEmotionPacket(ch - 0x56);
            } else if (ch <= L'n') {
                SendEmotionPacket(ch - 0x64);
            } else {
                SendEmotionPacket(ch - 0x58);
            }
            return;
        }

        if (ch != L'?') {
            return;
        }

        SystemMessagePane *pane = g_pChattingViewport;
        pane->m_refreshOnAppend = false;
        pane->AppendHeaderMarker();
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(31), 4, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(15), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(16), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(17), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(18), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(19), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(20), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(21), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(22), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(23), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(24), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(25), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(26), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(27), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(28), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(29), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(30), 132, 36);
        pane->AppendFooterMarker();
        pane->RefreshAndPruneMessages();

        new EmotionInputPane();
        return;
    }

    if (TextLength() != 1) {
        return;
    }

    wchar_t ch = 0;
    CopyText(&ch, 1);

    if (ch >= L'A' && ch <= L'Z') {
        ch = static_cast<wchar_t>(ch + 0x20);
    }

    if (ch >= L'a' && ch <= L'p') {
        if (ch <= L'l') {
            SendEmotionPacket(ch - 0x56);
        } else if (ch <= L'n') {
            SendEmotionPacket(ch - 0x64);
        } else {
            SendEmotionPacket(ch - 0x58);
        }
        return;
    }

    if (ch != L'?') {
        return;
    }

    OldSystemMessagePane *pane = g_pOldSystemMessagePane;
    pane->m_refreshOnAppend = false;
    pane->AppendHeaderMarker();
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(31), 4, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(15), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(16), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(17), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(18), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(19), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(20), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(21), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(22), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(23), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(24), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(25), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(26), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(27), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(28), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(29), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(30), 132, 36);
    pane->AppendFooterMarker();
    pane->RefreshAndPruneMessages();

    new EmotionInputPane();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Score Rationale

Recommended target score: `COMPLETION:90`, `CONFIDENCE:91`.

Completion increases because the current pass resolves the target-specific blank-C++ blockers:

- constructor and handler ranges are current MCP-confirmed;
- vtable route and constructor callers are current MCP-confirmed;
- the helper pages now support `TextLength()`, `CopyText(...)`, `SetPromptText`, `CharInputPane(0)`, `SendEmotionPacket`, `g_useEpfAssets`, `g_pChattingViewport`, and `g_pOldSystemMessagePane`;
- SystemMessagePane/OldSystemMessagePane helper roles are decompile-proven enough for source-facing method names;
- exact selector arithmetic and menu string/color/style arguments are documented;
- formal first-draft C++ is supplied as exact marker/block content.

Confidence remains below final because:

- exact original spellings for `AppendHeaderMarker`, `AppendColoredText`, `AppendFooterMarker`, `RefreshAndPruneMessages`, and `m_refreshOnAppend` are inferred from behavior rather than recovered symbols;
- a future standalone `EmotionInputPane.cpp` source split remains plausible but unproven;
- generated output has not yet been refreshed after target formal C++ insertion;
- the source-level spelling of localization wrappers and old/current message-pane APIs may be refined by a later final-source naming pass without changing behavior.

## Rejected Alternatives And Negative Evidence

| Alternative | Decision | Reason |
| --- | --- | --- |
| Leave [UID:0001M3] formal C++ blank | rejected | Current blockers are resolved to first-draft quality; live target is reconstructable with valid emitter and average score above the active C++ gate. |
| Split constructor and handler before C++ | rejected for this callback | Exact split is possible but unnecessary; both target functions share owner/emitter and no internal padding. |
| Move handler body to the class page | rejected | [UID:00004B] class page owns layout/method inventory; executable bodies belong to child by-memory pages. |
| Fold [UID:0001M4] into [UID:0001M3] | rejected | Eight `0xcc` bytes separate the target and helper; helper has its own accepted C++ and caller set. |
| Flatten selector mapping to `ch - 'a'` | rejected | Current MCP proves three different call-site subtractions: `0x56`, `0x64`, and `0x58`. |
| Treat SystemMessagePane as owner | rejected | The message panes own menu display/list helpers only; EmotionInputPane owns input command flow. |
| Treat packet/global dependencies as owners | rejected | `g_packetSender`, `PacketBufferWriteUInt8`, and `QueueAndSendPacket` are helper dependencies through [UID:0001M4], not Emotion command owners. |
| Treat ChatInputPane/Chatting as owner | rejected | Emotion sends opcode `0x1d`; ChatInputPane opcode `0x0e` is a different route. |
| Use IDA/generated labels such as `sub_`, `unk_`, `dword_`, or `byte_` in source-facing docs | rejected | Best-supported canonical names exist in support docs or are behavior-backed first-draft names. Historical labels should remain only as aliases/search terms. |

## Recommended Target Doc Changes

Target: `by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md`

Required implementation details:

- Set `COMPLETION:90` and `CONFIDENCE:91`.
- Preserve `CANONICAL_OWNER:00004B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004B`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
- Replace the target formal reconstruction marker/block with the exact formal marker/block content from this report, without the report's Markdown fence.
- Update Item Summary to this exact recommended text:
  - `Emotion command constructor and virtual OnCharInput method cluster; B006 MCP session 80de0a67 confirms constructor size 176, handler size 1272, vtable slot 0x0062fa00, prompt id 32/max emotion count 112, one-character input helpers, uppercase normalization, exact a-l/m-n/o-p selector arithmetic, current/legacy ? menu branches, SendEmotionPacket caller set, and padding before the helper.`
- Update status/C++ notes so the handler is no longer blank pending a split. State [UID:0001M3] is the emitting method cluster, while [UID:0001M4] remains the separate helper.
- Preserve and expand current MCP evidence at report-level detail: session `80de0a67`, lookup sizes, constructor callers, vtable slot, helper caller set, `g_useEpfAssets`, current/legacy globals, padding bytes, and `int_convert.py` command provenance.
- Add C++ rationale that the menu helper method names and `m_refreshOnAppend` are inferred source-facing names with support-doc proof; they cap confidence but no longer block first-draft target C++.
- Preserve the exact selector arithmetic and explicitly reject a linear `ch - 'a'` rewrite.
- Preserve rejected-owner/source-placement rationale: `CommandInputPanes` route retained; SystemMessagePanes, PacketBuffer, Socket, Chatting/ChatInputPane, LineInputPane/CharInputPane, and standalone `EmotionInputPane.cpp` rejected or left unproven as above.

## Recommended Support Doc Changes

### Required: `by-class/EmotionInputPane.md`

- Set `COMPLETION:88`, `CONFIDENCE:90`; preserve `CANONICAL_OWNER:0000ID`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ID`, and blank formal class C++.
- Update confidence/status wording so the current generated empty handler body is historical/generated lag after the target implementation, not a live target C++ blocker.
- In Method Map, change `OnCharInput` from "emitted code is currently an empty child marker" to state first-draft body C++ lives on [UID:0001M3] and preserves exact `a-l`/`m-n`/`o-p` arithmetic and current/legacy `?` menu branches.
- Keep `SendEmotionPacket` as a file-local/static helper on [UID:0001M4], not an instance method.
- Add B006 session `80de0a67` facts: constructor size 176, handler size 1272, vtable slot `0x0062fa00`, menu helper families, `m_refreshOnAppend` support decision, and [UID:0001M4] accepted helper relationship.
- Preserve class-page no-code proof: class page remains declaration/layout/method inventory only; method bodies belong to child by-memory pages.

### Required: `by-file/CommandInputPanes.md`

- Keep score `86/86` and source route.
- Update the Emotion row/evidence to say [UID:0001M3] now has first-draft constructor/handler C++ ready/recommended, [UID:0001M4] keeps the helper C++, and generated tracker/coverage rows were stale before implementation.
- Add exact current B006 evidence: constructor callers `0x005a6138`, `0x005a9390`, and `0x005b2f38`; vtable slot `0x0062fa00`; handler size 1272; helper calls `0x005b2aef`, `0x005b2b15`, `0x005b2f52`; current/legacy menu globals; `m_refreshOnAppend`; exact selector arithmetic; padding before/after helper.
- Preserve source-placement rejection of a standalone `EmotionInputPane.cpp` as plausible but unproven.

### Required: `by-class/SystemMessagePane.md`

- Keep score `86/87`, owner/emitter [UID:0000OE], and blank formal C++.
- Add a B006 support note that [UID:0001M3] current-mode `?` menu uses:
  - `AppendHeaderMarker()` for `0x005854b0`;
  - `AppendColoredText(...)` for `0x005854d0`;
  - `AppendFooterMarker()` for `0x00585560`;
  - `RefreshAndPruneMessages()` for `0x00585360`;
  - `m_refreshOnAppend` at `+0x130`.
- State the names are source-facing/descriptive and behavior-backed, not recovered debug symbols. They support target C++ only and do not make `SystemMessagePane` owner of the Emotion command logic.

### Required: `by-class/OldSystemMessagePane.md`

- Keep score `85/88`, owner/emitter [UID:0000OE], and blank formal C++.
- Add a B006 support note that [UID:0001M3] legacy `?` menu uses:
  - `AppendHeaderMarker()` for `0x00589330`;
  - `AppendColoredText(...)` for `0x00589350`;
  - `AppendFooterMarker()` for `0x00589470`;
  - `RefreshAndPruneMessages()` for `0x005892a0`;
  - `m_refreshOnAppend` at `+0x130`.
- State this is helper/type evidence only; OldSystemMessagePane remains a SystemMessagePanes class and does not own Emotion input logic.

### Required: `by-global/g_useEpfAssets.md`

- Keep score `88/90`, owner/emitter [UID:0000O5], and blank formal C++.
- Add [UID:0001M3] as a consumer: the handler compares `byte_66DA97`/`g_useEpfAssets` with `1` at `0x005b2a99`; current mode uses `g_pChattingViewport`, legacy mode uses `g_pOldSystemMessagePane`.
- State this is read-consumer evidence only and does not alter StartupWindow/source-owner inference.

### Required: `by-global/g_pChattingViewport.md`

- Keep score `87/90`, owner/emitter [UID:0000OE], and blank formal C++.
- Add [UID:0001M3] current-mode consumer evidence: read at `0x005b2b35`, `m_refreshOnAppend`/`+0x130` clear before appending emotion menu messages, helper calls `0x005854b0`, `0x005854d0`, `0x00585560`, `0x00585360`.
- State this does not change SystemMessagePanes ownership of the singleton.

### Required: `by-global/g_pOldSystemMessagePane.md`

- Keep score `86/90`, owner/emitter [UID:0000OE], and blank formal C++.
- Add [UID:0001M3] legacy-mode consumer evidence: read at `0x005b2d5a`, `m_refreshOnAppend`/`+0x130` clear before appending emotion menu messages, helper calls `0x00589330`, `0x00589350`, `0x00589470`, `0x005892a0`.
- State this does not change SystemMessagePanes ownership of the singleton.

### Required: `by-global/g_packetSender.md`

- Keep score `86/88`, owner/emitter [UID:0000NS], and blank formal C++.
- Add [UID:0001M4] as the Emotion feature packet-builder consumer: `SendEmotionPacket` builds opcode `0x1d`, writes selector byte `selector - 0x0b`, stores a local-only zero byte, and calls `QueueAndSendPacket(g_packetSender, packet, 2)`.
- State this is consumer/type evidence only and does not move Socket ownership of `g_packetSender`.

### Required: `by-item/ScopedMarkerMissingMethodBodies.md`

- Keep metadata ignored/non-reconstructable.
- Update the `EmotionInputPane::OnCharInput` row to say B006 [UID:0001M3] supplies accepted/recommended first-draft target C++ for the constructor/handler method cluster once implementation is applied; the row remains only a historical generated-output quality warning until generated output refreshes.
- Do not use this page for coverage scoring and do not add formal C++.

### Explicit No-Edit-Required Support Checks

- `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md`: no edit required. It is already `88/91`, formal helper C++ is present, B009/B006 session `80de0a67` evidence confirms caller set and `packet[128]` scratch shape, and this report does not change helper behavior.
- `by-type/by-vtable/CommandInputPaneVtableFamily.md`: no edit required. It already records the `EmotionInputPane` vtable slot and stores; target implementation only consumes that existing fact.
- `by-type/by-vtable/EmotionInputPaneVtables.md`: no edit required. It already carries the source-local vtable family and `0x0062fa00` slot evidence.
- `by-global/g_pLanguageMan.md`: no edit required. It already owns the localization singleton/lookup role; target-specific prompt/menu ids belong in [UID:0001M3] and file/class docs.
- `by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md` and `by-memory/0x004f2310-0x004f231b.LineInputPaneTextLength.md`: no edit required. Existing helper docs are sufficient for `CopyText(...)` and `TextLength()` names used by the target.
- `by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md` and `by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md`: no edit required. Existing docs support the constructor and prompt setter dependencies.
- `by-file/SystemMessagePanes.md` and `by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md`: no edit required unless implementation finds contradictory wording. The required helper-name synchronization belongs on the concrete SystemMessagePane and OldSystemMessagePane class pages.
- Generated tracker/coverage files and manual coverage reports: no manual edit. Expected refresh is validator/supervisor-owned after implementation and report execution.

## Exact Validator Commands After Implementation

Run these scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every edited file listed here. Record command id, timestamp, exit code, ok count, warnings, and generated-refresh observations in the report checklist during implementation.

> Executable block R002 was removed from this report and preserved verbatim in [0001M3-EmotionInputPane-source-quality-removed.md](0001M3-EmotionInputPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not run validators for no-edit-required files unless they are actually edited during implementation.

## Implementation Tracking Checklist

- [x] Target `by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md`: implemented. Proof: metadata is `COMPLETION:90`, `CONFIDENCE:91`; owner/emitter/reconstructable metadata and `Nested:0` were preserved; the exact formal `RECONSTRUCTION_CPP CODE` marker/block from this report was inserted; Item Summary now uses the recommended constructor/handler cluster wording; body evidence records MCP session `80de0a67`, lookup sizes, constructor callers, vtable slot `0x0062fa00`, helper caller set, `g_useEpfAssets`, current/legacy globals, padding bytes, `int_convert.py` provenance, source-placement, helper-name, split, score, rejected-alternative, and generated-staleness details. Validator command: `python .\tools\validator.py --mode file --file by-memory\0x005b29c0-0x005b2f68.EmotionInputPane.md --apply --queue-timeout 240`; `command_id: 000000002480`; `command_timestamp: 2026-06-26T06:17:23-04:00`; exit code `0`; `ok: 1`; warnings/actions: `missing_ref_uid: 3` for out-of-scope UID references, `uid_link_insert: 5`, metadata/autogen normalization, `projected_stats_update: 1`; `generated_refresh: deferred`.
- [x] Support `by-class/EmotionInputPane.md`: implemented. Proof: metadata is `COMPLETION:88`, `CONFIDENCE:90`; class formal C++ remains declaration-only/blank for method bodies; method map/status/no-code proof now states method-body C++ lives on [UID:0001M3], [UID:0001M4] remains the helper, and generated empty marker wording is historical/generated lag after callback. Validator command: `python .\tools\validator.py --mode file --file by-class\EmotionInputPane.md --apply --queue-timeout 240`; `command_id: 000000002483`; `command_timestamp: 2026-06-26T06:17:34-04:00`; exit code `0`; `ok: 1`; warnings/actions: `missing_ref_uid: 6` for out-of-scope UID references, `uid_link_insert: 1`, metadata normalization, `projected_stats_update: 1`; `generated_refresh: deferred`.
- [x] Support `by-file/CommandInputPanes.md`: implemented. Proof: score remains `86/86`; Emotion row/evidence now carries B006 session facts, first-draft target C++ readiness, exact selector arithmetic, current/legacy menu helper names, helper separation, and generated tracker staleness. Validator command: `python .\tools\validator.py --mode file --file by-file\CommandInputPanes.md --apply --queue-timeout 240`; `command_id: 000000002486`; `command_timestamp: 2026-06-26T06:17:44-04:00`; exit code `0`; `ok: 1`; warnings/actions: existing aggregate-page `missing_ref_uid: 22`, `missing_ref_target: 7`, `uid_link_insert: 2`, `projected_stats_update: 1`; `generated_refresh: deferred`.
- [x] Support `by-class/SystemMessagePane.md`: implemented. Proof: score remains `86/87`; added [UID:0001M3] current-mode helper-name and `m_refreshOnAppend` support note; blank formal C++ and SystemMessagePanes ownership preserved. Validator command: `python .\tools\validator.py --mode file --file by-class\SystemMessagePane.md --apply --queue-timeout 240`; `command_id: 000000002489`; `command_timestamp: 2026-06-26T06:17:55-04:00`; exit code `0`; `ok: 1`; warnings/actions: `missing_ref_uid: 6` for out-of-scope UID references, `uid_link_insert: 1`, `reference_index_add: 2`, `projected_stats_update: 1`; `generated_refresh: deferred`.
- [x] Support `by-class/OldSystemMessagePane.md`: implemented. Proof: score remains `85/88`; added [UID:0001M3] legacy-mode helper-name and `m_refreshOnAppend` support note; blank formal C++ and SystemMessagePanes ownership preserved. Validator command: `python .\tools\validator.py --mode file --file by-class\OldSystemMessagePane.md --apply --queue-timeout 240`; `command_id: 000000002490`; `command_timestamp: 2026-06-26T06:18:05-04:00`; exit code `0`; `ok: 1`; warnings/actions: `missing_ref_uid: 5` for out-of-scope UID references, `uid_link_insert: 1`, `reference_index_add: 1`, `projected_stats_update: 1`; `generated_refresh: deferred`.
- [x] Support `by-global/g_useEpfAssets.md`: implemented. Proof: score remains `88/90`; added [UID:0001M3] read-consumer branch evidence for compare at `0x005b2a99`, current branch through `g_pChattingViewport`, and legacy branch through `g_pOldSystemMessagePane`; StartupWindow owner/emitter and blank formal C++ preserved. Validator command: `python .\tools\validator.py --mode file --file by-global\g_useEpfAssets.md --apply --queue-timeout 240`; `command_id: 000000002491`; `command_timestamp: 2026-06-26T06:18:16-04:00`; exit code `0`; `ok: 1`; warnings/actions: existing `missing_ref_uid: 6`, `missing_ref_target: 1`, `uid_link_insert: 1`, metadata/autogen normalization, `reference_index_add: 4`, `projected_stats_update: 1`; `generated_refresh: deferred`.
- [x] Support `by-global/g_pChattingViewport.md`: implemented. Proof: score remains `87/90`; added [UID:0001M3] current-branch consumer evidence at `0x005b2b35`, `+0x130`/`m_refreshOnAppend`, and current helper family calls; SystemMessagePanes owner/emitter and blank formal C++ preserved. Validator command: `python .\tools\validator.py --mode file --file by-global\g_pChattingViewport.md --apply --queue-timeout 240`; `command_id: 000000002492`; `command_timestamp: 2026-06-26T06:18:25-04:00`; exit code `0`; `ok: 1`; warnings/actions: `uid_link_insert: 1`, metadata/autogen normalization, `reference_index_add: 1`, `projected_stats_update: 1`; `generated_refresh: deferred`.
- [x] Support `by-global/g_pOldSystemMessagePane.md`: implemented. Proof: score remains `86/90`; added [UID:0001M3] legacy-branch consumer evidence at `0x005b2d5a`, `+0x130`/`m_refreshOnAppend`, and legacy helper family calls; SystemMessagePanes owner/emitter and blank formal C++ preserved. Validator command: `python .\tools\validator.py --mode file --file by-global\g_pOldSystemMessagePane.md --apply --queue-timeout 240`; `command_id: 000000002494`; `command_timestamp: 2026-06-26T06:18:32-04:00`; exit code `0`; `ok: 1`; warnings/actions: `path_update: 1`, `uid_link_insert: 1`, metadata/autogen normalization, `reference_index_add: 5`, `projected_stats_update: 1`; `generated_refresh: deferred`.
- [x] Support `by-global/g_packetSender.md`: implemented. Proof: score remains `86/88`; added [UID:0001M4] Emotion packet helper consumer evidence for opcode `0x1d`, selector byte after the handler's `selector - 0x0b` conversion, local-only zero, length `2`, and `g_packetSender->QueueAndSendPacket`; Socket owner/emitter and blank formal C++ preserved. Validator command: `python .\tools\validator.py --mode file --file by-global\g_packetSender.md --apply --queue-timeout 240`; `command_id: 000000002497`; `command_timestamp: 2026-06-26T06:18:40-04:00`; exit code `0`; `ok: 1`; warnings/actions: existing `missing_ref_uid: 2`, `reference_index_add: 4`, `projected_stats_update: 1`; `generated_refresh: deferred`.
- [x] Support `by-item/ScopedMarkerMissingMethodBodies.md`: implemented. Proof: ignored/non-reconstructable metadata preserved; `EmotionInputPane::OnCharInput` row now reflects accepted [UID:0001M3] target constructor/handler C++ after callback and keeps the row as generated-output refresh expectation only; no formal C++ added. Validator command: `python .\tools\validator.py --mode file --file by-item\ScopedMarkerMissingMethodBodies.md --apply --queue-timeout 240`; `command_id: 000000002499`; `command_timestamp: 2026-06-26T06:18:51-04:00`; exit code `0`; `ok: 1`; warnings/actions: metadata/autogen normalization, `reference_index_add: 2`, `projected_stats_update: 1`; `generated_refresh: deferred`.
- [x] No edit required: [UID:0001M4] `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md`. Proof: accepted report and target/support checks confirmed it already has `88/91` metadata, formal `SendEmotionPacket` helper C++, caller set only from [UID:0001M3], opcode `0x1d`, selector-byte send, `packet[128]` local, length `2`, and helper separation at equal-or-greater detail; no contradiction found during implementation.
- [x] No edit required: vtable pages `by-type/by-vtable/CommandInputPaneVtableFamily.md` and `by-type/by-vtable/EmotionInputPaneVtables.md`. Proof: accepted report check confirmed they already document the `0x0062fa00` handler slot and vtable-store evidence consumed by [UID:0001M3]; implementation found no contradiction requiring edits.
- [x] No edit required: `by-global/g_pLanguageMan.md`, line/char input helper pages, `CharInputPaneConstructor`, and `LineInputPaneSetPromptText`. Proof: accepted report check confirmed existing docs support the localization lookup, `CopyText(...)`, `TextLength()`, `CharInputPane` constructor, and prompt setter roles used by target C++; implementation found no target-specific contradiction or naming blocker.
- [x] No edit required unless contradiction found: `by-file/SystemMessagePanes.md` and `by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md`. Proof: implementation found no contradiction; required helper-name synchronization was applied to the concrete `SystemMessagePane` and `OldSystemMessagePane` class pages, which own the accepted support detail.
- [x] Generated refresh expectation: no manual edits were made to `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, generated source, `by-memory/-coverage-report.md`, or any `-coverage-report.md`. Scoped validators reported `generated_refresh: deferred` for each changed by-* file; generated rows remain expected to refresh only through validator/report execution and supervisor-owned generated/coverage processes.
- [x] Lease and validation proof: B006 leased the immediate edit batch before by-* edits; after the scoped validator batch, `python tools\leaser\leaser.py B006 unlease ...` released all ten edited by-* files successfully. `tools/leaser/Agents/current_leases.md` was checked after release and showed no active B006 leases, only other agents' unrelated leases. Validator proof is recorded above for every edited by-* file with command, `command_id`, `command_timestamp`, exit code, `ok` count, warnings/actions, and generated-refresh state.
- [x] Supervisor cleanup callback: removed the remaining stale current-blocker sentence in `by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md` that still said formal C++ stayed blank pending a split or accepted inferred menu-helper spellings. Replacement wording preserves the 2026-06-21 generated-output symptom as historical context and states the B006 2026-06-26 callback resolved it by accepting cluster-level first-draft formal constructor/handler C++ on [UID:0001M3]. Cleanup scan command covered the target plus edited support docs and found no other current-blocker matches for `Formal C++ stays blank`, `pending a split`, `C++ is blocked`, `generated empty handler body`, `handler body remains missing`, `virtual handler body remains missing`, `blank-C++ rationale`, or `empty handler body`. Validator command: `python .\tools\validator.py --mode file --file by-memory\0x005b29c0-0x005b2f68.EmotionInputPane.md --apply --queue-timeout 240`; `command_id: 000000002531`; `command_timestamp: 2026-06-26T06:31:55-04:00`; exit code `0`; `ok: 1`; warnings/actions: existing `missing_ref_uid: 1` for `0003HI`, `reference_index_add: 1`, `projected_stats_update: 1`; `generated_refresh: deferred`. Lease proof: B006 leased only the target file for the cleanup edit/validator batch, released it with `python tools\leaser\leaser.py B006 unlease by-memory\0x005b29c0-0x005b2f68.EmotionInputPane.md`, and `tools/leaser/Agents/current_leases.md` showed no active leases afterward.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0001M3-EmotionInputPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0001M3-EmotionInputPane-source-quality.md","timestamp":"2026-06-26T06:36:05","uid":"0001M3"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001M3-EmotionInputPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0001M3-EmotionInputPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001M3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
