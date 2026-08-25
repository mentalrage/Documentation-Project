*** UID:00006Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone ItemWhoInputPaneState class declaration is emitted here; [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md) emits SetInputModeFlag.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ItemWhoInputPaneState

## Status

- Confidence: strong for the known helper behavior, caller mode semantics, target-selection ownership, and source-facing method/field names; medium-high for full class declaration/layout because only the known state helper has been audited.
- Likely source file: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), with [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) as a consumer/launcher rather than owner.
- Address range: [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md).
- Autogen status: reconstructable state helper class attached to [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md). The exact method C++ now belongs on [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md); this broad class page intentionally keeps its formal C++ block blank because a complete class declaration/header-layout audit has not been performed.
- Current C++ gate: the exact by-memory method clears the combined-score/emitter route for first-draft method C++, but this support page is not a substitute for a full class declaration. Do not revive the old numeric-only blank-C++ blocker wording for [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md).

## Class Purpose

`ItemWhoInputPaneState` stores the active/input-mode state for the item-target prompt. The known object byte is `m_active` at offset `+0xfa` (`250` decimal, Verified with `int_convert.py`) on the state object returned by `sub_4B85F0(dword_67A874, 3)` / GeneralPurposePanel child index `3`.

Item-target creation checks this byte before allocating an `ItemWhoInputPane`, sets it to `true` while the item-target prompt is active, and clears it through item-target teardown paths. The field is object-relative and distinct from [UID:0002A9][0x0069bed8-0x0069bee0.TargetSelectionModeFlags](by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md), whose file-scope globals belong to SelectObject/TargetObject keyboard-map modes.

B013 ItemWho reanalysis already named the item-side byte descriptively as `ItemWhoInputPaneState::m_active` / the item-target input-mode flag. B001 2026-06-26 reanalysis resolved the exact setter method name and formal source body by comparing live callers with accepted sibling [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md).

## Known Method And Field

| Method | Address | Field | Role |
| --- | --- | --- | --- |
| `bool ItemWhoInputPaneState::SetInputModeFlag(bool active)` | `0x0057d0a0-0x0057d0af` | `m_active` at `+0xfa` / decimal `250` (Verified with `int_convert.py`) | Stores the active flag byte and returns the assigned value. |

Exact formal C++ for the method belongs on [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md):

```cpp
bool ItemWhoInputPaneState::SetInputModeFlag(bool active)
{
    m_active = active;
    return active;
}
```

The class support page does not emit a broad class declaration yet. A complete class declaration would need a whole-class layout/header pass, including any inherited state object shape around the `+0xfa` field.

## Evidence Notes

- B001 2026-06-26 live MCP evidence used session `80de0a67`; `server_health` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- `lookup_funcs 0x0057d0a0` returned `sub_57D0A0`, size `0x10` (`16` decimal, Verified with `int_convert.py`), exclusive end `0x0057d0b0`.
- IDA decompilation remains `char __thiscall sub_57D0A0(_BYTE *this, char a2)`, assigning `this[250] = a2` at `0x0057d0a6` and returning the same byte at `0x0057d0ac`.
- Disassembly copies `[ebp+arg_0]` into `AL`, stores `AL` to `[ecx+0FAh]`, pops `ebp`, and returns with `retn 4`.
- The raw ABI is `char`; source-facing C++ is `bool` because every live direct caller passes `0` or `1`, the item-use caller observes the set-to-`1` return, and accepted sibling [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md) uses the same source method standard.
- `callees 0x0057d0a0` is empty; `analyze_component` reports one basic block, complexity `1`, no strings, no shared globals, and no internal call-graph edges.
- Current `xrefs_to 0x0057d0a0` returns 17 direct code xrefs and no overflow. The item-use path `0x005a3e30` reads `state+0xfa`, allocates a `0x10c`-byte `ItemWhoInputPane` only when the byte is clear, then calls `SetInputModeFlag(true)`.
- The item-target non-deleting destructor `0x005aed40` and scalar deleting destructor `0x005b7a20` call the setter with `false` after reconciling saved target globals.
- Shared spell/target constructors and destructors call this item-state setter when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` is `1`; the paired spell-state setter is used on the other branch.
- `get_bytes 0x0057d097 size 41` shows nine `0xcc` bytes before the setter, exact bytes `55 8b ec 8a 45 08 88 81 fa 00 00 00 5d c2 04 00`, `nullsub_54` at `0x0057d0b0`, and following alignment. No expanded range or child split is required.
- `find_bytes` for exact setter pattern `55 8B EC 8A 45 08 88 81 FA 00 00 00 5D C2 04 00` returns `0x0057c430`, `0x0057d0a0`, and raw no-xref `0x0057eae0`. Only the first two are active state-helper pages.

## Owner And Emitter Decision

Keep this class attached to [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md). The exact method page [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md) owns the function body through this class page, and this class page preserves the generated source route to `NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`.

Rejected owner routes remain:

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md): consumer/launcher only.
- [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md): consumer/destructor class only, not the state setter owner.
- `SpellInventoryPane` / `NewSpellInventoryPane`: physical address adjacency and parent split/index caveats, not source-owner proof.
- `CANONICAL_OWNER:NONE`: rejected because the state helper class and file emitter route are supported.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `87` | The class page records the known method, field name/offset, exact target C++ location, raw `char` ABI versus source-facing `bool` rationale, item-use set-to-`1`, destructor clear-to-`0`, shared item/spell branch family, sibling relation, duplicate raw-copy status, owner/emitter route, and why broad class C++ remains blank. It stays below `90` because only the one helper and field are audited, not a whole class declaration. |
| Confidence `90` | Confidence is supported by live MCP session `80de0a67`, exact by-memory setter evidence, 17 direct xrefs, caller semantics, accepted sibling comparison, B013 `m_active` naming, and the direct [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) source route. It remains below final-audit confidence because exact original class/member spelling and full layout are inferred rather than recovered from symbols. |

## Cross-References

- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md)
- [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md)
- [UID:0000DM][SpellInputPaneState](by-class/SpellInputPaneState.md)
- [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0002A9][0x0069bed8-0x0069bee0.TargetSelectionModeFlags](by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md)

## Changes

- 2026-06-29 B005 UID0000OH direct empty-emitter callback:
  - Score unchanged at `87/90`.
  - Summary/evidence: inserted the accepted formal no-standalone state-class marker with `[[CHILDREN]]` so the exact state-helper child still emits through this class. [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md) remains the exact source-emitting child for `ItemWhoInputPaneState::SetInputModeFlag(bool active)` under [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md).
- 2026-06-26 B001 accepted implementation callback:
  - Before: `COMPLETION:85`, `CONFIDENCE:88`, stale numeric-only blank-C++ wording, and unresolved state/method/field caveats.
  - After: `COMPLETION:87`, `CONFIDENCE:90`; owner/emitter [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), `RECONSTRUCTABLE:TRUE`, blank optional emitter position, and broad formal class C++ block remain unchanged.
  - Evidence: incorporated [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md) as `ItemWhoInputPaneState::SetInputModeFlag(bool active)` with `m_active` at `+0xfa` / decimal `250` (Verified with `int_convert.py`), raw `char __thiscall` ABI preservation, 17-xref live MCP session `80de0a67` evidence, accepted sibling [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md) comparison, duplicate pattern at `0x0057c430`, `0x0057d0a0`, and raw no-xref `0x0057eae0`, and the exact-method-C++ versus broad-class-declaration split.
- 2026-06-22 B013 ItemWho state-name sync: score unchanged; added source-facing `m_active` / item-target input-mode flag wording and clarified this object field is distinct from global target-selection mode flags.
- 2026-06-13 A001 refreshed low-score batch:
  - Before: `COMPLETION:76`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`; kept `CANONICAL_OWNER` and `EMITTER_UIDS` as [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md).
  - Evidence: live IDA MCP reconfirmed the `16`-byte (`0x10`, Verified with `int_convert.py`) single-block setter, current decompilation at `0x0057d0a6`, empty callee/internal call graph, 17 direct code xrefs, exact byte body, and padding/nullsub boundaries around `0x0057d0a0`. C++ remained blank at that time because the final source-facing state type and field name were not resolved under the older code-entry wording.
- 2026-06-07 A008 alias cleanup: normalized the item/spell state-selection `byte_66DA97` branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- 2026-06-03: Raised completion/confidence from `70/82` to `76/86`. Live IDA MCP reconfirmed `0x0057d0a0` as a `0x10`-byte pure `this+0xfa` setter with no callees; caller/decompile evidence documented the item-use allocation guard, active-prompt set-to-`1`, teardown set-to-`0`, and `byte_66DA97` branch that selects the paired spell or item state setter.
- 2026-06-02: Raised completion/confidence from `62/76` to `70/82`, marked the page reconstructable, and attached it to [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md). This used the exact setter memory page's IDA-recorded byte, caller, callee, and boundary evidence while keeping C++ blank because the final state declaration and field names were not source-quality yet.
