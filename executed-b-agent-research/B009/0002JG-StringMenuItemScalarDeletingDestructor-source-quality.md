** TARGET-REPORT-UID:0002JG **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002JG StringMenuItem Scalar Deleting Destructor Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: raise [UID:0002JG] from `84/90` to `86/92`, keep `RECONSTRUCTABLE:TRUE`, keep direct owner/emitter [UID:0000E8] `StringMenuItem`, and keep the target `RECONSTRUCTION_CPP` block blank.
- Final disposition: no split or owner reroute is needed. This exact range is an MSVC scalar deleting destructor wrapper generated from ordinary/default `StringMenuItem` destructor semantics.
- Required action: incorporate the B009 raw PE recheck, exact flag behavior, no-code proof, ordinary destructor source guidance, and coverage-row replacement text below into the target/support docs after supervisor review.
- Confidence: high for exact bytes, wrapper shape, vtable route, owner/emitter, and no-formal-C++ policy; below final-audit only because live IDA MCP was unavailable and the original source spelling could be explicit empty destructor or implicit/default destructor.

## Supporting Research

## Target

- Target UID: `0002JG`.
- Target path: `source-3/project-documentation/by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md`.
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/0002JG-StringMenuItemScalarDeletingDestructor-source-quality.md`.
- Current documented state: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000E8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000E8`, formal C++ blank.
- Current generated route: `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`; generated output contains an empty emitter marker for `0002JG`, which is correct for this wrapper.

## Executive Recommendation

[UID:0002JG] should stay a reconstructable source-declared/generated-binary wrapper, directly owned by [UID:0000E8] `StringMenuItem` with [UID:0000MN] `PopupMenuControls` as the source-file root. The target's current blank C++ block is correct, but the reason should be upgraded from stale "below old threshold" language to target-specific proof: the wrapper body is compiler ABI glue and should be regenerated from ordinary `StringMenuItem` destructor semantics.

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:92
CANONICAL_OWNER:0000E8
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000E8
RECONSTRUCTION_CPP CODE: blank
```

Source-level action, not target C++:

```cpp
class StringMenuItem : public MenuItem {
public:
    virtual ~StringMenuItem();
};

StringMenuItem::~StringMenuItem()
{
}
```

An inline/default spelling such as `virtual ~StringMenuItem() {}` or an implicit destructor remains source-plausible. The binary proves ordinary destruction semantics, not the exact original spelling.

## Supervisor Active Recheck

- The user assigned a B009 report-only source-quality pass for [UID:0002JG] and explicitly banned edits to target/support docs and `by-memory/-coverage-report.md`.
- The target is already an exact half-open function range and does not require split repair.
- This report preserves prior completed B009 reports and creates only the required B009 research report.

## Inference Research Guidance Check

- Current Rule 20 / code-entry gate is used: the item is reconstructable, has nonblank emitter [UID:0000E8], and its current average score is `(84 + 90) / 2 = 87`, already above `85`. After this report's recommended score, the average becomes `89`.
- Passing the code-entry gate does not require target C++ when target-specific source-shape evidence says the exact range is compiler-generated. The correct source expression is an ordinary destructor declaration/body in the class, not a method named `ScalarDeletingDestructor`.
- Existing docs and previous B003 reports were treated as leads. The new raw PE recheck independently validates the wrapper body, flag path, object size, vtable-only reachability, and no-code policy.
- Live IDA MCP was attempted and failed with `Unable to connect to the remote server`; this report therefore uses existing IDA-backed docs, exported function records, and fresh raw PE evidence.

## Heuristic / Inference Reanalysis And Validation

| Issue | Best defensible conclusion | Evidence checked | Rejected alternatives | Impact |
| --- | --- | --- | --- | --- |
| Exact range | Keep `0x00517400-0x00517441`. | Exported IDA/Ghidra function records report size `65`; raw PE body is `0x41` / 65 bytes (Verified with `int_convert.py`); body ends at `ret 4` at `0x0051743e`; fifteen `0xcc` bytes follow before `0x00517450`. | Extending into padding or adjacent [UID:000238] `MenuDialogFactoryHelpers`; shortening before the flag-4 path. | No split/range repair needed. |
| Compiler/generated name | Use descriptive IDA name `StringMenuItem_ScalarDeletingDestructor` or `StringMenuItem_scalar_deleting_destructor`; do not treat it as source method name. | Exported records show IDA `sub_517400`, Ghidra `~StringMenuItem`, OOAnalyzer `virt_deldtor_0x517400`; vtable slot `0x0061ebb4` points here. | Final source method `StringMenuItem::ScalarDeletingDestructor(int flags)`; keeping only `sub_517400`; treating generated `virt_deldtor` as original spelling. | IDA can be renamed descriptively, but target C++ stays blank. |
| Wrapper policy | Compiler-generated MSVC deleting-destructor wrapper from ordinary/default destructor semantics. | Raw body resets vptr, calls base destructor, branches on deleting flags, optionally calls operator delete, and returns `this`; no `StringMenuItem` fields require explicit cleanup. | Handwritten wrapper source; ignored/non-reconstructable compiler glue; source-authored helper with flag parameter. | Keep reconstructable TRUE because class declarations must regenerate vtable/destructor semantics; keep formal C++ blank. |
| Flag behavior | `flags & 1` gates delete work; if bit 4 is also set, the wrapper calls no-op helper `0x0041b6a0` with `this` and size `0x118`; otherwise it calls operator delete. | Capstone disassembly at `0x00517414-0x00517437`; target bytes include `68 18 01 00 00 56 e8 69 42 f0 ff`; `0x118` / 280 verified with `int_convert.py`. | Generic "conditionally frees"; independent flag-4 cleanup path; flag-4 frees storage; ignoring flag-4 path as Ghidra presentation noise. | Target docs should preserve exact branch order and no-op/sized-delete meaning. |
| Callee `0x004f4a90` | [UID:000370] `LObjectDestructorBody`, the non-deleting base destructor body. | Support doc confirms exact `0x004f4a90-0x004f4a97`; raw call at `0x0051740c` follows vtable reset. | Unknown `sub_4F4A90`; StringMenuItem-specific cleanup helper; MenuItem field cleanup. | Use base `LObject::~LObject()` / base cleanup wording. |
| Callee `0x004f4ac0` | [UID:000197] `OperatorDeleteWrapper`, MemoryMan-backed global delete wrapper. | Support doc confirms `GetMemoryMan` -> `FreeBufferMemory`; raw call at `0x0051741d` only occurs when `(flags & 1) != 0 && (flags & 4) == 0`. | Class-specific delete helper; label-buffer cleanup; unconditional free. | Confirms scalar-delete flag behavior. |
| Callee `0x0041b6a0` | One-byte compiler no-op / guard-check helper used by sized-delete path. | Sibling [UID:0002JF] raw recheck verified the helper is one-byte `ret`; this target pushes `0x118` and `this` before calling it. Existing docs name it `@_guard_check_icall_nop@4`. | Source-owned StringMenuItem helper; actual delete/free path; unresolved blocker. | Mention as no-op sized-delete/guard path, not project source. |
| Object size `0x118` | `StringMenuItem` object size, matching `MenuItem` base `0x18` plus inline label buffer `0x100`. | [UID:0001V5] records `StringMenuItem +0x18` as inline `wchar_t[0x80]`; `0x80` / 128 and `0x100` / 256 verified with `int_convert.py`; `0x18 + 0x100 = 0x118`. | Heap text pointer; STL/string object member; allocator padding reason unrelated to class layout. | Confirms label is inline and destructor has no label free. |
| Ordinary destructor source shape | Empty/default ordinary destructor is sufficient. | Wrapper body only restores base vtable and calls base cleanup; `m_text` is fixed inline storage; no owned heap/resource field appears. | Explicit field cleanup; `delete[] m_text`; custom scalar deleting method. | Recommended class/support source guidance, not target C++. |
| Owner/emitter | Keep direct owner/emitter [UID:0000E8] `StringMenuItem`; [UID:0000MN] remains source-file root. | Vtable slot `0x0061ebb4` points to target; constructor installs `StringMenuItem` vtable at `0x0051704e`; class page is `88/90`; file root is `86/85`. | Direct file owner only; [UID:00007V] `MenuItem`; [UID:0000CY] `SeparatorMenuItem`; [UID:00007W] `MenuPane`; [UID:000238] `MenuDialogFactoryHelpers`. | Metadata already correct; support docs should get stronger proof. |
| Vtable/caller route | Runtime reachability is through the `StringMenuItem` vtable, not direct code calls. | Raw dword search found target VA `0x00517400` only at raw `0x21d5b4` -> `.rdata:0x0061ebb4`; target RVA/raw-offset searches found no hits; `.text` rel32 scan found no direct calls/jumps. | Dead code; hidden direct helper; feature-local callback. | No direct callers is expected and not a blocker. |
| Source placement | Keep `NexusTK/ui/menu/PopupMenuControls.cpp` as source root for the menu-item family. | [UID:0000MN], [UID:0001BK], [UID:0001Y4], [UID:0001V5], and current autogen route all agree. | New standalone file for this wrapper; feature menu/dialog file; MemoryMan/LObject owner. | No new file recommended. |
| Generated-output pollution | Current generated file should continue to omit a wrapper body. | `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` contains source-authored sibling methods and an empty emitter marker for `0002JG`; `auto-generated/-ag-memory-coverage.md` shows code `no`. | Treating generated source-like `ScalarDeletingDestructor` bodies as final C++; adding wrapper code only because target passes the average gate. | This report explicitly says not to populate target formal C++. |

Remaining caveats:

- Live IDA MCP was unavailable in this session, so the report uses raw PE evidence plus existing IDA-backed docs rather than new live IDA decompilation.
- The binary does not prove whether the original source explicitly declared `StringMenuItem::~StringMenuItem()` or let the compiler synthesize it. That only caps final-audit certainty; it does not block the recommended score or no-code policy.
- `0x0041b6a0` lacks a dedicated exact by-memory page. This is a broader compiler-helper documentation gap and is not a blocker for [UID:0002JG].

## Evidence Checked

Primary and support docs:

- `by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md`
- `by-class/StringMenuItem.md`
- `by-class/MenuItem.md`
- `by-file/PopupMenuControls.md`
- `by-type/by-vtable/MenuItemVtables.md`
- `by-type/by-struct/MenuItemLayouts.md`
- `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md`
- `by-memory/0x00516290-0x00517441.MenuPaneAndItems.md`
- `by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md`
- `by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md`
- `by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md`
- `by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md`

Research/generated state:

- Prior B003 executed popup-menu controls report.
- Prior B003 executed [UID:0002JF] raw recheck report.
- `resources/exported_data/functions/0x00517400.json`
- `source-3/core/data/readonly/prewave/exported-functions/0x00517400.json`
- `source-3/core/data/cache/prewave/functions/0x00517400.json`
- `by-memory/-coverage-report.md` row for `0002JG`.
- `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and current `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`.

Tooling checks:

- IDA MCP availability check against `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`.
- Raw PE extraction/disassembly from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- `tools/int_convert.py` verified `0x41 = 65`, `0x118 = 280`, `0x02 = 2`, `0x0f = 15`, `0x18 = 24`, `0x80 = 128`, and `0x100 = 256`.

## Raw PE / IDA-Backed Facts

Raw PE section context:

- Image base: `0x00400000`.
- `.text`: `0x00401000-0x0060c600`.
- `.rdata`: `0x0060d000-0x0066c200`.
- Target raw file offset: `0x00116800`.
- Target body: `0x00517400-0x00517441`, `0x41` / 65 bytes (Verified with `int_convert.py`).
- Preceding padding: `0x005173fe-0x00517400`, two `0xcc` bytes, `0x02` / 2 bytes (Verified with `int_convert.py`).
- Following padding: `0x00517441-0x00517450`, fifteen `0xcc` bytes, `0x0f` / 15 bytes (Verified with `int_convert.py`).

Target bytes:

```text
55 8b ec 56 8b f1 c7 06 98 eb 61 00 e8 7f d6 fd ff 8b 45 08 a8 01 74 22 a8 04 75 10 56 e8 9e d6 fd ff 83 c4 04 8b c6 5e 5d c2 04 00 68 18 01 00 00 56 e8 69 42 f0 ff 83 c4 08 8b c6 5e 5d c2 04 00
```

Capstone disassembly:

```asm
00517400  push   ebp
00517401  mov    ebp, esp
00517403  push   esi
00517404  mov    esi, ecx
00517406  mov    dword ptr [esi], 0x0061eb98
0051740c  call   0x004f4a90
00517411  mov    eax, dword ptr [ebp+8]
00517414  test   al, 1
00517416  je     0x0051743a
00517418  test   al, 4
0051741a  jne    0x0051742c
0051741c  push   esi
0051741d  call   0x004f4ac0
00517422  add    esp, 4
00517425  mov    eax, esi
00517427  pop    esi
00517428  pop    ebp
00517429  ret    4
0051742c  push   0x118
00517431  push   esi
00517432  call   0x0041b6a0
00517437  add    esp, 8
0051743a  mov    eax, esi
0051743c  pop    esi
0051743d  pop    ebp
0051743e  ret    4
```

Precise deleting-flag pseudocode for documentation only:

```cpp
// Compiler wrapper pseudocode only. Do not emit as target C++.
this->vptr = &MenuItem::vftable;
LObject::~LObject();

if ((flags & 1) != 0) {
    if ((flags & 4) != 0) {
        compiler_noop_sized_delete_path(this, 0x118);
    } else {
        operator delete(this);
    }
}

return this;
```

Pointer and caller-route checks:

- Whole-file little-endian dword search for target VA `0x00517400` found exactly one hit: raw `0x21d5b4` -> `.rdata:0x0061ebb4`, the `StringMenuItem` vtable slot `+0x00`.
- Search for target RVA `0x00117400` found no hits.
- Search for target raw file offset `0x00116800` found no hits.
- `.text` rel32 call/jump scan found no direct branch or call target to `0x00517400`.
- Search for `MenuItem` vtable VA `0x0061eb98` found expected immediate occurrences in the base constructor, `StringMenuItem` base construction, `SeparatorMenuItem` base construction, [UID:0002JF], and this target's base-vtable reset.
- Search for `StringMenuItem` vtable VA `0x0061ebb4` found the constructor install immediate in `StringMenuItemConstructor`, matching the final class vtable route.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score Recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00517400-0x00517441` | `0002JG` / `by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md` | `StringMenuItem` scalar deleting destructor wrapper | true, source-declared/generated-binary | `0000E8` `StringMenuItem` | `84/90 -> 86/92` | Keep formal C++ blank; add raw PE proof and ordinary destructor guidance. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `.rdata:0x0061ebb4` | Dword points to `0x00517400` | Sole raw pointer hit for target VA; `StringMenuItem` vtable slot `+0x00`. |
| `.text` rel32 scan | No direct call/jump targets to `0x00517400` | No ordinary direct caller; vtable route expected. |
| `0x00517406` | Writes `0x0061eb98` to `[this]` | Compiler restores base `MenuItem` vtable before base cleanup. |
| `0x0051740c` | Calls `0x004f4a90` | Calls [UID:000370] `LObjectDestructorBody`. |
| `0x0051741d` | Calls `0x004f4ac0` | Calls [UID:000197] `OperatorDeleteWrapper` only for scalar-delete flag with bit 4 clear. |
| `0x00517432` | Calls `0x0041b6a0` after pushing `0x118` and `this` | No-op sized-delete/guard path for `flags & 4`. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0002JG] already has correct owner/emitter [UID:0000E8], exact half-open range, blank C++ policy, vtable slot evidence, and inline-label no-extra-cleanup context.
- [UID:0000E8] `StringMenuItem` documents `m_text[0x80]` at `+0x18` and the ordinary/default destructor policy.
- [UID:0001Y4] `MenuItemVtables` and [UID:00036I] `MenuItemVtableData` place `0x00517400` at `StringMenuItem` slot `+0x00`.
- [UID:0001V5] `MenuItemLayouts` ties `0x118` to base `MenuItem` plus inline label storage.
- [UID:0000MN] `PopupMenuControls` remains the accepted `NexusTK/ui/menu/PopupMenuControls.cpp` source root.

Existing docs that are stale or incomplete:

- [UID:0002JG] still lacks the raw PE recheck, exact full disassembly, pointer-route proof, and precise flag-4 branch order now available here.
- Any old reason that formal C++ is blank because of a `95/95`, `90/90`, or low-score threshold should be replaced. The current reason is source-shape correctness: this exact range is compiler output.
- Ghidra/exported decompilation can obscure the flag-4 branch as a guard check with an uninitialized temporary. Raw bytes show the actual branch pushes `0x118` and `this`, calls the one-byte helper, and returns.

Generated/coverage state:

- `auto-generated/-ag-memory-coverage.md` currently shows [UID:0002JG] as `emits`, owner/emitter `0000E8`, code `no`, generated path `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`. That is expected for this no-code wrapper.
- Current generated `PopupMenuControls.cpp` has source-authored sibling menu methods plus an empty emitter marker for [UID:0002JG]. It should continue not to emit a wrapper body.
- `project-level/-auto-completion-stats.md` lists [UID:0002JG] at `84/90`, average `87.0`; after the recommended score update it should leave any low-completion queue for this source-quality reason.

## Ranked Ownership Analysis

### 1. `StringMenuItem` class owner with `PopupMenuControls` source root

Evidence for:

- Sole target pointer hit is the `StringMenuItem` vtable slot at `0x0061ebb4`.
- `StringMenuItem` constructor installs the `0x0061ebb4` vtable at `0x0051704e`.
- Object size path is `0x118`, matching `StringMenuItem` layout, not base `MenuItem`.
- Class page [UID:0000E8] clears `88/90`; file root [UID:0000MN] clears `86/85`.

Evidence against:

- Exact source spelling of the destructor is not proven.

Decision:

- Accepted. Keep metadata `CANONICAL_OWNER:0000E8`, `EMITTER_UIDS:0000E8`.

### 2. Direct file owner `PopupMenuControls`

Evidence for:

- The menu-item family is reconstructed under the current `NexusTK/ui/menu/PopupMenuControls.cpp` source root.

Evidence against:

- By-structure prefers the narrowest semantic owner when the class clears the gate. The vtable slot and object size are class-specific.

Decision:

- Reject as direct owner; retain only as source-file root.

### 3. `MenuItem` base owner

Evidence for:

- The wrapper resets the vptr to the base `MenuItem` vtable and calls base `LObject` cleanup.

Evidence against:

- The vtable entry belongs only to `StringMenuItem`; the flag-4 object size is `0x118`, not base `MenuItem` `0x18`; the base wrapper is separately documented at [UID:0002JF].

Decision:

- Reject. `MenuItem` provides inherited cleanup, not direct ownership of this wrapper.

### 4. Ignored/non-reconstructable compiler glue

Evidence for:

- The exact instructions are compiler-generated ABI wrapper glue.

Evidence against:

- Source class declarations/destructor semantics must still regenerate this vtable slot and wrapper. Project policy keeps such source-declared/generated-binary destructor wrappers reconstructable with blank formal C++ when proof is documented.

Decision:

- Reject ignored/non-reconstructable. Keep reconstructable TRUE and no-code proof.

### 5. Feature menu/dialog or adjacent `MenuDialogFactoryHelpers`

Evidence for:

- `StringMenuItem` constructor is reused by feature/dialog creation paths, and `MenuDialogFactoryHelpers` starts nearby at `0x00517450`.

Evidence against:

- The target is vtable-owned by generic `StringMenuItem`; adjacent `0xcc` padding separates the reusable menu-item cluster from the later factory island; constructor fan-in is reuse, not ownership.

Decision:

- Reject.

## First-Draft C++ / No-Code Recommendation

Do not populate [UID:0002JG] target formal C++.

Target-specific no-code proof:

- The range takes a compiler deleting-destructor flag parameter, restores the base vtable, calls base cleanup, performs scalar-delete flag checks, calls the project global delete wrapper only on the normal scalar-delete path, and calls a no-op sized-delete/guard helper with object size `0x118` on the flag-4 path.
- Those instructions are compiler ABI output. Handwriting them in project source would encode vtable addresses, compiler flags, and allocation-helper calls directly in source.
- `StringMenuItem` has no heap-owned label data to clean up; `m_text` is inline `wchar_t[0x80]` at `+0x18`.
- The source-level object behavior is an ordinary/default destructor; MSVC should regenerate the wrapper.

Recommended support-level source shape, not target code:

```cpp
StringMenuItem::~StringMenuItem()
{
}
```

If the class declaration already needs a virtual destructor inherited from `MenuItem`, an inline/default spelling is also plausible. The report should not overclaim exact original spelling.

## Recommended Target Doc Changes

Apply these changes to `by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md` after supervisor acceptance.

Header changes:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep owner/emitter/reconstructable metadata and formal C++ blank.

Recommended status/rebuild wording:

```text
Rebuild handling: source-declared/generated-binary compiler wrapper. This exact range is the MSVC scalar deleting destructor wrapper generated for ordinary/default `StringMenuItem` destructor semantics. Keep the target formal C++ block blank; reconstructed source should express ordinary `StringMenuItem` destructor semantics on the class, and MSVC should regenerate this wrapper.
```

Recommended behavior wording:

```text
The wrapper restores the base `MenuItem` vtable, calls [UID:000370] `LObjectDestructorBody`, reads deleting-destructor flags from `[ebp+8]`, calls [UID:000197] `OperatorDeleteWrapper` only when `(flags & 1) != 0` and `(flags & 4) == 0`, takes the flag-4 path through the one-byte no-op helper at `0x0041b6a0` after pushing `this` and object size `0x118` / 280 bytes (Verified with `int_convert.py`), and returns `this`. No `StringMenuItem` label cleanup is present because the label is inline `wchar_t m_text[0x80]` at `+0x18`.
```

Recommended raw evidence subsection:

```text
B009 2026-06-19 raw PE recheck against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirmed `0x00517400-0x00517441` as a `0x41` / 65-byte wrapper (Verified with `int_convert.py`) at raw file offset `0x00116800`. The body bytes are:

55 8b ec 56 8b f1 c7 06 98 eb 61 00 e8 7f d6 fd ff 8b 45 08 a8 01 74 22 a8 04 75 10 56 e8 9e d6 fd ff 83 c4 04 8b c6 5e 5d c2 04 00 68 18 01 00 00 56 e8 69 42 f0 ff 83 c4 08 8b c6 5e 5d c2 04 00

Capstone disassembly shows the base vtable reset at `0x00517406`, [UID:000370] `LObjectDestructorBody` call at `0x0051740c`, deleting flag checks at `0x00517414` and `0x00517418`, [UID:000197] `OperatorDeleteWrapper` call at `0x0051741d`, and flag-4 no-op/sized path at `0x0051742c-0x00517437` using size `0x118` / 280 bytes (Verified with `int_convert.py`). A raw dword search found target VA `0x00517400` only in the `StringMenuItem` vtable slot at `.rdata:0x0061ebb4`, found no target RVA/raw-offset hits, and a `.text` rel32 scan found no direct calls or jumps to the target start. Preceding bytes `0x005173fe-0x00517400` are two `0xcc` bytes and following bytes `0x00517441-0x00517450` are fifteen `0xcc` bytes before [UID:000238] `MenuDialogFactoryHelpers`.
```

Recommended score rationale:

```text
Raised from `84/90` to `86/92` after B009 added target-specific raw PE evidence and resolved the no-code policy under the current 85/85 gate. Completion now reflects exact bytes, padding, disassembly, scalar-delete flag order, callee identities, vtable-only pointer route, absence of direct callers, object-size/layout proof, owner/emitter validation, and explicit no-formal-C++ proof. Confidence remains below final-audit because live IDA MCP was unavailable in this session and exact original destructor spelling remains inferred, but those caveats no longer block source-quality routing.
```

Recommended target no-code proof:

```text
Do not populate target formal C++. This range is compiler-generated deleting-destructor glue. The source-level representation is ordinary/default `StringMenuItem` destructor semantics; MSVC regenerates the deleting-wrapper flag checks, base vtable reset, base `LObject` cleanup call, no-op sized-delete path, and optional `operator delete` call. Handwriting those instructions in final project C++ would be decompiler-shaped and less source-faithful than an ordinary destructor.
```

## Recommended Support-Doc Changes

Apply this insertion to [UID:0000E8] `by-class/StringMenuItem.md`, preferably near the B003 source-quality incorporation/destructor row:

```text
Destructor source policy: [UID:0002JG][0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor](by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md) is the compiler-generated scalar deleting destructor wrapper for ordinary/default `StringMenuItem` destruction. Raw PE recheck confirms the wrapper object-size path is `0x118` / 280 bytes (Verified with `int_convert.py`), matching `MenuItem` base size `0x18` plus inline `wchar_t m_text[0x80]` at `+0x18`; no heap label cleanup exists. Reconstructed class-level source should use ordinary destructor semantics, for example an empty/default `StringMenuItem::~StringMenuItem()` if a definition is needed. The by-memory wrapper page should keep formal C++ blank because MSVC regenerates the flag checks, base vtable reset, base `LObject` cleanup, no-op sized-delete path, and optional delete call.
```

Apply this optional insertion to [UID:0001Y4] `by-type/by-vtable/MenuItemVtables.md` or [UID:00036I] `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md`:

```text
2026-06-19 B009 raw PE recheck found the little-endian target pointer `0x00517400` only at `.rdata:0x0061ebb4` (`StringMenuItem` slot `+0x00`), with no target RVA/raw-offset hits and no `.text` rel32 callers. This strengthens the interpretation that [UID:0002JG] is vtable-owned deleting-destructor glue generated from ordinary `StringMenuItem` destructor semantics rather than an ordinary directly called helper.
```

No score/path changes are required for `PopupMenuControls`, `MenuItemLayouts`, `MenuItemVtables`, or `MenuItemVtableData` beyond optional evidence text.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace the existing [UID:0002JG] row inside the `0x00516290-0x00517441.MenuPaneAndItems` nested region, preserving address order after the [UID:0002JF] row/padding and before the `0x00517441-0x00517450` padding row.

Replacement row:

```text
        - [UID:0002JG][0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor](by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md) 0x00517400-0x00517441 | compiler-generated destructor wrapper | StringMenuItemScalarDeletingDestructor : reconstructable : 86% : very-strong : B009 2026-06-19 raw PE recheck confirms the exact `0x41` / 65-byte wrapper (Verified with `int_convert.py`), two-byte prepad and fifteen-byte postpad (Verified with `int_convert.py`), full body bytes, base `MenuItem` vtable reset at `0x00517406`, [UID:000370][0x004f4a90-0x004f4a97.LObjectDestructorBody](by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md) `LObjectDestructorBody` call at `0x0051740c`, [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md) `OperatorDeleteWrapper` call only for `flags & 1` with `flags & 4` clear, flag-4 path through the one-byte `0x0041b6a0` no-op helper with `0x118` / 280-byte object size (Verified with `int_convert.py`), target VA pointer hit only in the `StringMenuItem` vtable slot at `0x0061ebb4`, no target RVA/raw-offset hits, no `.text` rel32 direct callers, direct StringMenuItem class owner/emitter with PopupMenuControls source root, inline `wchar_t m_text[0x80]` no-extra-cleanup proof, and explicit target-specific no-formal-C++ proof because source should express ordinary/default `StringMenuItem` destructor semantics and let MSVC regenerate the deleting-wrapper body.
```

## IDA Rename / Type / Comment Recommendations

High confidence:

- Rename `sub_517400` to `StringMenuItem_ScalarDeletingDestructor` or `StringMenuItem_scalar_deleting_destructor`. Keep the name descriptive; do not imply original source contained `ScalarDeletingDestructor`.
- Type the function as `StringMenuItem *__thiscall StringMenuItem_ScalarDeletingDestructor(StringMenuItem *this, unsigned int flags)` or equivalent. The wrapper returns `this` and consumes one stack dword with `ret 4`.
- Type/layout `StringMenuItem` as deriving from `MenuItem` with inline `wchar_t m_text[0x80]` at offset `+0x18`, total recovered size `0x118`.
- Comment `0x00517406`: restores base `MenuItem` vtable before base destructor.
- Comment `0x0051740c`: calls `LObjectDestructorBody`.
- Comment `0x00517414`: `flags & 1` gates delete work.
- Comment `0x00517418`: `flags & 4` diverts to no-op sized-delete/guard path.
- Comment `0x0051741d`: normal scalar-delete path calls `OperatorDeleteWrapper`.
- Comment `0x0051742c`: flag-4 path passes `this` and object size `0x118`; helper is compiler no-op/guard, not source cleanup.

Medium confidence:

- Keep global helper `0x0041b6a0` named as the existing `@_guard_check_icall_nop@4` or a neutral `compiler_noop_guard_helper`; do not rename it to a `StringMenuItem` helper.

## Validation Commands Needed

After supervisor accepts the report and sends an implementation callback, run targeted validation after applying by-* doc changes:

> Executable block R001 was removed from this report and preserved verbatim in [0002JG-StringMenuItemScalarDeletingDestructor-source-quality-removed.md](0002JG-StringMenuItemScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected validation outcome:

- Target page validates at `86/92`, owner/emitter [UID:0000E8], blank formal C++.
- Generated `PopupMenuControls.cpp` should continue to omit a [UID:0002JG] wrapper body and retain only an empty emitter marker for this UID.
- Refreshed generated coverage may still show code `no`; that is expected for this documented compiler-wrapper no-code case.

## Implementation Readiness

Ready for supervisor implementation callback.

No blocker remains for raising [UID:0002JG] above the per-field `85/85` source-quality gate. The only residual uncertainty is exact original destructor spelling, which should remain documented as an inferred source-shape caveat and cap final-audit scoring. The target should not receive first-draft wrapper C++.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/0002JG-StringMenuItemScalarDeletingDestructor-source-quality.md`
- Modified: none.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0002JG-StringMenuItemScalarDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"0002JG"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002JG-StringMenuItemScalarDeletingDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/0002JG-StringMenuItemScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002JG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
