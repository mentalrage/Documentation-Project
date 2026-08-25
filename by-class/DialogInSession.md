*** UID:00003S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class DialogSession;

class DialogInSession : public DialogPane
{
public:
    DialogInSession(DialogSession *session,
                    unsigned short dialogConfigId,
                    unsigned char dialogType);
    virtual ~DialogInSession();

    unsigned char m_dialogType;
    DialogSession *m_session;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DialogInSession

## Status

- Confidence: very strong for class identity, direct DialogPane inheritance, constructor signature, tail fields, three-view vtables, destructor family, file route, and source-compatible declaration.
- Likely source file: [UID:0000IU][DialogSession](by-file/DialogSession.md)
- Address range: [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md)
- Current recovered file: `source-3/simroot_v2/class_DialogInSession.cpp`
- Type docs: [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- Vtables: [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md), exact data [UID:0002NB][0x00618d2c-0x00618e50.DialogSessionVtableData](by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md)
- Direct autogen parent: [UID:0000IU][DialogSession](by-file/DialogSession.md)

## Class Purpose

`DialogInSession` is the base for dialogs managed by a `DialogSession`. It derives directly from `DialogPane`, stores `unsigned char m_dialogType` at `+0x26c`, naturally aligns, then stores `DialogSession *m_session` at `+0x270`. Public field placement is the strongest current source-compatible shape because current session-family source reads `m_dialogType` directly and derived classes read `m_session`; inventing getters would add an unobserved API and require unrelated consumer rewrites.

See [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md) for the `DialogPane` base and derived tail offsets.

## Method Notes

| Method or range | Address | Role |
| --- | --- | --- |
| `DialogInSession(DialogSession *session, unsigned short dialogConfigId, unsigned char dialogType)` | `0x004a1400-0x004a144e` | Constructs `DialogPane(L"", dialogConfigId, 1)`, stores `dialogType` at `+0x26c`, stores `session` at `+0x270`, and installs all three class vptrs. The x86 caller pushes a full stack dword, but the base contract consumes the 16-bit config value. |
| non-deleting destructor | `0x004a1450-0x004a146f` | Resets `DialogInSession` vtables and destroys the `DialogPane` base. |
| destructor thunks | `0x004a146f-0x004a1485` | Secondary and tertiary adjustor thunks forwarding to `0x004a14a0`. |
| scalar deleting destructor | `0x004a14a0-0x004a14f5` | Resets vtables, destroys `DialogPane`, and conditionally deletes the object. |

## Vtable Evidence

| View | Vtable | Key slots |
| --- | --- | --- |
| primary | `0x00618db8` | Scalar deleting destructor `0x004a14a0` at `+0x00`, inherited `DialogPane` slots through `+0x58`. |
| secondary | `0x00618e18` | Adjustor thunk `0x004a146f` at `+0x00`, inherited dialog secondary-view slots including `0x0049e240`, `0x0049e6e0`, and `0x0049ea60`. |
| tertiary | `0x00618e48` | Adjustor thunk `0x004a147a` at `+0x00`, base event slot `0x00544e90` at `+0x04`. |

The constructor stores these vtables at `0x004a142d`, `0x004a1433`, and `0x004a143d`. The non-deleting destructor and scalar deleting destructor reinstall the same three vtables before base cleanup.

The primary table has 23 slots through `SetHoverControl(int)`. Its exact DialogPane extensions are OnCreate, OnDestroy, OnShow, OnHide, OnPaint, OnControlCommand, UpdateActionButton, DrawBackground, DrawBorder, and SetHoverControl. The secondary table has the exact EventHandler 11-slot order; its first three entries are DialogPane overrides and `+0x10` is the inherited five-byte false `HandlePacketEvent(Event *)` default at `0x0041d6b0`. The tertiary table carries the inherited true `OnTimer(int,int,int)` default.

## Supporting Exact Evidence

- [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md) records the exact `0x004a1400-0x004a14f5` constructor/destructor/deleting-destructor subrange, the `DialogPane` base construction, tail writes at `+0x26c/+0x270`, vtable stores, and the surrounding `DialogSession` physical island.
- [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md) records the `DialogInSession` tail layout and explicitly warns that `+0x26c/+0x270` are derived-tail fields, not base `DialogPane` state.
- [UID:0002NB][0x00618d2c-0x00618e50.DialogSessionVtableData](by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md) records the primary, secondary, and tertiary `DialogInSession` vtable bases, slot extents, destructor adjustor thunks, and boundary before `DIBitmap` RTTI.

## Evidence Notes

- IDA MCP confirms `0x004a1400`, `0x004a1450`, `0x004a146f`, `0x004a147a`, and `0x004a14a0`.
- `xrefs_to 0x004a1400` shows direct construction from several bulletin/session dialog constructors.
- Historical B014 argument-role research correctly separated the common board/article/mail config value `2` from the stored dialog type, but its `int dialogPaneConfigId` source spelling is superseded by the exact `DialogPane` `unsigned short` contract. The caller still pushes a dword under the x86 ABI.
- 2026-05-25 IDA checks show board/article deleting-destructor wrappers such as `ArticleDialog` `0x0047e950`, `ArticleListDialog` `0x0047e990`, `BulletinDialog` `0x0047ea10`, and `NewPredefinedFormArticleDialog` `0x0047ec30` all call this class's non-deleting destructor at `0x004a1450`.
- Historical disabled output listed `0x004a146f` as missing code and emitted a polluted `BackGroundPane` deleting alias. Exact UID000134/UID0002NB evidence supersedes those artifacts: the thunk and scalar deleting destructor are compiler products of the ordinary virtual destructor and must not be handwritten.
- Historical zero-vtable metadata is superseded by the exact three constructor/destructor store sets and three COL-backed table views.

## Assignment Gate

This class is `92/93`, directly owned and emitted by [UID:0000IU][DialogSession](by-file/DialogSession.md). UID000131 is the non-emitting physical index, while UID0001XD/UID0002NB are non-emitting compiler type/data authorities.

## Score Rationale

- Completion is `92` because the page now carries the complete class declaration, exact constructor types, source-compatible public fields, direct base, layout/alignment, three full vtable contracts, ordinary destructor source, compiler-wrapper exclusions, callers, history, and file route.
- Confidence is `93` because class identity, direct inheritance, offsets, constructor ABI, vtable stores, destructor paths, consumer access, and source file ownership are independently corroborated. Original lexical access style remains the only material source-shape uncertainty.

## Cross-References

- [UID:0000IU][DialogSession](by-file/DialogSession.md)
- [UID:00003U][DialogSession](by-class/DialogSession.md)
- [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md)
- [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md)
- [UID:0002NB][0x00618d2c-0x00618e50.DialogSessionVtableData](by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md)
- [UID:000134][0x004a146f-0x004a149b.DialogSessionAdjustorThunks](by-memory/0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md)
- [UID:00003T][DialogPane](by-class/DialogPane.md)
- [UID:00001C][BulletinDialog](by-class/BulletinDialog.md)
- [UID:00000J][ArticleDialog](by-class/ArticleDialog.md)
- [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md)

## Changes

- 2026-07-16 B004 UID0002NB accepted implementation callback:
  - Changed `85/88 -> 92/93` while preserving owner/emitter UID0000IU, reconstructable true, blank position, and all prior behavioral/caller/history evidence.
  - Installed the complete managed class declaration with `DialogSession *`, `unsigned short dialogConfigId`, `unsigned char dialogType`, virtual ordinary destructor, public `m_dialogType`, public `m_session`, and `[[CHILDREN]]`.
  - Added exact 23/11/2 slot/source contracts, natural byte-to-pointer alignment, inherited-facet explanation, renamed UID0002NB route, and no-handwritten scalar-wrapper/adjustor proof; historical `int`, BackGroundPane, missing-code, and zero-vtable artifacts are superseded.
- 2026-06-07 A003 Batch 084 class parent-gate update:
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:0000IU`.
  - Summary/evidence: added supporting exact evidence, assignment gate, and score rationale. Assignment to [UID:0000IU][DialogSession](by-file/DialogSession.md) is justified because the child is `85/88`, the direct file parent is `86/86`, and the exact memory/type pages document the `DialogInSession` constructor/destructor island, `+0x26c/+0x270` tail fields, and three vtable views.

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/86`.
  - Summary/evidence: class role, tail layout, constructor/destructor/thunks, vtable stores, direct construction/destruction evidence, generated alias caveat, and session/dialog cross-references are documented; remaining work is mainly final source-facing names for session tail fields.
- 2026-05-31 reconstructability:
  - Before: `RECONSTRUCTABLE` was blank.
  - After: `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP reconfirms the `DialogInSession` constructor/destructor/vtable stores and construction xrefs from bulletin/session dialogs. Parent/code autogen remains blank because final declarations and tail field names are not at near-final confidence.
- 2026-06-19 B014 BulletinDialog constructor support sync:
  - Score unchanged.
  - Summary/evidence: clarified the source-facing constructor argument roles so callers such as `BulletinDialog` are documented as passing `DialogInSession(session, 2, dialogType)`, with `2` as the `DialogPane` config/id/style value rather than the stored dialog-type byte.
