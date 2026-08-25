** TARGET-REPORT-UID:0000I2 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000I2 ChangeMan Empty-Emitter Family Source-Quality Report


## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000I2] `by-file/ChangeMan.md` as the canonical source file for `NexusTK/app/ChangeMan.cpp`, clear all 12 current empty markers, and do not create new child pages or move ownership.
- Primary repair: promote first-draft formal C++ for [UID:0000ZZ] `ChangeMan::DispatchMessage`, [UID:000100] `ChangeMan::UnregisterObject`, [UID:0000QI] `g_pChangeMan`, [UID:0001TV] `ChangeManEntry`, [UID:0001TW] `ChangeMan` layout declaration, and [UID:00001K] ordinary destructor source. Use formal covered-by/generated-binary comments for broad aggregate, vtable, exact vtable data, exact singleton storage, registration-pair aggregate, and scalar-deleting wrapper pages.
- Confidence: high for the owner/emitter route, method behavior, singleton/vtable/layout facts, and generated-empty disposition; medium-high for exact source spelling of `ChangeListener`, `OnChangeMessage`, `ChangeMessageScope`, and final public header split.
- Implementation callback note: accepted by-* docs were edited, scoped validators passed, leases were released, and generated `auto-generated/NexusTK/app/ChangeMan.cpp` refreshed with no old `Empty Emitter Marker` text. Generated tracker state is now `16` total emitters, `16` filled, `0` empty, `100.0%`.

## Target

- Assignment ID: `B009-report-0000I2-ChangeMan-empty-emitter-family-20260701`.
- Target UID/path: [UID:0000I2] `by-file/ChangeMan.md`.
- Generated file: `auto-generated/NexusTK/app/ChangeMan.cpp`.
- Queue basis: `auto-generated/-ag-research-tracker.md` -> `## Files With Empty Emitters`.
- Tracker row at assignment: 16 total emitters, 4 filled, 12 empty, 25.0% complete.
- Current target metadata: `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/"`.

## Current Target State

`auto-generated/NexusTK/app/ChangeMan.cpp` currently emits non-empty code for [UID:0000ZT] constructor, [UID:0000ZW] register, [UID:0000ZY] filtered unregister, and [UID:000101] comparator. The 12 empty markers are:

| UID | Path | Current disposition | Recommended empty-marker repair |
| --- | --- | --- | --- |
| [UID:00001K] | `by-class/ChangeMan.md` | class owner, formal C++ blank | emit ordinary `ChangeMan::~ChangeMan()` source body and class-level evidence note |
| [UID:0000ZZ] | `by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md` | source method, candidate only | populate formal first-draft `DispatchMessage` C++ |
| [UID:000100] | `by-memory/0x0047eea0-0x0047eedf.ChangeManUnregisterObject.md` | source method, candidate only | populate formal first-draft `UnregisterObject` C++ |
| [UID:000103] | `by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md` | compiler wrapper, blank by proof | add formal no-code/generated-wrapper comment |
| [UID:0001TV] | `by-type/by-struct/ChangeManEntry.md` | source struct, declaration candidate only | populate formal enum/struct declaration |
| [UID:0001TW] | `by-type/by-struct/ChangeManLayout.md` | class layout, blank | populate formal class layout declaration |
| [UID:0001X7] | `by-type/by-vtable/ChangeManVtable.md` | vtable type, compiler-generated | add formal generated-binary comment |
| [UID:0000QI] | `by-global/g_pChangeMan.md` | semantic singleton global, blank | populate formal global definition |
| [UID:0000ZU] | `by-memory/0x0047ec70-0x0047efae.ChangeMan.md` | broad range index | add formal covered-by-children comment |
| [UID:0000ZX] | `by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md` | register/unregister pair index | add formal covered-by-exact-children comment |
| [UID:0002M8] | `by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md` | exact vtable bytes | add formal source-declared/generated-binary comment |
| [UID:0001P4] | `by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md` | exact singleton storage | add formal covered-by-global-declaration comment |

## Evidence Checked

- Project skill/read gates: `ntk-b-agent-workflow`, B-agent workflow, score-blocker audit standard, Rule 26 standard, `goal.md`, and `by-structure.md` -> `IDA MCP Output Discipline`.
- Target/generated docs: `by-file/ChangeMan.md`, `auto-generated/NexusTK/app/ChangeMan.cpp`, `auto-generated/-ag-research-tracker.md`.
- Empty-marker docs read: all 12 listed empty marker pages.
- Source-bearing child/support docs read: [UID:0000ZT], [UID:0000ZW], [UID:0000ZY], [UID:000101], `by-memory/0x0047ec70-0x0047efae.ChangeMan.md`, `by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md`, `by-class/ChangeMan.md`.
- Prior reports searched with terms `0000I2`, `ChangeMan`, `0x0047ec70`, `0x0047ee20`, `0x0047eea0`, `0x0047ef50`, `0x00614cd0`, and `0x0067ab2c`.
- Prior executed reports opened as leads: B002 `0000ZZ-000100-changeman-method-source-quality.md`; B010 `0000ZT-0000ZW-0000ZY-000101-000103-ChangeMan-source-quality.md`.
- Live MCP provenance: JSON-RPC endpoint `http://127.0.0.1:13337/mcp`; session `supervisor_resume_20260629`; `idb_list` count `1`; `server_health` status `ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready.
- Live MCP tools used, all narrow and exact: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `decompile`, `xrefs_to`, `callees`, `get_bytes`, `get_int`, `disasm`, and `int_convert`.
- MCP call IDs in this pass: `10` idb list, `11` health, `12` exact function lookups, `20`-`30` exact decompiles, `40` xrefs, `41` callees, `42` bytes, `43` ints, `50`-`52` bounded disassembly, `60` integer conversion.

## Positive Evidence

- `lookup_funcs` confirms exact modeled functions: constructor `0x0047ec70` size `0xb0`, register `0x0047ed50` size `0x30`, filtered unregister `0x0047ed80` size `0x98`, dispatch `0x0047ee20` size `0x75`, broad unregister `0x0047eea0` size `0x3f`, comparator `0x0047ef20` size `0x1f`, singleton clear `0x0047ef40` size `0xb`, scalar deleting destructor `0x0047ef50` size `0x5e`, and Application wrappers `0x004f4b30/0x004f4b50/0x004f4b70`.
- `lookup_funcs` confirms `0x0047ed20`, `0x00614cd0`, and `0x0067ab2c` are not functions; they are cleanup/data contexts, not missing source method starts.
- Constructor decompilation confirms `LObject` setup, `g_pChangeMan` publication, `ChangeMan` vtable store, 24-byte `SortedList` allocation, `SortedList(16, CompareChangeEntries, 100)`, and `m_changeList` at `this + 4`.
- Register and filtered unregister decompilation confirm a `ChangeManEntry` stack record, owner/listener/scope/messageType field order, sorted-list insert, first-equal lower-bound, same-owner scan, listener wildcard, exact scope-byte semantics, and remove-at count `1`.
- Dispatch decompilation/disassembly confirms owner lower-bound, list count read at `+0x0c`, entry fetch through vtable slot `+0x10`, owner break, exact scope behavior (`1` all messages, `0` type match, other nonzero skip), `Message::m_type` read at message `+0x04`, listener pointer at entry `+0x04`, listener virtual call through slot `+0x08`, and loop increment at `0x0047ee87` even for skipped records.
- Broad unregister decompilation/disassembly confirms reverse scan from count minus one, entry fetch through slot `+0x10`, removal when object equals either entry owner or entry listener, remove slot `+0x1c`, and count `1`.
- Destructor decompilation confirms scalar-deleting wrapper mechanics: vtable restore, virtual deletion of `m_changeList` with delete flag `1`, field clear, `g_pChangeMan` clear, `LObject` base cleanup, and optional object free gated by MSVC deleting flags.
- Xrefs confirm ownership and reachability: constructor has one caller at `0x004644c1` in Application initialization; register, filtered unregister, and dispatch each have one Application wrapper caller; broad unregister has two BackPane teardown callers; comparator has one constructor data ref; destructor has one vtable data ref; `g_pChangeMan` has exactly 11 xrefs.
- Data evidence confirms vtable and singleton storage: bytes at `0x00614ccc-0x00614ce0` decode to RTTI `0x00644090`, slots `0x0047ef50/0x004f4b10/0x0041b6c0`, and successor RTTI `0x00644168`; bytes at `0x0067ab24-0x0067ab38` are zero-initialized writable pointer storage and `get_int 0x0067ab2c` returns `0`.
- Padding evidence confirms boundaries: `0x0047ec6b-0x0047ec70`, `0x0047ee18-0x0047ee20`, `0x0047ef3f`, `0x0047ef4b-0x0047ef50`, and `0x0047efae-0x0047efb0` are `0xcc` alignment bytes.
- `int_convert` verifies `0x08 == 8`, `0x10 == 16`, `0x18 == 24`, `0x64 == 100`, `0x75 == 117`, `0x3f == 63`, `0x5e == 94`, and `0x0c == 12`.

## Negative Evidence

- No live evidence supports moving ChangeMan internals to Application: Application constructs the singleton and wraps calls, but ChangeMan owns the vtable, list field, entry type, comparator, global singleton, dispatch, and teardown behavior.
- No live evidence supports moving broad unregister to BackPane: BackPane is a lifecycle consumer and passes `this` through `g_pChangeMan`.
- No live evidence supports treating [UID:000103] as handwritten scalar-deleting-wrapper source. Its only external reference is the vtable slot, and the delete-flag/free path is MSVC ABI glue.
- No live evidence supports hand-emitting vtable bytes from [UID:0001X7] or [UID:0002M8]. The source should declare virtual class/destructor shape and let the compiler/linker produce the vtable.
- No live evidence supports duplicate bodies on aggregate pages [UID:0000ZU] or [UID:0000ZX]. Their exact children already carry or should carry the source method bodies.
- No live evidence supports file-local `static ChangeMan *g_pChangeMan` if `Application.cpp` remains a separate generated source file: Application wrapper leaves read the same global, so the source model needs a definition in `ChangeMan.cpp` and a header/external declaration route, not a private file-static symbol.
- Older optional split endpoints `0x0047ed73`, `0x0047ee1c`, and `0x0047ef33` remain stale and rejected; live function ranges are the current exact half-open ranges.

## Heuristic / Inference Reanalysis And Validation

### Empty-marker classification

The current empty markers are not one uniform problem. Two method pages have exact behavior and should now receive formal first-draft bodies. One semantic global should receive a source definition. Two type/layout pages should emit source declarations that support the method bodies. One class page should emit the ordinary destructor source because the exact scalar-deleting wrapper is not the right source target. The remaining pages are source-route/index/generated-binary evidence pages and should use formal comments to stop producing misleading empty markers without duplicating child bodies or compiler output.

### Source-quality names

The best current source names are `ChangeMan::Register`, filtered `ChangeMan::Unregister`, `ChangeMan::DispatchMessage`, `ChangeMan::UnregisterObject`, `ChangeManEntry`, `ChangeListener`, `OnChangeMessage`, and `ChangeMessageScope`. These are descriptive source-facing names, not recovered original header proof. The names are still better than raw `sub_` labels because Application wrapper docs, ChangeMan class docs, listener-slot behavior, and existing accepted B002/B010 reports all converge on this API family.

### Scope-byte validation

The scope field must not be collapsed to a plain boolean. Dispatch and filtered unregister both test exact byte value `1` as the all-message path and exact byte value `0` as the message-type path. Other nonzero values fail matching and still advance the loop. The report C++ therefore uses enum constants but stores the field as `unsigned char` in `ChangeManEntry`.

### Return-type validation

The decompiler returns `int` or `char` for some methods because helper calls leave values in `EAX`. Current caller evidence does not prove a public return contract for `Register`, filtered `Unregister`, or dispatch. Existing first-draft code already uses `void` for register/unregister. This report extends the same source-facing `void` treatment to dispatch and broad unregister because the wrappers and callers use side effects.

### Global linkage validation

The semantic global [UID:0000QI] is strong enough for a first-draft definition. The current by-global page's `static ChangeMan* g_pChangeMan` hypothesis is too conservative for the current source route because Application wrapper leaves are modeled outside `ChangeMan.cpp` and read the global. Recommended formal source is a normal external-linkage definition:

```cpp
ChangeMan *g_pChangeMan = NULL;
```

The corresponding header/export declaration can be documented on `ChangeMan` support docs later. The exact storage page [UID:0001P4] should not duplicate the definition.

## Ranked Ownership Analysis

1. [UID:0000I2] `ChangeMan.cpp` / [UID:00001K] `ChangeMan` class: accepted. Owns the singleton router, class layout, vtable, sorted registration list, entry type, comparator, global singleton definition, source methods, ordinary destructor source, and generated-binary vtable context.
2. [UID:0000HG] `Application`: rejected as owner. It constructs and forwards through wrappers but does not own ChangeMan state or behavior.
3. [UID:0000HO] `BackPane`: rejected as owner. It is a teardown consumer of broad unregister only.
4. [UID:0000NU]/[UID:0000DF] `SortedList`: rejected as ChangeMan owner. It owns list mechanics, not the ChangeMan records, comparator's source context, or singleton router.
5. New source file: rejected. Existing `by-file/ChangeMan.md` has a valid `NexusTK/app/` route and the current generated output already stages `ChangeMan.cpp`.
6. No-owner/non-emitting: rejected. Every empty target either has a proven source owner/emitter route or a target-specific duplicate/generated-binary no-code reason.

## Function / Child Inventory

| Range / item | UID/path | Role | Recommendation |
| --- | --- | --- | --- |
| class page | [UID:00001K] `by-class/ChangeMan.md` | class owner/scaffold | add ordinary destructor source body and update source-quality notes |
| `0x0047ee20-0x0047ee95` | [UID:0000ZZ] dispatch | source method | add first-draft formal C++ and raise score modestly |
| `0x0047eea0-0x0047eedf` | [UID:000100] broad unregister | source method | add first-draft formal C++ and raise score modestly |
| `0x0047ef50-0x0047efae` | [UID:000103] scalar deleting destructor | compiler wrapper | add formal no-code comment, keep no wrapper body |
| struct | [UID:0001TV] `ChangeManEntry` | source record | add first-draft enum/struct declaration |
| layout | [UID:0001TW] `ChangeManLayout` | class layout | add first-draft class declaration with `SortedList *m_changeList` |
| vtable type | [UID:0001X7] `ChangeManVtable` | compiler-generated virtual table model | add formal generated-binary comment |
| global | [UID:0000QI] `g_pChangeMan` | semantic singleton definition | add first-draft global definition |
| `0x0047ec70-0x0047efae` | [UID:0000ZU] broad ChangeMan range | aggregate/index | add covered-by-children comment |
| `0x0047ed50-0x0047ee18` | [UID:0000ZX] register pair index | aggregate/index | add covered-by exact children comment |
| `0x00614cd0-0x00614cdc` | [UID:0002M8] exact vtable data | generated-binary data | add formal generated-binary comment |
| `0x0067ab2c-0x0067ab30` | [UID:0001P4] exact singleton storage | generated-binary storage | add covered-by [UID:0000QI] comment |

## First-Draft C++ / No-Code Disposition

### [UID:00001K] `by-class/ChangeMan.md`

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
ChangeMan::~ChangeMan()
{
    delete m_changeList;
    m_changeList = NULL;
    g_pChangeMan = NULL;
}
```

Reason: [UID:000103] proves source-declared destructor semantics but should not emit scalar-deleting-wrapper code. The class page is the correct current source context for ordinary destructor source until a narrower normal-destructor by-memory page exists.

### [UID:0000ZZ] `by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md`

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
void ChangeMan::DispatchMessage(void *owner, Message *message)
{
    ChangeManEntry key;
    key.owner = owner;

    int index = m_changeList->FindFirstEqual(&key);
    if (index < 0)
        return;

    int count = m_changeList->GetCount();
    for (; index < count; ++index) {
        ChangeManEntry *entry =
            static_cast<ChangeManEntry *>(m_changeList->GetElementAt(index));
        if (entry->owner != owner)
            break;

        if (entry->scope == ChangeMessageScope_AllTypes ||
            (entry->scope == ChangeMessageScope_MatchType &&
             entry->messageType == message->m_type)) {
            entry->listener->OnChangeMessage(owner, message);
        }
    }
}
```

This preserves the exact skip behavior: nonmatching scope/type records do not dispatch but the loop still increments.

### [UID:000100] `by-memory/0x0047eea0-0x0047eedf.ChangeManUnregisterObject.md`

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
void ChangeMan::UnregisterObject(void *object)
{
    for (int index = m_changeList->GetCount() - 1; index >= 0; --index) {
        ChangeManEntry *entry =
            static_cast<ChangeManEntry *>(m_changeList->GetElementAt(index));
        if (entry->owner == object || entry->listener == object)
            m_changeList->RemoveRange(index, 1);
    }
}
```

### [UID:000103] `by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md`

Recommended formal no-code marker:

```cpp
// Source-level teardown is emitted as the ordinary ChangeMan destructor on
// [UID:00001K]. This page documents the MSVC scalar deleting destructor wrapper
// at 0x0047ef50-0x0047efae; do not hand-write the delete-flag wrapper body.
```

### [UID:0001TV] `by-type/by-struct/ChangeManEntry.md`

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
enum ChangeMessageScope {
    ChangeMessageScope_MatchType = 0,
    ChangeMessageScope_AllTypes = 1
};

struct ChangeManEntry {
    void *owner;
    ChangeListener *listener;
    unsigned char scope;
    unsigned char padding[3];
    unsigned int messageType;
};
```

The explicit padding preserves the `0x10` / 16-byte record and dword `messageType` at `+0x0c`.

### [UID:0001TW] `by-type/by-struct/ChangeManLayout.md`

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
class ChangeMan : public LObject {
public:
    ChangeMan();
    virtual ~ChangeMan();

    void Register(void *owner,
                  ChangeListener *listener,
                  unsigned int messageType,
                  ChangeMessageScope scope);
    void Unregister(void *owner,
                    ChangeListener *listener,
                    unsigned int messageType,
                    ChangeMessageScope scope);
    void DispatchMessage(void *owner, Message *message);
    void UnregisterObject(void *object);

private:
    SortedList *m_changeList;
};
```

### [UID:0001X7] `by-type/by-vtable/ChangeManVtable.md`

Recommended formal generated-binary marker:

```cpp
// ChangeMan vtable bytes are generated from the ChangeMan virtual declaration
// and ordinary destructor. Exact slot data is documented by [UID:0002M8];
// no handwritten vtable object should be emitted here.
```

### [UID:0000QI] `by-global/g_pChangeMan.md`

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
ChangeMan *g_pChangeMan = NULL;
```

This is intentionally not `static` under the current separated `Application.cpp` / `ChangeMan.cpp` route, because Application wrappers read the global.

### [UID:0000ZU] `by-memory/0x0047ec70-0x0047efae.ChangeMan.md`

Recommended formal covered-by marker:

```cpp
// This broad ChangeMan range is an index over exact children. Source emission is
// carried by the constructor/register/unregister/dispatch/comparator/global/type
// pages and by the ordinary destructor on [UID:00001K].
```

### [UID:0000ZX] `by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md`

Recommended formal covered-by marker:

```cpp
// Registration source bodies are emitted by [UID:0000ZW] ChangeManRegister and
// [UID:0000ZY] ChangeManUnregisterFiltered. This pair page is an index and
// should not duplicate either method body.
```

### [UID:0002M8] `by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md`

Recommended formal generated-binary marker:

```cpp
// Exact ChangeMan vtable data at 0x00614cd0-0x00614cdc is generated by the
// compiler/linker from the ChangeMan class declaration and destructor. The
// three slot values are evidence, not a handwritten source table.
```

### [UID:0001P4] `by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md`

Recommended formal covered-by marker:

```cpp
// Exact storage for g_pChangeMan is emitted by the semantic global declaration
// on [UID:0000QI]. This page documents the zero-initialized 0x0067ab2c storage
// and xref set without duplicating the source definition.
```

## Score And Metadata Recommendation

- [UID:0000I2] `by-file/ChangeMan.md`: `86/89` -> recommend `90/91`; owner/path unchanged.
- [UID:00001K] `by-class/ChangeMan.md`: `85/89` -> implemented `88/91`; owner/emitter unchanged through [UID:0000I2].
- [UID:0000ZZ] `ChangeManDispatchMessage`: `86/90` -> recommend `88/91`; owner/emitter unchanged through [UID:00001K].
- [UID:000100] `ChangeManUnregisterObject`: `86/91` -> recommend `88/92`; owner/emitter unchanged through [UID:00001K].
- [UID:000103] `ChangeManScalarDeletingDestructor`: keep `86/91`; add formal no-code marker and preserve source-declared/generated-binary rationale.
- [UID:0001TV] `ChangeManEntry`: `85/90` -> recommend `88/91`; owner/emitter unchanged through [UID:00001K].
- [UID:0001TW] `ChangeManLayout`: `85/90` -> recommend `88/91`; owner/emitter unchanged through [UID:00001K].
- [UID:0001X7] `ChangeManVtable`: keep `86/91` or raise to `87/92` after formal generated-binary marker; owner/emitter unchanged through [UID:00001K].
- [UID:0000QI] `g_pChangeMan`: `89/86` -> recommend `91/90`; owner/emitter unchanged through [UID:0000I2].
- [UID:0000ZU] `ChangeMan` aggregate: keep `86/90`; add formal covered-by marker.
- [UID:0000ZX] `ChangeManRegistrationMethods` aggregate: keep `86/90`; add formal covered-by marker.
- [UID:0002M8] `ChangeManVtableData`: keep `86/91`; add formal generated-binary marker.
- [UID:0001P4] `g_pChangeMan` exact storage: `86/90` -> implemented `88/91`; add formal covered-by marker.
- Do not change `CANONICAL_OWNER`, `RECONSTRUCTABLE`, `EMITTER_UIDS`, projected path, ranges, filenames, or child splits.
- Do not use `95+` scores: listener/interface/header spellings and final `SortedList` declaration names remain descriptive rather than source-proven.

## Recommended Target Doc Changes

Update `by-file/ChangeMan.md`:

- Raise score to `90/91`.
- Record that the 12 empty emitters are implementation-ready: two method bodies, ordinary destructor source, global definition, struct/class declarations, and formal covered-by/generated-binary comments.
- Preserve current source placement `NexusTK/app/ChangeMan.cpp`; reject Application/BackPane/SortedList ownership.
- Add live MCP provenance from session `supervisor_resume_20260629`, including health, exact function sizes, xrefs, vtable bytes, singleton xrefs, and padding checks.
- Update Proposed Contents/Likely Contents to include formal emission routes for [UID:0000ZZ], [UID:000100], [UID:00001K], [UID:0001TV], [UID:0001TW], [UID:0000QI], and marker-only routes for [UID:000103], [UID:0000ZU], [UID:0000ZX], [UID:0001X7], [UID:0002M8], and [UID:0001P4].
- State generated-output expectation: after implementation validators, `auto-generated/NexusTK/app/ChangeMan.cpp` should have 16 filled emitters, 0 empty markers.

## Recommended Support Doc Changes

- `by-class/ChangeMan.md`: add ordinary destructor formal C++, score `88/91`, update method map/source-quality note that destructor semantics are emitted here while scalar deleting wrapper remains generated-binary support; preserve listener/scope/source-name caveats.
- `by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md`: insert formal C++, score `88/91`, update status/changes with live disassembly loop-increment proof.
- `by-memory/0x0047eea0-0x0047eedf.ChangeManUnregisterObject.md`: insert formal C++, score `88/92`, update status/changes with reverse-walk proof and BackPane caller proof.
- `by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md`: insert formal no-code marker, keep score, document that ordinary destructor now belongs on [UID:00001K].
- `by-type/by-struct/ChangeManEntry.md`: insert formal enum/struct declaration, score `88/91`, preserve exact size/offset/padding caveat and source-name provisionality.
- `by-type/by-struct/ChangeManLayout.md`: insert formal class declaration, score `88/91`, preserve `SortedList *m_changeList` at `+0x04` and object size `0x08`.
- `by-type/by-vtable/ChangeManVtable.md`: insert formal generated-binary marker and update stale "95/95" wording to current combined-score/source-quality rule if still present.
- `by-global/g_pChangeMan.md`: insert formal global definition, score `91/90`, replace the too-conservative `static` hypothesis with "normal external-linkage definition in ChangeMan.cpp plus header declaration route remains final-source detail."
- `by-memory/0x0047ec70-0x0047efae.ChangeMan.md`: insert formal covered-by-children marker and update evidence summary with live MCP session.
- `by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md`: insert formal covered-by-child marker; no duplicate method bodies.
- `by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md`: insert formal generated-binary marker; preserve exact bytes and boundary evidence.
- `by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md`: insert formal covered-by [UID:0000QI] marker, score `88/91`, preserve exact zeroed storage and 11-xref set.
- Optional support not required in this callback: Application wrapper docs, BackPane docs, SortedList docs, and Message docs already carry sufficient support evidence for this first batch.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0000I2-01 | [UID:0000I2] remains the canonical source file/emitter for ChangeMan family. | High | Current by-file path, generated route, live function/data xrefs. | `by-file/ChangeMan.md` Status, File Role, Likely Contents, `2026-07-01 B009 Empty-Emitter Implementation`, Changes; score `90/91` | incorporate | applied |
| C-00001K-01 | Ordinary `ChangeMan::~ChangeMan()` source belongs on class/source context, not scalar-deleting wrapper page. | High | Destructor wrapper decompile, vtable-only xref, B010 no-code proof. | `by-class/ChangeMan.md` formal C++, method map, `2026-07-01 B009 Empty-Emitter Implementation`, Changes; score `88/91` | incorporate | applied |
| C-0000ZZ-01 | `DispatchMessage` is first-draft C++ ready. | High | Live decompile/disasm/xref; exact scope/message/listener behavior. | `by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md` metadata, formal C++, evidence, changes; score `88/91` | incorporate | applied |
| C-000100-01 | `UnregisterObject` is first-draft C++ ready. | High | Live decompile/disasm/xrefs; reverse walk and BackPane callers. | `by-memory/0x0047eea0-0x0047eedf.ChangeManUnregisterObject.md` metadata, formal C++, evidence, changes; score `88/92` | incorporate | applied |
| C-000103-01 | Scalar deleting destructor remains generated-binary support and should emit only a formal no-code marker. | High | Vtable-slot-only xref and MSVC delete-flag mechanics. | `by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md` formal marker, reconstruction notes, changes; score `86/91` | incorporate | applied |
| C-0001TV-01 | `ChangeManEntry` declaration is first-draft ready with explicit padding. | High | Live register/dispatch/unregister/comparator evidence and size conversion. | `by-type/by-struct/ChangeManEntry.md` formal C++, layout, score rationale, changes; score `88/91` | incorporate | applied |
| C-0001TW-01 | `ChangeMan` layout declaration is first-draft ready. | High | Constructor/destructor decompile; object size 8 and `m_changeList` at `+0x04`. | `by-type/by-struct/ChangeManLayout.md` formal C++, layout, changes; score `88/91` | incorporate | applied |
| C-0001X7-01 | Vtable type should not hand-emit a vtable object. | High | Exact vtable bytes and compiler generation route. | `by-type/by-vtable/ChangeManVtable.md` formal generated-binary marker, status, changes; score `86/91` | incorporate | applied |
| C-0000QI-01 | Semantic global should emit `ChangeMan *g_pChangeMan = NULL;` with non-static external linkage under current source split. | Medium-high | 11 xrefs, Application wrappers read global from separate route, zero-initialized storage. | `by-global/g_pChangeMan.md` formal C++, status, type hypothesis, score rationale, changes; score `91/90` | incorporate | applied |
| C-0000ZU-01 | Broad ChangeMan memory range is a covered-by-children index and should not duplicate bodies. | High | Exact child pages carry bodies; live range inventory. | `by-memory/0x0047ec70-0x0047efae.ChangeMan.md` formal marker, B009 section, Changes; score `86/90` | incorporate | applied |
| C-0000ZX-01 | RegistrationMethods aggregate is covered by [UID:0000ZW] and [UID:0000ZY]. | High | Existing exact child bodies and live range/xref evidence. | `by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md` formal marker, reconstruction guidance, Changes; score `86/90` | incorporate | applied |
| C-0002M8-01 | Exact vtable data is compiler/linker output from class declaration, not handwritten source. | High | Bytes/ints/xrefs at `0x00614cd0`; RTTI boundaries. | `by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md` formal marker, Summary, Changes; score `86/91` | incorporate | applied |
| C-0001P4-01 | Exact singleton storage is covered by semantic global [UID:0000QI], not a duplicate source definition. | High | Zeroed storage and 11 xrefs; semantic global owner. | `by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md` formal marker, B009 section, score rationale, Changes; score `88/91` | incorporate | applied |
| C-NEG-01 | Reject Application, BackPane, SortedList, no-owner, and stale split endpoint alternatives. | High | Live xrefs/callees and prior report validation. | `by-file/ChangeMan.md` `2026-07-01 B009 Empty-Emitter Implementation`; `by-class/ChangeMan.md` B009 section; relevant target evidence sections | incorporate | applied |

## Open Questions With Attempted Resolution

- Exact original listener interface and callback spelling remain unresolved. Current best names are `ChangeListener` and `OnChangeMessage`; this caps confidence below final audit but does not block first-draft method C++.
- Exact public header split remains unresolved. Current implementation recommendation emits declarations into existing type/class/global pages; final project integration may later move declarations into a header.
- Exact `SortedList` method names remain descriptive. Existing accepted code already uses `InsertSorted`, `FindFirstEqual`, `GetElementAt`, `GetCount`, and `RemoveRange`; this report does not reopen those helper pages.
- Exact global linkage spelling is not source-proven. Under the current separated file route, non-static `ChangeMan *g_pChangeMan = NULL;` is more source-correct than a file-static definition because Application wrappers read the same global.

## Validator / Generated Refresh Expectations

Implementation validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the accepted by-* edits. All exited `0` with `ok: 1`:

| File | Command ID | Start UTC | End UTC | Exit | OK |
| --- | --- | --- | --- | ---: | ---: |
| `by-class/ChangeMan.md` | `000000003544` | `2026-07-01T10:13:48.8324129Z` | `2026-07-01T10:13:52.5637156Z` | 0 | 1 |
| `by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md` | `000000003546` | `2026-07-01T10:13:52.6000587Z` | `2026-07-01T10:14:03.8647597Z` | 0 | 1 |
| `by-memory/0x0047eea0-0x0047eedf.ChangeManUnregisterObject.md` | `000000003548` | `2026-07-01T10:14:03.8687646Z` | `2026-07-01T10:14:14.3727075Z` | 0 | 1 |
| `by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md` | `000000003550` | `2026-07-01T10:14:14.3777109Z` | `2026-07-01T10:14:24.9072342Z` | 0 | 1 |
| `by-type/by-struct/ChangeManEntry.md` | `000000003552` | `2026-07-01T10:14:24.9122344Z` | `2026-07-01T10:14:36.4360183Z` | 0 | 1 |
| `by-type/by-struct/ChangeManLayout.md` | `000000003554` | `2026-07-01T10:14:36.4407059Z` | `2026-07-01T10:14:46.9652906Z` | 0 | 1 |
| `by-type/by-vtable/ChangeManVtable.md` | `000000003556` | `2026-07-01T10:14:46.9692961Z` | `2026-07-01T10:14:57.5184846Z` | 0 | 1 |
| `by-global/g_pChangeMan.md` | `000000003558` | `2026-07-01T10:14:57.5234918Z` | `2026-07-01T10:15:08.5454919Z` | 0 | 1 |
| `by-memory/0x0047ec70-0x0047efae.ChangeMan.md` | `000000003560` | `2026-07-01T10:15:08.5505051Z` | `2026-07-01T10:15:19.0707045Z` | 0 | 1 |
| `by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md` | `000000003562` | `2026-07-01T10:15:19.0757152Z` | `2026-07-01T10:15:30.3224884Z` | 0 | 1 |
| `by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md` | `000000003564` | `2026-07-01T10:15:30.3274894Z` | `2026-07-01T10:15:42.3282822Z` | 0 | 1 |
| `by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md` | `000000003566` | `2026-07-01T10:15:42.3322906Z` | `2026-07-01T10:15:53.3416495Z` | 0 | 1 |
| `by-file/ChangeMan.md --wait-generated` | `000000003569` | `2026-07-01T10:15:53.3486493Z` | `2026-07-01T10:16:15.1611624Z` | 0 | 1 |

Generated refresh proof: `auto-generated/NexusTK/app/ChangeMan.cpp` has header `validator-command-id: 000000003571`, `validator-refreshed-at: 2026-07-01T06:16:25-04:00`, and filesystem `LastWriteTimeUtc 2026-07-01T10:16:28Z`. `rg "Empty Emitter Marker|empty marker|empty emit"` found no matches in `auto-generated/NexusTK/app/ChangeMan.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, or `auto-generated/-ag-type-coverage.md`. The tracker row for [UID:0000I2] now reports `16` total emitters, `16` filled, `0` empty, `100.0%`.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B009/research/0000I2-ChangeMan-empty-emitter-family-source-quality.md`
- Modified by implementation callback: `by-class/ChangeMan.md`; `by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md`; `by-memory/0x0047eea0-0x0047eedf.ChangeManUnregisterObject.md`; `by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md`; `by-type/by-struct/ChangeManEntry.md`; `by-type/by-struct/ChangeManLayout.md`; `by-type/by-vtable/ChangeManVtable.md`; `by-global/g_pChangeMan.md`; `by-memory/0x0047ec70-0x0047efae.ChangeMan.md`; `by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md`; `by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md`; `by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md`; `by-file/ChangeMan.md`; this report.
- Generated by validator only, not manually edited: `auto-generated/NexusTK/app/ChangeMan.cpp` and generated tracker/coverage outputs.
- Leases: B009 leased the 13 edited by-* target/support docs, re-leased the same exact set before validation after the earlier lease window expired, and released all 13 successfully immediately after the validator batch. Current lease report has no B009/ChangeMan/g_pChangeMan lines.

## Implementation Tracking Checklist

Report-only pass:
- [x] Supervisor validation required before implementation.
- [x] Target/support docs to update identified.
- [x] Current target state and generated empty markers recorded.
- [x] Live IDA MCP evidence used and provenance recorded.
- [x] Prior executed ChangeMan reports searched/opened as leads and rechecked against live evidence.
- [x] Claim And Incorporation Ledger updated with destination and report-only verification state for every accepted claim.
- [x] Score/metadata changes to apply recorded.
- [x] Owner/emitter/reconstructable changes to apply: no owner/emitter/reconstructable route changes recommended.
- [x] Split/rename/new-child changes to apply: none; stale split endpoints rejected.
- [x] Source-placement, range/split/padding/reclassification, and generated-binary status recorded.
- [x] First-draft C++ or no-code/covered-by proof supplied in formal insertion shape for every empty marker.
- [x] Open questions closed or documented with evidence-backed unresolved rationale.
- [x] Validators deferred to implementation callback.
- [x] Generated report refresh expectation documented.

Implementation callback pass:
- [x] Add ordinary destructor formal C++ and source-quality notes to `by-class/ChangeMan.md`; updated score to `88/91`.
- [x] Add first-draft formal C++ to `by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md`; updated score to `88/91`; preserved loop-increment and scope-byte evidence.
- [x] Add first-draft formal C++ to `by-memory/0x0047eea0-0x0047eedf.ChangeManUnregisterObject.md`; updated score to `88/92`; preserved BackPane caller/reverse-walk evidence.
- [x] Add formal no-code/generated-wrapper marker to `by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md`; kept score and wrapper proof.
- [x] Add formal enum/struct declaration to `by-type/by-struct/ChangeManEntry.md`; updated score to `88/91`; preserved size/offset/padding/scope caveats.
- [x] Add formal class layout declaration to `by-type/by-struct/ChangeManLayout.md`; updated score to `88/91`; preserved object-size/list-member evidence.
- [x] Add formal generated-binary marker to `by-type/by-vtable/ChangeManVtable.md`; updated stale gate wording.
- [x] Add formal global definition to `by-global/g_pChangeMan.md`; updated score to `91/90`; replaced static-only hypothesis with current external-linkage rationale.
- [x] Add formal covered-by-children marker to `by-memory/0x0047ec70-0x0047efae.ChangeMan.md`; preserved child inventory and padding evidence.
- [x] Add formal covered-by-exact-children marker to `by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md`; preserved aggregate/index handling.
- [x] Add formal generated-binary marker to `by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md`; preserved exact slot/RTTI bytes.
- [x] Add formal covered-by-global marker to `by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md`; updated score to `88/91`.
- [x] Update `by-file/ChangeMan.md` to score `90/91` and incorporate report-level owner/emitter/source-placement/generated-output evidence.
- [x] Preserve rejected alternatives: Application owner, BackPane owner, SortedList owner, no-owner/non-emitting route, scalar deleting wrapper hand-emission, duplicate aggregate bodies, and stale split endpoints.
- [x] Run the scoped validators listed above and record command IDs, timestamps, exit codes, ok counts, warnings, and generated refresh side effects.
- [x] Verify `auto-generated/NexusTK/app/ChangeMan.cpp` is fresh for the final by-file validator command and has no `Empty Emitter Marker`.
- [x] Update this report's Claim And Incorporation Ledger and checklist with `applied` proof during the callback.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0000I2-ChangeMan-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0000I2-ChangeMan-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T06:21:54","uid":"0000I2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
