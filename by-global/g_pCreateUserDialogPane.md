*** UID:0004Y3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class CreateUserDialogPane;

CreateUserDialogPane *g_pCreateUserDialogPane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Sole externally linked, explicitly zero-initialized CreateUserDialogPane pointer definition in NexusTK/login/CreateUserDialogPane.cpp at position 0. Exact backing UID0002B3 is a loader-zeroed false/non-emitting physical slot; five direct references are direct Singleton<CreateUserDialogPane> publication/fallback/unwind/teardown lowering, RTTI proves the +0x26c empty direct Singleton base, and one-definition routing prevents duplicate physical or template emission. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# g_pCreateUserDialogPane

## Status

- Semantic type: `CreateUserDialogPane *`.
- Source owner: [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md), emitted in `NexusTK/login/CreateUserDialogPane.cpp` at position `0`.
- Exact physical backing: [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md).
- Source role: the sole externally linked definition. The matching forward declaration and `extern` declaration belong to the [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) H channel; this page's H channel is intentionally blank.
- Initializer: explicit C++03-style zero, `= 0`. The binary cannot distinguish the exact lexical null token from implicit static zero initialization, but current project/family source style and the loader-zero storage make this the highest-probability human source shape.

## Physical Storage And Loader Initialization

- Exact physical range is `[0x0069b890,0x0069b894)`, width four bytes.
- Live IDA bytes are `00 00 00 00`; the loaded `u32le` value is zero/null.
- PE `.data` begins at VA `0x0066d000`, has virtual size `0x2fe24`, and therefore ends virtually at `0x0069ce24`.
- `.data` raw backing starts at file offset `0x26ac00`, has raw size `0xd800`, and ends at VA `0x0067a800`.
- The slot begins at `.data` offset `0x2e890`, which is `0x21090` bytes beyond the raw-backed end. It has no physical file bytes and is initialized by the PE loader's zero-filled virtual tail.
- Historical `0xffffffff`/all-ones startup wording is false for this slot. No integer sentinel initializer belongs in reconstructed source.

## Exact Lifetime Reference Inventory

Exactly five direct references cover publication and teardown:

| Instruction | Access | Source interpretation |
| --- | --- | --- |
| `0x0052dd87` | write complete-object pointer | [UID:00046E][0x0052dd30-0x0052e6eb.CreateUserDialogPaneConstructor](by-memory/0x0052dd30-0x0052e6eb.CreateUserDialogPaneConstructor.md) publishes the adjusted complete object through direct `Singleton<CreateUserDialogPane>` base lowering. |
| `0x0052dd8e` | write zero | Constructor fallback/EH lowering clears publication if the construction route does not retain the complete object. |
| `0x0052e71a` | write zero | [UID:00046F][0x0052e6f0-0x0052e72a.CreateUserDialogPaneConstructorCleanupRaw](by-memory/0x0052e6f0-0x0052e72a.CreateUserDialogPaneConstructorCleanupRaw.md) reverses the Singleton publication during constructor unwind. |
| `0x0052f710` | write zero | The dedicated compiler-generated Singleton clear helper reverses publication; it is reached only through exception/unwind metadata. |
| `0x0052f82d` | write zero | [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md) clears the slot during scalar deleting destruction. |

No read consumer, pointer arithmetic, aggregate indexing, alternate writer, VA/RVA/raw-offset pointer table, or sibling alias reaches this slot. Those negative results support one singleton pointer rather than an integer, handle, pointer-to-pointer, or array.

## Type, RTTI, And Direct Singleton Source Cause

- Constructor publication stores an adjusted complete [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) object, proving `CreateUserDialogPane *` rather than a raw integer or opaque handle.
- RTTI type descriptors identify both `CreateUserDialogPane` and `Singleton<CreateUserDialogPane>`.
- The class hierarchy descriptor records direct bases in source order: `DialogPane`, then `Singleton<CreateUserDialogPane>`.
- The Singleton base descriptor PMD is `{0x26c,-1,0}` with attributes `0x40`.
- `DialogPane` occupies `0x26c` bytes. Under the old-MSVC empty-base optimization, the empty Singleton base can occupy `+0x26c` while the first derived field `m_initialAppearanceRoll` also begins at `+0x26c`; no authored padding or nonempty Singleton member is required.
- Constructor publication, null fallback, unwind clear, dedicated clear, and scalar teardown are compiler/template lowering generated by that direct base. Human constructor/destructor source must not duplicate those assignments.

## Linkage And One-Definition Decision

- The source-facing name is `g_pCreateUserDialogPane`, matching the project's singleton-global convention and the existing CreateUserDialogPane source vocabulary.
- External linkage is the strongest source reconstruction. The pointer is part of the login/dialog source contract, while a class-header `extern` makes the singleton visible without defining it twice.
- This page owns the only initialized definition. [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md) documents exact storage but is false/non-emitting.
- The direct Singleton base is a source-level inheritance cause, not a separate template-static source definition. No evidence supports a qualified `Singleton<CreateUserDialogPane>::...` storage object.
- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) owns one declaration contract in H and emits no duplicate CPP definition.
- A file-static or anonymous-namespace definition is less probable than the external project-global route and would conflict with the selected header contract. A raw-address wrapper or duplicate physical declaration would violate one-definition semantics.

## Exact Range And Neighbor Boundaries

- The semantic definition maps only to `[0x0069b890,0x0069b894)`; no split, merge, or extension is required.
- Predecessor dword `[0x0069b88c,0x0069b890)` has two independent MIDI scratch references at `0x005272b1` and `0x0052730b`.
- Successor storage begins at `0x0069b894` and belongs to independent PoolAllocator/LivingObjectPane pool state with references at `0x0041a107`, `0x00506071`, `0x00514c85`, `0x0053d542`, and `0x0060c380`.
- The unrelated predecessor/successor xref families reject aggregate ownership and protect the exact four-byte boundary.

## IDA Current State And Supervisor Handoff

- Before supervisor Gate 2B, IDA models the four bytes as separate undefined bytes. At `0x0069b890`, `inspect_items` reports head `0x69b890`, end `0x69b891`, size `1`, `is_data:false`, synthetic display name `unk_69B890`, and no persistent name or data declaration/type.
- Address-regular and address-repeatable comments are blank; function comment channels do not apply to nonfunction data.
- Exact collision lookup for `g_pCreateUserDialogPane` returned zero existing globals.
- The accepted supervisor action is to define one four-byte data item, apply `CreateUserDialogPane *`, rename it `g_pCreateUserDialogPane`, and add the accepted address-regular lifetime comment while preserving bytes, range, neighboring items, repeatable-comment state, and the existing size-`0x280` UDT.
- This documentation callback does not mutate IDA. Supervisor Gate 2B owns mutation, readback, save, and checkpoint evidence.

## Generated Source Acceptance

- Generated `NexusTK/login/CreateUserDialogPane.cpp` must contain exactly one `CreateUserDialogPane *g_pCreateUserDialogPane = 0;` definition, preceded by the local incomplete-type declaration.
- The definition appears at position `0`; the class H route appears at position `10`; the corrected constructor appears at position `20`.
- Generated output must contain no empty-emitter marker for UID0002B3 or UID0002SI and no duplicate physical, vtable-array, template-static, constructor-publication, or teardown-clear definition.
- The class declaration and its exact virtual/method children remain the human source causes that regenerate the compiler vtable/COL and lifecycle artifacts.

## Negative Evidence And Rejected Alternatives

- Rejected names and forms: `dword_69B890`, `unk_69B890`, `DAT_0069b890`, `void *`, integer sentinel, raw-address access, and decompiler-shaped aliases.
- Rejected ownership: the physical by-memory slot, compiler vtable page, constructor helper, scalar wrapper, or a standalone globals source file.
- Rejected linkage/source forms: duplicate definition in the class H, a class static data member, qualified template-static storage, anonymous-namespace duplicate, and explicit constructor/destructor publication or clear assignments.
- Rejected initializers: `0xffffffff`, `-1`, and a raw copied file value. Exact PE loader semantics prove zero initialization.
- Rejected range forms: merging with MIDI scratch state or the following pool allocator state.

## Historical And Superseded Assumptions

- Earlier physical documentation described the slot as `dword_69B890` initialized to `0xffffffff`. Live IDA bytes and exact PE raw/virtual section math supersede both the integer spelling and all-ones initializer.
- Earlier routing attached the reconstructable physical slot directly to [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md), which produced an empty marker because the physical page carried no human source. The semantic definition now lives here; the physical page becomes false/non-emitting.
- Earlier constructor drafts wrote `g_pCreateUserDialogPane = this;`. RTTI PMD/EBO evidence and the symmetric unwind/scalar clear routes prove that publication is direct Singleton-base lowering and should not be handwritten.
- Earlier class drafts omitted `Singleton<CreateUserDialogPane>` from the direct base list. Current RTTI resolves the source hierarchy and the reason this global exists.

## Score Rationale

- Completion `92`: exact type/name, source owner, definition, initializer, physical range, PE loader semantics, five-reference lifetime, direct Singleton cause, PMD/EBO layout, linkage, one-definition route, IDA handoff, boundaries, generated acceptance, rejected alternatives, and historical corrections are documented.
- Confidence `93`: current bytes, all direct refs, RTTI hierarchy/PMD, class layout, compiler cleanup symmetry, source-family conventions, and physical neighbors agree. Confidence remains below 95 because stripped symbols cannot prove the original lexical null token or external declaration spelling byte-for-byte.

## Cross-References

- [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md)
- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md)
- [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md)
- [UID:00046E][0x0052dd30-0x0052e6eb.CreateUserDialogPaneConstructor](by-memory/0x0052dd30-0x0052e6eb.CreateUserDialogPaneConstructor.md)
- [UID:00046F][0x0052e6f0-0x0052e72a.CreateUserDialogPaneConstructorCleanupRaw](by-memory/0x0052e6f0-0x0052e72a.CreateUserDialogPaneConstructorCleanupRaw.md)
- [UID:0002QT][0x0052dd30-0x0052f710.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md)
- [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md)
- [UID:0002SI][0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData](by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md)
- [UID:00025Z][0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData](by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md)

## Changes

- 2026-07-26 B003 accepted UID0002B3/UID0002SI callback: created the semantic global definition at `92/93`, selected external linkage and explicit zero, separated physical storage and compiler vtable evidence from authored source, and incorporated exact PE/lifetime/RTTI/EBO/one-definition/history evidence.
