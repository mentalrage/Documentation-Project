*** UID:0002X1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ChattingModifyHeightPane;

ChattingModifyHeightPane *g_pChattingModifyHeightPane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pChattingModifyHeightPane

## Status

- Address: `0x0067add4`.
- Storage page: [UID:0002X2][0x0067add4-0x0067add8.g_pChattingModifyHeightPane](by-memory/0x0067add4-0x0067add8.g_pChattingModifyHeightPane.md)
- Source type: `ChattingModifyHeightPane *` with external linkage.
- Owner/emitter: [UID:0000I5][Chatting](by-file/Chatting.md), source position `0`.
- Source route: this page emits the sole module definition; the class page emits the header-facing external declaration, and the physical storage page is false/non-emitting.

## Evidence

The exact physical slot is `[0x0067add4,0x0067add8)`. Its four live bytes are `00 00 00 00`, SHA-256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`. PE mapping places it in the zero-filled virtual tail of `.data`, beyond the raw-backed extent, so the source definition has ordinary zero initialization. Historical `NULL` spelling is source-equivalent, but this formal uses `0` consistently with the accepted direct-global source policy.

### Complete xref and lifetime inventory

Exactly seven instructions reference the slot:

- `0x004807f7` and `0x004807fe`: one null-preserving publication sequence during [UID:0002F4][0x004807b0-0x0048085e.ChattingModifyHeightPaneConstructor](by-memory/0x004807b0-0x0048085e.ChattingModifyHeightPaneConstructor.md).
- `0x0048087a`: clear during [UID:0002F5][0x00480860-0x00480889.ChattingModifyHeightPaneDestructor](by-memory/0x00480860-0x00480889.ChattingModifyHeightPaneDestructor.md).
- `0x004839d0`: constructor-unwind cleanup.
- `0x00483c20`: scalar-deleting-destructor cleanup.
- `0x00481e6d`: no-null-check runtime read in `ChattingHandlePane::OnMouseEvent`.
- `0x00504972`: null-checked runtime read during MapPane exit teardown, followed by child removal at `0x0050497e`.

Direct RTTI proves that `ChattingModifyHeightPane` inherits `Singleton<ChattingModifyHeightPane>` at PMD offset `+0xf8`. The first five sites are compiler-lowered construction, destruction, unwind, or scalar-wrapper behavior of that base, not independent handwritten assignments or definitions. The two reads are non-owning UI consumers. The constructor's complete-object size `0x110`, the empty-base identity at `+0xf8`, `m_dragActive` sharing `+0xf8` through empty-base optimization, `m_dragAnchorY` at `+0xfc`, and `m_handleRect` at `+0x100..+0x10f` independently agree with this route.

The source split is deliberate:

- this global page owns the only source definition;
- [UID:00001W][ChattingModifyHeightPane](by-class/ChattingModifyHeightPane.md) owns the complete class declaration and external pointer declaration;
- [UID:0002X2][0x0067add4-0x0067add8.g_pChattingModifyHeightPane](by-memory/0x0067add4-0x0067add8.g_pChattingModifyHeightPane.md) retains bytes, range, and xref evidence but emits no marker or duplicate definition;
- compiler glue and vtable/RTTI pages document generated lowering without emitting source bodies.

B003 2026-06-28 source-quality implementation for [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md) records `g_pChattingModifyHeightPane` as a dependent refresh target for the secondary-chat toggle: when `ChattingHandlePane::m_secondaryChatEnabled` changes, the mouse-up path invalidates `g_pChattingModifyHeightPane->m_bounds` along with the back and display panes. This refresh dependency supports existing modify-height paint gating on the secondary-chat state; it is not an ownership change.

## Assignment Gate

Assigned to [UID:0000I5][Chatting](by-file/Chatting.md). The relationship is direct because this externally linked pointer is the semantic singleton global for the chat height/resize pane and belongs at the start of the Chatting source module's global inventory. The page is `92/94`: type, storage, seven references, ownership, lifecycle, declaration/definition split, and generated one-definition policy converge, while original private/header spelling is not linker-symbol proven.

## Negative Evidence And Source Exclusions

- The neighboring dwords in UID0002B5 have independent xref families and do not form a source struct with this global.
- The historical file-backed `0xffffffff` interpretation is rejected by live bytes and PE virtual-tail mapping.
- Constructor/destructor/EH/scalar writes do not justify handwritten publication, clearing, raw addresses, adjusted-null logic, delete flags, or duplicate definitions; they are implicit Singleton/compiler lowering.
- Runtime invalidation and teardown reads do not own or publish the global.
- Vtables, RTTI, EH state, cookies, vptr stores, cleanup funclets, and scalar-delete mechanics remain compiler output.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:00001W][ChattingModifyHeightPane](by-class/ChattingModifyHeightPane.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)

## Changes

- 2026-07-21 B005 UID0002X2 source-quality callback: raised the semantic global to `92/94`, set source position `0`, normalized the sole module definition to zero initialization, and incorporated exact bytes/PE semantics, all seven references, direct Singleton RTTI/EBO lifetime meaning, runtime consumers, header/source split, one-definition policy, negative evidence, and compiler exclusions.
- 2026-07-21 source-lifecycle correction: the previously documented explicit constructor/destructor assignment interpretation is superseded by direct `Singleton<ChattingModifyHeightPane>` RTTI. Publication and clearing are implicit base behavior; only this global definition and the class-page external declaration are human-authored source.
- 2026-06-30 B005 UID0000I5 empty-emitter family callback: inserted formal VC-era singleton definition `ChattingModifyHeightPane *g_pChattingModifyHeightPane = NULL;` with an ordinary forward declaration, raised score to `86/90`, and kept owner/emitter route unchanged. Accepted evidence: active MCP reads `0x0067add4` as zero/null storage with seven xrefs across height/resize pane lifecycle and chat layout consumers, with exact storage page [UID:0002X2][0x0067add4-0x0067add8.g_pChattingModifyHeightPane](by-memory/0x0067add4-0x0067add8.g_pChattingModifyHeightPane.md).
- 2026-06-07 A008 Batch 037 split: created as the canonical global page for the chat height/resize pane singleton.
- 2026-06-28 B003 support sync: added [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md) dependency notes for modify-height-pane invalidation on secondary-chat toggle. Score unchanged.
