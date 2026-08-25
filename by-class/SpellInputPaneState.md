*** UID:0000DM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// SpellInputPaneState is declared by this page's formal H; [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md) emits the method body.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SpellInputPaneState
{
public:
    void SetInputModeFlag(bool active);

private:
    unsigned char m_opaquePrefix[0xfa];
    bool m_spellInputActive;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SpellInputPaneState

## UID0000O1 External-Helper Correction - 2026-08-22

The accepted member declaration is `void SpellInputPaneState::SetInputModeFlag(bool active)`. This page's formal H declares the class, method, and proven `m_spellInputActive` byte at `+0xfa` behind an opaque prefix; it does not invent names for the unaudited preceding layout. The exact body remains owned by [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md) and emits through this class into `TargetSelectionInputPanes.cpp`. The observed `AL` copy is compiler residue and does not establish a source-level return value. Physical overlap with legacy SpellInventoryPane is explicitly non-owning.

## Status

- Confidence: strong for helper behavior, caller mode semantics, field offset, target-selection ownership, the exact by-memory method CPP route, and the matching formal H member declaration; the prefix remains intentionally opaque because only one state helper is currently documented.
- Likely source file: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), emitted through `NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`, with [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) as a consumer/neighbor.
- Address range: [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md)
- Source-facing helper: `SpellInputPaneState::SetInputModeFlag(bool active)`
- Source-facing field: `m_spellInputActive` at offset `+0xfa` (`250` decimal, Verified with `int_convert.py`)
- Autogen status: reconstructable state helper class attached to [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md). This page emits the coherent class/member declaration through formal H and retains `[[CHILDREN]]` in formal CPP; exact by-memory [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md) emits the sole method body without duplication.

## Class Purpose

`SpellInputPaneState` is currently represented by one small helper, `SetInputModeFlag(bool active)`, which writes the spell input active byte at offset `+0xfa` (`250` decimal, Verified with `int_convert.py`) on the state object returned by `sub_4B85F0(dword_67A874, 3)`. Shared spell/target constructors and destructors choose this setter on the non-item branch of the [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` mode test, with the paired [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md) setter used when item-target mode is active.

The source-facing field name for the `+0xfa` byte on this spell-side helper is `m_spellInputActive`. The name is inferred, not symbol-recovered, but it is supported by the live branch pairing, the sibling item state active guard, and the legacy spell-inventory caveat. It is distinct from [UID:0002A9][0x0069bed8-0x0069bee0.TargetSelectionModeFlags](by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md), which documents file-scope SelectObject/TargetObject mode flags rather than this object field.

B007 2026-06-19 legacy spell inventory reanalysis remains an important caveat: inside [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md), legacy `SpellInventoryPane` code uses a local `+0xfa` pending/active spell-input byte. That supports the spell-input-active field semantics, but it is not a reparenting or source-name override for this exact state helper because live xrefs to `0x0057c430` come from shared state-helper constructor/destructor branch families rather than the legacy dispatcher.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `void SetInputModeFlag(bool active)` | `0x0057c430-0x0057c43f` | Stores `active` to `m_spellInputActive` at `this + 0xfa`; the low-byte register copy is compiler residue, not a source return. The exact method body is emitted by [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md). |

## Evidence Notes

- B006 live MCP session `80de0a67` confirmed `0x0057c430` as `sub_57C430`, a real `0x10`-byte (`16` decimal, Verified with `int_convert.py`) function with exclusive end `0x0057c440`. A callback recheck on 2026-06-26 confirmed the same session healthy for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- IDA decompilation/disassembly remains the exact setter shape: copy the byte argument through `AL` to `this[250]` / `[ecx+0xfa]`; the source-level disposition is `void` because no caller consumes a return value.
- `callees 0x0057c430` is empty; component analysis reports one basic block, complexity `1`, no strings, no shared globals, and no internal call-graph edges.
- Current `xrefs_to 0x0057c430` returns 14 direct code xrefs and no overflow: seven spell/target prompt constructor calls and seven scalar deleting destructor calls.
- Representative decompilation shows constructors such as `0x005adfd0` and `0x005ae380` call the item-state setter when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` is `1`, otherwise call this spell-state setter with `0` after fetching GeneralPurposePanel child index `3`.
- Representative scalar deleting destructors such as `0x005b7c20` through `0x005b8100` use the same branch before base cleanup and optional storage deletion.
- The exact memory page records the pure setter semantics, raw bytes `55 8b ec 8a 45 08 88 81 fa 00 00 00 5d c2 04 00`, empty callee list, 14-site xref table, boundary bytes, sibling comparison, duplicate pattern, and formal C++.
- Boundary review around `0x0057c425` shows eleven `0xcc` padding bytes before the setter, the exact 16-byte body, and `sub_57C440` immediately after. No expanded range or child split is required.
- [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md) is the item-target sibling with the same one-byte setter body at `0x0057d0a0`. Its exact memory page records 17 xrefs, including the item-use active guard at `0x005a3e30`, item-target teardown clears at `0x005aed40` and `0x005b7a20`, and the same shared constructor/destructor branch family.
- Exact 16-byte duplicate-pattern search found matches at `0x0057c430`, `0x0057d0a0`, and raw `0x0057eae0`. The raw `0x0057eae0` copy is not an IDA function and has zero xrefs to its start, so it is not an owner/emitter route for this class.
- Negative evidence preserved: no callees, no strings, no shared globals, no legacy dispatcher xrefs to `0x0057c430`, no xrefs to raw duplicate `0x0057eae0`, and no owner proof from physical spell-inventory adjacency alone.

## C++ Gate And Emission

Current reconstruction C++ code entry is allowed when a target is `RECONSTRUCTABLE:TRUE`, has a confirmed nonblank `EMITTER_UIDS` route that surfaces to generated output without a dead end, and `(COMPLETION + CONFIDENCE) / 2 > 85`. Older `90/90+` wording on this page was stale.

[UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md) now satisfies that gate after B006 implementation: it is `88/90`, reconstructable, owned/emitted by this class, and this class emits through [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md). The exact by-memory target contains the formal source-ready method body. This class page supplies the matching formal H declaration and proven `+0xfa` member while leaving the preceding unaudited layout opaque; it does not duplicate the method body.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `87` | The class page records the known helper, accepted source-facing method and field names, owner choice, source-layout caveat, exact memory evidence summary, sibling state helper, parent relationship, branch semantics that select spell-state versus item-state clearing, current live xref count, byte-boundary evidence, duplicate-pattern evidence, current C++ gate wording, and target C++ readiness. Completion remains below `90` because only one state helper is known and the final broader class declaration/layout/header shape has not been fully audited. |
| Confidence `90` | Confidence is supported by the exact by-memory setter page, B006 live MCP session `80de0a67`, byte-level evidence, 14 direct code xrefs, representative caller semantics, sibling helper comparison, duplicate no-xref raw-copy analysis, and a direct parent file already at `89/85`. Confidence is high for the helper and route; it remains below final-audit `95+` because the original source spelling and complete class declaration were inferred rather than recovered. |

## Cross-References

- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md)
- [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md)

## Changes

- 2026-08-23 B005 UID0000O1 header-route repair:
  - Replaced the invalid global `void SetInputModeFlag(bool active);` fragment with a formal `SpellInputPaneState` class declaration whose member signature exactly matches UID0001II and whose opaque prefix preserves the proven `m_spellInputActive` offset `+0xfa` without inventing preceding field names.
  - Superseded the 2026-06-29 no-standalone-declaration disposition. The exact child still owns the only method definition; this page now owns the required formal H class/member route.
- 2026-06-29 B005 UID0000OH direct empty-emitter callback:
  - Score unchanged at `87/90`.
  - Summary/evidence: inserted the accepted formal no-standalone state-class marker with `[[CHILDREN]]` so the exact state-helper child still emits through this class. [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md) remains the exact source-emitting child for `SpellInputPaneState::SetInputModeFlag(bool active)` under [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md).
- 2026-06-26 B006 source-quality implementation:
  - Before: `COMPLETION:85`, `CONFIDENCE:88`; stale autogen text cited an older `90/90+` code-entry gate and said final state type/field names were not source-quality.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:90`; kept `CANONICAL_OWNER:0000OH`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000OH`.
  - Evidence: incorporated [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md) source-quality resolution: `SpellInputPaneState::SetInputModeFlag(bool active)`, `m_spellInputActive` at `+0xfa` (`250` decimal, Verified with `int_convert.py`), MCP session `80de0a67` function/boundary/decompile/disasm/xref/callee/component facts, sibling comparison, duplicate raw no-xref copy, B007 legacy caveat, current combined-score/emitter C++ gate, and exact target C++ readiness.
- 2026-06-13 A001 refreshed low-score batch:
  - Before: `COMPLETION:76`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`; kept `CANONICAL_OWNER` and `EMITTER_UIDS` as [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md).
  - Evidence: live IDA MCP reconfirmed the `16`-byte (`0x10`, Verified with `int_convert.py`) single-block setter, current decompilation at `0x0057c436`, empty callee/internal call graph, 14 direct code xrefs, exact byte body, and padding/next-function boundary around `0x0057c430`. C++ remained blank at that time because the final source-facing state type and field name were not resolved.
- 2026-06-07 A008 alias cleanup: normalized the spell/item state-selection `byte_66DA97` branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- 2026-06-03: Raised completion/confidence from `70/82` to `76/86`.
  - Summary/evidence: live IDA MCP reconfirmed `0x0057c430` as a `0x10`-byte pure `this+0xfa` setter with no callees; caller/decompile evidence documented the 14-site spell/target constructor and destructor fanout plus the `byte_66DA97` branch that selects this spell-state setter versus the item-state sibling.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `68`, confidence `76`.
- Evidence: the page documents the exact helper behavior, field offset, IDA function size, and caller-family placement; completion stays limited because this is probably a state/layout helper rather than a standalone class and the final owner source is open.
- 2026-06-03: Raised completion/confidence from `68/76` to `70/82`, marked the page reconstructable, and attached it to [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md).
  - Evidence: [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md) records IDA-backed byte/decompile/caller/callee/boundary evidence, and [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md) documents the sibling state-helper pattern.
- 2026-06-21 B007 legacy SpellInventoryPane caveat:
  - Score unchanged at `85/88`.
  - Evidence: incorporated the stronger local interpretation from [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md): legacy `SpellInventoryPane` also uses a local pending/active input byte at `this+0xfa`, but that caveat does not replace this class route for [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md).
