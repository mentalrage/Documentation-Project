** TARGET-REPORT-UID:0001IJ **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0001IJ] ItemWhoInputPaneStateSetFlag Source-Quality Reanalysis

Agent: Agent-B001  
Assignment id: B001-report-0001IJ-item-who-input-pane-state-set-flag-20260626  
Mode: report-only research first  
Target: `by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md`  
Date: 2026-06-26

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0001IJ] as an exact source-authored item-target state-helper method owned and emitted by [UID:00006Y] `by-class/ItemWhoInputPaneState.md`, with the generated source route through [UID:0000OH] `by-file/TargetSelectionInputPanes.md`.
- Final disposition: source-quality names are now strong enough for first-draft formal C++ on this exact by-memory range. Use `ItemWhoInputPaneState::SetInputModeFlag(bool active)` as the source-facing method name, and `m_active` as the item-side active/input-mode byte field at offset `+0xfa`.
- Required action if accepted: update the target/support docs at report-level detail, raise the target from `85/88` to `88/90`, insert the formal C++ block below, update item-state support docs to match the accepted [UID:0001II] sibling standard, and refresh generated output through normal validators. Do not manually edit generated reports or coverage reports.
- Confidence: high for behavior, range, xrefs, owner/emitter route, sibling relationship, and C++ body; medium-high for exact original source spelling because no original symbol/PDB source name was recovered.

## Target

- Target UID: `0001IJ`
- Target path: `by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`
- Current generated-report row observed in generated reports: `76/86`, average `81.0`, stale versus live target metadata. This is generated-report lag, not target truth.
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:00006Y`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006Y`, blank `RECONSTRUCTION_CPP`.

## Current Target State

The current page already records the exact `0x0057d0a0-0x0057d0af` range, the `this+0xfa` byte store, empty callee list, 17 direct xrefs, item-use allocation guard, item-target teardown clears, sibling relation to [UID:0001II] `by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md`, and boundary padding. The current blocker is stale source quality: the page still says C++ is blank because final class/field/method names and inline-versus-private-method shape are not source-final.

This pass resolves that blocker for this exact target. The exact source spelling is not proven, but the accepted sibling, item-use caller, teardown callers, and support docs are strong enough to use inferred source-facing names in formal first-draft C++.

Related docs checked:

- `by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md`
- `by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md`
- `executed-b-agent-research/B006/0001II-SpellInputPaneStateSetFlag-source-quality.md`
- `by-class/ItemWhoInputPaneState.md`
- `by-class/SpellInputPaneState.md`
- `by-class/ItemWhoInputPane.md`
- `by-file/TargetSelectionInputPanes.md`
- `by-file/ItemActionInputPanes.md`
- `by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md`
- `by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md`
- `by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md`
- `by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md`
- `executed-b-agent-research/B013/0001L4-ItemWhoInputPane-source-quality.md`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`

## Supervisor Active Recheck

- The active instruction assigns only [UID:0001IJ] in report-only mode.
- No split execution or by-* implementation was authorized. No by-* docs, generated reports, validator state/cache, IDA DB, or coverage reports were edited.
- IDA MCP evidence was required and used. Endpoint `http://127.0.0.1:13337/mcp` was live; session `80de0a67` was active for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Read-only listener/process check before MCP calls showed `127.0.0.1:13337` listening under process `13684`, `idalib-mcp` process `17084`, and active worker Python process `26892`. No start/stop/restart/process-management actions were made.
- MCP `server_health` at 2026-06-26 reported `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and strings cache size `2067`.

## Inference Research Guidance Check

- Address adjacency was not used as ownership proof. The target sits inside the physical spell-inventory/new-spell-inventory executable island, but live xrefs show it is an item-target state helper called by the item-use launcher, item-target destructor paths, and shared spell/target constructor/destructor state-reset families.
- The accepted [UID:0001II] sibling is the project precedent for this exact setter shape: decompiler prints a byte/`char` helper, but formal source-facing C++ uses a `bool` `SetInputModeFlag(bool active)` signature because every observed caller passes `0` or `1` and the helper represents an active/input-mode flag.
- B013 ItemWho support docs already name the item-side field as `ItemWhoInputPaneState::m_active` / item-target input-mode flag and explicitly separate it from the file-scope [UID:0002A9] `TargetSelectionModeFlags` globals.
- IDA facts, documentation evidence, and inference are separated below.
- Stale generated C++ and generated report rows were checked only as generated refresh state; they were not used as authority for behavior or ownership.

## Evidence Checked

IDA MCP/session facts:

- `initialize`, `tools/list`, and `idb_list` succeeded.
- Current schema requires `database:'80de0a67'` on every IDB-backed tool call.
- Active worker session: `80de0a67`, filename `NexusTK.exe.i64`, `is_analyzing:false`, active worker PID `26892`.
- `server_health` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

Direct MCP checks:

- `lookup_funcs` for `0x0057d080`, `0x0057d0a0`, `0x0057d0b0`, accepted sibling `0x0057c430`, duplicate-pattern copy `0x0057eae0`, item callers `0x005a3e30`, `0x005aed40`, `0x005b7a20`, constructor-family callers `0x005adfd0`, `0x005ae380`, `0x005b0810`, `0x005b0b50`, `0x005b0e30`, `0x005b10c0`, `0x005b1310`, and scalar destructor-family callers `0x005b7c20`, `0x005b7cf0`, `0x005b7dc0`, `0x005b7e90`, `0x005b7f60`, `0x005b8030`, `0x005b8100`.
- `decompile` and `disasm` for `0x0057d0a0`.
- `decompile` and `disasm` for accepted sibling `0x0057c430`.
- `get_bytes` for `0x0057d097` size `41`, `0x0057c425` size `43`, and raw duplicate `0x0057eae0` size `16`.
- `xrefs_to` for `0x0057d0a0`, `0x0057c430`, and `0x0057eae0`.
- `callees` for `0x0057d0a0` and `0x0057c430`.
- `analyze_component` for both setters.
- `analyze_function` for `0x0057d0a0`.
- `find_bytes` for exact setter pattern `55 8B EC 8A 45 08 88 81 FA 00 00 00 5D C2 04 00`.
- Representative caller decompiles: `0x005a3e30`, `0x005aed40`, `0x005b7a20`, `0x005adfd0`, and `0x005b7e90`.

Numeric conversion:

- `python .\tools\int_convert.py 0xfa` returned decimal `250`.
- `python .\tools\int_convert.py 0x10` returned decimal `16`.
- These conversions are documented as Verified with `int_convert.py`.

## IDA MCP Facts

Target function:

- `lookup_funcs 0x0057d0a0` returned `sub_57D0A0`, size `0x10` (`16` decimal, Verified with `int_convert.py`), exclusive end `0x0057d0b0`.
- Decompilation is:

```text
char __thiscall sub_57D0A0(_BYTE *this, char a2)
{
  char result; // al

  result = a2; /*0x57d0a3*/
  this[250] = a2; /*0x57d0a6*/
  return result; /*0x57d0ac*/
}
```

- Disassembly is six instructions: `push ebp`, `mov ebp, esp`, `mov al,[ebp+arg_0]`, `mov [ecx+0FAh],al`, `pop ebp`, `retn 4`.
- Stack frame records one byte argument at `[ebp+8]`; MCP disassembly reports return type `char` and argument type `char`.
- `callees 0x0057d0a0` is empty.
- `analyze_component` reports prototype `char __thiscall(_BYTE *this, char)`, size `16`, one basic block, complexity `1`, no strings, no shared globals, and no internal call-graph edges.
- `analyze_function 0x0057d0a0` reports the same decompilation, no strings, no constants, no callees, 17 callers, and one basic block with cyclomatic complexity `1`.
- Boundary bytes from `get_bytes 0x0057d097 size 41`: nine `0xcc` bytes precede the target; `0x0057d0a0-0x0057d0af` is the exact setter body; `0x0057d0b0` is `c3` (`nullsub_54`) followed by `0xcc` alignment bytes.

Accepted sibling:

- `lookup_funcs 0x0057c430` returned `sub_57C430`, size `0x10` (`16` decimal, Verified with `int_convert.py`), exclusive end `0x0057c440`.
- Decompilation and disassembly match the target shape: store the low-byte argument to `this[250]` / `[ecx+0FAh]` and return the same byte in `AL`.
- `callees 0x0057c430` is empty.
- Boundary bytes from `get_bytes 0x0057c425 size 43`: eleven `0xcc` bytes precede the sibling, then the exact setter body, then `sub_57C440`.
- The accepted sibling target now emits formal C++:

```cpp
bool SpellInputPaneState::SetInputModeFlag(bool active)
{
    m_spellInputActive = active;
    return active;
}
```

Duplicate byte-pattern facts:

- `find_bytes` for `55 8B EC 8A 45 08 88 81 FA 00 00 00 5D C2 04 00` returned exactly three matches: `0x0057c430`, `0x0057d0a0`, and `0x0057eae0`.
- `lookup_funcs 0x0057eae0` returned `Not a function`.
- `xrefs_to 0x0057eae0` returned zero xrefs.
- `get_bytes 0x0057eae0 size 16` returned the same raw setter bytes. This is a retained raw duplicate copy, not an owner/emitter route for [UID:0001IJ].

## Direct Xref / Caller Inventory

Live `xrefs_to 0x0057d0a0` returned 17 direct code xrefs and no overflow:

| Call site | Caller function | Meaning |
| --- | --- | --- |
| `0x005a3fda` | `0x005a3e30` / `sub_5A3E30` | Item-use inventory launcher reads `state+0xfa`, allocates/initializes `ItemWhoInputPane` only when clear, then calls this setter with `1`. |
| `0x005ae029` | `0x005adfd0` / `sub_5ADFD0` | Shared prompt constructor-family branch clears item state when `g_useEpfAssets` / `byte_66DA97` is `1`. |
| `0x005ae3d9` | `0x005ae380` / `sub_5AE380` | Same constructor-family branch pattern. |
| `0x005aedaf` | `0x005aed40` / `sub_5AED40` | `ItemWhoInputPane` non-deleting destructor clears item state. |
| `0x005b0869` | `0x005b0810` / `sub_5B0810` | Same constructor-family branch pattern. |
| `0x005b0ba9` | `0x005b0b50` / `sub_5B0B50` | Same constructor-family branch pattern. |
| `0x005b0e89` | `0x005b0e30` / `sub_5B0E30` | Same constructor-family branch pattern. |
| `0x005b1119` | `0x005b10c0` / `sub_5B10C0` | Same constructor-family branch pattern. |
| `0x005b1369` | `0x005b1310` / `sub_5B1310` | Same constructor-family branch pattern. |
| `0x005b7a96` | `0x005b7a20` / `sub_5B7A20` | `ItemWhoInputPane` scalar deleting destructor clears item state. |
| `0x005b7c80` | `0x005b7c20` / `sub_5B7C20` | Scalar deleting destructor branch clears item state. |
| `0x005b7d50` | `0x005b7cf0` / `sub_5B7CF0` | Scalar deleting destructor branch clears item state. |
| `0x005b7e20` | `0x005b7dc0` / `sub_5B7DC0` | Scalar deleting destructor branch clears item state. |
| `0x005b7ef0` | `0x005b7e90` / `sub_5B7E90` | SpellString scalar deleting destructor clears item state on the item-mode branch. |
| `0x005b7fc0` | `0x005b7f60` / `sub_5B7F60` | Scalar deleting destructor branch clears item state. |
| `0x005b8090` | `0x005b8030` / `sub_5B8030` | Scalar deleting destructor branch clears item state. |
| `0x005b8160` | `0x005b8100` / `sub_5B8100` | Scalar deleting destructor branch clears item state. |

Live `xrefs_to 0x0057c430` returned 14 direct code xrefs and no overflow. The item-side target has three extra item-specific callers absent from the spell sibling: `0x005a3e30`, `0x005aed40`, and `0x005b7a20`.

Representative caller decompiles:

- `0x005a3e30` reads `*(sub_4B85F0(unk_67A874,3)+250)` at `0x005a3efb`, allocates `268` bytes through `sub_4F4AA0(268)` only when that byte is clear, initializes an `ItemWhoInputPane`, stores the selected item slot at object `+0x108`, updates/highlights `unk_69BF24`, then calls `sub_57D0A0(state,1)` at `0x005a3fda`. The caller assigns the low-byte return into its own return path, so the helper's return value is observable for the set-to-`1` path.
- `0x005aed40` restores `ItemWhoInputPane` vtables, reconciles saved target globals, fetches GeneralPurposePanel child index `3`, calls `sub_57D0A0(state,0)` at `0x005aedaf`, then runs `LineInputPane` cleanup.
- `0x005b7a20` repeats the item destructor cleanup in a scalar deleting destructor wrapper, calls `sub_57D0A0(state,0)` at `0x005b7a96`, then handles delete flags.
- `0x005adfd0` writes `SpellStringInputPane` vtables, tests `byte_66DA97`, calls item setter `sub_57D0A0(child,0)` on the `== 1` branch at `0x005ae029`, and calls accepted sibling spell setter `sub_57C430(child,0)` on the other branch at `0x005ae037`.
- `0x005b7e90` repeats the same item-vs-spell branch inside a scalar deleting destructor before base cleanup/free handling.

## Heuristic / Inference Reanalysis And Validation

### Exact Setter Role

Direct fact: [UID:0001IJ] is a 16-byte (`0x10`, Verified with `int_convert.py`) `thiscall` byte setter. It stores the argument byte to offset `+0xfa` (`250` decimal, Verified with `int_convert.py`) and returns that same byte in `AL`. It has no callees, strings, globals, branches, or internal data flow beyond the one field write.

Inference: source-level `bool` is the right formal C++ surface for this exact target, matching accepted sibling [UID:0001II]. Every live direct caller passes `0` or `1`; the primary item-use caller tests the same byte as an active guard before allocating the target-selection pane; item-target destructor paths clear it with `false`; and sibling support has already accepted `SetInputModeFlag(bool active)` for the paired helper. The report must still preserve the raw ABI fact that IDA prints a `char`/low-byte return and that the target returns the assigned byte in `AL`.

Rejected alternatives:

- `void` setter: rejected because the item-use caller at `0x005a3e30` assigns the low-byte return from `sub_57D0A0(state,1)` into its own return path. The formal body should return `active`.
- Raw `char ItemWhoInputPaneState::SetInputModeFlag(char active)`: behaviorally close, but weaker source-quality than the accepted sibling and all observed 0/1 callsites. Keep the raw byte return in prose, not as the source-facing formal signature.
- Raw `sub_57D0A0` / `_BYTE *this`: rejected for final C++ because source-quality reconstruction should not retain decompiler labels or raw pointer types when behavior and owner are resolved.
- Standalone free helper: rejected because all live xrefs pass a state object in `ecx`, and owner/emitter routing already supports a class method.

### Field And Method Source-Facing Names

Recommended method: `ItemWhoInputPaneState::SetInputModeFlag(bool active)`.

Evidence:

- Existing target and class docs already use `SetInputModeFlag` as the working method name.
- Accepted sibling [UID:0001II] uses `SpellInputPaneState::SetInputModeFlag(bool active)`.
- Shared constructor/destructor branches choose item or spell state helpers for the same operation after fetching GeneralPurposePanel child index `3`.
- Item-use allocation uses the byte as a mode/active guard and then sets it to `1`, while item-target teardown clears it to `0`.

Recommended field: `m_active`.

Evidence:

- B013 ItemWho reanalysis already names the item-side `+0xfa` byte as `ItemWhoInputPaneState::m_active` / item-target input-mode flag.
- The field is item-side and short-lived active state, unlike the spell sibling field where B006 accepted the more specific `m_spellInputActive`.
- `m_active` avoids confusing this object field with file-scope `s_selectObjectTargetModeActive` / `s_targetObjectTargetModeActive` in [UID:0002A9].

Rejected alternatives:

- `m_itemWhoActive`: acceptable as a descriptive alias, but weaker than the already-incorporated B013 `m_active` wording and not needed to distinguish within `ItemWhoInputPaneState`.
- `m_pendingInput`: weaker for the item-side launcher because the byte gates whether the active `ItemWhoInputPane` prompt already exists.
- `TargetSelectionModeFlags` or any global flag name: rejected because MCP and support docs prove this is object-relative `this+0xfa`, not an absolute `.data` flag.

### Sibling Relation

[UID:0001II] is the direct accepted sibling: same 16-byte body, same `+0xfa` offset, same no-callee shape, same constructor/destructor branch family, same raw duplicate pattern, and same source-facing method name. The differences are meaningful:

- Item target [UID:0001IJ] has 17 xrefs.
- Spell sibling [UID:0001II] has 14 xrefs.
- The three item-only xrefs are the item-use launcher set-to-`1`, the ordinary item destructor clear-to-`0`, and the item scalar deleting destructor clear-to-`0`.
- The item-use set-to-`1` caller is the strongest source-facing proof that this field is the active guard for the item-target prompt.

The accepted sibling C++ standard should be mirrored with the item-specific field name:

```cpp
bool ItemWhoInputPaneState::SetInputModeFlag(bool active)
{
    m_active = active;
    return active;
}
```

### Owner And Emitter Support

Keep:

```text
CANONICAL_OWNER:00006Y
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00006Y
```

Rationale:

- [UID:00006Y] `ItemWhoInputPaneState` clears the class-owner gate at `85/88`.
- [UID:00006Y] emits through [UID:0000OH] `TargetSelectionInputPanes`, which has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`, `CANONICAL_OWNER:FILE`, and current scores `89/85`.
- `auto-generated/-ag-class-coverage.md` confirms [UID:00006Y] routes to `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`.
- `auto-generated/-ag-memory-coverage.md` confirms [UID:0001IJ] routes through [UID:00006Y] to `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`.
- Live call flow fetches GeneralPurposePanel child index `3`, chooses item versus spell state through `g_useEpfAssets` / `byte_66DA97`, and uses this helper as target-selection state. That is direct state-helper evidence, not merely physical address adjacency.

Rejected owners:

- [UID:0000KC] `ItemActionInputPanes`: rejected as owner. It launches inventory/item-use flows, but B013 and current support docs place `ItemWhoInputPane` implementation under TargetSelectionInputPanes; ItemActionInputPanes is a consumer/neighbor.
- [UID:00006X] `ItemWhoInputPane`: rejected as direct owner for this exact setter. `ItemWhoInputPane` consumes the state helper in destructor paths, but the setter belongs to the state class.
- [UID:0000O1] `SpellInventoryPane` / [UID:0000LU] `NewSpellInventoryPane`: rejected. Physical overlap is a parent split/index caveat, not ownership proof.
- `CANONICAL_OWNER:NONE`: rejected because the narrow state class and emitter chain are supported.

### Range / Split / Padding Analysis

No split or range repair is needed.

- `0x0057d080` is `sub_57D080`, size `0x17`.
- `0x0057d097-0x0057d0a0` is nine `0xcc` bytes.
- `0x0057d0a0-0x0057d0b0` is the exact setter body.
- `0x0057d0b0` is `nullsub_54`, size `0x1`, followed by alignment.
- The third duplicate raw body at `0x0057eae0` is not an IDA function and has zero xrefs, so it is not a child/split of this target.

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

Eligibility proof:

- `RECONSTRUCTABLE:TRUE`.
- `EMITTER_UIDS:00006Y` routes through [UID:00006Y] to [UID:0000OH] and generated `NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`.
- `(COMPLETION + CONFIDENCE) / 2 = (85 + 88) / 2 = 86.5`, above the active combined-score/emitter code-entry gate.
- The exact range is a complete one-method body with no child split, callees, strings, globals, unresolved control flow, or unresolved data flow.
- Source-facing names are resolved to an inferred but defensible method/field pair, parallel to accepted sibling [UID:0001II].

Exact formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:0001IJ]:

```cpp
bool ItemWhoInputPaneState::SetInputModeFlag(bool active)
{
    m_active = active;
    return active;
}
```

Why it preserves exact behavior for the current source call surface:

- Loads the active flag, stores it to the state object's `+0xfa` byte, and returns the same value.
- All observed callers pass `0` or `1`.
- The `0x005a3e30` set-to-`1` caller can still observe a true/low-byte `1` return.
- No callees, branches, globals, or side effects are omitted.
- The body stays inside the target range; it does not emit sibling, caller, class declaration, or physical spell-inventory parent code.

## Score And Metadata Recommendation

Current:

```text
COMPLETION:85
CONFIDENCE:88
CANONICAL_OWNER:00006Y
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00006Y
RECONSTRUCTION_CPP: blank
```

Recommended after accepted implementation:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:00006Y
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00006Y
RECONSTRUCTION_CPP: bool ItemWhoInputPaneState::SetInputModeFlag(bool active) ...
```

Why completion rises:

- The final source-facing field and method shape are no longer left as a blocker.
- Formal first-draft C++ can be inserted for the exact range.
- The report resolves the sibling relationship, bool/byte ABI prose, owner/emitter route, item-use set-to-`1` proof, teardown clear proof, duplicate raw-copy status, and generated refresh state.

Why not higher than `88/90`:

- Original source spelling is inferred, not recovered from PDB/source symbols.
- The broader `ItemWhoInputPaneState` class declaration/layout is not fully audited beyond this known helper and field.
- `95+` final-audit completeness/confidence is not appropriate without exhaustive class/source-file audit.

Score-limiting blockers researched:

| Blocker | Current research performed | Result |
| --- | --- | --- |
| Final field/method names | Live caller branch analysis, accepted sibling comparison, B013 support docs, target-selection/global-flag separation | Resolved to `SetInputModeFlag(bool active)` and `m_active`. |
| Owner/emitter uncertainty | Live xrefs, class/file docs, generated route markers, ItemActionInputPanes consumer check | Resolved: keep [UID:00006Y] owner/emitter, route through [UID:0000OH]. |
| Formal C++ readiness | Exact bytes, disasm/decompile, xrefs, callees, boundary bytes, duplicate-pattern search, code-entry gate | Resolved: insert formal C++ block above. |
| Sibling relation | Read accepted [UID:0001II] target/report/support implementation and live-compared xrefs/decompile/disasm | Resolved: paired helper, item-specific fanout, mirror sibling C++ style. |
| Physical spell-inventory adjacency | Current target/support docs plus live xrefs and duplicate raw copy status | Resolved: physical overlap does not reparent the exact state helper. |

No named blocker remains as future work for this target. Remaining uncertainty is limited to original source spelling and full class declaration shape, which score the page below final-audit level but do not block exact target C++.

## Recommended Target Doc Changes

Target path: `by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md`

Apply these if accepted:

- Update metadata to `COMPLETION:88`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:00006Y`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006Y`, and blank `EMITTER_POSITION_OPTIONAL`.
- Insert the exact formal C++ block:

```cpp
bool ItemWhoInputPaneState::SetInputModeFlag(bool active)
{
    m_active = active;
    return active;
}
```

- Replace "C++ remains blank because final class/field/method names and inline/private-method source shape are not source-final" with resolved C++ readiness rationale from this report.
- Update the Function table to use `ItemWhoInputPaneState::SetInputModeFlag(bool active)` and field `m_active` at `+0xfa` (`250` decimal, Verified with `int_convert.py`).
- Add live MCP provenance: session `80de0a67`, `server_health` ok, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `callees`, `analyze_component`, `analyze_function`, `get_bytes`, and `find_bytes` findings above.
- Preserve raw ABI evidence: IDA prints `char __thiscall`; the body stores one low-byte argument and returns the same low byte in `AL`. Explain that formal source-facing C++ uses `bool` because all observed callers pass `0` or `1` and accepted sibling [UID:0001II] uses the same method style.
- Preserve and expand caller table with all 17 live callsites above.
- Preserve item-specific behavior: `0x005a3e30` reads `state+0xfa`, allocates and initializes `ItemWhoInputPane` only when clear, then calls this setter with `1`; `0x005aed40` and `0x005b7a20` clear it with `0`; shared prompt constructors/destructors select this item setter on the `g_useEpfAssets` / `byte_66DA97 == 1` branch and accepted sibling spell setter otherwise.
- Add duplicate-pattern note: exact 16-byte setter body appears at `0x0057c430`, `0x0057d0a0`, and raw no-xref `0x0057eae0`; only the first two are current exact state-helper pages.
- Preserve owner/emitter/source route through `ItemWhoInputPaneState` and `TargetSelectionInputPanes`; reject `ItemActionInputPanes`, `ItemWhoInputPane`, `SpellInventoryPane`, `NewSpellInventoryPane`, and physical adjacency as owners.

No filename rename is recommended in this pass. The UID and path remain stable.

## Recommended Support Doc Changes

`by-class/ItemWhoInputPaneState.md`:

- Update the stale autogen/status wording that says C++ is intentionally blank because final state type/field names are unresolved under an old `90/90+` gate.
- Add accepted method/field wording: `ItemWhoInputPaneState::SetInputModeFlag(bool active)` and `m_active` at `+0xfa` (`250` decimal, Verified with `int_convert.py`).
- State that exact method C++ belongs on [UID:0001IJ], while the class page itself can keep a blank broad formal block because the full class declaration/header layout is not audited.
- Recommended support score after implementation: `COMPLETION:87`, `CONFIDENCE:90`. Keep `CANONICAL_OWNER:0000OH`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OH`.
- Mirror [UID:0000DM] `SpellInputPaneState` support language where applicable, but keep the item-specific field as `m_active`, not `m_spellInputActive`.

`by-file/TargetSelectionInputPanes.md`:

- Add a B001 item-side state bullet parallel to the existing B006 spell-side bullet: [UID:00006Y] owns `ItemWhoInputPaneState::SetInputModeFlag(bool active)`, and the `+0xfa` (`250` decimal, Verified with `int_convert.py`) object byte is `m_active`.
- Expand the `ItemWhoInputPaneState` proposed-contents row from the current short "equivalent state flag helper" wording to include the exact method name, field name, 17-xref live MCP evidence, item-use set-to-`1`, item/destructor clear-to-`0`, accepted sibling relation, duplicate-pattern status, and formal target C++ readiness.
- Preserve the source route through `NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`.
- Note that generated `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` currently has stale empty emitter markers for [UID:00006Y]/[UID:0001IJ] at `76/86`; refresh through validator-generated output, not by hand.

`by-file/ItemActionInputPanes.md`:

- No required ownership change. The current file already says `ItemWhoInputPane` is a target-selection pane launched by item-use dispatch but implemented under [UID:0000OH] `TargetSelectionInputPanes`, and lists `ItemWhoInputPaneState` only as a shared state helper.
- If implementation touches this page, add only a consumer note: `UseInventorySlotDispatch` launches/sets the item state helper, but [UID:0001IJ] remains owned by `ItemWhoInputPaneState` / `TargetSelectionInputPanes`.

`by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md`:

- Recommended small support sync: replace the open question that asks to confirm the source-level signature for `0x0057d0a0` target-pane activation with this report's resolution, `ItemWhoInputPaneState::SetInputModeFlag(bool active)`.
- Preserve that this LivingObjectPane dispatcher itself remains blank-C++ for its own unresolved helper/local naming; the [UID:0001IJ] signature is no longer a blocker for the state-helper call.

Already-present / no required edit proof:

- `by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md` already emits source C++ using `state->SetInputModeFlag(false)` and names [UID:0001IJ] as the state clear helper.
- `by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md` already documents the scalar deleting wrapper, item state clear through [UID:0001IJ], and no-source-C++ wrapper policy.
- `by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md` already states that ItemWho active state is object field `+0xfa` on [UID:00006Y], not the file-scope `byte_69BED9` / `byte_69BEDA` cluster.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` edit text is supplied or requested.

Generated report state observed:

- `auto-generated/-ag-research-tracker.md` still lists [UID:0001IJ] and [UID:00006Y] as `76/86`, average `81.0`.
- `auto-generated/-ag-coverage-report-by-memory.md` lists [UID:0001II] as `emits_code:true`, `88%`, updated 2026-06-26, but [UID:0001IJ] as `emits_code:false`, `76%`, updated 2026-06-24. This is stale relative to the target's current live metadata and this report recommendation.
- `auto-generated/-ag-memory-coverage.md` routes [UID:0001IJ] through [UID:00006Y] to `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`.
- `auto-generated/-ag-class-coverage.md` routes [UID:00006Y] to `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`.
- `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` currently contains accepted spell-side `SpellInputPaneState::SetInputModeFlag(bool active)` C++ and stale empty emitter markers for [UID:00006Y] and [UID:0001IJ].

Expected refresh path: after accepted by-* implementation and scoped validators, validator-owned generated reports/source should refresh. Do not edit generated files manually.

## Validator Baseline

No validators were run in this report-only pass because no by-* docs were edited. Recommended scoped validators after accepted implementation are listed in the implementation checklist below.

## Report-Only File Changes

Created report:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\0001IJ-ItemWhoInputPaneStateSetFlag-source-quality.md
```

No by-* docs, generated reports, generated C++, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md` were edited. No leases were used during this report-only pass.

## Implementation Tracking Checklist

- [x] Supervisor accepted this report for implementation in the 2026-06-26 callback for target UID `0001IJ`.
- [x] Leased only the immediate by-* edit batch before editing:
  `by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md`,
  `by-class/ItemWhoInputPaneState.md`,
  `by-file/TargetSelectionInputPanes.md`, and
  `by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md`.
  Proof: B001 lease command returned `Success` for all four files; after the first lease window expired before validation, B001 re-leased the same four files and again received `Success` for all four.
- [x] Released the by-* edit leases immediately after validators. Proof: B001 `unlease` command returned `Success` for all four by-* files, and the post-release `current_leases.md` check reported `No active leases.`
- [x] Updated target doc `by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md` with MCP session `80de0a67`, `server_health` ok, direct `lookup_funcs`/decompile/disasm/xref/callee/component/function facts, boundary bytes, duplicate-pattern evidence, resolved owner/name/C++ recommendation, and rejected alternatives.
- [x] Applied target metadata change: `COMPLETION:85 -> 88`, `CONFIDENCE:88 -> 90`; kept `CANONICAL_OWNER:00006Y`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006Y`, and blank `EMITTER_POSITION_OPTIONAL`. Validator proof: command `000000002053`, timestamp `2026-06-26T01:09:06-04:00`, exit `0`, `ok: 1`, recorded `completion_update 0001IJ ... 88`, `confidence_update 0001IJ ... 90`, and `canonical_owner_update 0001IJ ... 00006Y`.
- [x] Inserted exact formal target `RECONSTRUCTION_CPP CODE`:

```cpp
bool ItemWhoInputPaneState::SetInputModeFlag(bool active)
{
    m_active = active;
    return active;
}
```

- [x] Preserved raw ABI evidence in the target prose: IDA prints `char __thiscall`, stores one byte at `this+0xfa` / decimal `250`, and returns the assigned low byte in `AL`; formal source-facing C++ uses `bool` because every live caller passes `0` or `1` and accepted sibling [UID:0001II] uses the same source method style.
- [x] Updated support doc `by-class/ItemWhoInputPaneState.md` with `SetInputModeFlag(bool active)`, `m_active`, current combined-score/emitter C++ gate wording, target C++ readiness, broad-class-C++ blank policy, and support score `87/90`. Validator proof: command `000000002054`, timestamp `2026-06-26T01:09:13-04:00`, exit `0`, `ok: 1`, recorded `completion_update 00006Y ... 87`, `confidence_update 00006Y ... 90`, and `canonical_owner_update 00006Y ... 0000OH`.
- [x] Updated support doc `by-file/TargetSelectionInputPanes.md` with item-side state helper details parallel to the accepted spell-side B006 section, preserving the `NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` route. Proof: file now records [UID:00006Y] ownership of `ItemWhoInputPaneState::SetInputModeFlag(bool active)`, `m_active` at `+0xfa`, 17-xref MCP evidence, item-use set-to-`1`, item/destructor clear-to-`0`, accepted sibling relation, duplicate-pattern status, and formal target C++ readiness. Validator proof: command `000000002055`, timestamp `2026-06-26T01:09:21-04:00`, exit `0`, `ok: 1`; pre-existing missing-ref UID warnings remain but the scoped file validated.
- [x] Confirmed `by-file/ItemActionInputPanes.md` remains a consumer/launcher only, not owner. No edit made because the target, class, TargetSelectionInputPanes support route, and UseInventorySlotDispatch consumer note now carry the accepted owner/consumer split without needing another support-file touch.
- [x] Updated `by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md` to remove the unresolved `0x0057d0a0` signature caveat. Proof: page now names [UID:0001IJ] as `ItemWhoInputPaneState::SetInputModeFlag(bool active)`, records this caller's set-to-`true` use, and keeps this broad helper's own C++ scope blank pending constructor/local naming only. Validator proof: command `000000002056`, timestamp `2026-06-26T01:09:28-04:00`, exit `0`, `ok: 1`; existing missing-ref UID/target warnings remain.
- [x] Confirmed already-present support in `by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md`: formal C++ already calls `state->SetInputModeFlag(false)`, and evidence notes the state-clear call through [UID:0001IJ]. No edit needed.
- [x] Confirmed already-present support in `by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md`: page documents the scalar deleting wrapper, item state clear through [UID:0001IJ], and no-source-C++ wrapper policy. No edit needed.
- [x] Confirmed already-present support in `by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md`: page already states ItemWho active state is object field `+0xfa` on [UID:00006Y], not the file-scope `byte_69BED9` / `byte_69BEDA` cluster. No edit needed.
- [x] Preserved negative evidence: no callees, no strings, no shared globals, no owner proof from physical spell-inventory/new-spell-inventory adjacency, no xrefs to raw duplicate `0x0057eae0`, and no `ItemActionInputPanes` ownership.
- [x] No manual edits were made to generated reports, generated C++, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md`. Validator-owned registry/reference/stat updates and deferred generated refresh state were produced only by scoped `validator.py --apply` runs.
- [x] Ran scoped validators from `source-3/project-documentation` for every edited by-* file:

> Executable block R001 was removed from this report and preserved verbatim in [0001IJ-ItemWhoInputPaneStateSetFlag-source-quality-removed.md](0001IJ-ItemWhoInputPaneStateSetFlag-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- [x] Validator record:
  - `by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md`: command_id `000000002053`, timestamp `2026-06-26T01:09:06-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
  - `by-class/ItemWhoInputPaneState.md`: command_id `000000002054`, timestamp `2026-06-26T01:09:13-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
  - `by-file/TargetSelectionInputPanes.md`: command_id `000000002055`, timestamp `2026-06-26T01:09:21-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`; known pre-existing `missing_ref_uid` warnings persisted.
  - `by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md`: command_id `000000002056`, timestamp `2026-06-26T01:09:28-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`; known pre-existing `missing_ref_uid` / `missing_ref_target` warnings persisted.
- [x] Files changed by this implementation: target `by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md`, support `by-class/ItemWhoInputPaneState.md`, support `by-file/TargetSelectionInputPanes.md`, support `by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md`, and this report checklist.
- [x] No C++ removal/no-code proof applies to this UID callback: the accepted implementation required exact formal C++ insertion for [UID:0001IJ], and the formal target block now contains only that method body.
- [x] Generated report/source rows remain validator/generator-owned. Any stale generated rows or old empty emitter markers should refresh through validator/generator only; no manual generated-output edit was made.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001IJ-ItemWhoInputPaneStateSetFlag-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0001IJ-ItemWhoInputPaneStateSetFlag-source-quality.md","timestamp":"2026-06-26T01:14:37","uid":"0001IJ"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001IJ-ItemWhoInputPaneStateSetFlag-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001IJ-ItemWhoInputPaneStateSetFlag-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001IJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
