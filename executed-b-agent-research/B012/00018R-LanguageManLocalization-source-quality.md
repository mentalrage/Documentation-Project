** TARGET-REPORT-UID:00018R **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B012 Research Report: 00018R LanguageMan Localization

Report-only pass for [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](../../../../../by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md). No by-* documentation, generated reports, validator state/cache, coverage reports, IDA database state, or generated C++ files were edited.

## Assignment And Constraints

- Agent: `Agent-B012`.
- Target: `by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md`.
- Required report path: `tools/leaser/Agents/Agent-B012/research/00018R-LanguageManLocalization-source-quality.md`.
- Mode: report-only first pass. Implementation edits require supervisor validation and callback.
- IDA MCP: mandatory and used successfully.
- Subagents: not used.
- Leases: none taken, because this pass made no target/support documentation edits.

## Executive Finding

`00018R` is not a single source-emitting C++ unit. It is a reviewed executable island and split index over the LanguageMan constructor, destructor, zero-initializer orphan, lookup/copy/clear helpers, scalar deleting destructor wrapper, and internal `0xcc` alignment. The page should not emit aggregate C++ through `LanguageMan.cpp`.

Recommended target result:

| Field | Recommendation |
| --- | --- |
| `COMPLETION` | raise from `88` to `90` after adding current MCP split evidence |
| `CONFIDENCE` | raise from `91` to `92` |
| `CANONICAL_OWNER` | change from `0000KK` to `NONE` |
| `RECONSTRUCTABLE` | change from `TRUE` to `FALSE` |
| `EMITTER_UIDS` | clear the current `0000KK` emitter |
| `RECONSTRUCTION_CPP CODE` | keep blank; no aggregate formal C++ should be inserted |

Implementation should create an exact constructor child for `0x004f0010-0x004f028c` and make that child the source-bearing constructor page. Existing exact children already own the destructor, zero-initializer orphan, lookup helpers, clear helper, and scalar deleting destructor wrapper. The constructor child is ready for class ownership and source emission through [UID:000071][LanguageMan](../../../../../by-class/LanguageMan.md); `00018R` remains the non-emitting island map.

## IDA MCP Session

Mandatory MCP checks succeeded against the active IDB.

| Check | Result |
| --- | --- |
| Active database | session `80de0a67` |
| IDB | `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Module | `NexusTK.exe` |
| Worker PID | `26892` |
| Health | ok; auto-analysis ready; Hex-Rays ready; strings cache ready |

Rework status checks also confirmed listener `127.0.0.1:13337`, process `python.exe` PID `13684`, MCP session `57d9094b-2370-4930-a720-627e62710575`, and the same active database session `80de0a67`. IDA MCP evidence used: `server_health`, `lookup_funcs`, `analyze_component`, `decompile`, `callees`, `xref_query`, `get_bytes`, `get_string`, `insn_query`, `stack_frame`, and `entity_query`.

## Exact Function Map

Current MCP confirms the island is a sequence of independent function bodies and padding, not one source body.

| Range | IDA status | Current documentation role | Report disposition |
| --- | --- | --- | --- |
| `0x004f0010-0x004f028c` | `sub_4F0010`, size `0x27c` | LanguageMan constructor / `str.res` loader | Create exact source-bearing constructor child with class owner/emitter and formal C++ |
| `0x004f028c-0x004f0290` | bytes only | padding | keep in aggregate evidence |
| `0x004f0290-0x004f0310` | stale IDA name `??1exception@boost@@MAE@XZ_3`, size `0x80` | [UID:00018S][LanguageManCleanupDestructor](../../../../../by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md) | exact child already emits destructor C++ |
| `0x004f0310-0x004f0342` | `sub_4F0310`, size `0x32` | [UID:00018T][LocalizationAdjacentZeroInitializer](../../../../../by-memory/0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md) | exact file-level orphan; C++ remains blank |
| `0x004f0342-0x004f0350` | bytes only | padding | keep in aggregate evidence |
| `0x004f0350-0x004f0372` | `sub_4F0350`, size `0x22` | [UID:00040P][LanguageManGetLocalizedString](../../../../../by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md) | exact child already emits direct lookup C++ |
| `0x004f0372-0x004f0380` | bytes only | padding | keep in aggregate evidence |
| `0x004f0380-0x004f03bb` | `sub_4F0380`, size `0x3b` | [UID:00040Q][LanguageManCopyLocalizedString](../../../../../by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md) | exact child; C++ still blocked by public string-return signature |
| `0x004f03bb-0x004f03c0` | bytes only | padding | keep in aggregate evidence |
| `0x004f03c0-0x004f03cb` | `sub_4F03C0`, size `0x0b` | [UID:00040R][LanguageManClearSingletonHelper](../../../../../by-memory/0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper.md) | exact child already emits file-local clear helper C++ |
| `0x004f03cb-0x004f03d0` | bytes only | padding | keep in aggregate evidence |
| `0x004f03d0-0x004f0477` | `sub_4F03D0`, size `0xa7` | [UID:00018V][LanguageManScalarDeletingDestructor](../../../../../by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md) | exact child emits no-code marker only |
| `0x004f0477-0x004f0480` | bytes only | tail padding before successor | keep in aggregate evidence; successor `0x004f0480` is separate |

## Caller, Callee, And Xref Evidence

Current MCP xrefs:

| Target | Result |
| --- | --- |
| Constructor `0x004f0010` | one code xref at `0x00464108` in `Application::Initialize` function `sub_4639D0` |
| Destructor `0x004f0290` | no direct start xrefs; called through compiler/vtable lifecycle paths |
| Zero helper `0x004f0310` | no direct start xrefs |
| Zero-helper tail `0x004f0342` | no xrefs |
| Direct lookup `0x004f0350` | 351 direct code xrefs; first observed at `0x0041ba63`, `0x00464375`, `0x00464434`, `0x0046c3df`, `0x0046f255` |
| Copy helper `0x004f0380` | two direct code xrefs at `0x00530c27` and `0x005c08a2` |
| Clear helper `0x004f03c0` | one code xref at `0x00600a64` from the constructor cleanup path |
| Scalar deleting destructor `0x004f03d0` | one data xref from vtable slot storage at `0x0061c9e0` |
| Tail boundary `0x004f0477` | no xrefs |
| LanguageMan vtable slot `0x0061c9e0` | three refs: constructor `0x004f007b`, destructor `0x004f02b7`, scalar wrapper `0x004f03fe` |
| Singleton `0x0067a750` | 192 refs; constructor writes it at `0x004f0066`/`0x004f006d`, destructor clears it at `0x004f02ef`, clear helper at `0x004f03c0`, scalar wrapper at `0x004f0431` |

Current MCP callees:

- Constructor calls the LObject shell constructor, DAT file helpers, MemoryMan allocation/free/copy helpers, `MultiByteToWideChar`, MyError construction/allocation, `_CxxThrowException`, security-cookie support, and DAT cleanup.
- Destructor calls MemoryMan allocation context, buffer-free helper, and LObject base cleanup.
- Zero helper, direct lookup, and clear helper have no callees.
- Copy helper calls `0x00582560`.
- Scalar deleting destructor calls the same cleanup/free/base helpers plus delete wrapper and guard-check support.

## Resource And String Evidence

Current MCP `get_string` and xrefs confirm the LanguageMan string-resource evidence:

| Address | String | Xref evidence |
| --- | --- | --- |
| `0x0061c9ec` | `str.res` | one constructor ref at `0x004f0099` |
| `0x0061c9fc` | `Too many strings` | one constructor throw-path ref at `0x004f0261` |
| `0x0061ca20` | `Invalid String ID` | two refs from direct lookup `0x004f0369` and copy helper `0x004f03a9` |
| `0x00676f04` | `.?AVLanguageMan@@` | RTTI/name evidence for `LanguageMan` |

Current MCP `entity_query` found 11 `LanguageMan` names, including `LanguageMan` RTTI and `Singleton<LanguageMan>` RTTI/name records. It found zero `LanguageManager` names. This supports keeping `LanguageManager` as an alias/view-only page, not a source class owner.

The constructor decompilation confirms the parser behavior already documented on the target/support pages: it opens `str.res`, reads byte lines up to the `0x400` cap, maps byte `0x11` to carriage return, converts through `MultiByteToWideChar`, stores allocated wide strings, throws `Too many strings` when the count reaches `0x400`, then copies the temporary pointer table into the final table. Current MCP `insn_query` found the three `0x400` immediates at `0x004f011f`, `0x004f0167`, and `0x004f01d1`.

## Padding And Boundaries

Current MCP `get_bytes` confirms all internal gaps are `0xcc` alignment:

| Range | Bytes |
| --- | --- |
| `0x004f0008-0x004f0010` | eight `0xcc` bytes before the LanguageMan island |
| `0x004f028c-0x004f0290` | four `0xcc` bytes |
| `0x004f0342-0x004f0350` | fourteen `0xcc` bytes |
| `0x004f0372-0x004f0380` | fourteen `0xcc` bytes |
| `0x004f03bb-0x004f03c0` | five `0xcc` bytes |
| `0x004f03cb-0x004f03d0` | five `0xcc` bytes |
| `0x004f0477-0x004f0480` | nine `0xcc` bytes before successor `0x004f0480` |

These bytes are part of the aggregate's boundary proof only. They should not be emitted as source and should not be merged into neighboring exact child pages.

## C++ Readiness

No formal aggregate C++ is defensible for `00018R`.

Target-specific no-code proof:

- The range is not one function, class method, global declaration, or source construct.
- Existing exact children already carry their own source decisions.
- Emitting aggregate C++ would duplicate child output for the destructor, direct lookup, clear helper, and scalar deleting destructor marker.
- The scalar deleting destructor is compiler-generated wrapper glue and must not be hand-authored as ordinary LanguageMan source.
- The zero helper writes only offsets `+0x0c` through `+0x24`, has no callers/callees/xrefs, and remains a file-level orphan/private helper rather than a proven LanguageMan class method.
- The constructor is the only source-authored executable body in the aggregate without an exact child page; that is a split defect, not a reason to place constructor C++ on the aggregate page.

Constructor child source decision:

- New exact child path: `by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md`.
- Recommended child metadata: `COMPLETION:91`, `CONFIDENCE:92`, `CANONICAL_OWNER:000071`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000071`, blank `EMITTER_POSITION_OPTIONAL`.
- Owner proof: the body calls the LObject shell constructor, installs the LanguageMan vtable at `0x0061c9e0`, publishes `g_pLanguageMan`, initializes the class string-table fields at `+0x04` and `+0x08`, opens `str.res`, and is called once from `Application::Initialize` at `0x00464108`.
- DATFile source shape: use `DATFile::DATFile`, `Open`, `GetSize`, `Tell`, `Read`, `Seek`, and `~DATFile`. `Seek(1, 1)` is current-position relative and skips the LF after a CR line ending.
- Memory helper source shape: use `MemoryMan* memoryMan = GetMemoryMan()` with the same member-style allocation/free spelling already used by the accepted LanguageMan destructor C++ (`memoryMan->AllocateBufferMemory` and `memoryMan->FreeBufferMemory`). Use `MemmoveWrapper` for the documented copy helper. No raw `malloc`, `free`, or CRT `memmove` spelling is supported for this child.
- MyError throw shape: use `throw MyError(kTooManyStringsMessage)`. MCP shows `operator new(8)`, `MyError::MyError(L"Too many strings")`, and `_CxxThrowException`; the source-facing type is the documented `MyError`.
- Parser locals: model the local pointer table as `temporaryStrings`, the `0x800` byte stack region as `char multiByteLine[kMaxStringResourceLineBytes * 2]`, the `0x400` wide stack region as `wchar_t wideLine[kMaxStringResourceLineBytes]`, and the EOF flag as `reachedEndOfFile`.
- String-table source shape: preserve the binary's post-store/post-increment overflow check. The code stores the new pointer at `temporaryStrings[m_stringCount]`, increments `m_stringCount`, and then throws if the old stored index is `>= kMaxLocalizedStringCount`.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text for `by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md`:

```cpp
LanguageMan::LanguageMan()
{
    g_pLanguageMan = this;
    MemoryMan* memoryMan = GetMemoryMan();

    DATFile stringResource;
    stringResource.Open(kStringResourceName);
    (void)stringResource.GetSize();

    wchar_t **temporaryStrings =
        static_cast<wchar_t **>(
            memoryMan->AllocateBufferMemory(sizeof(wchar_t *) * kMaxLocalizedStringCount));
    m_stringCount = 0;

    bool reachedEndOfFile = false;
    char multiByteLine[kMaxStringResourceLineBytes * 2];
    wchar_t wideLine[kMaxStringResourceLineBytes];

    do {
        int lineLength = 0;

        while (stringResource.Tell() < stringResource.GetSize()) {
            stringResource.Read(&multiByteLine[lineLength], 1);

            if (multiByteLine[lineLength] == '\r') {
                stringResource.Seek(1, 1);
                break;
            }

            if (multiByteLine[lineLength] == '\n' || ++lineLength >= kMaxStringResourceLineBytes)
                break;
        }

        if (stringResource.Tell() >= stringResource.GetSize())
            reachedEndOfFile = true;

        for (int i = 0; i < lineLength; ++i) {
            if (multiByteLine[i] == 0x11)
                multiByteLine[i] = '\r';
        }

        const int wideChars = MultiByteToWideChar(
            0,
            0,
            multiByteLine,
            lineLength,
            wideLine,
            kMaxStringResourceLineBytes);
        const size_t byteCount = static_cast<size_t>(wideChars) * sizeof(wchar_t);
        wchar_t *copiedLine =
            static_cast<wchar_t *>(
                memoryMan->AllocateBufferMemory(byteCount + sizeof(wchar_t)));

        temporaryStrings[m_stringCount] = copiedLine;
        MemmoveWrapper(temporaryStrings[m_stringCount], wideLine, byteCount);
        temporaryStrings[m_stringCount][wideChars] = L'\0';

        const int storedIndex = m_stringCount++;
        if (storedIndex >= kMaxLocalizedStringCount)
            throw MyError(kTooManyStringsMessage);
    } while (!reachedEndOfFile);

    m_strings =
        static_cast<wchar_t **>(memoryMan->AllocateBufferMemory(sizeof(wchar_t *) * m_stringCount));
    for (int i = 0; i < m_stringCount; ++i)
        m_strings[i] = temporaryStrings[i];

    memoryMan->FreeBufferMemory(temporaryStrings);
}
```

The copy helper at `0x004f0380` is narrower after current StringBase work: `0x00582560` is now documented as the wide raw StringBase initializer/copy helper under [UID:0002RM][StringBaseConversionAndCrtShims](../../../../../by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md). However, the LanguageMan-facing public signature is still unresolved: the observed output pointer can represent an explicit output parameter, a reference return, or a hidden return-by-value string object. Keep [UID:00040Q][LanguageManCopyLocalizedString](../../../../../by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md) C++ blank until that signature is decided.

## Owner And Emitter Recommendation

Positive ownership evidence:

- The island is physically bounded between KeySpeedMgr predecessor padding and the Layer-family successor.
- `LanguageMan` RTTI and `Singleton<LanguageMan>` metadata are present; `LanguageManager` metadata is absent.
- Constructor, destructor, lookup, copy, clear, and scalar wrapper all share the same singleton, vtable, string table, and resource literals.
- `by-file/LanguageMan.md` remains the correct source root for the family, and `by-class/LanguageMan.md` remains the correct class context for class methods.

Negative aggregate-emitter evidence:

- The aggregate has no source-level identity independent of its exact child functions.
- The current `CANONICAL_OWNER:0000KK` / `EMITTER_UIDS:0000KK` route causes an empty generated marker for a page that should be an index.
- The accepted [UID:00018U][LanguageManLookupAndSingletonHelpers](../../../../../by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md) split-index precedent uses `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank emitters while exact child pages carry the real source decisions. `00018R` should follow the same pattern at the larger island level.

Recommended metadata:

- `00018R`: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.
- New constructor child `by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md`: new UID assigned by the normal documentation workflow, `COMPLETION:91`, `CONFIDENCE:92`, `CANONICAL_OWNER:000071`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000071`, blank `EMITTER_POSITION_OPTIONAL`, and the formal constructor C++ above. The child clears the code-entry gate because `(91 + 92) / 2 = 91.5` and has a valid class-to-file emitter route through [UID:000071][LanguageMan](../../../../../by-class/LanguageMan.md) to [UID:0000KK][LanguageMan file](../../../../../by-file/LanguageMan.md).

Recommended constructor child item summary:

`Exact LanguageMan constructor body at 0x004f0010-0x004f028c. The constructor initializes the LanguageMan singleton and string-table fields, opens str.res through DATFile, parses up to 1024 localized-string records with 0x11-to-CR remapping and MultiByteToWideChar conversion, allocates/copies owned wide strings through the MemoryMan buffer helpers, throws MyError on the post-store 1024-entry overflow path, and copies the temporary pointer table into m_strings before DATFile cleanup.`

## Rejected Alternatives

- Keep `00018R` as reconstructable/emitting file-owned code: rejected because it is a split index and would duplicate or obscure exact child output.
- Assign `00018R` directly to [UID:000071][LanguageMan](../../../../../by-class/LanguageMan.md): rejected because the aggregate includes file-level clear helper, file-level zero-initializer orphan, compiler-generated wrapper glue, and padding.
- Treat `LanguageManager` as the class owner: rejected because current MCP finds LanguageMan/Singleton<LanguageMan> RTTI names and no LanguageManager names.
- Attach `0x004f0310` as a class method or extend LanguageMan layout through `+0x24`: rejected because the helper has no callers/callees/xrefs and the confirmed LanguageMan methods use only vptr, `+0x04` string table, and `+0x08` count.
- Emit constructor C++ on the aggregate as a shortcut: rejected because constructor source should live on an exact child page.
- Keep the constructor child non-emitting or file-owned: rejected because the exact constructor body has direct class evidence, a valid class emitter route, a code-entry score above threshold, and resolved helper/source-shape details.
- Spell constructor allocation/copy/free as raw CRT calls: rejected because MCP reaches the documented project wrappers `AllocateBufferMemory`, `MemmoveWrapper`, and `FreeBufferMemory`.
- Replace the constructor table with `StringBase` or a higher-level container: rejected because the binary stores raw allocated `wchar_t *` entries in `m_strings`; `StringBase` uncertainty applies only to the later copy helper `0x004f0380`.
- Hand-edit generated files, coverage reports, validator cache/state, or IDA names: rejected by assignment constraints.

## Recommended Documentation Edits If Approved

Target page [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](../../../../../by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md):

- Change metadata to non-emitting split/index: `90/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.
- Replace the item summary so it no longer says the adjacent zero-initializer is unresolved by owner. The current state is file-level ownership with unresolved class/object semantics.
- Add current MCP evidence for session `80de0a67`: function map, caller/xref counts, vtable refs, singleton refs, string refs, and padding bytes.
- Add explicit no-aggregate-C++ proof.
- Link the new exact constructor child `by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md` as the owner of the constructor subrange.

New by-memory constructor child:

- Create `by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md` with a new UID assigned by the normal documentation workflow.
- Set metadata to `COMPLETION:91`, `CONFIDENCE:92`, `CANONICAL_OWNER:000071`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000071`, blank `EMITTER_POSITION_OPTIONAL`.
- Use the item summary text from this report and insert the exact formal constructor C++ from this report.
- Record exact range, one caller at `0x00464108`, no overlap with destructor/padding, constructor callee map, `str.res` / `Too many strings` refs, vtable store, singleton publication, three `0x400` immediates, local stack-buffer evidence, DATFile helper spelling, MemoryMan helper spelling, MyError throw shape, and final string-table copy into `+0x04` / `+0x08`.

Support pages:

- [UID:0000KK][LanguageMan](../../../../../by-file/LanguageMan.md): list `00018R` as the non-emitting island map, add the new constructor child as the constructor source page, and update generated-source expectations so the aggregate empty marker is removed and the constructor child emits into `auto-generated/NexusTK/localization/LanguageMan.cpp`.
- [UID:000071][LanguageMan](../../../../../by-class/LanguageMan.md): replace the constructor row's aggregate-only range with the new exact child link, record constructor emission through `EMITTER_UIDS:000071`, and preserve `m_strings` at `+0x04`, `m_stringCount` at `+0x08`, and the `+0x0c..+0x24` class-layout caveat.
- [UID:00018T][LocalizationAdjacentZeroInitializer](../../../../../by-memory/0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md): repair stale wording that still says the child/aggregate are below assignment gate or unresolved by owner; keep the class-method rejection and blank C++.
- [UID:0000RC][g_pLanguageMan](../../../../../by-global/g_pLanguageMan.md) and [UID:0001OS][g_pLanguageMan storage](../../../../../by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md): link the new constructor child as the singleton publisher.
- [UID:0001RP][str-res-localized-strings](../../../../../by-resource/str-res-localized-strings.md): link the new constructor child as the parser/load-site for `str.res`.
- [UID:00040V][LanguageManParserLimitConstants](../../../../../by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md): link the new constructor child as the consumer of the two `0x400` parser limits and keep the constant C++ unchanged.
- [UID:00040W][LanguageManVtableData](../../../../../by-memory/0x0061c9dc-0x0061c9ec.LanguageManVtableData.md): link the new constructor child as the vtable-store site and preserve the destructor/scalar-wrapper refs.
- [UID:00040X][LanguageManStringResourceLiterals](../../../../../by-memory/0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals.md): link the new constructor child as the `kStringResourceName` and `kTooManyStringsMessage` consumer and keep literal C++ unchanged.

No required edit is recommended for [UID:00040Q][LanguageManCopyLocalizedString](../../../../../by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md) in this callback. Its public LanguageMan-facing StringBase signature remains a separate blocker and its formal C++ should remain blank.

Generated tracker, generated source, generated reports, and all `-coverage-report.md` files are stale in places for this target and should be refreshed only by the approved validator/generator flow after supervisor callback. They should not be hand-edited.

## Validation Status

The report-only pass ran no validators because no by-* documentation edits were made. The accepted implementation callback ran the scoped validator/generator batch from `source-3/project-documentation` on 2026-06-25. Full proof is logged at [validation-logs/00018R-implementation-20260625.md](../validation-logs/00018R-implementation-20260625.md).

Implementation validator results:

- `000000001877`: initial validator pass on `by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md`; validator assigned new [UID:00041V].
- `000000001907` through `000000001923`: scoped file validators for the constructor child, aggregate, support docs, and validator-only reference repair pages all returned `ok:1`.
- `000000001924`: final `by-file/LanguageMan.md --wait-generated` returned `ok:1` with `generated_refresh: completed`.
- Generated-output check found `auto-generated/NexusTK/localization/LanguageMan.cpp` now emits `// UID:00041V` followed by `LanguageMan::LanguageMan()` and `g_pLanguageMan = this;`; the checked output did not contain a `00018R` generated marker.
- Residual validator warnings for missing [UID:0003O5] are pre-existing SelfSave prompt-consumer registry warnings in LanguageMan/resource support pages, not introduced by this constructor split. Final generated refresh also reported broad project-level stale-registry and missing-coverage-metadata warnings unrelated to this target.
- No generated files, coverage reports, validator state/cache, or IDA database files were manually edited.

## Implementation Tracking Checklist

- [x] Lease only the approved target/support files immediately before editing. Proof: leases were acquired for the accepted target/support by-* set and minimal validator-only reference repair pages; stale self-owned `B012`/`Agent-B012` lease aliasing was normalized before validation.
- [x] Update `00018R` metadata to non-emitting split/index and add current MCP evidence/no-code proof. Proof: `by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md` now has `90/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/formal C++, [UID:00041V] child link, current MCP split/index evidence, no-aggregate-C++ proof, and validator `000000001916` returned `ok:1`.
- [x] Create `by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md` with a new UID, `91/92`, `CANONICAL_OWNER:000071`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000071`, the exact item summary from this report, MCP child evidence, and the exact formal constructor C++ from this report. Proof: validator `000000001877` assigned [UID:00041V]; validator `000000001915` returned `ok:1` and confirmed the accepted metadata/owner/emitter/formal constructor C++.
- [x] Update `by-file/LanguageMan.md` to list `00018R` as the non-emitting island map, add the constructor child as the constructor source page, and update generated-source expectations for `LanguageMan.cpp`. Proof: support page updated; validator `000000001917` returned `ok:1`; final generated wait `000000001924` returned `ok:1`.
- [x] Update `by-class/LanguageMan.md` to replace the aggregate constructor row with the exact constructor child link and preserve the confirmed `m_strings`/`m_stringCount` layout plus the `+0x0c..+0x24` caveat. Proof: class page now routes constructor through [UID:00041V] and keeps the layout caveat; validator `000000001918` returned `ok:1`.
- [x] Update `by-global/g_pLanguageMan.md` and `by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md` to cite the constructor child as the singleton publisher. Proof: both pages link [UID:00041V] as the `g_pLanguageMan = this` publisher; validators `000000001920` and `000000001921` returned `ok:1`.
- [x] Update `by-resource/str-res-localized-strings.md`, `by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md`, `by-memory/0x0061c9dc-0x0061c9ec.LanguageManVtableData.md`, and `by-memory/0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals.md` to link the constructor child as the exact consumer/store site without changing their C++. Proof: pages now cite [UID:00041V] for `str.res`, `Too many strings`, `0x400` parser limits, and vtable-store evidence; validators `000000001912`, `000000001913`, `000000001914`, and `000000001922` returned `ok:1`.
- [x] Repair stale `by-memory/0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md` assignment-gate/owner wording while keeping its class-method rejection and blank C++. Proof: page now keeps file-level owner/emitter and class-method rejection while removing stale gate/aggregate wording; validator `000000001923` returned `ok:1`.
- [x] Leave `by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md` unchanged unless the supervisor separately authorizes StringBase signature work. Proof: no StringBase signature/C++ content was implemented; validator-only reference repair was required by scope and validator `000000001910` returned `ok:1`; formal C++ remains blank.
- [x] Run the exact scoped validator/generator batch listed in this report and capture logs under the Agent-B012 validation log area. Proof: validator command IDs and results are captured in [validation-logs/00018R-implementation-20260625.md](../validation-logs/00018R-implementation-20260625.md); final command `000000001924` completed generated refresh.
- [x] Release leases immediately after the edit/validator batch. Proof: `python .\leaser.py B012 unlease` released all active implementation leases; follow-up cleanup returned `B012: No active leases`; `python .\leaser.py Agent-B012 unlease` returned `Agent-B012: No active leases`.
- [x] Report exact files changed, validator results, generated-output status, and any unresolved conflicts back to the supervisor. Proof: changed by-* files and validator-only repair pages are listed in the validation log; generated `LanguageMan.cpp` was refreshed by validator/generator flow; no active lease conflicts remain; residual [UID:0003O5] warning is unrelated pre-existing registry state.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/00018R-LanguageManLocalization-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/00018R-LanguageManLocalization-source-quality.md","timestamp":"2026-06-26T00:09:32","uid":"00018R"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
