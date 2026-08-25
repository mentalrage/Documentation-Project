*** UID:0000R8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
InterfaceEfxMgr *g_pInterfaceEfxMgr = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pInterfaceEfxMgr

## Status

- Confidence: very strong for exact storage, loader-zero state, singleton role, type/name, owner, complete seven-ref lifecycle, sole definition, and focused source route.
- Address: `0x0069b360`
- Exact storage: [UID:0002VQ][0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage](by-memory/0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage.md)
- IDA name: `dword_69B360`
- Source name: `g_pInterfaceEfxMgr`
- Owner class: [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md)

## Summary

`g_pInterfaceEfxMgr` is the sole typed source definition for the active [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md). The manager is created by [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) only in the older layout branch and owns persistent character, magic, and item interface effects.

This slot is the final feature singleton before the MainUiLayerSlots head triplet at `0x0069b364`. Keep `g_pInterfaceEfxMgr` with `InterfaceEfx`/`InterfaceEfxMgr` ownership rather than merging it into the generic layer-slot family.

## Evidence

- Exact physical payload is four loader-zero bytes, SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`; `0xffffffff` is a superseded historical claim.
- IDA xrefs show constructor publication writes at `0x004e9d4b/0x004e9d52`.
- Clear routes are raw ordinary-destructor `0x004e9ecf`, constructor-EH rollback `0x004ea060`, and scalar-wrapper `0x004ea0e2`.
- Additional reads include [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md), which calls the manager trigger method at `0x004e9ee0`.
- Live IDA MCP decompilation confirms singleton writes in the constructor and clears in the helper/destructor paths; `0x004e9ee0` remains the IDA-confirmed trigger helper.
- Historical Batch 039 described an initial `0xffffffff` dword. Current PE/raw/live-byte proof rejects that value and retains the old statement only as superseded provenance.
- Live IDA MCP on 2026-06-14 rechecked the same seven direct refs with no extra owners: `0x004b8805`, `0x004e9d4b`, `0x004e9d52`, `0x004e9ecf`, `0x004ea060`, `0x004ea0e2`, and `0x00504aeb`. The constructor at `0x004e9d00` remains a `0x178`-byte, 376 decimal byte (Verified with int_convert.py), `InitializeMainUiGraph`-called manager constructor; `0x004ea060` remains an 11-byte constructor EH singleton rollback clear; and the scalar deleting destructor at `0x004ea090` remains the delete-wrapper clear path.
- `0x004ea060` remains constructor-EH cleanup glue. Current raw-body proof distinguishes ordinary-destructor clear `0x004e9ecf` from scalar-wrapper clear `0x004ea0e2`.

## One-Definition And Source Order

- [UID:0002VQ][0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage](by-memory/0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage.md) is false/non-emitting and does not duplicate this definition.
- [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md) emits the complete class at position 10.
- This semantic definition emits at position 20.
- Constructor UID0004V0, destructor UID0004V1, trigger UID00018H, and OnTimer UID0004V2 follow at positions 30/40/50/60.
- Singleton publication and clears are compiler/base-template lowering and are intentionally absent from handwritten methods.

## Lifetime And Consumers

- Legacy MainMenuPane startup allocates `0x104` and constructs the manager.
- GeneralPurposePanel legacy switching reads the pointer and calls TriggerInterfaceEffect without a local null guard inside the established lifetime.
- MapPane legacy exit reads the pointer and invokes deleting virtual destruction.
- Current-layout/EPF branches do not construct or consume this legacy manager.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 92 | Exact storage/loader state, seven refs, typed definition, owner/emitter/position, startup/consumer/teardown lifetime, one-definition route, and historical corrections are complete. |
| Confidence | 94 | PE zero-fill, live bytes/value, exact xrefs, RTTI Singleton PMD, constructor/ordinary/scalar destruction, and current callers agree. |
| Parent | [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md) | The focused source route owns the manager class/global/method union and rejects duplicate physical emission or a speculative manager file. |

## Resolved Questions

- `g_pInterfaceEfxMgr` is the accepted source-facing descriptive name; `dword_69B360` remains only a historical raw-search alias.
- Source placement is the existing InterfaceEfx route. A separate manager file has no supporting boundary/debug/project evidence.
- Initializer is zero, matching loader state.

## Cross-References

- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md)
- [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md)
- [UID:0002VQ][0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage](by-memory/0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage.md)
- [UID:0001RE][interface-efx-resources](by-resource/interface-efx-resources.md)
- [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md)

## Changes

- 2026-06-20 B006 Rule 26 sync: clarified that the `0x004ea060` clear is constructor EH rollback glue from [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md), while the scalar deleting destructor clear at `0x004ea0e2` is the normal destructor path. Score unchanged; the global spelling and source-split caveats are unchanged.
- 2026-05-30: Changed completion/confidence from `0/0` to `84/82`.
  - Before: The page had basic singleton lifecycle notes but was unscored and did not link the exact storage aggregate.
  - After: The page records the exact `0x0069b360-0x0069b364` storage context, owner split caveat, and manager helper caveats.
  - Evidence: [UID:0002VQ][0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage](by-memory/0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage.md) documents the slot and xrefs; IDA xrefs tie the slot to the `InterfaceEfxMgr` constructor, trigger helper consumers, clear helper, destructor, and main UI shutdown.
- 2026-06-05: Marked reconstructable under [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md). Evidence: live IDA MCP reports seven xrefs to `0x0069b360`; decompilation confirms constructor `0x004e9d00`, clear helper `0x004ea060`, and scalar deleting destructor `0x004ea090` write/clear `dword_69B360`.
- 2026-06-06: Synced [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) after live IDA corrected the third adjustor endpoint from `0x004ea080` to `0x004ea081`; singleton ownership and score were unchanged.
- 2026-06-07: Raised to `85/86` during Batch 039 parent-gate follow-up after splitting exact storage [UID:0002VQ][0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage](by-memory/0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage.md). The parent now satisfies the corrected `85/85` gate for the storage child.
- 2026-06-14 A003 score refresh:
  - Before: `85/86`; the target page lagged behind the exact storage child and lacked a current full-xref confirmation.
  - Changed to: `86/88`, retaining [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md) as canonical owner/emitter and keeping reconstruction C++ blank.
  - Summary/evidence: live IDA MCP rechecked the seven direct refs to `0x0069b360`, constructor `0x004e9d00`, clear helper `0x004ea060`, and scalar deleting destructor `0x004ea090`. Final global spelling and manager-file split remain the blockers below final code entry.
