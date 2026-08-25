*** UID:0000A5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../core/BlackHole.h"

class ParcelIconPane;
class ParcelPane;
struct PaneEvent;

extern ParcelIconPane *g_pParcelIconPane;

class ParcelIconPane : public Pane,
                       public Singleton<ParcelIconPane>
{
public:
    ParcelIconPane();
    virtual ~ParcelIconPane();

protected:
    virtual bool OnParcelUpdate(const PaneEvent *event);

private:
    bool UpdateParcelCounts(const unsigned char *packet);

    unsigned char m_totalParcelCount;
    unsigned char m_leftParcelCount;
    unsigned char m_rightParcelCount;
    ParcelPane *m_parcelPane;
    int m_notificationState;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ParcelIconPane

## B001 UID0002ZO Accepted Callback - 2026-07-21

- Current declaration is complete at module position 20: direct `Pane` plus empty `Singleton<ParcelIconPane>` bases, virtual destructor, protected packet callback, private `UpdateParcelCounts`, and exact fields.
- Exact size is `0x104`: count bytes `+0xf8/+0xf9/+0xfa`, natural alignment at `+0xfb`, child `ParcelPane *` at `+0xfc`, and intentionally uninitialized inactive `int` at `+0x100`. Exhaustive constructor/destructor/callback/scalar scans reject ownership, active flag, resource, timer, and padding alternatives for that final dword.
- Constructor and reverse base destruction implement singleton publication/clear. Handwritten source does not assign `g_pParcelIconPane`; vptrs, EH clear, Pane teardown, adjustors, and scalar wrapper are compiler output.
- Raw range `[0x005460f0,0x005461c0)` is the out-of-line source method `UpdateParcelCounts(const unsigned char *)`. Its exact body appears inlined into `OnParcelUpdate`, which explains no inbound xref without making it dead or unrelated.
- The callback is the thin source opcode gate/call wrapper. Historical raw-non-emitting, comment-only declaration, Pane-only inheritance, explicit padding, and unresolved source-route conclusions are superseded. Lexical uncertainty caps this complete class at `92/93`.

## Status

- Confidence: very strong for ownership, both direct bases, exact `0x104` size, all four source methods, singleton lifecycle, child ownership, three vtable views, and ParcelPane.cpp placement. Inferred private/access/member spellings cap the current page at `92/93`.
- Likely source file: [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- Emission route: this complete declaration and post-class `[[CHILDREN]]` marker emit through UID0000MF. Historical `simroot_v2/class_ParcelIconPane.cpp` output is retained only as a superseded generated lead.
- Memory range: [UID:0001EH][0x00545e40-0x005470ad.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md)
- Vtable/type evidence: [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md)
- Layout evidence: [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md)

## Class Purpose

`ParcelIconPane` is the outer parcel notification pane/icon. It derives directly from `Pane` and empty `Singleton<ParcelIconPane>`, creates and owns a child [UID:0000A6][ParcelPane](by-class/ParcelPane.md), stores its singleton separately from `g_pParcelPane`, forwards parcel-count updates to the child, and requests child dismissal during derived teardown.

## Layout Notes

The inherited `Pane` region occupies `+0x000..+0x0f7`. Live RTTI identifies direct non-virtual empty base `Singleton<ParcelIconPane>` at PMD `mdisp=0xf8`, `pdisp=-1`, `vdisp=0`, attributes `0x40`; MSVC empty-base optimization overlaps it with the first derived byte. Derived fields are `m_totalParcelCount` at `+0xf8`, `m_leftParcelCount` at `+0xf9`, `m_rightParcelCount` at `+0xfa`, natural alignment at `+0xfb`, and owned `ParcelPane *m_parcelPane` at `+0xfc`. The packet callback's secondary `this+0x58..+0x5c` accesses normalize to those owner fields.

Two MainUiGraph construction paths allocate `0x104` bytes before calling the constructor, and the scalar wrapper's size-bearing compiler path independently carries literal `0x104`; therefore `sizeof(ParcelIconPane)==0x104`. The final dword at `+0x100` has no surviving initialization, read, write, comparison, copy, release, singleton-consumer use, adjusted-receiver use, or constructor/EH access. The source declaration uses inferred `int m_notificationState` as the highest-probability human-written inactive status field and intentionally leaves it uninitialized.

Ranked alternatives are: inactive 32-bit status member first; one-byte `bool m_updatePending` plus natural padding second; a 32-bit `ParcelNotificationState` enum third. A pointer is rejected because no initialization/use/release lifecycle exists. `unsigned char m_reservedTail[4]` is rejected as reverse-engineering-shaped source: high-quality project declarations omit pure alignment bytes, while genuine project `m_reserved...` storage has observable clearing, copying, retention, or serialization. The selected name is explicitly inferred rather than symbol-proven.

## Method Notes

| Range | Method | Notes |
| --- | --- | --- |
| `0x00545e40-0x0054606a` | `ParcelIconPane::ParcelIconPane` | [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md) emits `Pane(1)` plus `Singleton<ParcelIconPane>()`, three zero count initializers, null child initialization, and `m_parcelPane = new ParcelPane`. Singleton publication, inlined child setup, vptr stores, security cookie, and EH cleanup are compiler effects; `m_notificationState` remains intentionally uninitialized. |
| `0x00546070-0x005460e8` | ordinary virtual destructor | [UID:0001EI][0x00546070-0x005460e8.ParcelIconPaneDestructor](by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md) explicitly queues the associated child for deferred deletion and unregisters the event handler. Reverse `Singleton<ParcelIconPane>` destruction clears the singleton before implicit Pane teardown; no body-level clear is emitted. |
| `0x005460f0-0x005461c0` | `ParcelIconPane::UpdateParcelCounts` | [UID:00043J][0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper](by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md) emits the exact out-of-line source body; no inbound xref is explained by exact compiler inlining into `OnParcelUpdate`, while the retained standalone body proves source emission. |
| `0x005461c0-0x0054628d` | parcel packet/update callback | [UID:0001EJ][0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback](by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md) at `0x00621c10`. Decodes parcel packet bitmasks from an event wrapper, updates icon-side total/left/right counters, and forwards new counts to the child `ParcelPane`. Direct owner/emitter is this class; not emitted in active `class_ParcelIconPane.cpp`. |
| `0x00546e70-0x00546e7b` | constructor/EH Singleton-base cleanup funclet | Non-emitting compiler unwind target that clears `g_pParcelIconPane` after the direct Singleton base becomes live; no standalone source helper. |
| `0x00546ea1-0x00546eb7` | destructor adjustor thunks | Secondary/tertiary vtable thunks forwarding to `0x00546f40`. Compiler-generated; see [UID:0001EM][0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks](by-memory/0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks.md). |
| `0x00546f40-0x00546ff9` | scalar deleting destructor | [UID:0001EO][0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor](by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md) is `92/94`, ownerless, false, non-emitting, and formally blank. It duplicates ordinary cleanup, inlines Singleton/Pane teardown, interprets compiler flags, and conditionally releases storage. |

## Evidence Notes

- IDA MCP decompilation of `0x00545e40` writes `ParcelIconPane` vtables, then allocates and initializes a `ParcelPane` child.
- 2026-06-29 B006 implementation of [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md) records current MCP session `b2ae72ec`: one active IDB session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `16112`, `server_health` status `ok`, exact `sub_545E40` range `0x00545e40-0x0054606a`, size `0x22a` / 554, exclusive-end non-function, two `sub_4F7D10` calls at `0x004f848c` and `0x004f89f3`, `ParcelIconPane` owner vtable/global evidence, `+0xf8/+0xf9/+0xfa` counter clears, `+0xfc` child pointer store, `0x124` / 292-byte child allocation, child `ParcelPane` vtable writes, and `g_pParcelPane` publication.
- The UID0001EG source body intentionally expresses the compiler-inlined child setup as `m_parcelPane = new ParcelPane;` because [UID:0002KB][0x00546290-0x00546436.ParcelPaneConstructor](by-memory/0x00546290-0x00546436.ParcelPaneConstructor.md) already emits the accepted `ParcelPane::ParcelPane()` source for the child field setup, `SetParcelSlotData(0,0,0)`, pane order, and 100 ms timer.
- 2026-06-13 live IDA MCP `lookup_funcs` confirms `0x00545e40` as a `0x22a` / 554-byte constructor candidate and `0x005461c0` as a `0xcd` / 205-byte parcel update callback (Verified with int_convert.py).
- 2026-06-13 live IDA MCP `xrefs_to` confirms the three `ParcelIconPane` vtable views are written from constructor, non-deleting destructor, and scalar deleting destructor paths: `0x00621bb4` at `0x00545eab`, `0x0054609b`, and `0x00546f6b`; `0x00621c00` at `0x00545eb1`, `0x005460a1`, and `0x00546f71`; and `0x00621c30` at `0x00545ebb`, `0x005460ab`, and `0x00546f7b`.
- 2026-06-13 live IDA MCP `analyze_function 0x00545e40` reconfirms singleton publication to `g_pParcelIconPane`, owner field clears at `+0xf8..+0xfa`, allocation of a `0x124` / 292-byte child `ParcelPane`, child vtable initialization, child field/rectangle initialization, timer setup, and owner child-pointer storage at `+0xfc` (Verified with int_convert.py).
- 2026-06-13 live IDA MCP `analyze_function 0x005461c0` reconfirms the secondary callback slot at `0x00621c10`, packet type check for byte `8`, flag-dependent parcel-count decoding, owner-normalized writes at `+0xf8..+0xfa`, child pointer access at owner `+0xfc`, and forwarding to `ParcelPane::SetParcelSlotData`.
- [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md) now records the exact `0x22a` constructor span, MainUiGraph construction callers, child `ParcelPane` allocation/setup, timer setup, and publication of both parcel singletons.
- [UID:0001EI][0x00546070-0x005460e8.ParcelIconPaneDestructor](by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md) records the exact non-deleting destructor, child-pane dismissal, vtable restoration, base cleanup, and icon singleton clear.
- [UID:0001EJ][0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback](by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md) records the secondary-vtable packet callback, flag-dependent parcel-count decoding, normalized owner offsets, `ParcelPane::SetParcelSlotData` forwarding, exact padding after the function, and the separate raw helper follow-up before it.
- [UID:00043J][0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper](by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md) records the exact retained out-of-line `UpdateParcelCounts` method between destructor and callback, including eight-byte pre-padding, no direct xref, complete payload/count behavior, `retn 4`, exact body hash, and compiler-inlined callback duplicate. Its old blank/non-emitting policy is superseded.
- IDA MCP `xrefs_to 0x005461c0` reports the vtable data reference at `0x00621c10`, which is slot `+0x10` of the ParcelIconPane secondary vtable.
- IDA MCP vtable dump confirms the tertiary table at `0x00621c30` has only two slots. The next dword at `0x00621c38` is `ParcelPane` RTTI, not a `ParcelIconPane` virtual.
- [UID:0001EO][0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor](by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md) records the ABI wrapper, adjustor-thunk/vtable refs, optional delete branch, and generated-reference-context caveat.
- The destructor path calls pane-manager dismissal for the associated child and clears the icon singleton, distinct from `g_pParcelPane`.

## 2026-07-15 B001 Accepted Class Source-Shape Callback

- Direct source bases are exactly `Pane` and `Singleton<ParcelIconPane>`. RTTI TypeDescriptors/CHD/BCA/BCD records identify the Singleton specialization, and its PMD at `+0xf8` matches the ScreenDimmer/SimpleHelpPane family EBO convention. EventHandler and TimerHandler facets at `+0xa0/+0xa4` arrive through Pane and are not repeated as direct bases.
- Constructor publication stores at `0x00545e91/0x00545e98` occur at the direct Singleton-base construction stage. Source uses `Singleton<ParcelIconPane>()`, not manual `g_pParcelIconPane = this`, raw pointer adjustment, or a null-adjustment artifact.
- Ordinary/scalar clears at `0x005460c9` and `0x00546fa0` occur between derived cleanup and inherited Pane teardown, matching reverse destruction of the direct Singleton base. Source destructor contains only child dismissal and `UnregisterEventHandler()`; manual or guarded global clear is superseded.
- The direct class declaration is closed before `[[CHILDREN]]`. UID0001EG, UID0001EI, and UID0001EJ supply namespace-scope definitions in source order; UID0001EO and UID0001EM remain blank compiler support and do not emit duplicate class methods.
- Exact no-use research for the final dword covered constructor variants/EH, all three vtable write families, all six `g_pParcelIconPane` refs, pointer-derived and adjusted receivers, parcel-island `0x100..0x103` displacement searches, sibling parcel layouts, allocation/deallocation paths, RTTI/base geometry, and project-era class conventions. Local `0x100` hits belong to child `ParcelPane` rectangles or `FlyingParcelPane::m_animationLayer`, not the outer final dword.
- The class remains reconstructable through UID0000MF at `92/93`; declaration, inheritance, layout, all methods, source/compiler boundaries, and child route are complete. Only original lexical/access spellings remain inferred.
- Rejected current source shapes are the historical comment-only class marker, Pane-only inheritance, direct EventHandler/TimerHandler duplication, explicit padding/reserved array, pointer ownership at the final dword, body-level singleton publication/clear, wrapper/adjustor/EH helpers, raw offsets, vptr stores, and a new standalone class source file.

## Parent And Score Rationale

Current assessment: this page is the complete class declaration/layout and child-insertion surface at `91/92`. UID0001EG, UID0001EI, and UID0001EJ emit the constructor, ordinary destructor, and callback through `[[CHILDREN]]`; UID0001EO is blank non-emitting compiler support. Historical B005 `88/90` comment-only handling is preserved in Changes below but no longer describes the current source route.

| Evidence group | Current assessment |
| --- | --- |
| Source module | [UID:0000MF][ParcelPane](by-file/ParcelPane.md) is `90/90` and groups `ParcelIconPane`, `ParcelPane`, `FlyingParcelPane`, both parcel globals, resources, and the PatchPane boundary. |
| Class-owned methods | Constructor, non-deleting destructor, raw parcel update helper, secondary-vtable parcel update callback, singleton-clear cleanup funclet, adjustor thunks, and scalar deleting destructor are all identified; the exact code-bearing child pages are `80+` confidence except compiler-generated glue where no source C++ should be emitted. |
| Layout and vtables | [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md) now clears `86/88`, and [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md) clears `86/92`; together they support the primary/secondary/tertiary views, normalized callback offsets, child allocation bound, and child pointer field. |
| Remaining confidence caps | `PaneEvent::packetData`, protected callback access, final inactive-member spelling, and original header exposure remain inferred. The raw helper source route is closed; remaining items are lexical caps only. |

The class clears the support gate because live IDA evidence fixes direct bases, exact size, constructor/destructor/callback inventory, vtables, child allocation/layout, singleton lifecycle, and UID0000MF parentage. The complete formal declaration now supplies the previously missing generated class/child route; exact child pages carry the out-of-class source bodies.

## Cross-References

- [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- [UID:0000A6][ParcelPane](by-class/ParcelPane.md)
- [UID:0001EH][0x00545e40-0x005470ad.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md)
- [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md)
- [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md)
- [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md)
- [UID:0001EI][0x00546070-0x005460e8.ParcelIconPaneDestructor](by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md)
- [UID:00043J][0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper](by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md)
- [UID:0001EJ][0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback](by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md)
- [UID:0001EO][0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor](by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md)
- [UID:0000RX][g_pParcelIconPane](by-global/g_pParcelIconPane.md)

## Changes

- 2026-06-29 B006 accepted ParcelIconPane constructor implementation sync:
  - Recorded that [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md) now has first-draft formal `ParcelIconPane::ParcelIconPane()` C++ and emits through this class route under [UID:0000MF][ParcelPane](by-file/ParcelPane.md).
  - Added source-facing constructor field names for the icon-side counters (`m_totalParcelCount`, `m_leftParcelCount`, `m_rightParcelCount`) and owned child pointer (`m_parcelPane` at `+0xfc`). The exact original child-pointer spelling remains inferred, but the role is proven by constructor storage, destructor dismissal, and callback forwarding.
  - Evidence: accepted B006 report and MCP session `b2ae72ec` confirm the exact constructor range, `0x22a` / 554-byte size, exclusive-end non-function, two `sub_4F7D10` callers, direct `ParcelIconPane` vtable/global writes, owner fields `+0xf8/+0xf9/+0xfa`, child pointer `+0xfc`, `0x124` / 292-byte child allocation, child `ParcelPane` vtable writes, and `g_pParcelPane` publication. At that time the class formal block remained blank only for broader callback/raw-helper/destructor declaration shape; B005 now replaces the empty class block with a comment-only support marker and populates the destructor/callback children.
- 2026-06-26 B007 accepted raw-helper support update:
  - Added [UID:00043J][0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper](by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md) to the method inventory and evidence notes as a ParcelIconPane-owned exact child, and updated [UID:0001EJ][0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback](by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md) as direct class-owned/emitted callback support.
  - Summary/evidence: accepted B007 report and MCP session `80de0a67` prove the raw helper is real code, not padding or part of [UID:0001EJ][0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback](by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md); it starts after eight `0xcc` bytes, has no modeled function or inbound xrefs, decodes direct payload counts, writes `+0xf8/+0xf9/+0xfa`, reads child pointer `+0xfc`, calls `ParcelPane::SetParcelSlotData`, and ends before the callback at `0x005461c0`.
  - Then-current C++ policy: broad class formal C++ remained blank for field/helper names, raw helper route/signature, packet/event wrapper type, child pointer declaration, and private/helper declaration shape. The old "needs exact raw helper page" blocker was closed, and the old `95/95` wording was not used as a current gate. B005 supersedes the blank block with a comment-only support marker.
- 2026-06-13 A003 Goal 2 support refresh: Raised from `84/82` to `85/86`.
  - Before: the covered-class page remained below the strict support gate for [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md).
  - After: current IDA evidence confirms the outer icon-pane owner, child `ParcelPane` allocation/layout, callback offset normalization, vtable stores, singleton split, and direct parent [UID:0000MF][ParcelPane](by-file/ParcelPane.md) at `86/85`.
  - Evidence: IDA MCP `lookup_funcs`, `xrefs_to`, and `analyze_function` on 2026-06-13 against session `a001_goal2_0002UM`; key sizes and offsets were verified with `tools/int_convert.py`.
- 2026-06-18 B006 singleton-clear support update:
  - Updated [UID:0002KM][0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton](by-memory/0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton.md) from a class-owned helper description to a non-emitting constructor/EH cleanup funclet. The class still owns the source-level singleton lifetime through constructor publication, destructor clear, scalar deleting destructor clear, and the `g_pParcelIconPane` declaration; the standalone one-store range should not emit C++.
  - Evidence: B006 confirmed no ordinary caller or callees, an unwind/EH xref at `0x00605bc1`, exact bytes and padding, and same-shape cleanup precedents. [UID:0002KN][0x00546e80-0x00546e8b.ClearParcelPaneSingleton](by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md) remains a queued sibling consistency review.
- 2026-05-31: Marked reconstructable and attached to [UID:0000MF][ParcelPane](by-file/ParcelPane.md).
  - Before: class evidence was documented but validator autogen metadata was blank.
  - After: `RECONSTRUCTABLE:TRUE` with the file parent set; broad class C++ remained blank until constructor/callback names and helper APIs were near-final. The constructor-specific hold is now superseded by the 2026-06-29 B006 UID0001EG implementation, while callback/raw-helper/destructor declaration caveats still keep the broad class block blank.
  - Evidence: IDA MCP confirms the constructor, destructor, packet/update callback, singleton-clear helper, adjustor thunks, and scalar deleting destructor as part of the parcel notification source family.
- Initial scoring pass: changed completion/confidence metadata from `0/0` to `82/78`.
  - Evidence: IDA-backed constructor behavior, packet callback vtable slot, scalar deleting destructor, layout offsets, singleton global, and generated constructor omissions were documented.
- 2026-06-06: Raised completion/confidence from `82/78` to `84/82` and replaced stale generated-output caveats with exact child-page evidence.
  - Before: the class stayed below the confidence gate even though constructor, destructor, callback, scalar destructor, layout, vtable, and singleton pages had since been strengthened.
  - Changed to: added parent/score rationale, documented the exact `80+` child evidence set, clarified that active generated output is incomplete rather than a current confidence blocker, and kept C++ blank below the final-source gate.
  - Evidence: [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md), [UID:0001EI][0x00546070-0x005460e8.ParcelIconPaneDestructor](by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md), [UID:0001EJ][0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback](by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md), [UID:0001EO][0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor](by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md), [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md), and [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md) now support the class-level owner and score.
