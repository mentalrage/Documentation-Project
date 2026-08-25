** TARGET-REPORT-UID:0000WZ **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000WZ JsonCpp Value Path Iterator / CRT Alias Source-Inference Research

## Finalized Report / Current Recommendation
- Current recommendation: split or at least heavily revise [UID:0000WZ]. The range is mostly JsonCpp `json_value.cpp` / `json_valueiterator.inl` source-bearing third-party code, not a pure non-emitting CRT/runtime support island.
- Final disposition: keep the current broad item as a non-emitting audit/container only if it is not split. The JsonCpp source-bearing children should be assigned to [UID:0000KI] `JsonCpp` and emitted/routed through the vendored JsonCpp source strategy; padding and compiler/linker-folded alias details should not emit as NexusTK product code.
- Required action: update the target page, by-memory coverage row, by-memory ignored entry, [UID:0000KI] `JsonCpp`, [UID:0001QE] `client_libraries`, and `other/signatures.md` to remove the stale "15 modeled functions" and "CRT numeric helper fragments" framing. Recommend IDA function starts/comments for the raw JsonCpp methods listed below.
- Confidence: high for JsonCpp source roles and split direction; medium-high for exact derived iterator copy-constructor labels where several trivial constructors have identical byte shapes.

## Supporting Research

## Target
- Target UID: `0000WZ`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport.md`
- Source queue/report row: supervisor assignment `B002-goal2-jsoncpp-value-path-crt-source-inference-0000WZ-20260616`; current by-memory coverage row at `by-memory/-coverage-report.md:311`.
- Current supervisor classification: report-only B-preferred Goal 2 work.
- Current scores and parent state: `COMPLETION:82`, `CONFIDENCE:88`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, no emitters.

## Executive Recommendation
- Best direct source owner for source-bearing code: [UID:0000KI] `JsonCpp`, specifically `third_party_embeds/jsoncpp/src/lib_json/json_value.cpp` and `third_party_embeds/jsoncpp/src/lib_json/json_valueiterator.inl` from the staged `b299d3581f4dc670734f1fe1a34fce1282337802` snapshot.
- The broad current page should not remain the final exact source item. It mixes source-bearing JsonCpp methods, compiler/linker padding, IDA-unmodeled functions, and an ICF/name-polluted CRT `__crt_strtox::big_integer` alias.
- If the supervisor does not split now, raise/update the current page only as an audit/container, with `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, no emitters, and score about `88/90`. If split, assign the JsonCpp children to `0000KI` with `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:0000KI`; keep padding and any pure compiler/runtime alias pages non-emitting.
- Exact condition before final source C++: no final decompiler-written C++ should be added to this broad page. JsonCpp source should come from the staged vendored source tree; child pages can become eligible for final-output routing only as static-embed/source-route references, not as hand-reconstructed local code blocks.

## Supervisor Active Recheck
- Assignment rechecked: the user explicitly required report-only work and prohibited direct edits to by-* docs, generated reports, IDA DB, and `by-memory/-coverage-report.md`.
- Split repair is warranted by evidence, but not performed because this turn is report-only.
- Every source-bearing child in scope has a source-role recommendation below. Remaining ambiguity is limited to exact labels for compiler-generated trivial iterator copy helpers, not owner, source file, or non-product classification.

## Inference Research Guidance Check
- `by-structure.md` requires distinguishing third-party/static-embed code from NexusTK-owned source. It also allows static embedded third-party code to be reconstructable through a vendored source route rather than handwritten product C++.
- `inference_research.md` pushed this audit away from address-adjacency-only claims. The strongest evidence used here is IDA/MCP disassembly, decompilation, xrefs, exact diagnostic strings, local staged upstream source, and source-order/layout comparison.
- Existing documentation was treated as a lead. It was partially contradicted: the current page's "15 modeled functions" statement is true only for IDA-modeled starts, but false as a complete range inventory; the "CRT numeric support" framing overstates the actual local evidence.

## Heuristic / Inference Reanalysis And Validation

### Range Identity
- Evidence checked: live IDA MCP `server_health`, `entity_query`, `analyze_component`, `analyze_function`, `decompile`, `disasm`, `search_text`, `make_signature_for_range`; local staged JsonCpp source in `third_party_embeds/jsoncpp`.
- Best inference: `0x00428b4b-0x004298f0` is a JsonCpp value/comment/path/iterator island with one pair of folded zero/free helper aliases currently named like CRT `__crt_strtox::big_integer`.
- Rejected alternative: "small CRT helper pair followed by JsonCpp" as the main classification. IDA xrefs at `0x00425120`, `0x0042528a`, `0x00428377`, and `0x00428372` point the zero/free helper pair into JsonCpp `CommentInfo` vector construction/destruction contexts. Broader CRT numeric parsing lives in later runtime ranges such as the documented `__crt_strtox::parse_integer` family, not here.
- Final direction: rename/reword as JsonCpp value/comment/path/iterator support with CRT/ICF alias notes, not as a CRT numeric-support range.

### `0x00428b50` / `0x00428b60`
- Existing claim: `0x00428b50` is `__crt_strtox::big_integer::big_integer`; `0x00428b60` frees the big-integer backing pointer.
- Evidence checked: `analyze_function 0x00428b50` gives a 9-byte zero-store constructor and data xrefs from `0x00425120` and `0x00428377`; `analyze_function 0x00428b60` gives a pointer-free destructor with data xrefs from `0x0042511b`, `0x0042528a`, and `0x00428372`. Those sites are JsonCpp value/comment allocation and cleanup paths.
- Best inference: these are identical-code-folded or IDA-symbol-polluted aliases for `Json::Value::CommentInfo::CommentInfo()` and `Json::Value::CommentInfo::~CommentInfo()` in this local range. The body is also compatible with CRT `__crt_strtox::big_integer` zero/free support, so preserve that alias as a note.
- Rejected alternative: a separate CRT numeric source child at `0x00428b50-0x00428b6e`. There is no local parse-integer or floating-conversion call chain here; the local xrefs prove JsonCpp comment-array use.
- Score/source effect: does not block assigning the surrounding JsonCpp child to `JsonCpp`, but should cap "original name" confidence below final-audit level.

### `sub_428B70`
- Evidence checked: decompile references `assert json failed` and `in Json::Value::setComment(): Comments must start with /`; local source `json_value.cpp:233-243`.
- Best inference: `Json::Value::CommentInfo::setComment(char const* text, size_t len)`.
- Rejected alternatives: product comment handling, fitting-room cache logic, or CRT string helper. The diagnostic is exact JsonCpp source text and callers are JsonCpp value-copy/comment paths.
- Recommendation: IDA comment/name should mention exact upstream role.

### Raw `0x00428c60-0x00428d6a`
- Evidence checked: IDA raw disassembly and `json_value.cpp:1459-1471`.
- Best inference:
  - `0x00428c60-0x00428c8c`: `Json::PathArgument::PathArgument()`
  - `0x00428c90-0x00428cbd`: `Json::PathArgument::PathArgument(ArrayIndex index)`
  - `0x00428cc0-0x00428d0e`: `Json::PathArgument::PathArgument(char const* key)`
  - `0x00428d10-0x00428d6a`: `Json::PathArgument::PathArgument(JSONCPP_STRING const& key)`
- Rejected alternative: padding or raw compiler glue. These bodies construct a `std::string` member at offset `0`, set `index_` at `+0x18`, and set `kind_` at `+0x1c`, matching `PathArgument`.
- Recommendation: add IDA function starts and comments at all four starts.

### `sub_428D70`
- Evidence checked: decompile initializes a 3-pointer vector, pushes five argument addresses, calls `0x00429090`, then frees the temporary vector; local source `json_value.cpp:1476-1488`.
- Best inference: `Json::Path::Path(JSONCPP_STRING const& path, PathArgument const& a1, ..., PathArgument const& a5)`.
- Rejected alternatives: generic vector helper or product JSON key helper. The five `PathArgument` pointer pushes and call to `makePath` match upstream exactly.

### Raw `0x00428ee0`, `0x00428f70`, `0x00429030`
- Evidence checked: disassembly walks `Path::args_` entries of 32 bytes, tests `kind_ == 1` and `kind_ == 2`, calls JsonCpp array/object helpers, and either returns null/default/made nodes; local source `json_value.cpp:1539-1598`.
- Best inference:
  - `0x00428ee0-0x00428f65`: `Json::Path::resolve(Value const& root) const`
  - `0x00428f70-0x00429025`: `Json::Path::resolve(Value const& root, Value const& defaultValue) const`
  - `0x00429030-0x00429088`: `Json::Path::make(Value& root) const`
- Rejected alternative: unrelated object member lookup helpers. These bodies are specifically iterating `PathArgument` records and calling value array/object accessors documented in [UID:0000WY].
- Recommendation: add IDA starts and comments.

### `sub_429090`, raw `0x00429410`, and `nullsub_21`
- Evidence checked: decompile scans `[` / `%` / `.` syntax and string `"[."`; disassembly at `0x00429410` checks `PathArgument::kind_` and pushes a copied argument; `nullsub_21` is an empty `retn 8`; source `json_value.cpp:1491-1536`.
- Best inference:
  - `0x00429090-0x00429401`: `Json::Path::makePath(JSONCPP_STRING const& path, InArgs const& in)`
  - `0x00429410-0x00429463`: `Json::Path::addPathInArg(...)`
  - `0x00429470-0x00429473`: `Json::Path::invalidPath(...)`, source-defined empty stub.
- Rejected alternative: STL vector insert ownership. The vector helper calls are dependencies, but the control flow and syntax match `Path::makePath`.
- Recommendation: add IDA function start at `0x00429410`; rename/comment `nullsub_21` as `Json::Path::invalidPath` stub.

### `sub_429480` and raw iterator accessor cluster
- Evidence checked: decompile of `0x00429480` builds a `Json::Value` from a current map key; disassembly of `0x004295b0-0x004296e5`; source `json_valueiterator.inl:78-112` and `:26-34`.
- Best inference:
  - `0x00429480-0x004295a8`: `Json::ValueIteratorBase::key() const`
  - `0x004295b0-0x00429614`: `Json::ValueIteratorBase::index() const`
  - `0x00429620-0x00429676`: `Json::ValueIteratorBase::name() const`
  - `0x00429680-0x00429690`: `Json::ValueIteratorBase::memberName() const`
  - `0x00429690-0x004296bc`: `Json::ValueIteratorBase::memberName(char const** end) const`
  - `0x004296c0-0x004296c6`: `Json::ValueIteratorBase::deref() const`
  - `0x004296d0-0x004296d5`: `Json::ValueIteratorBase::increment()`, thunk to Dinkumware map-iterator `++`
  - `0x004296e0-0x004296e5`: `Json::ValueIteratorBase::decrement()`, thunk to Dinkumware map-iterator `--`
- Rejected alternatives: pure Dinkumware/STL helpers. The thunks call STL iterator primitives, but the surrounding bodies are JsonCpp wrapper methods from `json_valueiterator.inl`.
- Recommendation: add missing starts at `0x004295b0`, `0x00429620`, `0x00429680`, `0x00429690`, and `0x004296c0`; keep starts at thunks but comment as JsonCpp wrappers over STL iterator ops.

### Iterator comparison/copy/constructor cluster
- Evidence checked: disassembly at `0x004296f0-0x004298e6`; source `json_valueiterator.inl:38-73` and `:121-163`.
- Best inference:
  - `0x004296f0-0x00429736`: `ValueIteratorBase::computeDistance(SelfType const& other) const`
  - `0x00429740-0x0042975e`: `ValueIteratorBase::isEqual(SelfType const& other) const`
  - `0x00429760-0x00429774`: `ValueIteratorBase::copy(SelfType const& other)`
  - `0x00429780-0x0042978d`: `ValueIteratorBase::ValueIteratorBase()`
  - `0x00429790-0x004297a4`: `ValueIteratorBase::ValueIteratorBase(ObjectValues::iterator const& current)`
  - `0x004297b0-0x004297bd`: `ValueConstIterator::ValueConstIterator()`
  - `0x004297c0-0x004297d6`: likely `ValueConstIterator::ValueConstIterator(ValueIterator const& other)` or the compiler-emitted base copy used by that constructor.
  - `0x004297e0-0x004297f4`: `ValueConstIterator::ValueConstIterator(ObjectValues::iterator const& current)`
  - `0x00429800-0x00429816`: `ValueConstIterator::operator=(ValueIteratorBase const& other)`
  - `0x00429820-0x0042982d`: `ValueIterator::ValueIterator()`
  - `0x00429830-0x00429882`: `ValueIterator::ValueIterator(ValueConstIterator const& other)` throwing `ConstIterator to Iterator should never be allowed.`
  - `0x00429890-0x004298a6`: likely `ValueIterator::ValueIterator(ValueIterator const& other)` or compiler-emitted base copy used by that constructor.
  - `0x004298b0-0x004298c4`: `ValueIterator::ValueIterator(ObjectValues::iterator const& current)`
  - `0x004298d0-0x004298e6`: `ValueIterator::operator=(ValueIterator const& other)`
- Rejected alternative: `unknown_libname_2` and `unknown_libname_3` are Visual C runtime source. They are trivial copies inside JsonCpp iterator constructors; IDA's runtime-like label is a signature/heuristic artifact.
- Remaining blocker: exact original symbol assignment for `0x004297c0` and `0x00429890` cannot be proven beyond the copy-constructor/helper family without mangled symbols. This should not block JsonCpp ownership or split; it should only cap exact-name confidence.

### Raw `0x004298b0` and `0x004298d0`
- Evidence checked: `make_signature_for_range 0x004298b0-0x004298f0` returned:
  - `0x004298b0`: copies `*(arg)` to `this->current_`, sets `isNull_ = false`, returns `this`.
  - `0x004298d0`: copies `current_` and `isNull_` byte from another iterator, returns `this`.
- Best inference: `ValueIterator(ObjectValues::iterator const& current)` and `ValueIterator::operator=(SelfType const& other)`.
- Decision: model as IDA functions. They are not padding and not generic inline-support bytes.

### Split / Range Decision
- Existing claim validated: outer boundaries `0x00428b4b` and `0x004298f0` are clean. `sub_428940` ends at `0x00428b4b`; `sub_4298F0` begins at `0x004298f0`.
- Existing claim contradicted: the current page is incomplete as an exact function inventory because IDA has many raw/unmodeled starts inside the range.
- Best split:
  - `0x00428b4b-0x00428b50`: padding.
  - `0x00428b50-0x00428c53`: `JsonCppCommentInfoCtorDtorSetComment`, with ICF/CRT alias note.
  - `0x00428c53-0x00428c60`: padding.
  - `0x00428c60-0x00429473`: `JsonCppPathArgumentAndPath`.
  - `0x00429473-0x00429480`: padding.
  - `0x00429480-0x004298e6`: `JsonCppValueIteratorSupport`.
  - `0x004298e6-0x004298f0`: padding before `sub_4298F0`.
- Rejected alternative: keep one exact broad source page and just raise scores. The range crosses source-method families and has real raw starts needing their own evidence. A container can remain, but exact source-bearing children should carry ownership/emitter decisions.

### Generated Output / Pollution
- `auto-generated/-ag-memory-coverage.md` currently reports [UID:0000WZ] as `not_reconstructable` while [UID:0000WY] and [UID:0000X0] emit through `0000KI`. This is stale if JsonCpp children are split, because most of this range is vendored JsonCpp source.
- `other/signatures.md` currently says the page is accurate because the IDA count is 15 function starts and `unknown_libname_2/3` are Visual C runtime-like copies. This is now incomplete and partly misleading: the IDA count is modeled starts only, and the two copies are JsonCpp iterator trivial constructors/copies.
- `JsonCpp.md` and `client_libraries.md` can keep [UID:0000WZ] as a JsonCpp support reference, but should stop implying that there is a substantive CRT numeric helper fragment here. Better wording: "folded `CommentInfo`/CRT zero/free aliases plus `Json::Value::CommentInfo`, `Json::Path`, and iterator support."

## Evidence Standards Used
- IDA MCP facts: active session `b001_000211_20260616`, `NexusTK.exe.i64`, imagebase `0x400000`, Hex-Rays ready, strings cache ready.
- IDA MCP tools used: `server_health`, `entity_query`, `analyze_component`, `analyze_function`, `decompile`, `disasm`, `search_text`, `make_signature_for_range`, `trace_data_flow`.
- Local source evidence: `third_party_embeds/jsoncpp/src/lib_json/json_value.cpp`, `json_valueiterator.inl`, and `include/json/value.h`; matching staged source under `simroot_v2/third_party/jsoncpp`.
- Negative evidence: no product-code callers into most of the range; no local parse-integer chain; no evidence that FittingRoom, CashShop, or Downloader owns these helpers.

## IDA MCP Facts
- Function/range facts:
  - `entity_query` reports modeled starts at `0x00428b50`, `0x00428b60`, `0x00428b70`, `0x00428d70`, `0x00429090`, `0x00429470`, `0x00429480`, `0x004296d0`, `0x004296e0`, `0x00429780`, `0x004297b0`, `0x004297c0`, `0x00429820`, `0x00429830`, `0x00429890`; `0x004298f0` is next-page start.
  - `search_text` over the target found raw `push ebp` starts at `0x00428c60`, `0x00428c90`, `0x00428cc0`, `0x00428d10`, `0x00428ee0`, `0x00428f70`, `0x00429030`, `0x00429410`, `0x00429620`, `0x00429690`, `0x004296f0`, `0x00429740`, `0x00429760`, `0x00429790`, `0x004297e0`, `0x00429800`, `0x004298b0`, and `0x004298d0`.
  - Raw non-`push ebp` starts include `0x004295b0`, `0x00429680`, and `0x004296c0`.
- Data/table/padding facts:
  - `0xcc` alignment separates many methods. Padding spans are exact enough to split around method bodies.
  - `make_signature_for_range 0x004298b0-0x004298f0` confirms two raw bodies followed by `0xcc` alignment through `0x004298f0`.
- Xref facts:
  - `0x00428b50` has data xrefs from `0x00425120` and `0x00428377`.
  - `0x00428b60` has data xrefs from `0x0042511b`, `0x0042528a`, and `0x00428372`.
  - `0x00428b70` has callers `sub_425010` and `sub_428330`, both JsonCpp value/comment paths.
  - `0x00429090` has caller `sub_428D70`.
- Vtable/global/type facts:
  - No vtable evidence is needed. Layout evidence comes from source structs/classes and offset use.
  - `PathArgument` uses a 24-byte string member, `index_` at `+0x18`, `kind_` at `+0x1c`.
  - `Path` is a vector triple at `+0`, `+4`, `+8`.
  - `ValueIteratorBase` is a map iterator pointer plus `isNull_` byte.
- Negative IDA facts:
  - No direct product-code calls into `Path` or iterator support were found.
  - No local CRT numeric parse body exists in this range.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00428b4b-0x004298f0` | [UID:0000WZ] | Current mixed audit/container | `FALSE` as container | `NONE` | recommend `88/90` after update | Keep only if split deferred |
| `0x00428b50-0x00428c53` | proposed child | `Value::CommentInfo` ctor/dtor/setComment, with folded CRT alias note | `TRUE` for JsonCpp source child | [UID:0000KI] | `88/90` | Create/split recommended |
| `0x00428c60-0x00429473` | proposed child | `PathArgument` and `Path` methods | `TRUE` | [UID:0000KI] | `90/91` | Create/split recommended |
| `0x00429480-0x004298e6` | proposed child | `ValueIteratorBase`, `ValueConstIterator`, `ValueIterator` support | `TRUE` | [UID:0000KI] | `88/90` | Create/split recommended |
| padding spans | [UID:0000VN] or child ledger | `0xcc` alignment | `FALSE` | `NONE` | `95` if exact ledgered | Keep ignored/non-emitting |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00425120`, `0x00428377` | data xrefs to `0x00428b50` | `eh vector constructor iterator` constructor pointer for JsonCpp comment info array |
| `0x0042511b`, `0x0042528a`, `0x00428372` | data xrefs to `0x00428b60` | destructor/free pointer for the same JsonCpp comment info array contexts |
| `sub_425010`, `sub_428330` | callers of `sub_428B70` | JsonCpp value copy/comment paths call `CommentInfo::setComment` |
| `sub_428D70 -> sub_429090` | only internal modeled call | `Path::Path` calls `Path::makePath` |
| `0x00429830` | string xref `ConstIterator to Iterator should never be allowed.` | exact `ValueIterator(ValueConstIterator const&)` diagnostic |
| `0x004296d0`, `0x004296e0` | thunks to `0x0043ac80`, `0x0043ad30` | JsonCpp iterator increment/decrement wrappers over STL map iterator operations |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - [UID:0000KI] already identifies the best JsonCpp source snapshot and lists [UID:0000WZ] as the value/path/iterator island.
  - [UID:0000WY] and [UID:0000X0] already anchor the adjacent JsonCpp value core and parse front-end ranges.
  - [UID:0001QE] records JsonCpp as a client library dependency rather than product code.
- Existing docs that are stale, incomplete, or contradicted:
  - [UID:0000WZ] misses raw function starts from `0x00428c60` through `0x004298d0` except for the last two raw bodies.
  - [UID:0000WZ] overstates `__crt_strtox` source ownership for `0x00428b50/60`; local xrefs favor JsonCpp `CommentInfo` ICF/name-pollution.
  - `other/signatures.md` row at line 212 is incomplete because "15 function starts" ignores raw source-bearing methods.
- Generated/coverage report state:
  - `auto-generated/-ag-memory-coverage.md` reports [UID:0000WZ] as `not_reconstructable`; after split, JsonCpp children should surface through [UID:0000KI], while padding and pure compiler/runtime aliases remain non-emitting.

## Ranked Ownership Analysis

### 1. [UID:0000KI] JsonCpp
- Evidence for: exact JsonCpp diagnostics, exact `json_value.cpp` / `json_valueiterator.inl` source bodies, source-order match from `CommentInfo` to `Path` to iterator support, adjacent JsonCpp-owned ranges, staged vendored source.
- Evidence against: `0x00428b50` IDA name is CRT `big_integer`, and trivial copy helpers have runtime-like IDA names.
- Decision: accepted for source-bearing child pages. The contrary evidence is name/ICF/signature pollution, not stronger ownership.

### 2. `CANONICAL_OWNER:NONE` broad audit/container
- Evidence for: current page mixes source-bearing JsonCpp, folded alias helpers, and padding; a broad aggregate is not one original source function.
- Evidence against: using `NONE` as the final answer for the whole range hides reconstructable JsonCpp source bodies.
- Decision: accepted only for the unsplit parent/container.

### 3. MSVC CRT / runtime owner
- Evidence for: IDA names `0x00428b50` as `__crt_strtox::big_integer::big_integer`; `sub_428B60` body is compatible with a pointer-owning CRT object destructor.
- Evidence against: local xrefs use these as JsonCpp comment-array ctor/dtor helpers; no local parse-integer/floating conversion flow; most of the range maps to JsonCpp source.
- Decision: rejected as primary owner. Preserve as an alias/pollution note for the folded helper pair.

### 4. Product owners such as FittingRoom, CashShopVersionRequest, Downloader
- Evidence for: product code consumes JsonCpp parse/value APIs in adjacent ranges.
- Evidence against: no product strings, no product-specific state, and no product caller into most of this target; the functions match upstream JsonCpp.
- Decision: rejected.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new owner needed. Use existing [UID:0000KI] `JsonCpp`.
- Likely full contents: upstream JsonCpp `include/json/*`, `src/lib_json/json_value.cpp`, `json_valueiterator.inl`, `json_reader.cpp`, `json_writer.cpp`, matching the staged source tree.
- Candidate related items that belong: [UID:0000WY], JsonCpp portions of [UID:0000WZ] after split, [UID:0000X0], [UID:0000X1], [UID:0000X2], [UID:0000X3], [UID:0000X4], [UID:0000X6], [UID:0000X7], [UID:0000X8], [UID:0000X9], [UID:0001ZS], [UID:0001ZX], and JsonCpp static data [UID:00028N].
- Candidate related items rejected: pure Dinkumware/MSVC STL runtime ranges [UID:0001ZT], [UID:0001ZV], and pure product consumer modules.
- Standalone, narrow, or broad source-file inference: broad vendored third-party source-tree grouping, not a new one-off local file.

## Negative Evidence Summary
- Consumer xrefs from product JSON-loading code prove use of JsonCpp, not ownership of JsonCpp internals.
- IDA's `unknown_libname_2` / `unknown_libname_3` labels are not sufficient runtime ownership evidence because raw surrounding iterator bodies match JsonCpp source and the helpers are trivial copy constructors.
- The `__crt_strtox::big_integer` name is insufficient to classify the start of the range as CRT numeric parsing because local data xrefs point to JsonCpp comment-info vector construction/destruction and no parse-number flow begins here.
- Address adjacency to JsonCpp value core and parser front ends is supporting evidence, but not the sole basis; source text, diagnostics, and instruction behavior also match.

## Final Recommendation
- Exact changes applied or recommended: no by-* edits applied by B002 because this is report-only. Recommended target page update: replace the current inventory with a full raw/modeled inventory and reword the title/status to `JsonCpp Value Comment Path Iterator Support With CRT/ICF Aliases`.
- Exact parent assignments recommended:
  - Parent/container [UID:0000WZ]: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, no emitters if kept broad.
  - JsonCpp split children: `CANONICAL_OWNER:0000KI`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KI`.
  - Padding: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, no emitters.
- Exact items left no-owner/non-emitting and why:
  - Current broad range only, because it is a mixed container.
  - Padding, because it is compiler/linker alignment.
  - No pure CRT child is recommended unless the supervisor wants an alias-only note for `0x00428b50/60`; the local source role is JsonCpp `CommentInfo`.
- Exact future work outside this report: split-page creation, target/support doc edits, coverage row update, IDA function-start/comment update if the supervisor permits IDA DB changes.

## Exact Supervisor Actions
- Target doc:
  - Update [UID:0000WZ] with the raw start inventory and source-role table above.
  - Change wording from "small CRT `__crt_strtox::big_integer` helper pair followed by JsonCpp" to "folded `CommentInfo`/CRT zero-free aliases followed by JsonCpp `CommentInfo`, `PathArgument`, `Path`, and iterator support."
  - If not splitting immediately, set scores to `COMPLETION:88`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank emitters as a reviewed mixed container.
- Split recommendation:
  - Create `by-memory/0x00428b50-0x00428c53.JsonCppCommentInfoSetCommentAndFoldedCtorDtor.md`.
  - Create `by-memory/0x00428c60-0x00429473.JsonCppPathArgumentAndPath.md`.
  - Create `by-memory/0x00429480-0x004298e6.JsonCppValueIteratorSupport.md`.
  - Ledger or child-record padding `0x00428b4b-0x00428b50`, `0x00428c53-0x00428c60`, `0x00429473-0x00429480`, and `0x004298e6-0x004298f0`.
- Support doc edits:
  - Update [UID:0000KI] `JsonCpp` to say this range now maps to `json_value.cpp` lines for `CommentInfo`, `PathArgument`, `Path`, and `json_valueiterator.inl` iterator methods; mention the `__crt_strtox` name as ICF/signature alias, not a primary source owner.
  - Update [UID:0001QE] `client_libraries` with the same wording.
  - Update `other/signatures.md` row 212: "Current IDA modeled count is 15, but a raw disassembly pass finds additional unmodeled JsonCpp method starts; `unknown_libname_2/3` are JsonCpp iterator trivial-copy helpers, not standalone runtime source."
- IDA function starts/comments recommended:
  - Add function starts at `0x00428c60`, `0x00428c90`, `0x00428cc0`, `0x00428d10`, `0x00428ee0`, `0x00428f70`, `0x00429030`, `0x00429410`, `0x004295b0`, `0x00429620`, `0x00429680`, `0x00429690`, `0x004296c0`, `0x004296f0`, `0x00429740`, `0x00429760`, `0x00429790`, `0x004297e0`, `0x00429800`, `0x004298b0`, `0x004298d0`.
  - Add comments/names according to the inventory in the heuristic section.
  - Keep `0x00428b50` current symbol if needed, but add a repeatable comment that local xrefs use it as folded `Json::Value::CommentInfo::CommentInfo()`.
- Score changes:
  - Unsplitted parent/container: `88/90`.
  - Proposed `CommentInfo` child: about `88/90`.
  - Proposed `PathArgumentAndPath` child: about `90/91`.
  - Proposed `ValueIteratorSupport` child: about `88/90`.
- Owner/emitter/reconstructability:
  - Parent/container: `NONE`, `FALSE`, no emitters.
  - JsonCpp children: owner/emitter [UID:0000KI], `TRUE`.
  - Padding: `NONE`, `FALSE`, no emitters.
- Split/no-split:
  - Split recommended. If supervisor defers, at minimum update the current page and row to say it is a reviewed mixed container with hidden JsonCpp function starts.

## Exact Coverage Row Text
Immediate no-split replacement for current row 311:

```text
    - [UID:0000WZ][0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport](by-memory/0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport.md) : ignored : 88% : strong : 2026-06-16 B002 recheck finds a mixed JsonCpp value/comment/path/iterator container with many raw unmodeled starts, not only 15 IDA-modeled functions. Local source comparison maps `0x00428b70` to `Json::Value::CommentInfo::setComment`, `0x00428c60-0x00429473` to `PathArgument`/`Path`, and `0x00429480-0x004298e6` to `ValueIteratorBase`/`ValueConstIterator`/`ValueIterator`; `0x00428b50/60` are best treated as folded `CommentInfo` ctor/dtor aliases despite the CRT `__crt_strtox::big_integer` IDA name. Keep the current broad item non-emitting only as a mixed audit/container; split JsonCpp source-bearing children to [UID:0000KI] when edits are allowed.
```

Recommended post-split row set, with validator-assigned UIDs replacing the temporary labels:

```text
    - [UID:<new>][0x00428b50-0x00428c53.JsonCppCommentInfoSetCommentAndFoldedCtorDtor](by-memory/0x00428b50-0x00428c53.JsonCppCommentInfoSetCommentAndFoldedCtorDtor.md) : ignored : 88% : strong : JsonCpp `Value::CommentInfo` zero/free ctor-dtor aliases and `setComment` body from `json_value.cpp`; note IDA's `__crt_strtox::big_integer` symbol as identical-code/name pollution, not primary source ownership.
    - [UID:<new>][0x00428c60-0x00429473.JsonCppPathArgumentAndPath](by-memory/0x00428c60-0x00429473.JsonCppPathArgumentAndPath.md) : ignored : 90% : strong : JsonCpp `PathArgument` constructors and `Path` constructor/resolve/default/make/makePath/addPathInArg/invalidPath bodies from `json_value.cpp`, including raw starts not currently modeled by IDA.
    - [UID:<new>][0x00429480-0x004298e6.JsonCppValueIteratorSupport](by-memory/0x00429480-0x004298e6.JsonCppValueIteratorSupport.md) : ignored : 88% : strong : JsonCpp `ValueIteratorBase`, `ValueConstIterator`, and `ValueIterator` support from `json_valueiterator.inl`; `unknown_libname_2/3` and raw `0x004298b0/0x004298d0` are iterator trivial-copy/current/assignment helpers.
```

## Follow-Up Actions
- Supervisor actions: decide whether to split now; apply target/support doc updates; update coverage row; optionally apply IDA function-start/comment changes.
- A-agent actions: after split, route JsonCpp children through [UID:0000KI] and ensure static-embed source route is documented rather than adding decompiler-shaped C++.
- B002 future research actions: if assigned, audit the next JsonCpp raw-helper pages for the same IDA-modeled-only inventory problem.

## Confidence
- Recommendation confidence: high.
- Score confidence: high for parent `88/90` after doc update; medium-high for child scores until split pages are written and validated.
- Remaining uncertainty: exact original symbol names for `0x004297c0` and `0x00429890` are not provable from current stripped/heuristic IDA names, but their JsonCpp iterator role is strong.

## Validator Results
- Commands run: none. This was report-only and no by-* file was edited.
- Validator commands to run after supervisor applies edits:

> Executable block R001 was removed from this report and preserved verbatim in [0000WZ-jsoncpp-value-path-crt-source-inference-removed.md](0000WZ-jsoncpp-value-path-crt-source-inference-removed.md). The archived block is non-authoritative and must not be executed.

- Any unresolved validator warnings/errors: not applicable; no validator run was needed for this research report.

## Changed Files
- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0000WZ-jsoncpp-value-path-crt-source-inference.md`
- Modified: none outside B002 research.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0000WZ-jsoncpp-value-path-crt-source-inference.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"0000WZ"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000WZ-jsoncpp-value-path-crt-source-inference-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0000WZ-jsoncpp-value-path-crt-source-inference.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000WZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
