** TARGET-REPORT-UID:0002T0 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0002T0] IconsPaneShowReducedIcons Source-Quality Report

Agent: B004
Mode: report-only research
Assignment id: `B004-report-0002T0-icons-pane-show-reduced-icons-source-quality-20260626`
Target: `by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md`
Required report path: `tools/leaser/Agents/Agent-B004/research/0002T0-IconsPaneShowReducedIcons-source-quality.md`
MCP session: `80de0a67`
Report timestamp: 2026-06-26T16:23:39-04:00

## Finalized Report / Current Recommendation

- Current recommendation: promote [UID:0002T0] from current source metadata `COMPLETION:86`, `CONFIDENCE:88` to `COMPLETION:91`, `CONFIDENCE:92`.
- Final disposition: keep the existing `IconsPane` owner and emitter route: `CANONICAL_OWNER:00006B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006B`.
- Required action: after supervisor validation, update the target page with report-level evidence and insert formal first-draft C++ into its `RECONSTRUCTION_CPP CODE` block.
- Confidence: strong for exact range, bytes, behavior, caller route, source placement, source-facing names, and first-draft C++ readiness; below final-audit range because exact original `Config` field spelling and the final full class declaration remain inferred broader work.

## Executive Recommendation

[UID:0002T0] should receive the same source-quality treatment as the already-executed sibling [UID:0002SZ] `ShowAllIcons`. The old blank-C++ rationale on the target page is now stale for this exact child. Current IDA MCP evidence in session `80de0a67` reconfirms that `sub_4CF2D0` is a complete 0x26-byte `IconsPane` state mutator: it runs only when `m_showAllIcons` is true, writes persisted config byte `g_pConfig->m_iconPaneReducedMode = 1`, clears `m_showAllIcons`, and invalidates `m_bounds` through inherited virtual slot `+0x20`.

This report recommends inserting this exact formal C++ block after supervisor acceptance:

```cpp
void IconsPane::ShowReducedIcons()
{
    if (m_showAllIcons) {
        g_pConfig->m_iconPaneReducedMode = 1;
        m_showAllIcons = false;
        InvalidateRect(&m_bounds);
    }
}
```

The source-facing names are the current best-supported names, not raw IDA labels:

- `m_showAllIcons` for object byte `this+0xf8`.
- `g_pConfig` for `dword_67A7C8`.
- `m_iconPaneReducedMode` for persisted byte `g_pConfig+0x28de32`; stored `0` means full/all-icons mode and stored `1` means reduced/two-icon strip.
- `m_bounds` for the rectangle member at `this+0x44`.
- `InvalidateRect(&m_bounds)` for the inherited vtable slot `+0x20` call.

Use source return type `void`. IDA decompiles a synthetic `int` because the changed branch tail-returns the indirect invalidation call and the no-change branch leaves a decompiler temporary undefined, but the only known caller treats this as a command/state mutator and does not consume a return value.

## Target

- Target UID: `0002T0`
- Target path: `by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` under `## by-memory` -> `### Not-Covered Files - Reconstructable`; generated row still shows stale `78/86`, average `82.0`, report count `0`.
- Current supervisor classification: source-quality blocker for reduced-icon-mode mutator, including exact range, caller route, config byte, `IconsPane` field names, invalidation helper name, sibling relationship, owner/emitter route, source placement, score movement, item summary, and first-draft C++ readiness.
- Current target metadata: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:00006B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006B`, blank emitter position, blank formal C++.

## Current Target State

- Existing behavior text is correct at the raw level: the method persists config byte `+0x28de32 = 1`, clears `this+0xf8`, and invalidates bounds.
- Existing owner/emitter route is already correct: owner and emitter [UID:00006B] `IconsPane`, source placement [UID:0000JZ] `IconsPane.cpp`.
- Existing blocker is stale: the target says final C++ remains blank because final field/global declarations and invalidation helper name are broader decisions. Sibling [UID:0002SY] and [UID:0002SZ], class/file docs, and current `g_pConfig`/`g_pIconsPane` docs now resolve those names enough for exact child C++.
- Current generated coverage is stale: `auto-generated/-ag-coverage-report-by-memory.md` still shows [UID:0002T0] as `emits_code:false`, `78%`, while [UID:0002SY] and [UID:0002SZ] now emit formal C++ at `91/92`.
- Current generated C++ has an empty emitter marker for [UID:0002T0] in `auto-generated/NexusTK/ui/panels/IconsPane.cpp`.

## Evidence Sources Read

Current assignment and workflow:

- `tools/leaser/Agents/Agent-B004/goal.md`
- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `by-structure.md`
- `by-memory/-guidance.md`

Target and support docs:

- [UID:0002T0] `by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md`
- [UID:0002SZ] `by-memory/0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons.md`
- [UID:0002SY] `by-memory/0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons.md`
- [UID:00016Z] `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md`
- [UID:00006B] `by-class/IconsPane.md`
- [UID:0000JZ] `by-file/IconsPane.md`
- [UID:0000M7] `by-file/OptionPane.md`
- [UID:00009V] `by-class/OptionPane.md`
- [UID:0001DN] `by-memory/0x0053ddb0-0x0053e191.OptionPaneOnOptionCommand.md`
- [UID:0001DO] `by-memory/0x0053d820-0x0053e520.OptionPane.md`
- [UID:00028Q] `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- [UID:0002XU] `by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md`
- [UID:0000R6] `by-global/g_pIconsPane.md`
- [UID:000031] `by-class/Config.md`
- [UID:0000IE] `by-file/Config.md`

Generated and project-state inputs:

- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/NexusTK/ui/panels/IconsPane.cpp`
- `project-level/-resolved.md`
- `project-level/-unresolved.md`
- `project-level/-resolved-multple-aliases.md`

Relevant executed reports used as context or leads:

- `executed-b-agent-research/B001/0002SZ-IconsPaneShowAllIcons-source-quality.md`
- `executed-b-agent-research/B001/0002SY-IconsPaneIsShowingAllIcons-source-quality.md`
- `executed-b-agent-research/B003/00016Z-IconsPaneCore-source-quality.md`
- `executed-b-agent-research/B004/0001DO-OptionPane-source-quality.md`

The old B004 OptionPane report was treated as historical lead material because it states MCP was unavailable in that pass. Current MCP evidence in this report revalidates the specific OptionPane control-6 route and the reduced-mode callsite.

## MCP Availability

MCP was available and usable for this report.

- Endpoint: `http://127.0.0.1:13337/mcp`
- `initialize` succeeded and returned server `ida-pro-mcp`, protocol `2025-06-18`.
- `tools/list` succeeded and showed the current database-required tool schema.
- `idb_list` returned active session `80de0a67`.
- Active IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Active backend/process: worker session, PID `26892`.
- `server_health` returned `status:"ok"`, imagebase `0x400000`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

B004 did not start, stop, restart, save, patch, rename, or otherwise mutate MCP/IDA state.

## Live MCP Function Evidence

`lookup_funcs` confirms the exact target and neighboring boundaries:

| Query | MCP result | Meaning |
| --- | --- | --- |
| `0x004cf290` | `sub_4CF290`, size `0x7` | sibling `IsShowingAllIcons` accessor |
| `0x004cf2a0` | `sub_4CF2A0`, size `0x26` | sibling `ShowAllIcons` mutator |
| `0x004cf2d0` | `sub_4CF2D0`, size `0x26` | target `ShowReducedIcons` mutator |
| `0x004cf2f6` | not a function | padding after target |
| `0x004cf300` | `sub_4CF300`, size `0xd3` | following `OnPaint` method |
| `0x0053ddb0` | `sub_53DDB0`, size `0x3e1` | old `OptionPane` command/apply path |

Target bytes for `0x004cf2d0-0x004cf2f6`:

```text
80 b9 f8 00 00 00 01 75 1c a1 c8 a7 67 00 c6 80 32 de 28 00 01 8d 41 44 8b 11 50 c6 81 f8 00 00 00 00 ff 52 20 c3
```

Padding bytes after target at `0x004cf2f6-0x004cf300`:

```text
cc cc cc cc cc cc cc cc cc cc
```

Sibling padding before the target at `0x004cf2c6-0x004cf2d0` is also ten `0xcc` bytes. No target split or range repair is needed.

Unique signature for the exact target range:

```text
80 B9 F8 00 00 00 01 75 1C A1 C8 A7 67 00 C6 80 32 DE 28 00 01 8D 41 44 8B 11 50 C6 81 F8 00 00 00 00 FF 52 20 C3
```

## Target Disassembly

MCP `disasm` for [UID:0002T0]:

```asm
0x004cf2d0  cmp     byte ptr [ecx+0F8h], 1
0x004cf2d7  jnz     short locret_4CF2F5
0x004cf2d9  mov     eax, dword_67A7C8
0x004cf2de  mov     byte ptr [eax+28DE32h], 1
0x004cf2e5  lea     eax, [ecx+44h]
0x004cf2e8  mov     edx, [ecx]
0x004cf2ea  push    eax
0x004cf2eb  mov     byte ptr [ecx+0F8h], 0
0x004cf2f2  call    dword ptr [edx+20h]
0x004cf2f5  retn
```

The binary branch is direct:

- If `this+0xf8` is not `1`, return without writes or invalidation.
- Otherwise load `g_pConfig`.
- Write byte `g_pConfig+0x28de32 = 1`.
- Pass member rectangle `this+0x44`.
- Clear `this+0xf8` to `0`.
- Call the inherited virtual slot `+0x20` with that rectangle pointer.

The write order should be preserved in source C++: persisted config first, runtime state second, invalidation last.

## Target Decompilation

MCP `decompile` for [UID:0002T0]:

```c
int __thiscall sub_4CF2D0(_BYTE *this)
{
  int v1; // edx
  int result; // eax

  if ( this[248] == 1 ) /*0x4cf2d7*/
  {
    *(_BYTE *)(dword_67A7C8 + 2678322) = 1; /*0x4cf2de*/
    v1 = *(_DWORD *)this; /*0x4cf2e8*/
    this[248] = 0; /*0x4cf2eb*/
    return (*(int (__stdcall **)(_BYTE *))(v1 + 32))(this + 68); /*0x4cf2f2*/
  }
  return result; /*0x4cf2f5*/
}
```

The decompiler confirms the disassembly but retains raw labels and the synthetic `int` return. Source-level reconstruction should use a `void IconsPane::ShowReducedIcons()` mutator with source-facing field/global/helper names.

## Numeric Conversion Evidence

`tools/int_convert.py` was used for the target constants:

| Hex constant | Decimal result | Use |
| --- | ---: | --- |
| `0xf8` | `248` | `m_showAllIcons` byte at `this+0xf8` (Verified with int_convert.py) |
| `0x28de32` | `2678322` | persisted config byte offset (Verified with int_convert.py) |
| `0x44` | `68` | member bounds rectangle at `this+0x44` (Verified with int_convert.py) |
| `0x20` | `32` | inherited virtual invalidation slot (Verified with int_convert.py) |

## Caller and Reachability Evidence

`xrefs_to` reports exactly one code reference to [UID:0002T0]:

| Target | Xref | Meaning |
| --- | --- | --- |
| `0x004cf2d0` | code xref at `0x0053dee0` in `sub_53DDB0` | old OptionPane control-6 apply path calls reduced-mode mutator |
| `0x004cf2a0` | code xref at `0x0053ded2` in `sub_53DDB0` | same path calls sibling all-icons mutator |
| `0x004cf2f6` | no xrefs | padding after [UID:0002T0] |
| `0x004cf300` | one data xref at `0x0061b48c` | following virtual `OnPaint` slot, not part of target |

`callees 0x004cf2d0` returns no direct callees because the only call is an indirect vtable slot call. `analyze_function 0x004cf2d0` reports one caller `sub_53DDB0`, no strings, three basic blocks, and cyclomatic complexity `2`.

MCP `insn_query` around the old OptionPane apply route:

```asm
0x0053dea7  mov     ecx, [esi+1FCh]
0x0053dead  push    6
0x0053deaf  mov     eax, [ecx]
0x0053deb1  call    dword ptr [eax+10h]
0x0053deb4  mov     eax, [eax]
0x0053deb6  mov     al, [eax+10Ch]
0x0053debc  mov     [edi+28DE32h], al
0x0053dec0  mov     [edi+28DE32h], al
0x0053dec2  mov     ecx, dword ptr unk_69B41C
0x0053dec8  test    al, al
0x0053deca  jnz     short loc_53DED9
0x0053decc  mov     [edi+28DE32h], al
0x0053ded2  call    sub_4CF2A0
0x0053ded7  jmp     short loc_53DEE5
0x0053ded9  mov     byte ptr [edi+28DE32h], 1
0x0053dee0  call    sub_4CF2D0
```

This confirms:

- Old OptionPane asks its control list for control id `6`.
- It reads the control byte from `[control+0x10c]`.
- It stores that byte to `g_pConfig+0x28de32`.
- It reads `g_pIconsPane` from `0x0069b41c`.
- If the option byte is zero, it calls `ShowAllIcons`.
- If the option byte is nonzero, it writes persisted byte `1` and calls `ShowReducedIcons`.

This proves [UID:0002T0] is the reduced/two-icon-strip mutator and [UID:0002SZ] is the all-icons/full-mode mutator.

## Pointer and Padding Negative Evidence

`find_bytes` found no little-endian loaded-VA pointer hits for target start `0x004cf2d0` using pattern `d0 f2 4c 00`.

`find_bytes` found no little-endian RVA pointer hits for target start `0x000cf2d0` using pattern `d0 f2 0c 00`.

`xrefs_to 0x004cf2f6` found no references to the post-target padding boundary. The ten `0xcc` bytes after the function are alignment/trap padding and should not be included in source output.

The target has one normal code caller and no evidence of a hidden pointer-table dispatch route.

## Sibling Method Evidence

[UID:0002SY] `IconsPaneIsShowingAllIcons` now emits formal C++:

```cpp
bool IconsPane::IsShowingAllIcons() const
{
    return m_showAllIcons;
}
```

That sibling validates object byte `this+0xf8` as the boolean runtime state `m_showAllIcons`.

[UID:0002SZ] `IconsPaneShowAllIcons` now emits formal C++:

```cpp
void IconsPane::ShowAllIcons()
{
    if (!m_showAllIcons) {
        g_pConfig->m_iconPaneReducedMode = 0;
        m_showAllIcons = true;
        InvalidateRect(&m_bounds);
    }
}
```

[UID:0002T0] is the exact inverse of [UID:0002SZ]:

- [UID:0002SZ] executes when `m_showAllIcons` is false, writes persisted reduced mode `0`, sets `m_showAllIcons = true`, and invalidates bounds.
- [UID:0002T0] executes when `m_showAllIcons` is true, writes persisted reduced mode `1`, sets `m_showAllIcons = false`, and invalidates bounds.

The sibling evidence removes the old field/global/helper naming blocker for this exact child.

## Heuristic / Inference Reanalysis And Validation

### Blank formal C++ blocker

Resolved. Current `by-structure.md` allows C++ when the target is reconstructable, has a valid nonblank emitter route, and average score is greater than 85. [UID:0002T0] already has `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006B`, and current source metadata `86/88`; this report supplies additional MCP-backed evidence and source-facing names. The old 95+ or broad declaration blocker should be replaced with exact child C++ readiness.

### `this+0xf8` naming

Resolved to `m_showAllIcons`.

Evidence:

- [UID:0002SY] returns the byte directly and now emits `IsShowingAllIcons()`.
- [UID:0002SZ] sets it true for full/all-icons mode.
- [UID:0002T0] clears it for reduced/two-icon mode.
- [UID:0002T1] paint and [UID:0002T3] hit-test use this state to start at icon index `0` or `6`.
- [UID:00006B] class docs record this member name.

Rejected:

- `this[248]`, `field_0xf8`, `byte_0xf8`, or `mbr_0xf8`: raw/decompiler-shaped.
- `m_iconPaneReducedMode`: wrong for the object field because runtime state is inverse of the persisted reduced-mode byte.

### `dword_67A7C8` and `+0x28de32` naming

Resolved enough for first-draft child C++.

Evidence:

- [UID:00028Q] documents `dword_67A7C8` as `g_pConfig`.
- [UID:00028Q] records `+0x28de32` as the IconsPane reduced-display-mode byte: stored `0` means full/all icons, stored `1` means reduced/two-icon strip.
- OptionPane control id `6` writes the same byte and then calls `ShowAllIcons` or `ShowReducedIcons`.
- [UID:00006B] and [UID:0000JZ] prefer `m_iconPaneReducedMode` for the current source-facing field name, with `m_iconPaneDisplayMode` left only as a possible future neutral project-wide rename.

Rejected:

- Raw `dword_67A7C8` and `byte_28de32`: raw IDA labels.
- `m_showAllIcons` for the config byte: wrong polarity; that name belongs to the `IconsPane` runtime bool.
- By-value `g_Config`: binary loads and dereferences a pointer.

### Invalidation helper and bounds naming

Resolved to `InvalidateRect(&m_bounds)`.

Evidence:

- Target pushes `this+0x44` and calls vtable slot `+0x20`.
- Current `IconsPane` children already use `m_bounds` and inherited `InvalidateRect`.
- [UID:0002T4] uses the same inherited slot family for rectangle invalidation.

Rejected:

- Raw virtual-call syntax in source C++.
- `Invalidate()` with no argument, because the binary pushes a rectangle pointer.
- Generic `Refresh()` or `Redraw()`, because the call is rectangle-specific.

### Source placement and owner

Resolved. Keep [UID:00006B] `IconsPane` as canonical owner and emitter; source file route is [UID:0000JZ] `NexusTK/ui/panels/IconsPane.cpp`.

OptionPane is the consumer. Config owns the persisted byte. Neither is the direct source owner for this method.

### Range and split

Resolved. The target is a single modeled 0x26-byte function followed by ten `0xcc` padding bytes and the following `OnPaint` function at `0x004cf300`. No split, merge, range rename, or padding child is needed for this exact target.

## Evidence Standards Used

Evidence ladder used for this recommendation:

- Direct IDA MCP facts: function boundaries, bytes, disassembly, decompilation, xrefs, caller window, signature, pointer-pattern negative checks, server health/session status.
- Documentation facts: current target/support docs, executed sibling reports, generated coverage/tracker state, global/config support docs, project-level resolved alias reports.
- Inference: source-facing names and source shape where original symbols are not present.

Important IDA/MCP limitation: MCP cannot prove exact original source spelling for `m_showAllIcons`, `m_iconPaneReducedMode`, or `InvalidateRect`. The recommendation is therefore marked source-quality inferred/descriptive where spelling is concerned, but behavior, range, call route, and data flow are direct MCP facts.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:0002T0] is `IconsPane::ShowReducedIcons` | Strong | Target writes config byte `1`, clears `this+0xf8`, and caller route dispatches nonzero option control 6 to `0x004cf2d0` | Sibling `ShowAllIcons` writes `0` and sets the bool; no pointer-table route found | Exact original spelling is not symbol-proven |
| `this+0xf8` is `m_showAllIcons` | Strong | [UID:0002SY] accessor, sibling mutators, paint/hit-test use, class docs | Rejected raw field names and inverse reduced-mode object naming | Final class declaration still broader work |
| `g_pConfig+0x28de32` is `m_iconPaneReducedMode` | Strong behavior, medium-high spelling | `g_pConfig` page, OptionPane control-6 route, sibling polarity | Rejected `m_showAllIcons` for persisted byte and raw names | Exact original Config member spelling not recovered |
| `this+0x44` and vtable slot `+0x20` should be `InvalidateRect(&m_bounds)` | Strong | Disassembly pushes `this+0x44`; current child docs and pane-family docs use inherited rectangle invalidation | Rejected no-arg invalidation and raw vtable syntax | Exact base-class declaration spelling follows existing docs |
| Formal C++ is ready for this exact child | Strong | Code-entry gate met, exact bytes/range/caller/source names resolved, sibling [UID:0002SZ] already emits inverse body | Checked range/padding, pointer route, owner/emitter, generated stale marker | Final audit score remains below 95 due to broader declaration/name proof |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004cf290-0x004cf297` | [UID:0002SY] `IconsPaneIsShowingAllIcons` | accessor returning `m_showAllIcons` | TRUE | [UID:00006B] | `91/92` | formal C++ present |
| `0x004cf2a0-0x004cf2c6` | [UID:0002SZ] `IconsPaneShowAllIcons` | full/all-icons mutator | TRUE | [UID:00006B] | `91/92` | formal C++ present |
| `0x004cf2c6-0x004cf2d0` | padding | alignment between siblings | FALSE | none | ignored | ten `0xcc` bytes |
| `0x004cf2d0-0x004cf2f6` | [UID:0002T0] `IconsPaneShowReducedIcons` | reduced/two-icon mutator | TRUE | [UID:00006B] | current `86/88`, recommended `91/92` | formal C++ recommended |
| `0x004cf2f6-0x004cf300` | padding | alignment before `OnPaint` | FALSE | none | ignored | ten `0xcc` bytes |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0053dee0` | code xref to `0x004cf2d0` inside `sub_53DDB0` | old OptionPane apply path calls reduced-mode mutator |
| `0x0053ded2` | code xref to `0x004cf2a0` inside `sub_53DDB0` | same path calls all-icons mutator when control byte is zero |
| `0x004cf2f6` | zero xrefs | target padding is not source code |
| `0x004cf2d0` loaded VA/RVA | zero `find_bytes` hits | no address-taken pointer-table route found |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0002SZ] sibling report and page now have formal C++ using `m_showAllIcons`, `g_pConfig->m_iconPaneReducedMode`, `m_bounds`, and `InvalidateRect`.
- [UID:0002SY] page now emits the exact accessor for `m_showAllIcons`.
- [UID:00016Z], [UID:00006B], and [UID:0000JZ] route this cluster through `IconsPane` and `IconsPane.cpp`.
- [UID:00028Q] documents the config byte polarity.
- [UID:0002XU] and [UID:0000R6] document the `g_pIconsPane` option-consumer route.
- `project-level/-resolved.md` and `project-level/-resolved-multple-aliases.md` resolve `dword_67A7C8` to `g_pConfig` and `dword_69B41C` to `g_pIconsPane`.

Existing docs that are stale or incomplete:

- [UID:0002T0] target page still has blank formal C++ under stale broader field/global/helper wording.
- Generated tracker row is stale at `78/86`, report count `0`.
- Generated coverage and generated `IconsPane.cpp` still show [UID:0002T0] as empty/no-code.

No stale Wave2/Wave3 material was used as authority. Old generated names and old reports were used only as leads and were rechecked against current docs/MCP.

## Ranked Ownership Analysis

### 1. [UID:00006B] IconsPane

- Evidence for: method operates on `IconsPane` object state `this+0xf8`, member bounds `this+0x44`, and inherited pane invalidation; sibling methods and class docs identify the mode API as `IconsPane`; option UI reaches it through `g_pIconsPane`.
- Evidence against: exact original class declaration/header spelling is not recovered.
- Decision: keep as canonical owner and emitter.

### 2. [UID:0000JZ] IconsPane source file

- Evidence for: by-file page owns old-layout icon strip, source route `NexusTK/ui/panels/IconsPane.cpp`, and current generated output already emits sibling mode methods through this route.
- Evidence against: `CANONICAL_OWNER` should be the class, not the file, for a class method.
- Decision: keep as source placement and final file route through [UID:00006B].

### 3. [UID:0000M7] OptionPane

- Evidence for: sole direct caller is old OptionPane control-6 apply path.
- Evidence against: consumer/caller does not own the method; OptionPane obtains `g_pIconsPane` and calls the class method.
- Decision: reject as owner; keep only as caller/support evidence.

### 4. [UID:00028Q] g_pConfig / Config

- Evidence for: target writes a `Config` field.
- Evidence against: writing a persisted setting does not make this an owned `Config` method; the object state and invalidation target are `IconsPane`.
- Decision: reject as owner; keep as dependency.

### 5. No-owner/non-emitting

- Evidence for: no original symbol proof.
- Evidence against: exact source-authored method, direct caller, known class state, valid owner/emitter, and current source route are all present.
- Decision: reject.

## Source Placement

Recommended placement: `IconsPane::ShowReducedIcons` in [UID:0000JZ] `NexusTK/ui/panels/IconsPane.cpp` through class owner/emitter [UID:00006B].

This placement fits source-tree and subsystem context because the method is one member of the old-layout icon strip state API, paired with `IsShowingAllIcons` and `ShowAllIcons`, and used by the old option dialog only as an external preference command.

Rejected placements:

- `OptionPane.cpp`: caller/consumer only.
- `Config.cpp`: persisted storage owner only.
- `TabPane.cpp`: adjacency and shared helper caveats do not override `IconsPane` field, singleton, vtable, and resource evidence.

Remaining placement uncertainty: final physical grouping with `TabPane` is a broader class/file question, but it does not block exact child emission under current `IconsPane.cpp` route.

## Range / Split / Padding / Reclassification Analysis

- Exact range: `0x004cf2d0-0x004cf2f6`.
- Function size: `0x26`.
- Start boundary: modeled function start at `0x004cf2d0`, immediately after ten bytes of sibling padding at `0x004cf2c6-0x004cf2d0`.
- End boundary: `0x004cf2f6`, followed by ten bytes of `0xcc` padding before `OnPaint` at `0x004cf300`.
- No child split is needed.
- No reclassification is needed; target remains reconstructable source-authored class method.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are requested or performed by B004.

Source-facing name/type recommendations if a supervisor or IDA-maintenance pass later chooses to apply them:

- `sub_4CF2D0` -> `IconsPane::ShowReducedIcons`
- Object field `+0xf8` -> `m_showAllIcons`
- `dword_67A7C8` -> `g_pConfig`
- Config byte `+0x28de32` -> `m_iconPaneReducedMode`
- Bounds member `+0x44` -> `m_bounds`
- Slot `+0x20` call comment -> `Pane::InvalidateRect(&m_bounds)` or inherited bounds invalidation

Items intentionally left as documentation/source recommendations only: all of the above, because this is report-only and IDA DB mutations are outside B-agent scope.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes.
- Required formal C++ insertion text:

```cpp
void IconsPane::ShowReducedIcons()
{
    if (m_showAllIcons) {
        g_pConfig->m_iconPaneReducedMode = 1;
        m_showAllIcons = false;
        InvalidateRect(&m_bounds);
    }
}
```

Reason it preserves exact original behavior:

- Guard matches `cmp byte ptr [ecx+0F8h], 1` followed by no-op return when false.
- Persists byte value `1` before runtime state changes.
- Clears the runtime bool before invalidation.
- Calls the rectangle invalidation path with `this+0x44`.
- Emits no code for padding or siblings.

Reason it matches plausible original source shape:

- It is a short state-mutator member paired with `ShowAllIcons`.
- It uses source-facing class/global/member names established by sibling method docs.
- It uses ordinary mid-2000s C++ member-call shape instead of raw vtable syntax.
- It avoids decompiler temporaries and raw labels.

No-code proof is not applicable. The target clears the current code-entry gate and has no target-local blocker remaining.

## Score And Metadata Recommendation

Current target metadata:

```text
COMPLETION:86
CONFIDENCE:88
CANONICAL_OWNER:00006B
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00006B
EMITTER_POSITION_OPTIONAL:
```

Recommended target metadata after accepted implementation:

```text
COMPLETION:91
CONFIDENCE:92
CANONICAL_OWNER:00006B
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00006B
EMITTER_POSITION_OPTIONAL:
```

Reason to raise:

- Exact body bytes, disassembly, decompilation, size, padding, caller route, source owner, source placement, field/global/helper names, and sibling polarity are now current and documented.
- The only old target-level blocker was blank C++ due to broader names; those names are now sufficiently resolved for exact child output.
- Generated empty-emitter state is stale and should be corrected through target/support docs plus validator flow.

Reason not lower:

- No unresolved target-local behavior, range, ownership, or C++ blocker remains.
- The exact target is a simple two-state mutator with one known caller and no nested source dependencies.

Reason not `95+`:

- Exact original source spelling for `m_iconPaneReducedMode`, `m_showAllIcons`, and inherited invalidation declaration is inferred, not symbol-proven.
- Final full class declaration/header placement remains broader work.
- Broader `IconsPaneCore` still has unrelated table/raw-dispatch caveats that affect class/file final audit but not this exact child.

Score-improvement attempt:

- Blank C++ blocker: resolved by rechecking current code-entry rule, sibling reports, generated output, and exact target MCP evidence.
- Field/global/helper names: resolved to best-supported source-facing names with rejected alternatives.
- Caller route: revalidated from current MCP caller instructions, including control id `6` and branch polarity.
- Range/padding: revalidated with `lookup_funcs`, `get_bytes`, and `xrefs_to`.
- Hidden route concern: checked with VA/RVA `find_bytes` patterns; no pointer route found.

## Recommended Target Doc Changes

Target path: `by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md`

After supervisor acceptance:

- Update metadata to `COMPLETION:91` and `CONFIDENCE:92`; keep owner/emitter/reconstructability unchanged.
- Insert the exact formal C++ block from this report.
- Update `Item Summary` to:

```text
`IconsPane::ShowReducedIcons` switches from all-icons mode to reduced mode by persisting reduced-mode byte `1`, clearing `m_showAllIcons`, and invalidating bounds.
```

- Update behavior to use source-facing names:
  - guard on `m_showAllIcons`;
  - write `g_pConfig->m_iconPaneReducedMode = 1`;
  - set `m_showAllIcons = false`;
  - call `InvalidateRect(&m_bounds)`;
  - return without writes when already reduced.
- Add current MCP evidence:
  - session `80de0a67`;
  - `sub_4CF2D0`, size `0x26`;
  - exact bytes and unique signature;
  - target disassembly and decompilation;
  - padding `0x004cf2f6-0x004cf300` is ten `0xcc` bytes with no xrefs;
  - caller `0x0053dee0` inside `sub_53DDB0`;
  - OptionPane control id `6` branch polarity;
  - no VA/RVA pointer hits for target start;
  - `int_convert.py` constants.
- Replace stale reconstruction note that final C++ remains blank due to broader names. The target now has first-draft C++ readiness; broader declaration spelling remains only a score cap.
- Add rejected alternatives: raw `dword_67A7C8`, raw `this+0xf8`, raw virtual-call syntax, no-arg invalidation, and blank formal C++.
- Add a 2026-06-26 B004 change entry with before/after score and evidence summary.

## Recommended Support Doc Changes

### `by-class/IconsPane.md`

- Update the [UID:0002T0] method row to state that the child now emits formal first-draft C++.
- Update source-quality/autogen notes so [UID:0002T0] is no longer listed as blocked by blank-C++/field/global/invalidation-helper wording.
- Add the current MCP evidence summary: exact body bytes, caller at `0x0053dee0`, no VA/RVA pointer route, `m_showAllIcons`, `g_pConfig->m_iconPaneReducedMode`, `m_bounds`, and inherited `InvalidateRect`.
- Keep class-level raw-dispatch, `0x004cf74b-0x004cf7d0` gap, action-helper names, and TabPane grouping caveats scoped to broader class work.
- No class-level C++ block is required.

### `by-file/IconsPane.md`

- Update proposed contents/behavior notes so [UID:0002T0] is recorded as formal first-draft C++ under the `IconsPane.cpp` source route.
- State that `ShowReducedIcons` persists reduced mode `1`, clears `m_showAllIcons`, and invalidates `m_bounds`.
- Preserve file-level raw-dispatch/gap/action-helper/TabPane grouping caveats.
- No file-level C++ block is required.

### `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md`

- Update the [UID:0002T0] child row/status note to say exact child C++ is now present.
- Update behavior/data notes with the reduced-mode transition and sibling polarity.
- Preserve marker-only aggregate C++. Do not paste the method body into the aggregate.

### No required changes to `g_pConfig`, `g_pIconsPane`, or `OptionPane`

The current support docs already document the relevant `+0x28de32` and control-id-6 facts at sufficient detail. They may be cross-linked if the supervisor wants support-sync wording, but this report does not require metadata or C++ changes in those pages.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` or tracker edit is required.

Do not write rows into validator-owned generated reports. After accepted implementation and scoped validators, generated `-ag-*` coverage/tracker state should refresh through validator and executed-report lifecycle commands.

## Open Questions With Attempted Resolution

- Exact original `Config` member spelling: no original symbol proof found. Current best name is `m_iconPaneReducedMode`, supported by target/sibling polarity and config docs. This remains a score cap, not a C++ blocker.
- Exact original return type: decompiler shows `int`, but no caller uses a return value and the no-change branch returns an undefined temporary. Source-facing type should be `void`.
- Boolean assignment spelling: use `m_showAllIcons = false` for the runtime bool and `g_pConfig->m_iconPaneReducedMode = 1` for the persisted byte. This preserves byte polarity while keeping source shape readable.
- Final `IconsPane` class declaration and header grouping: broader class/file polish, not a blocker for this exact child.
- Generated tracker/coverage state after implementation: scoped validators refreshed generated state through command `000000002964`; by-memory coverage now reports [UID:0002T0] as `91/92` and `emits_code:true`, and the generated research tracker source row now reports `91/92` with report count still `0` until supervisor execution.

No remaining open question prevents the recommended target-level score or formal first-draft C++.

## Validator Results

Implementation callback validators, run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| Command | command_id | command_timestamp | Exit | ok | Generated refresh / side effects |
| --- | --- | --- | --- | --- | --- |
| `python .\tools\validator.py --mode file --file by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md --apply --queue-timeout 240` | `000000002961` | `2026-06-26T16:43:51-04:00` | `0` | `1` | `generated_refresh: deferred`; validator updated `tools/validator.ini`, completion `91`, confidence `92`, canonical owner/emitter registry, C++ block hash, UID link target annotations, reference index, and projected stats. |
| `python .\tools\validator.py --mode file --file by-class/IconsPane.md --apply --queue-timeout 240` | `000000002962` | `2026-06-26T16:43:58-04:00` | `0` | `1` | `generated_refresh: deferred`; projected stats update. |
| `python .\tools\validator.py --mode file --file by-file/IconsPane.md --apply --queue-timeout 240` | `000000002963` | `2026-06-26T16:44:09-04:00` | `0` | `1` | `generated_refresh: deferred`; projected stats update. |
| `python .\tools\validator.py --mode file --file by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md --apply --queue-timeout 240` | `000000002964` | `2026-06-26T16:44:18-04:00` | `0` | `1` | `generated_refresh: deferred`; projected stats update. |

Generated refresh follow-up:

- `python .\tools\validator.py --queue-status` returned command `000000002965` at `2026-06-26T16:44:49-04:00`, exit `0`, with `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 0`, and `processing generated refresh jobs: 0`.
- Generated headers for `auto-generated/NexusTK/ui/panels/IconsPane.cpp`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/-ag-research-tracker.md` show `validator-command-id: 000000002964`, `validator-refreshed-at: 2026-06-26T16:44:18-04:00`, and `validator-refresh-source: deferred-generated-refresh`.
- `auto-generated/NexusTK/ui/panels/IconsPane.cpp` now contains [UID:0002T0] `void IconsPane::ShowReducedIcons()` with `g_pConfig->m_iconPaneReducedMode = 1`, `m_showAllIcons = false`, and `InvalidateRect(&m_bounds)`.
- `auto-generated/-ag-coverage-report-by-memory.md` now reports [UID:0002T0] as `emits_code:true`, `91%`, `very-strong`, updated `2026-06-26 16:43:52`.
- `auto-generated/-ag-research-tracker.md` now reports the source row as `91/92`, average `91.5`, report count `0`; the report count remains expectedly unchanged until the supervisor runs `execute_report`.
- Generated/project-level/tool-state changes were validator-owned side effects only; no generated, project-level, coverage-report, validator/tool state, or IDA DB file was manually edited.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B004/research/0002T0-IconsPaneShowReducedIcons-source-quality.md`

Modified:

- `by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md`
- `by-class/IconsPane.md`
- `by-file/IconsPane.md`
- `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md`
- `tools/leaser/Agents/Agent-B004/research/0002T0-IconsPaneShowReducedIcons-source-quality.md`

Validator-owned/generated side effects observed:

- `tools/validator.ini`
- `project-level/-auto-completion-stats.md`
- `auto-generated/NexusTK/ui/panels/IconsPane.cpp`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/-ag-research-tracker.md`

Renamed:

- None.

Report execution:

- Not run by B004. The supervisor runs `tools/validator.py execute_report ... --apply` after claim-by-claim verification.

## Follow-Up Actions

- Supervisor after verification: execute the report through validator lifecycle, expected form `python .\tools\validator.py execute_report B004 0002T0-IconsPaneShowReducedIcons-source-quality.md 0002T0 --apply`.
- No B004 target-local implementation item remains unapplied.

## Confidence

- Recommendation confidence: strong.
- Score confidence: strong for `91/92`; not final-audit.
- Remaining uncertainty: exact original spelling of inferred source-facing names and broader final `IconsPane` declaration/header grouping.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor callback accepted this report for implementation on 2026-06-26 and updated `goal.md` with exact implementation scope.
- [x] Target doc `by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md`: update metadata to `91/92`, keep owner/emitter/reconstructable unchanged, insert exact formal C++ block, update item summary/status/behavior/evidence/reconstruction notes/score rationale/change log at report-level detail. Proof: target header now has `COMPLETION:91`, `CONFIDENCE:92`, unchanged `CANONICAL_OWNER:00006B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006B`, and formal `void IconsPane::ShowReducedIcons()` block.
- [x] Support doc `by-class/IconsPane.md`: update [UID:0002T0] method row and source-quality/autogen notes to record formal first-draft C++ and current MCP evidence; preserve broader class caveats. Proof: method row, source-quality bullet, Autogen Status, and 2026-06-26 B004 change entry updated; class-level raw-dispatch/gap/action-helper/TabPane caveats remain.
- [x] Support doc `by-file/IconsPane.md`: update proposed contents/behavior/data caveats/change log to record [UID:0002T0] as formal first-draft C++ under `IconsPane.cpp`; preserve broader file caveats. Proof: Proposed Contents, Behavior Notes, Data Caveats, and 2026-06-26 B004 change entry updated; file-level raw-dispatch/gap/action-helper/TabPane caveats remain.
- [x] Support doc `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md`: update [UID:0002T0] child row/status/behavior notes while preserving marker-only aggregate C++. Proof: child row, Behavior Summary, Data Issues, and 2026-06-26 B004 change entry updated; aggregate `RECONSTRUCTION_CPP` still contains only the marker comment.
- [x] Current target state and actual evidence checked recorded: MCP session `80de0a67`, exact bytes, disassembly, decompilation, caller route, padding, pointer-negative checks, int-convert constants, generated stale state, and support docs. Proof: target page Evidence and Reconstruction Notes now record these facts; generated stale state is superseded by validator refresh notes in this report.
- [x] Metadata/score changes to apply: [UID:0002T0] `COMPLETION:86 -> 91`, `CONFIDENCE:88 -> 92`; owner/emitter/reconstructable unchanged. Proof: target validator command `000000002961` reported `completion_update 91`, `confidence_update 92`, and canonical/autogen registry updates preserving [UID:00006B].
- [x] Score-limiting blockers researched to resolution: blank C++ gate, field/global/helper names, caller route, source placement, range/padding, hidden pointer route, and sibling polarity. Proof: target Reconstruction Notes and Score Rationale record superseded blank-C++ blocker, accepted source-facing names, caller/padding/pointer-negative evidence, and remaining broader score caps.
- [x] Owner/emitter/reconstructable changes to apply: none; explicitly preserve `CANONICAL_OWNER:00006B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006B`. Proof: target metadata unchanged for those fields and validator command `000000002961` kept canonical owner/emitter route through [UID:00006B].
- [x] Split/rename/new-child changes to apply: none. Proof: no files were renamed or created outside this report; target Range/Score notes still say no split is needed.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes: document source placement under [UID:0000JZ] and optional IDA rename/comment recommendations only; do not edit IDA DB. Proof: target/support docs record source placement through [UID:0000JZ]; no IDA DB edits were made.
- [x] First-draft C++ to apply: exact `void IconsPane::ShowReducedIcons()` block from this report. Proof: target formal block and generated `auto-generated/NexusTK/ui/panels/IconsPane.cpp` contain the accepted method body.
- [x] Exact target/support doc facts to incorporate at report-level detail, including rejected alternatives and negative evidence. Proof: target page records rejected raw labels, raw virtual-call syntax, no-argument invalidation, and blank C++; support pages carry current MCP evidence and scoped caveats.
- [x] Historical/stale assumptions to preserve or supersede: old blank-C++/broader-name blocker is superseded for this exact child; generated tracker/coverage rows are stale until validator refresh. Proof: target Reconstruction Notes supersede blank C++; generated coverage/tracker headers now show command `000000002964`, with coverage row refreshed and tracker report count still pending supervisor execution.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: generated tracker and generated C++ were read as tool-state, not authority; old raw labels kept only as search aliases. Proof: target retains raw labels only in evidence/rejected-alternative context; no Wave2/Wave3 generated names were used in formal C++.
- [x] Open questions to close or document as evidence-backed unresolved: original Config/member spelling, source return type, boolean assignment style, final class declaration, and generated stale state. Proof: Open Questions section updated; return type and boolean spelling resolved for code, exact original spelling/class declaration documented as score caps, generated stale state refreshed by validators.
- [x] Validators to run after implementation: four scoped file validators listed in `Validator Results`. Proof: commands `000000002961` through `000000002964` all exited `0` with `ok: 1`.
- [x] Generated report refresh expected through validator/executed-report flow; no manual coverage/tracker text required. Proof: generated headers now show command `000000002964`; no manual coverage/tracker text was applied.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: current `goal.md` assignment id `B004-implement-0002T0-icons-pane-show-reduced-icons-source-quality-20260626` accepts this report for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: all four accepted by-* docs were edited and validated; see `Changed Files` and `Validator Results`.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with reason. Proof: [UID:0002T0] score and C++ block applied; owner/emitter/reconstructable intentionally unchanged; no split/rename/new child required.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/support docs preserve/supersede the blank-C++ blocker and record rejected raw names, pointer-negative evidence, padding, and broader class/file caveats.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: this report and target docs record exact-original spelling/final declaration as broader score caps and not target-local blockers.
- [x] Validators run and results recorded with command, `command_id`, `command_timestamp`, exit code, `ok` count, generated-refresh state, and side effects. Proof: table above records all four scoped validators and queue-status/generated-header follow-up.
- [x] Leases taken only for immediate edit/validator batch and released immediately; release/expiry proof recorded. Proof: `python .\tools\leaser\leaser.py B004 lease ...` returned `Success` for all four by-* docs before edit; after validators, `unlease` reported `Rejected[No active lease]` for each path and `tools/leaser/Agents/current_leases.md` showed `No active leases`, so no B004 lease remains.
- [x] Generated report refresh completed by validator or explicitly deferred; no manual generated/project-level/coverage/tool/IDA DB edits. Proof: queue status command `000000002965` showed no queued/processing generated refresh jobs; generated headers show `validator-command-id: 000000002964`. Generated/project-level/tool-state side effects were validator-owned only.
- [x] Remaining unapplied accepted items listed with exact blocker, if any. Proof: none; no accepted item remains unapplied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0002T0-IconsPaneShowReducedIcons-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0002T0-IconsPaneShowReducedIcons-source-quality.md","timestamp":"2026-06-26T16:49:45","uid":"0002T0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
