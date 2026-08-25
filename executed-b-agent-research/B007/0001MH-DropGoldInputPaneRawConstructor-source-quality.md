** TARGET-REPORT-UID:0001MH **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001MH DropGoldInputPaneRawConstructor Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: update [UID:0001MH] `by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md` from a stale blank-C++ raw-constructor page into a source-ready retained constructor child.
- Final disposition: keep the exact range `0x005b4b70-0x005b4bb0`, keep `CANONICAL_OWNER:000043`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:000043`, leave `EMITTER_POSITION_OPTIONAL` blank, raise to `COMPLETION:88` / `CONFIDENCE:90`, and insert formal first-draft constructor C++.
- Required action: replace the old Item Summary and old `95+` no-code language with current Rule 26 code-entry language, current MCP evidence, source-placement reasoning, prompt-id evidence, negative route evidence, and the formal `RECONSTRUCTION_CPP CODE` block below.
- Confidence: high for source-ready constructor semantics; still not final-audit because the raw start has no direct call/xref/pointer route and the original prompt constant spelling is not recovered.

## Target

- Assignment id: `B007-report-0001MH-drop-gold-input-pane-raw-constructor-20260625`.
- Target UID: `0001MH`.
- Target path: `by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md`.
- Queue source: `auto-generated/-ag-research-tracker.md` by-memory not-covered reconstructable row.
- Current source header: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:000043`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000043`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Current stale Item Summary: raw numeric-prompt constructor bytes with prompt id `7`, NumberInputPane base construction, vtable stores, inline construction xrefs from DropInputPane, no direct start xref documented, and "C++ blank under the 95+ gate."
- Current generated/manual state is stale: `by-memory/-coverage-report.md` still renders [UID:0001MH] as `74% : strong`, and `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` refreshed at command id `000000000965` / `2026-06-25T02:25:13-04:00` still shows [UID:0001MH] as an empty emitter marker at `74/84`.

## Current Target State

The target already records the core constructor facts but still treats old policy as a no-code blocker. It documents a complete `0x40` / 64-byte raw body, no modeled IDA function at `0x005b4b70`, prompt id `7`, `g_pLanguageMan` / `dword_67A750`, `NumberInputPane` construction through `0x004f27a0`, and DropGold vtable stores at `0x005b4b8f`, `0x005b4b97`, and `0x005b4ba1`. It also documents the live inline construction mirror in [UID:000044] `DropInputPane::OnSubmit` at `0x005b4a9a-0x005b4abf`.

The stale part is the conclusion. Under current `by-structure.md`, formal C++ is allowed when the item is reconstructable, has a confirmed nonblank emitter route, and `(COMPLETION + CONFIDENCE) / 2 > 85`. [UID:0001MH] already clears the numeric and route gate through [UID:000043] `DropGoldInputPane`, which itself routes to [UID:0000KC] `ItemActionInputPanes`. The old `95+` gate is only a final-audit scoring rule now; it is not a required threshold for first-draft constructor C++.

## Evidence Checked

### Current IDA MCP Provenance

- Endpoint: `http://127.0.0.1:13337/mcp`.
- JSON-RPC session header: `Mcp-Session-Id: 6ee26df3-3787-4c0d-8760-144b98f246d5`.
- Active database from `idb_list`: session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, created `2026-06-24T06:15:52.461765`, last accessed during this pass `2026-06-25T02:28:06.348932`, `is_analyzing:false`, backend `worker`, pid/worker_pid `26892`.
- `server_health` call id `4`: status `ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.
- Tool schema rechecked in this pass: `lookup_funcs`, `xrefs_to`, `find_bytes`, `get_bytes`, `callees`, `analyze_function`, `decompile`, `disasm`, and `int_convert` all require `database:'80de0a67'` under the current server.

### MCP Function And Raw-Start Checks

- `lookup_funcs` call id `5`:
  - `0x005b4b70`: `fn:null`, `error:"Not a function"`.
  - `0x005b4bb0`: `sub_5B4BB0`, size `0x9a`.
  - `0x005b4920`: `sub_5B4920`, size `0x1c4`.
  - `0x004f0350`: `sub_4F0350`, size `0x22`.
  - `0x004f27a0`: `sub_4F27A0`, size `0x73`.
  - `0x005b4b6c`: `Not a function`.
  - `0x005b4c50`: `Not a function`.
- `decompile 0x005b4b70` call id `17`: `code:null`, `error:"Decompilation failed at 0x5b4b70"`.
- `disasm 0x005b4b70` call id `18`: reports `name:"<no function>"` but decodes the raw body as a normal thiscall constructor-shaped sequence:
  - `0x005b4b70`: prologue.
  - `0x005b4b75`: `esi = ecx` / saved `this`.
  - `0x005b4b77`: loads `dword_67A750` / [UID:0000RC] `g_pLanguageMan`.
  - `0x005b4b7d`: `push 7`.
  - `0x005b4b82`: calls `sub_4F0350`.
  - `0x005b4b8a`: calls `sub_4F27A0`.
  - `0x005b4b8f`: stores `??_7DropGoldInputPane@@6B@` / `0x0062fea4` to `this+0`.
  - `0x005b4b97`: stores `??_7DropGoldInputPane@@6B@_0` / `0x0062fef4` to `this+0xa0`.
  - `0x005b4ba1`: stores `??_7DropGoldInputPane@@6B@_1` / `0x0062ff24` to `this+0xa4`.
  - `0x005b4baf`: `retn`.

### MCP Bytes, Xrefs, And Pointer Searches

- `get_bytes` call id `14`:
  - `0x005b4b6c` size `4`: `0xcc 0xcc 0xcc 0xcc`.
  - `0x005b4b70` size `64`: `0x55 0x8b 0xec 0x51 0x56 0x8b 0xf1 0x8b 0xd 0x50 0xa7 0x67 0x0 0x6a 0x7 0x89 0x75 0xfc 0xe8 0xc9 0xb7 0xf3 0xff 0x50 0x8b 0xce 0xe8 0x11 0xdc 0xf3 0xff 0xc7 0x6 0xa4 0xfe 0x62 0x0 0x8b 0xc6 0xc7 0x86 0xa0 0x0 0x0 0x0 0xf4 0xfe 0x62 0x0 0xc7 0x86 0xa4 0x0 0x0 0x0 0x24 0xff 0x62 0x0 0x5e 0x8b 0xe5 0x5d 0xc3`.
  - `0x005b4bb0` size `16`: starts with `0x55 0x8b 0xec 0x81 0xec ...`, confirming the successor modeled submit function begins exactly at the exclusive end.
- `xrefs_to` call id `12`:
  - `0x005b4b70`: zero xrefs, message `No cross-references to this address`.
  - `0x0062fea4`: refs at `0x005b4aaf` in `sub_5B4920` and `0x005b4b8f` with no function owner.
  - `0x0062fef4`: refs at `0x005b4ab5` in `sub_5B4920` and `0x005b4b97` with no function owner.
  - `0x0062ff24`: refs at `0x005b4abf` in `sub_5B4920` and `0x005b4ba1` with no function owner.
  - `0x004f27a0`: refs at `0x005b4aaa` in `sub_5B4920`, `0x005b4b8a` in the raw DropGold constructor, `0x005b51f3` in the GiveInputPane gold branch, and `0x005b52ca` in the raw GiveGold constructor.
- `find_bytes` call id `13`:
  - Raw VA pointer pattern `70 4B 5B 00`: zero matches.
  - Raw RVA pointer pattern `70 4B 1B 00`: zero matches.
  - `0x0062fea4` pattern `A4 FE 62 00`: two matches at `0x005b4ab1` and `0x005b4b91`.
  - `0x0062fef4` pattern `F4 FE 62 00`: two matches at `0x005b4abb` and `0x005b4b9d`.
  - `0x0062ff24` pattern `24 FF 62 00`: two matches at `0x005b4ac5` and `0x005b4ba7`.

### MCP Inline Mirror And Base Constructor Facts

- `analyze_function 0x005b4920` call id `10` confirms the live [UID:000044] `DropInputPane::OnSubmit` gold branch:
  - It accepts the gold shortcut characters backslash `0x5c`, slash `0x2f`, or dollar `0x24`.
  - It allocates `0x108` bytes at `0x005b4a7a-0x005b4a7f`.
  - It loads `dword_67A750`, pushes `7`, calls `sub_4F0350`, passes the result into `sub_4F27A0`, and then stores the same DropGold vtables at `0x005b4aaf`, `0x005b4ab5`, and `0x005b4abf`.
  - Callees include `sub_4F0350`, `sub_4F27A0`, `sub_4F4AA0`, and the non-gold packet/callback helpers. This proves the live source route constructs a `DropGoldInputPane` inline even though it does not call the raw start.
- `decompile 0x004f27a0` call id `11` confirms [UID:00009L] `NumberInputPane` constructor behavior:
  - Calls `sub_4F1C00((int)this, a2)` / LineInputPane construction.
  - Installs NumberInputPane primary/secondary/tertiary vtables.
  - Calls `sub_544EA0(v3, 0)` on the edit child, matching reusable numeric-input base behavior.
- `callees` call id `15`:
  - `0x005b4920` includes `sub_4F0350`, `sub_4F27A0`, and allocator `sub_4F4AA0`.
  - `0x005b4bb0` has packet-submit callees only (`sub_4F2300`, `sub_4944F0`, `sub_575380`, `sub_5753F0`, `sub_574BB0`, security cookie), proving the successor submit method is separate from the constructor.
  - `0x004f27a0` calls only `sub_4F1C00` and `sub_544EA0`.

### Prompt Id And Resource Evidence

- Current target and support docs already record prompt id `7`.
- Read-only extraction of `STR.RES` from the documented `baram.dat` location in [UID:0001RP] `str-res-localized-strings` used path `E:\2026\Resources\Read_Only\NexusTK\Data\baram.dat`, offset `11268984`, size `7058`.
- The first current decoded records include:
  - id `6`: `What do you wish to drop, and no longer own? [%s\?] `
  - id `7`: `How much do you want to drop, and no longer own?`
  - id `8`: `Drop all what? [%s?]`
- This supersedes the older B001 class report's statement that no decoded text for id `7` was found in checked docs. It does not mean the constructor should hard-code the English text. The source call still goes through `g_pLanguageMan`; a future resource enum could name this id, but no original enum spelling is recovered.

### Supplemental PE Scan

Read-only PE scan of `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` was used only as negative route evidence:

- Parsed `.text` section: VA `0x1000`, virtual size `0x20b4ac`, raw pointer `0x400`, raw size `0x20b600`.
- Target VA `0x005b4b70`, target RVA `0x1b4b70`, target file offset `0x1b3f70`.
- Whole-file VA pattern `70 4b 5b 00`: zero hits.
- Whole-file RVA pattern `70 4b 1b 00`: zero hits.
- `.text` rel32 `E8`/`E9` call/jump scan to `0x005b4b70`: zero hits.

### Number Conversions

Conversions used in this report were checked with MCP `int_convert` call id `19` and local `tools/int_convert.py` for explicit wider byte widths:

- `7` / `0x7` (Verified with int_convert.py/MCP `int_convert`).
- `0x40` / 64 (Verified with int_convert.py/MCP `int_convert`).
- `0x108` / 264 (Verified with int_convert.py/MCP `int_convert`).
- `0xa0` / 160 (Verified with int_convert.py).
- `0xa4` / 164 (Verified with int_convert.py).
- `0x04` / 4, `0x0c` / 12, `0x06` / 6, `0x69` / 105, `0x9a` / 154, and `0x1c4` / 452 (Verified with int_convert.py).

## Positive Evidence Summary

- The raw bytes are a complete `thiscall` constructor-shaped body: save `this`, get localized string id `7`, call the `NumberInputPane` constructor, store three derived-class vtables, return `this`.
- The same object construction is live through `DropInputPane::OnSubmit`: allocate `0x108` bytes, call the same lookup and base constructor, store the same three vtables.
- Vtable xrefs are exactly the two expected sites per table in the current MCP pass: live inline mirror and raw retained constructor.
- The direct parent [UID:000043] `DropGoldInputPane` is already `87/88`, reconstructable, and routed to [UID:0000KC] `ItemActionInputPanes`, so the emitter path is not a dead end.
- [UID:00040P] `LanguageMan::GetLocalizedString` has formal first-draft C++ and source-facing naming already documented; [UID:00009L] `NumberInputPane` documents the base constructor and consumers.
- Current Rule 26 / `by-structure.md` code-entry gate is met before the recommended score change and is stronger after `88/90`.

## Negative / Counter-Evidence Summary

- There is still no IDA function object at `0x005b4b70`.
- `decompile 0x005b4b70` still fails.
- `xrefs_to 0x005b4b70` returns zero direct refs.
- MCP `find_bytes` finds no VA or RVA pointer pattern to the raw start.
- Supplemental PE scanning finds no VA pointer, RVA pointer, or rel32 call/jump route to the raw start.
- The live `DropInputPane::OnSubmit` branch inlines the constructor work rather than calling `0x005b4b70`.
- These are real confidence caps. They are not a no-code proof because the exact source-level constructor operation is fully represented and the equivalent live inline construction proves class reality.

## Heuristic / Inference Reanalysis And Validation

### Raw / No-Function / No-Route Blocker

Best decision: keep the binary label as a retained raw constructor-shaped body, but no longer treat no-route as a formal C++ blocker. This matches the accepted current policy for [UID:0001M0] `TakeOffInputPaneRawConstructor` and [UID:0001M5] `ChangeItemSlotInputPaneRawConstructor`: exact raw constructor bytes plus live inline construction mirrors support first-draft source constructor C++, while no direct raw-start route remains a score limiter.

Rejected alternatives:

- Active direct call target: rejected by zero xrefs, zero pointer hits, and zero rel32 route hits.
- Dead padding/fill: rejected by normal constructor prologue/epilogue, calls, vtable stores, and exact live mirror.
- `NumberInputPane`-owned code: rejected because `NumberInputPane` is the base dependency; the installed vtables are DropGold-specific.
- `DropInputPane`-owned method body: rejected because DropInputPane creates the prompt, but the constructor initializes a distinct `DropGoldInputPane` class with its own vtables and submit slot.
- File-root ownership bypassing the class: rejected because by-structure wants the narrowest semantic owner, and [UID:000043] clears the gate.
- Manual vptr stores in source C++: rejected as compiler output from the derived class declaration.

### Prompt Id 7

Best decision: document id `7` as the DropGold amount prompt id and include the current resource text as evidence, but keep the formal constructor source as a localization lookup. The source-facing code should not hard-code `How much do you want to drop, and no longer own?`; the binary calls the language table.

Naming decision: use numeric `7` in the formal target C++ rather than inventing a new file-level constant in this by-memory range. A descriptive constant such as `kPromptDropGoldAmount` remains a support-doc note only until a broader language-resource enum/source convention is recovered. `GetLocalizedString` is the best source-facing method name here because [UID:00040P] owns that exact first-draft method name and [UID:0001M0] already uses `g_pLanguageMan->GetLocalizedString(...)` for the analogous accepted constructor C++.

### Source Placement

Best decision: direct owner remains [UID:000043] `DropGoldInputPane`; output route remains through [UID:000043] to [UID:0000KC] `ItemActionInputPanes`, generating under `NexusTK/ui/dialogs/ItemActionInputPanes.cpp` after validator refresh. This is a compact item-action input pane, not a reusable input-pane base, socket/global packet sender, or resource-owner item.

### Boundary / Split

Best decision: preserve the exact half-open range `0x005b4b70-0x005b4bb0`. The predecessor [UID:0003FL] `SendDropItemPacketRaw` ends at `0x005b4b6c`, `0x005b4b6c-0x005b4b70` is four bytes of `0xcc` padding, this constructor is exactly `0x40` bytes, and the successor modeled submit method starts at `0x005b4bb0`. Do not merge successor `0x005b4bb0-0x005b4c4a`, helper `0x005b4c50-0x005b4cb9`, or padding into this page.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Remaining uncertainty |
| --- | --- | --- | --- | --- |
| `0x005b4b70-0x005b4bb0` is `DropGoldInputPane::DropGoldInputPane()` source logic. | High | Raw constructor disassembly, prompt id `7`, `NumberInputPane` call, DropGold vtables, inline mirror in `DropInputPane::OnSubmit`. | No IDA function, no xref/pointer/rel32 route; rejected padding/base-owner/file-owner alternatives. | Original object file kept an out-of-line copy, but observed live route uses inline construction. |
| Formal first-draft constructor C++ is justified. | High | Current code gate is met, exact behavior maps to one base initializer, vptr stores are compiler output, accepted sibling raw-constructor precedent. | No direct raw-start route and no original prompt constant spelling. | Final prompt enum/name convention can improve later without changing behavior. |
| Use `g_pLanguageMan->GetLocalizedString(7)` in formal C++. | Medium-high | Exact callee [UID:00040P] uses `GetLocalizedString`; TakeOff accepted sibling uses that method spelling; raw call passes `7`. | Some sibling docs/examples use `GetString(...)`; no original header survives. | Naming alias only; if project standardizes `GetString`, implementation can adjust by supervisor policy. |
| Prompt id `7` is the drop-gold amount prompt. | High | Raw constructor and live mirror both pass `7`; STR.RES extraction shows id `7` text is the drop amount prompt. | No recovered original enum name. | Localized text may vary by distribution; source should remain id lookup. |
| Owner/emitter should remain [UID:000043]. | High | Class vtables, class page score/route, source placement in ItemActionInputPanes. | `DropInputPane` creator relationship and `NumberInputPane` base relationship are not ownership. | None material for this target. |

## Ranked Ownership And Source Placement

### 1. [UID:000043] DropGoldInputPane - accepted

Evidence for:

- The raw constructor installs DropGold vtables `0x0062fea4`, `0x0062fef4`, and `0x0062ff24`.
- The live inline branch creates a DropGold object and installs the same vtables.
- The successor submit slot at `0x005b4bb0` is DropGold-specific.
- [UID:000043] is `87/88` and routes to [UID:0000KC].

Evidence against:

- The raw start has no direct call route. This affects reachability confidence, not class ownership.

Decision: keep `CANONICAL_OWNER:000043` and `EMITTER_UIDS:000043`.

### 2. [UID:0000KC] ItemActionInputPanes - route only

Evidence for:

- File page groups DropInputPane, DropGoldInputPane, GiveGoldInputPane, TakeOffInputPane, ChangeItemSlotInputPane, and sibling item-action prompts.
- Generated source root is `NexusTK/ui/dialogs/ItemActionInputPanes.cpp`.

Evidence against:

- By-structure asks for the narrowest direct semantic owner. This range is a class constructor, not a file-level free helper.

Decision: use [UID:0000KC] only as the surfaced file route through [UID:000043], not as the direct owner.

### 3. [UID:000044] DropInputPane - rejected as owner

Evidence for:

- `DropInputPane::OnSubmit` is the live creator/inline mirror.

Evidence against:

- Creator/caller relationship does not own the created class. The raw constructor and vtables identify `DropGoldInputPane`.

Decision: support-doc route evidence only.

### 4. [UID:00009L] NumberInputPane - rejected as owner

Evidence for:

- The constructor calls `NumberInputPane` as the base.

Evidence against:

- The raw body overwrites base vtables with DropGold vtables and belongs to the derived prompt class.

Decision: dependency documentation only.

### 5. Resource/global/socket pages - rejected as owners

`g_pLanguageMan`, `STR.RES`, `g_packetSender`, and `g_pCollectionData` are dependencies or submit-path context. They do not own this constructor.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. [UID:0001MH] is reconstructable, has nonblank `EMITTER_UIDS:000043`, the route surfaces through [UID:0000KC], and its combined current score is already above `85`.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
DropGoldInputPane::DropGoldInputPane()
    : NumberInputPane(g_pLanguageMan->GetLocalizedString(7))
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason this preserves exact behavior:

- The raw constructor's only source-authored semantic operation is the `NumberInputPane` base construction with the localized prompt pointer returned from `g_pLanguageMan->GetLocalizedString(7)`.
- The derived vtable stores are compiler output from `DropGoldInputPane` construction and should not be written as source statements.
- `NumberInputPane` construction handles the reusable numeric-input base behavior; this derived constructor does not initialize additional source fields.
- The source block covers only the target's `0x005b4b70-0x005b4bb0` constructor operation and does not emit successor submit/helper code.

Reason it matches plausible original source:

- Thin input-pane constructors in this neighborhood are simple base-initializer constructors.
- It avoids IDA labels (`sub_`, `dword_`, vtable symbols) in final source.
- It uses the already documented `LanguageMan::GetLocalizedString` source-facing method rather than a raw helper label.
- It uses numeric id `7` rather than inventing an undeclared enum in a by-memory constructor range.

## Score And Metadata Recommendation

Current target metadata:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:000043`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000043`
- blank `EMITTER_POSITION_OPTIONAL`
- blank formal C++

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- Preserve `CANONICAL_OWNER:000043`
- Preserve `RECONSTRUCTABLE:TRUE`
- Preserve `EMITTER_UIDS:000043`
- Preserve blank `EMITTER_POSITION_OPTIONAL`
- Insert the formal constructor C++ block above.

Rationale:

- Completion rises because this pass resolves the stale first-draft C++ blocker, records current MCP provenance, confirms raw bytes, prompt id/resource text, route-negative evidence, source placement, and exact support dependencies.
- Confidence rises because the raw body and live inline mirror now jointly support source-ready constructor C++ under the accepted raw-constructor sibling policy.
- Scores remain below `95` because no direct raw-start route exists, IDA still has no function object, `decompile 0x005b4b70` still fails, and original prompt constant/source enum spelling remains unrecovered.

## Recommended Target Doc Changes

Target path: `by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md`.

Required target edits if accepted:

- Set `COMPLETION:88`, `CONFIDENCE:90`.
- Preserve `CANONICAL_OWNER:000043`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000043`, and blank `EMITTER_POSITION_OPTIONAL`.
- Replace the stale Item Summary with concise source-quality text. Recommended:
  - `Source-ready retained DropGoldInputPane constructor; exact raw bytes, prompt id 7, NumberInputPane base construction, compiler vptr stores, inline DropInputPane construction mirror, and no direct raw-start route are documented, with formal first-draft C++ present.`
- Insert the exact formal `RECONSTRUCTION_CPP CODE` block from this report.
- Replace old `95+` no-code wording with current code-entry gate language: no-function/no-route evidence remains a confidence cap, not a no-code proof.
- Add current MCP provenance at report-level detail: JSON-RPC session `6ee26df3-3787-4c0d-8760-144b98f246d5`, active IDB `80de0a67`, health status, lookup/decompile/disasm/bytes/xrefs/find_bytes/callees/analyze results.
- Add supplemental PE scan facts: `.text` mapping, target file offset `0x1b3f70`, zero VA/RVA pointer hits, zero rel32 call/jump hits.
- Add STR.RES prompt id `7` evidence from `baram.dat`; state the constructor still calls the language table and should not hard-code the current English text.
- Preserve rejected alternatives: not padding, not `NumberInputPane` owned, not `DropInputPane` owned, not direct active call target, not manual vptr source code, not source owned by globals/resources/socket.
- Preserve exact boundaries and padding: predecessor padding `0x005b4b6c-0x005b4b70`, exact target `0x005b4b70-0x005b4bb0`, successor submit at `0x005b4bb0`; do not create or merge padding.

## Recommended Support Doc Changes

### `by-class/DropGoldInputPane.md`

- Add/update notes that child [UID:0001MH] now has formal first-draft constructor C++.
- Preserve class-level C++ blank by design: class declaration, submit method child split, and adjacent helper policy remain separate decisions.
- Replace any implication that the constructor child remains blank solely because of the old `95+` gate.
- Add the current prompt id `7` resource-text evidence as support, while retaining the rule that source uses `g_pLanguageMan` lookup rather than an English literal.

### `by-file/ItemActionInputPanes.md`

- Update the `DropGoldInputPane` row so the raw constructor child [UID:0001MH] is described as formal first-draft constructor C++ emitted through `NexusTK/ui/dialogs/ItemActionInputPanes.cpp` after validator refresh.
- Add a boundary/source-quality note parallel to [UID:0001M0] and [UID:0001M5]: no-function/no-route remains a raw-body caveat, but it no longer blocks first-draft constructor C++.
- Preserve that the submit method and retained packet helper remain separate ranges; this report does not emit `0x005b4bb0-0x005b4c4a` or [UID:0003FM].

### `by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md`

- Fix the stale Item Summary sentence saying the aggregate child remains `78/82` and should attach only after clearing `85/85`; the page header is already `86/88` and attached.
- Add/update the B001 DropGold notes to say [UID:0001MH] now carries formal first-draft constructor C++.
- Replace aggregate `95/95` emission wording with current reasoning: aggregate C++ stays blank because it mixes multiple exact children, modeled methods, helpers, and padding; exact children own formal code when eligible.

### `by-class/DropInputPane.md`

- Update support wording for the live gold branch: `0x005b4a9a-0x005b4abf` is now not only a retained/no-route mirror but also the source-shape proof supporting formal [UID:0001MH] constructor C++.
- Replace the status note "leave C++ blank until final helper/member names are 95/95" with current language: class-level C++ can remain blank for broader method/class declaration reasons, but the DropGold constructor child has first-draft code.

### `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`

- Update the DropGold raw-constructor paragraph so [UID:0001MH] matches the newer TakeOff/ChangeItemSlot policy: first-draft constructor C++ is now accepted for the exact child, while no-function/no-route remains an IDA anchor caveat.
- Keep the vtable page's own formal C++ blank because vtables are compiler-generated from class declarations; do not emit data-table C++ here for this callback.

### Check-only support docs

- `by-class/NumberInputPane.md`: no target-specific edit required. It already documents [UID:0001MH] as a consumer and the `0x004f27a0` base constructor. Its class-level stale `95/95` wording is a separate NumberInputPane declaration pass, not a contradiction to this DropGold child.
- `by-memory/0x004f27a0-0x004f2813.NumberInputPaneConstructor.md`: no edit required for this target; it already documents the base constructor behavior used here.
- `by-global/g_pLanguageMan.md` and `by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md`: no edit required; they already document the singleton and formal `GetLocalizedString` source-facing method. The target can cite them.
- `by-global/g_packetSender.md` and packet helper pages: no constructor-route edit required. These are relevant to DropGold submit/helper pages, not to [UID:0001MH]'s constructor source block.

## Exact Supervisor-Owned Coverage Text

The manual row in `by-memory/-coverage-report.md` is stale and B agents must not edit it directly during report-only or ordinary implementation callback. If the supervisor still wants manual coverage synchronized outside validator-owned generated coverage, replace the [UID:0001MH] row with:

```markdown
    - [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md) 0x005b4b70-0x005b4bb0 | raw constructor | DropGoldInputPaneRawConstructor : reconstructable : 88% : very-strong : Source-ready retained DropGoldInputPane constructor; current MCP session `80de0a67` confirms exact `0x40` bytes, no IDA function/decompile/xref route, prompt id `7` / current STR.RES text `How much do you want to drop, and no longer own?`, `NumberInputPane` base construction, compiler-emitted vptr stores at `+0/+0xa0/+0xa4`, `DropInputPane::OnSubmit` inline mirror, zero VA/RVA pointer hits, and zero PE rel32 call/jump hits; formal first-draft constructor C++ is ready while no-route and prompt constant spelling remain confidence caps.
```

Do not write any row text for `auto-generated/-ag-coverage-report-by-memory.md`; it should refresh from the target metadata and Item Summary after the scoped target validator runs with `--wait-generated`.

## Expected Validators After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after accepted by-* edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001MH-DropGoldInputPaneRawConstructor-source-quality-removed.md](0001MH-DropGoldInputPaneRawConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Also run scoped validators for each edited support doc:

> Executable block R002 was removed from this report and preserved verbatim in [0001MH-DropGoldInputPaneRawConstructor-source-quality-removed.md](0001MH-DropGoldInputPaneRawConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If implementation chooses not to edit one of those support docs because the accepted callback narrows scope, do not run that support validator.

## Open Questions With Attempted Resolution

- Direct route to `0x005b4b70`: unresolved after MCP xrefs, MCP pointer scans, MCP decompile failure, MCP raw disassembly, and supplemental PE VA/RVA/rel32 scans. This remains a confidence cap only. It does not block formal constructor C++ because the source-level operation is exact and the live inline mirror proves the same construction semantics.
- Original prompt constant spelling: unresolved. Current STR.RES maps id `7` to the drop-gold amount prompt, but no original source enum/name survives. Use numeric `7` in formal C++ and keep descriptive constants only in prose.
- `GetLocalizedString` versus `GetString`: current [UID:00040P] and [UID:0001M0] support `GetLocalizedString`; some sibling constructor docs use `GetString`. This is a naming convention issue, not a behavior issue. For this target, `GetLocalizedString(7)` is the best supported source-facing method because it matches the exact LanguageMan child and the current assignment wording.
- Submit method C++: out of scope for this target. `0x005b4bb0-0x005b4c4a` remains successor method code and should receive its own exact child before formal submit C++.
- Retained packet helper C++: out of scope for this target. [UID:0003FM] remains the file-scope packet helper page.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B007/research/0001MH-DropGoldInputPaneRawConstructor-source-quality.md`.
- Modified target/support docs: none in this report-only pass.
- Generated/project-level/coverage/tool/IDA files: none edited.
- Leases: none taken.
- Validators: none run, because this is report-only research and no by-* docs were edited.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted the report for implementation, then issued a corrective implementation callback for the stale Item Summary and proof gap.
- [x] Target [UID:0001MH] `by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md`: set `COMPLETION:88`, `CONFIDENCE:90`, preserve `CANONICAL_OWNER:000043`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000043`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Target Item Summary: replaced stale blank-`95+` text with the supervisor-required source-ready constructor summary.
- [x] Target formal C++: inserted the exact `DropGoldInputPane::DropGoldInputPane() : NumberInputPane(g_pLanguageMan->GetLocalizedString(7)) {}` formal block from this report; no body-only snippet or side example was added.
- [x] Target evidence: incorporated MCP session `6ee26df3-3787-4c0d-8760-144b98f246d5`, active IDB `80de0a67`, health, lookup/decompile/disasm/bytes/xrefs/find_bytes/callees/analyze facts, STR.RES prompt id `7`, supplemental PE negative route scan, and stale generated/manual coverage state.
- [x] Target stale assumptions: replaced old `95+` C++ gate and "support-owned names block C++" wording with current code-entry rule and target-specific source-ready rationale.
- [x] Target negative evidence: preserved no IDA function, decompile failure, zero direct xrefs, zero VA/RVA pointer hits, zero PE rel32 hits, and no direct raw-start call route as confidence caps.
- [x] Target rejected alternatives: preserved not padding, not `NumberInputPane` owned, not `DropInputPane` owned, not file-root-owned bypassing class owner, not active direct-call proof, and not manual vptr source statements.
- [x] Target range/split: preserved exact `0x005b4b70-0x005b4bb0`; did not merge predecessor padding, successor `0x005b4bb0`, or helper `0x005b4c50`.
- [x] Support `by-class/DropGoldInputPane.md`: updated child [UID:0001MH] as formal first-draft constructor C++; kept class-level C++ blank for declaration/submit/helper reasons; added current prompt id resource evidence and current no-route-as-cap wording.
- [x] Support `by-file/ItemActionInputPanes.md`: updated DropGold row/boundary notes so [UID:0001MH] emits first-draft constructor C++ through `NexusTK/ui/dialogs/ItemActionInputPanes.cpp`, parallel to accepted retained raw-constructor policy.
- [x] Support `by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md`: fixed stale attachment/C++ policy; updated DropGold notes for [UID:0001MH] formal constructor C++; kept aggregate C++ blank for mixed child/range reasons, not the old `95/95` gate.
- [x] Support `by-class/DropInputPane.md`: updated inline mirror note to say it now supports formal [UID:0001MH] first-draft constructor C++; replaced class-level old `95/95` wording with current class-level blank-C++ rationale.
- [x] Support `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`: updated DropGold paragraph to match retained raw-constructor policy; kept vtable page non-emitting because vtables are compiler-generated.
- [x] Check-only support docs: confirmed no edit required for `by-class/NumberInputPane.md`, `by-memory/0x004f27a0-0x004f2813.NumberInputPaneConstructor.md`, `by-global/g_pLanguageMan.md`, `by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md`, `by-global/g_packetSender.md`, and packet helper docs.
- [x] Manual coverage: supervisor-owned `by-memory/-coverage-report.md` row replacement text was supplied in this report; B007 did not edit `by-memory/-coverage-report.md` or any other `-coverage-report.md`.
- [x] Validators after implementation: target and support validators were run; command ids, timestamps, exit codes, ok counts, and generated-refresh state are recorded below.
- [x] Generated/header verification after implementation: target header stayed corrected after the uid-only/no-generated validator; read-only generated check confirms `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` still contains the `DropGoldInputPane::DropGoldInputPane()` block.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail or marked already present/excluded with reason.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions documented with score/C++ impact.
- [x] Validators run and results recorded.
- [x] Leases released and final `current_leases.md` readback confirmed no active leases.
- [x] Remaining unapplied accepted items: none for the accepted B007 by-* implementation scope. Supervisor-owned coverage update was intentionally not edited by B007.

## Implementation Callback Checkpoint - 2026-06-25

Superseded status: `PAUSED_VALIDATOR_METADATA_CONFLICT`.

Implementation edits were started under B007's accepted callback. The target/support docs were updated with the accepted first-draft constructor policy and support evidence, then the target validator was run first:

> Executable block R003 was removed from this report and preserved verbatim in [0001MH-DropGoldInputPaneRawConstructor-source-quality-removed.md](0001MH-DropGoldInputPaneRawConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Validator result:

- `command_id: 000000001086`
- `command_timestamp: 2026-06-25T03:51:03-04:00`
- exit code `0`
- `ok: 1`
- generated refresh completed under the same command id/timestamp.

Conflict proof after validator `000000001086`:

- Target [UID:0001MH] still has `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter [UID:000043], and formal `DropGoldInputPane::DropGoldInputPane()` C++.
- `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` refreshed with `validator-command-id: 000000001086` and contains the constructor C++.
- The target `Item Summary` was rewritten back to stale text ending with `C++ blank under the 95+ gate.`

Per supervisor callback, B007 stopped immediately after the stale-summary rewrite. Support validators were not run after this stop condition, the implementation checklist remains unchecked/incomplete, and the report must not be executed until the supervisor resolves the stale metadata/header source and the implementation is resumed or revalidated.

Lease cleanup:

- B007 attempted to release all accepted target/support/report paths after the stop condition.
- `leaser.py` returned `Rejected[No active lease]` for each B007 path.
- Shared `current_leases.md` contained no active B007 lease after cleanup.

## Corrective Implementation Completion - 2026-06-25

Status: `FINISHED_IMPLEMENTATION`.

Supervisor correction was resumed on the same implementation. B007 leased the target/support by-* files immediately before the corrective edit/validator batch, corrected the target Item Summary, ran the required uid-only/no-generated target validator, ran scoped no-generated support validators, re-read the target header after validation, confirmed generated output by read-only check, and released the by-* leases immediately after the edit/validator batch. No generated report, project-level report, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or other `-coverage-report.md` file was manually edited by B007.

Corrected target Item Summary now reads exactly:

```text
Source-ready retained DropGoldInputPane constructor; exact raw bytes, prompt id 7, NumberInputPane base construction, compiler vptr stores, inline DropInputPane construction mirror, and no direct raw-start route are documented, with formal first-draft C++ present.
```

Corrective target validator:

> Executable block R004 was removed from this report and preserved verbatim in [0001MH-DropGoldInputPaneRawConstructor-source-quality-removed.md](0001MH-DropGoldInputPaneRawConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- `command_id: 000000001173`
- `command_timestamp: 2026-06-25T04:00:51-04:00`
- exit code `0`
- `ok: 1`
- generated refresh: skipped by `--no-generated-refresh`
- generated refresh command id/timestamp: `000000001173` / `2026-06-25T04:00:51-04:00`

Final target header readback after validator `000000001173`:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:000043`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000043`
- formal C++ present:

```cpp
DropGoldInputPane::DropGoldInputPane()
    : NumberInputPane(g_pLanguageMan->GetLocalizedString(7))
{
}
```

- Item Summary stayed corrected and no longer contains `C++ blank under the 95+ gate`.

Support validators:

| File | Command id | Timestamp | Exit | ok | Generated refresh |
| --- | --- | --- | --- | --- | --- |
| `by-class\DropGoldInputPane.md` | `000000001174` | `2026-06-25T04:01:16-04:00` | `0` | `1` | skipped by `--no-generated-refresh` |
| `by-file\ItemActionInputPanes.md` | `000000001175` | `2026-06-25T04:01:18-04:00` | `0` | `1` | skipped by `--no-generated-refresh` |
| `by-memory\0x005b44b0-0x005b538a.DropGiveInputPanes.md` | `000000001176` | `2026-06-25T04:01:19-04:00` | `0` | `1` | skipped by `--no-generated-refresh` |
| `by-class\DropInputPane.md` | `000000001177` | `2026-06-25T04:01:21-04:00` | `0` | `1` | skipped by `--no-generated-refresh` |
| `by-type\by-vtable\ItemActionInputPaneVtableFamily.md` | `000000001178` | `2026-06-25T04:01:22-04:00` | `0` | `1` | skipped by `--no-generated-refresh` |

Read-only support/generated proof:

- `by-class/DropGoldInputPane.md` documents [UID:0001MH] as a formal first-draft `DropGoldInputPane::DropGoldInputPane()` child, preserves the no-route caveat as a confidence cap, and keeps class-level C++ blank for declaration/submit/helper ownership reasons.
- `by-file/ItemActionInputPanes.md` records [UID:0001MH] as first-draft populated through `NexusTK/ui/dialogs/ItemActionInputPanes.cpp`, with no-function/no-start-xref and separate submit-method child caveats preserved.
- `by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md` records the exact child carrying formal constructor C++ while the mixed aggregate remains blank-C++.
- `by-class/DropInputPane.md` records the inline gold branch as source-shape proof for [UID:0001MH]'s formal constructor C++ without treating it as a direct-call route.
- `by-type/by-vtable/ItemActionInputPaneVtableFamily.md` records the three DropGold vtable stores and retained raw-constructor policy while leaving the vtable page non-emitting.
- `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` was read only; current header shows `validator-command-id: 000000001159` and the file contains:

```cpp
// UID:0001MH | by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md | Completion:88 | Confidence:90
DropGoldInputPane::DropGoldInputPane()
    : NumberInputPane(g_pLanguageMan->GetLocalizedString(7))
{
}
```

Lease release proof:

- B007 released `by-memory\0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md`, `by-class\DropGoldInputPane.md`, `by-file\ItemActionInputPanes.md`, `by-memory\0x005b44b0-0x005b538a.DropGiveInputPanes.md`, `by-class\DropInputPane.md`, and `by-type\by-vtable\ItemActionInputPaneVtableFamily.md`; `leaser.py` returned `Success` for each path.
- Final `tools/leaser/Agents/current_leases.md` readback after release contains no active leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0001MH-DropGoldInputPaneRawConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0001MH-DropGoldInputPaneRawConstructor-source-quality.md","timestamp":"2026-06-25T04:11:41","uid":"0001MH"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001MH-DropGoldInputPaneRawConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0001MH-DropGoldInputPaneRawConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001MH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
