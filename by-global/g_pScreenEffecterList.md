*** UID:0000S6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pScreenEffecterList

## Status

- Disposition: ignored stale alias; not a real source-level singleton to migrate.
- Confidence: strong that `g_pScreenEffecterList` is a stale alias for the real shared UI layer/context storage.
- Backing storage: `dword_69B364` at `0x0069b364`.
- Current type: unresolved; do not create a `ScreenEffecterList` type from this alias.
- Proposed owner: [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) under [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md), pending final layer naming.

## Observed Evidence

Live IDA MCP on 2026-05-30 confirms:

- `0x0069b364` is `dword_69B364`, a 4-byte `.data` item with 35 data xrefs.
- UI startup at `0x004f5fb0` writes `dword_69B364` at `0x004f6268` after a small layer/context construction path; the same startup function pushes `dword_69B364` at `0x004f6338` into `sub_556CE0` alongside sibling layer slots `dword_69B368`, `dword_69B36C`, `dword_69B374`, `dword_69B378`, and `dword_69B37C`.
- `InitializeMainUiGraph` at `0x004f7d10` passes `dword_69B364` into many pane setup calls: `0x004f7e4f`, `0x004f7ec3`, `0x004f7f37`, `0x004f7fae`, `0x004f8088`, `0x004f80f3`, `0x004f81dd`, `0x004f824e`, `0x004f82c2`, `0x004f8339`, `0x004f8656`, and `0x004f86cc`.
- UI shutdown at `0x004f6490` removes the slot from `dword_67A7CC`/screen-pane layer management by pushing `dword_69B364` at `0x004f64f3` into `sub_556D20`, then releases the object through its vtable at `0x004f6584-0x004f6592` and clears the slot at `0x004f6594`.
- `SolidColorFilterEffecter` at `0x0055ae00` is only one consumer: it pushes `dword_69B364` at `0x0055ae9a` into `sub_544C70` along with `dword_67A764` / active MapPane context and local pane state.
- `WaterFilterEffecter` at `0x0055b6a0` is another effecter consumer in the same concrete-subclass registration pattern. Its use of the slot after `FilterEffecter` base construction and Water-specific initialization confirms a pane/layer attachment dependency, not a screen-effecter list owner.
- Other IDA consumers span fitting-room, clan/browser/chatting/map/user/status-pane, effecter, system-message, and dialog paths; this broad fan-out is not compatible with a screen-effecter-owned global.

Historical recovered-source output used the name `g_pScreenEffecterList` for this storage in at least one effecter callsite. Treat that name as a search alias only; do not use it as source ownership evidence.

2026-06-19 B013 FilterEffecter source-quality pass: [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) is now modeled as `FilterEffecter : public ScreenEffecter, public Pane`. Its base constructor does not own or populate this global. Concrete filter subclasses attach their inherited Pane through `dword_69B364` after installing subclass vtables and state, which reinforces the Main UI layer/context-slot interpretation.

## Ownership Hypothesis

Treat `g_pScreenEffecterList` as ignored alias text. The reconstructable global is the backing `dword_69B364` layer/context slot, tracked with the surrounding [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) (`dword_69B368`, `dword_69B36C`, `dword_69B374`, `dword_69B378`, `dword_69B37C`) rather than inside `render/Effects.cpp`.

## Follow-Up

- Name the `dword_69B364` layer slot from the role it plays in [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md).
- Review the sibling layer globals initialized at `0x004f6239-0x004f632c`.
- Ensure future global-data repair suppresses `g_pScreenEffecterList` as an alias and does not create a fake `ScreenEffecterList` struct.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md)
- [UID:0000C9][ScreenEffecter](by-class/ScreenEffecter.md)
- [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0000PF][-ignored](by-global/-ignored.md)

## Changes

- 2026-06-19 B013 FilterEffecter support incorporation:
  - Score/disposition unchanged (`-1/-1`, ignored stale alias).
  - Summary/evidence: added the accepted FilterEffecter/subclass interpretation. `dword_69B364` is consumed by concrete effecter Pane registration paths, including SolidColor and Water, while FilterEffecter itself is only the inherited Pane-backed base. The stale `g_pScreenEffecterList` spelling remains a search alias and must not become a `ScreenEffecterList` source global.
- 2026-06-05: Marked `RECONSTRUCTABLE:FALSE` to resolve the global unclassified coverage row without attaching a false parent.
  - Reasoning: live IDA xrefs confirm this page is a stale alias over `dword_69B364`, a shared main UI layer/context slot tracked by [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md), not a direct `ScreenEffecterList` source item. No score change and no reconstruction C++ were added.
- 2026-05-30: What existed before: the page was marked `0/0` in completion metadata and still used weak source-output evidence for the stale alias. What changed: set completion/confidence to `-1/-1` because this is an ignored alias page, not a direct reconstruction target, and replaced the evidence with live IDA MCP xrefs for `0x0069b364`. Summary/evidence: IDA reports `dword_69B364` as a 4-byte `.data` item with 35 xrefs; startup, UI graph setup, shutdown/release, and broad pane/effecter consumers prove the real storage is a shared main UI layer/context slot, not a `ScreenEffecterList` singleton.
