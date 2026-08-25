<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\00037J-SortedListInsertSorted-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

## Removed Block CLEANUP-20260813-00037J-SECTION21

Source: [00037J-SortedListInsertSorted-empty-emitter-source-quality.md](00037J-SortedListInsertSorted-empty-emitter-source-quality.md)

This archive is non-authoritative and must never be executed. It preserves the exact report text removed during supervisor cleanup.

<!-- BEGIN CLEANUP-20260813-00037J-SECTION21 -->
## IDA Rename / Type / Comment Recommendations

Actionable entities and completed supervisor transaction:

Authority and rollback state: all prestates in T1/F1/F2 and P1-P11 below were originally read from evidence-time session `b004-gate2b-current` against saved IDB SHA256 `4E6757FAA6234898FF8303944146E646F06395F09B1292E9389DB0020D6B1CE6`. The first supervisor transaction used matching backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID00037J-prestate-20260803-202459`, failed closed at F1 physical readback, performed no save, discarded unsaved PID `13484`, and used `b005-rollback-clean` to prove exact restoration. The successful retry started from canonical SHA256 `400BFA5A1AE2E6C16906DB75060D2A1FDE30BB8DE8DDAB22758FDDC557A84948`, size `143,196,257`, with fresh matching backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID00037J-prestate-20260803-225322` and sole bound session `b002-persist-reopen` PID `11812`. Immediate prestates matched; all literal calls and protections below passed; `idb_save` returned `ok:true`; and fresh sole session `b005-persist-reopen` PID `2652` proves persistence in canonical SHA256 `92CD98A20133155CEC96C4AB6B60A00B7C5635A7C47E0A3F51BE918C13ACC5A0`, size `143,196,412`. Historical session placeholders and prestates below remain the exact executed transaction contract, not pending work or reusable request targets.

| ID | Exact entity/range/width | Exact transaction prestate | Evidence, xrefs, collision result | Exact action/classification | Accepted readback/protection |
| --- | --- | --- | --- | --- | --- |
| T1 | local type database; desired SortedList size 0x18 | SortedList: absent. SortedListCompareFunction: absent. List: present only as opaque non-UDT with no size/members. MemoryMan: present only as opaque non-UDT with no size/members. | Constructor and target prove +00 vtable, +04 element size, +08 page size, +0c count, +10 data, +14 comparator. No SortedList or typedef collision. Historical Gate 2B proved the declaration succeeds when `decls` is a one-element array; scalar text was rejected by comma splitting without mutation. | Apply the exact database-scoped T1 request below. Do not redefine List or MemoryMan. | `type_inspect` reports SortedListCompareFunction exists with exact cdecl pointer declaration and SortedList exists as a UDT of size 0x18 with six exact members/offsets/types; List and MemoryMan remain unchanged opaque types. |
| F1 | function 0x004f3690-0x004f377b; width 0xeb | Name sub_4F3690. Type int __thiscall(int this, void *Src). Address regular comment absent; address repeatable comment absent; function regular comment absent; function repeatable comment absent. Frame rows: var_8 +0x0c width 4 struct MemoryMan *; var_4 +0x10 width 4 _DWORD; __saved_registers +0x14 width 4 special/no user type; __return_address +0x18 width 4 special/no user type; Src +0x1c width 4 void *. Implicit ECX binding: this, width 4, int; no physical frame row. | Thirteen code xrefs: 47ed75, 520f4c, 520fbc, 52102e, 52109e, 52110c, 52117c, 5211f2, 521261, 5212cd, 52133d, 5213ff, 5214a2. Name SortedList_InsertSorted is collision-free. Exact body has 96 instructions. Historical no-save transaction proves semantic `set_type` succeeds without changing physical `Src`/`void *`. | Apply exact F1 request order below: function rename; semantic function `set_type`; immediate semantic and complete physical readbacks; stack rename dry-run; identical actual stack rename; explicit stack `set_type`; complete frame readback after every step; only then exact function-repeatable comment. | Exact name/type/function-repeatable comment; address regular/repeatable and function regular remain absent. Semantic readback must succeed while the physical row remains prestate until explicitly edited. Final +0x1c changes exactly to `element`/`const void *`; ECX binds as `SortedList *this`; every protected row, range, 96 instructions, 13 xrefs, bytes, and internal comments remain unchanged. |
| F2 | function 0x00516190-0x00516210; width 0x80 | Transaction-prestate name sub_516190 and type `void *__stdcall(void *Block, _DWORD *pExceptionObject)`. Address regular/repeatable and function regular/repeatable comments absent. Frame rows: var_C +0x04 width 4 _DWORD; var_4 +0x0c width 4 _DWORD; __saved_registers +0x10 width 4 special/no user type; __return_address +0x14 width 4 special/no user type; Block +0x18 width 4 void *; pExceptionObject +0x1c width 4 int. No implicit ECX parameter existed. The function-level `_DWORD *` and physical-frame `int` renderings were distinct prestate facts. | Ten code xrefs: 4b6247, 4bb2a6, 4f324d, 4f3285, 4f3354, 4f3476, 4f358a, 4f35ca, 4f3723, 4f3a26. Name MemoryMan_ReallocateBufferMemory was collision-free. The body casts the second argument to `size_t` for realloc and reuses the stack storage for the thrown pointer; accepted UID0001BG and MemoryMan H prove the source ABI. F1 proves semantic and physical bindings must be handled separately. | Applied exact F2 order below: function rename; semantic function `set_type`; immediate semantic/physical readbacks; dry-run/actual stack rename and stack type for `Block` -> `block`/`void *`; dry-run/actual stack rename and stack type for `pExceptionObject` -> `newSize`/`size_t`; complete frame readback after every step; then exact function-repeatable comment. | Exact name/type/function-repeatable comment persisted; address regular/repeatable and function regular remain absent. Semantic `__thiscall`/ECX readback and physical +0x18/+0x1c rows passed independently. Every protected row, range, EH/throw body, ten xrefs, comments, and bytes remain unchanged. |

### F1 Deterministic Prototype-To-Frame Binding Contract

Applying the F1 semantic prototype and editing its occupied physical argument are separate required operations. `this` is an implicit register argument and is not a physical stack-frame row; the only physical row allowed to change is the existing four-byte explicit argument at `+0x1c`. Historical Gate 2B proved that successful semantic function typing can leave that physical row unchanged, so `func_profile` and `stack_frame` are independent acceptance surfaces.

| Binding/row | Offset/register | Width | Exact prestate name/type | Exact poststate name/type | Disposition/readback |
| --- | --- | --- | --- | --- | --- |
| implicit receiver | `ECX` | 4 | `this` / `int`; implicit `__thiscall` binding, no frame row | `this` / `SortedList *`; implicit `__thiscall` binding, no frame row | Required type refinement; must not create or shift a stack row. |
| local | `+0x0c` | 4 | `var_8` / `struct MemoryMan *` | `var_8` / `struct MemoryMan *` | Protected unchanged. |
| local | `+0x10` | 4 | `var_4` / `_DWORD` | `var_4` / `_DWORD` | Protected unchanged. |
| saved-register row | `+0x14` | 4 | `__saved_registers` / IDA special frame row with no user type | `__saved_registers` / IDA special frame row with no user type | Protected unchanged. |
| return-address row | `+0x18` | 4 | `__return_address` / IDA special frame row with no user type | `__return_address` / IDA special frame row with no user type | Protected unchanged. |
| explicit argument 0 | `+0x1c` | 4 | `Src` / `void *` | `element` / `const void *` | The sole physical frame-row delta. |

F1 deterministic stop/readback rule: stop before mutation if any prestate name, type, offset, width, row count, implicit calling-convention binding, range, xref count, comment state, or byte hash differs. After semantic function `set_type`, require the exact desired semantic prototype and implicit ECX receiver while the complete physical frame still matches prestate, including `Src`/`void *` at `+0x1c`; this unchanged physical intermediate is expected, not a failure. The stack-rename dry run must report `dry_run:true`, no per-item error, and no frame delta. The actual stack rename must change only the name to `element`; the explicit stack type must then change only that row's type to `const void *`. Reject any local/saved/return row rename/retype/shift, extra/deleted row, stack-size change, physical `this` row, or semantic/physical poststate mismatch. On any failure, the supervisor stops before the F1 comment/F2/manual/generated/save stages, discards the complete unsaved worker transaction, and reopens the canonical IDB or exact matching backup to prove full prestate restoration.

### F2 Deterministic Calling-Convention And Frame Binding Contract

The F2 semantic change deliberately converts the function type from `__stdcall` to `__thiscall`. The receiver is added only as an implicit width-four ECX binding. It consumes no stack slot and therefore must not move the two existing four-byte physical arguments at `+0x18` and `+0x1c`. As with F1, semantic prototype application does not receive credit for occupied physical-row names/types; each F2 row has its own literal rename/type requests and immediate complete-frame readbacks.

| Binding/row | Offset/register | Width | Exact prestate name/type | Exact poststate name/type | Disposition/readback |
| --- | --- | --- | --- | --- | --- |
| implicit receiver | `ECX` | 4 | absent from current `void *__stdcall(void *Block, _DWORD *pExceptionObject)`; no implicit receiver and no frame row | `this` / `MemoryMan *`; implicit `__thiscall` binding, no frame row | Required ECX addition; must not create or shift a stack row. |
| local | `+0x04` | 4 | `var_C` / `_DWORD` | `var_C` / `_DWORD` | Protected unchanged. |
| local | `+0x0c` | 4 | `var_4` / `_DWORD` | `var_4` / `_DWORD` | Protected unchanged. |
| saved-register row | `+0x10` | 4 | `__saved_registers` / IDA special frame row with no user type | `__saved_registers` / IDA special frame row with no user type | Protected unchanged. |
| return-address row | `+0x14` | 4 | `__return_address` / IDA special frame row with no user type | `__return_address` / IDA special frame row with no user type | Protected unchanged. |
| explicit argument 0 | `+0x18` | 4 | `Block` / `void *` | `block` / `void *` | Required spelling normalization; offset, width, and pointer type unchanged. |
| explicit argument 1 | `+0x1c` | 4 | function prototype parameter `_DWORD *pExceptionObject`; physical frame row `pExceptionObject` / `int` | `newSize` / `size_t` in both function prototype and physical argument row | Required name/type correction at the same physical row; do not preserve the exception-reuse inference in the source-facing prototype. |

F2 deterministic stop/readback rule: stop before mutation unless both the complete function-level prototype `void *__stdcall(void *Block, _DWORD *pExceptionObject)` and complete physical frame, including `Block`/`void *` at `+0x18` and `pExceptionObject`/`int` at `+0x1c`, match exactly. Also stop on any drift in row count, implicit-receiver absence, calling convention, range, EH, xrefs, comments, or byte hash. After semantic function `set_type`, require exact desired `void *__thiscall MemoryMan_ReallocateBufferMemory(MemoryMan *this, void *block, size_t newSize)` in `func_profile` while the physical frame remains exactly at prestate. For each row, dry-run rename, actual rename, and explicit stack type are distinct checkpoints with complete-frame reads. Reject residual semantic `_DWORD *pExceptionObject`, any shift, any physical `this`, any unauthorized row change, extra/deleted row, stack-size change, or missing/error result. On failure, stop before the F2 comment/manual/generated/save stages, discard the entire unsaved T1/F1/F2 worker transaction, and reopen canonical/backup state for exact rollback proof.

Literal database-scoped request contract and fixed order used by the completed supervisor transaction:

- Session enumeration request: `idb_list {}`. The supervisor replaced `"<active-session-id-from-current-idb_list>"` with sole pre-transaction session `b002-persist-reopen` PID `11812` only after canonical SHA/size and fresh backup identity matched exactly, then reused that binding through the unsaved transaction. The placeholder is retained below to preserve the reusable literal contract; it is not a request to mutate the current fresh-reopen session. Any listener/session change, timeout, missing per-item result, error, false/missing `ok`, prestate drift, or unexpected readback was a no-save stop condition.
- T1 request, using a one-element array so declaration commas are not split:

~~~text
declare_type {decls:["typedef int (__cdecl *SortedListCompareFunction)(const void *left, const void *right); struct SortedList { void **vtable; int m_elementSize; int m_pageSize; int m_count; void *m_data; SortedListCompareFunction m_compare; };"],database:"<active-session-id-from-current-idb_list>"}
type_inspect {queries:[{name:"SortedListCompareFunction",include_members:false,max_members:0},{name:"SortedList",include_members:true,max_members:16},{name:"List",include_members:true,max_members:16},{name:"MemoryMan",include_members:true,max_members:16}],database:"<active-session-id-from-current-idb_list>"}
~~~

- F1 executable order and exact objects:

~~~text
rename {batch:{func:{addr:"0x004f3690",name:"SortedList_InsertSorted"},dry_run:true,stop_on_error:true,allow_overwrite:false},database:"<active-session-id-from-current-idb_list>"}
func_profile {queries:{addr:"0x004f3690",include_lists:false,max_items:0,include_prototype:true},database:"<active-session-id-from-current-idb_list>"}
rename {batch:{func:{addr:"0x004f3690",name:"SortedList_InsertSorted"},dry_run:false,stop_on_error:true,allow_overwrite:false},database:"<active-session-id-from-current-idb_list>"}
func_profile {queries:{addr:"0x004f3690",include_lists:false,max_items:0,include_prototype:true},database:"<active-session-id-from-current-idb_list>"}
set_type {edits:{addr:"0x004f3690",kind:"function",signature:"int __thiscall SortedList_InsertSorted(SortedList *this, const void *element)"},database:"<active-session-id-from-current-idb_list>"}
func_profile {queries:{addr:"0x004f3690",include_lists:false,max_items:0,include_prototype:true},database:"<active-session-id-from-current-idb_list>"}
stack_frame {addrs:"0x004f3690",database:"<active-session-id-from-current-idb_list>"}
rename {batch:{stack:{func_addr:"0x004f3690",old:"Src",new:"element"},dry_run:true,stop_on_error:true,allow_overwrite:false},database:"<active-session-id-from-current-idb_list>"}
stack_frame {addrs:"0x004f3690",database:"<active-session-id-from-current-idb_list>"}
rename {batch:{stack:{func_addr:"0x004f3690",old:"Src",new:"element"},dry_run:false,stop_on_error:true,allow_overwrite:false},database:"<active-session-id-from-current-idb_list>"}
stack_frame {addrs:"0x004f3690",database:"<active-session-id-from-current-idb_list>"}
set_type {edits:{addr:"0x004f3690",kind:"stack",name:"element",ty:"const void *"},database:"<active-session-id-from-current-idb_list>"}
stack_frame {addrs:"0x004f3690",database:"<active-session-id-from-current-idb_list>"}
func_profile {queries:{addr:"0x004f3690",include_lists:false,max_items:0,include_prototype:true},database:"<active-session-id-from-current-idb_list>"}
~~~

F1 checkpoint order is literal. Function-rename dry run changes nothing and its immediate profile must retain the original name/prototype; actual rename changes only the name and its immediate profile must show the new name with the old prototype. Semantic `set_type` must return `kind:"function"`, `ok:true`, no error; semantic readback must be exact while the first complete-frame read remains prestate. Stack dry run changes nothing and must return `dry_run:true`/no error. Actual stack rename changes only `Src` to `element` at `+0x1c`, retaining width 4/`void *`. Stack `set_type` must return `kind:"stack"`, `ok:true`, no error and change only that row to `const void *`. Re-read the complete frame, semantic prototype, four comment channels, 13 xrefs, eleven protected internal comments, byte hash, range, row count, and stack size before applying the exact F1 function-repeatable comment. If the available comment mutation mechanism cannot target function-repeatable state exactly, stop with no save rather than substitute another channel.

- F2 executable order and exact objects, performed only after final F1/comment/protection readback succeeds:

~~~text
rename {batch:{func:{addr:"0x00516190",name:"MemoryMan_ReallocateBufferMemory"},dry_run:true,stop_on_error:true,allow_overwrite:false},database:"<active-session-id-from-current-idb_list>"}
func_profile {queries:{addr:"0x00516190",include_lists:false,max_items:0,include_prototype:true},database:"<active-session-id-from-current-idb_list>"}
rename {batch:{func:{addr:"0x00516190",name:"MemoryMan_ReallocateBufferMemory"},dry_run:false,stop_on_error:true,allow_overwrite:false},database:"<active-session-id-from-current-idb_list>"}
func_profile {queries:{addr:"0x00516190",include_lists:false,max_items:0,include_prototype:true},database:"<active-session-id-from-current-idb_list>"}
set_type {edits:{addr:"0x00516190",kind:"function",signature:"void *__thiscall MemoryMan_ReallocateBufferMemory(MemoryMan *this, void *block, size_t newSize)"},database:"<active-session-id-from-current-idb_list>"}
func_profile {queries:{addr:"0x00516190",include_lists:false,max_items:0,include_prototype:true},database:"<active-session-id-from-current-idb_list>"}
stack_frame {addrs:"0x00516190",database:"<active-session-id-from-current-idb_list>"}
rename {batch:{stack:{func_addr:"0x00516190",old:"Block",new:"block"},dry_run:true,stop_on_error:true,allow_overwrite:false},database:"<active-session-id-from-current-idb_list>"}
stack_frame {addrs:"0x00516190",database:"<active-session-id-from-current-idb_list>"}
rename {batch:{stack:{func_addr:"0x00516190",old:"Block",new:"block"},dry_run:false,stop_on_error:true,allow_overwrite:false},database:"<active-session-id-from-current-idb_list>"}
stack_frame {addrs:"0x00516190",database:"<active-session-id-from-current-idb_list>"}
set_type {edits:{addr:"0x00516190",kind:"stack",name:"block",ty:"void *"},database:"<active-session-id-from-current-idb_list>"}
stack_frame {addrs:"0x00516190",database:"<active-session-id-from-current-idb_list>"}
rename {batch:{stack:{func_addr:"0x00516190",old:"pExceptionObject",new:"newSize"},dry_run:true,stop_on_error:true,allow_overwrite:false},database:"<active-session-id-from-current-idb_list>"}
stack_frame {addrs:"0x00516190",database:"<active-session-id-from-current-idb_list>"}
rename {batch:{stack:{func_addr:"0x00516190",old:"pExceptionObject",new:"newSize"},dry_run:false,stop_on_error:true,allow_overwrite:false},database:"<active-session-id-from-current-idb_list>"}
stack_frame {addrs:"0x00516190",database:"<active-session-id-from-current-idb_list>"}
set_type {edits:{addr:"0x00516190",kind:"stack",name:"newSize",ty:"size_t"},database:"<active-session-id-from-current-idb_list>"}
stack_frame {addrs:"0x00516190",database:"<active-session-id-from-current-idb_list>"}
func_profile {queries:{addr:"0x00516190",include_lists:false,max_items:0,include_prototype:true},database:"<active-session-id-from-current-idb_list>"}
~~~

F2 checkpoint order is literal. Semantic `set_type` must return function-kind success and exact semantic `__thiscall` readback while the first complete physical-frame read remains `Block`/`void *` and `pExceptionObject`/`int`. Each dry run must be collision-free and preserve the frame; each actual rename may change only its named occupied row; each stack type must return stack-kind success and may change only that row's type. The `block` type step is explicit even if `void *` is already physically rendered. Final readback requires exactly `block`/`void *` at `+0x18` and `newSize`/`size_t` at `+0x1c`, plus the exact desired semantic prototype and implicit ECX receiver. Re-read every protection, EH/range/ten xrefs/comments/byte hash/row count/stack size before the exact F2 function-repeatable comment. Do not save until T1/F1/F2, P1-P11, and all comment channels pass together; any failure discards the full unsaved worker and requires canonical/backup hash plus clean-prestate proof before another attempt.

T1 exact declaration:

~~~cpp
typedef int (__cdecl *SortedListCompareFunction)(const void *left,
                                                  const void *right);
struct SortedList {
    void **vtable;
    int m_elementSize;
    int m_pageSize;
    int m_count;
    void *m_data;
    SortedListCompareFunction m_compare;
};
~~~

F1 exact prototype:

~~~cpp
int __thiscall SortedList_InsertSorted(SortedList *this,
                                       const void *element);
~~~

F1 exact function-repeatable comment:

~~~text
SortedList::InsertSorted inserts one fixed-width element after all comparator-equal elements, grows backing storage in m_pageSize-element pages, shifts the tail, copies m_elementSize bytes, increments m_count, and returns the insertion index.
~~~

F2 exact prototype:

~~~cpp
void *__thiscall MemoryMan_ReallocateBufferMemory(
    MemoryMan *this,
    void *block,
    size_t newSize);
~~~

F2 exact function-repeatable comment:

~~~text
MemoryMan::ReallocateBufferMemory calls realloc(block, newSize), returns the new block on success, and throws new Win32Error on failure; callers pass the MemoryMan singleton in ECX.
~~~

Protected dependencies:

| ID | Exact entity and current identity/type | Exact comments/frame/xrefs | Protection and expected readback |
| --- | --- | --- | --- |
| P1 | 0x004f3600-0x004f3681, width 0x81; sub_4F3600; _DWORD *__thiscall(_DWORD *this, int, int, int) | Address regular absent; address repeatable absent; function regular absent; function repeatable absent. Frame: var_10 +08 LObject *, var_C +0c _DWORD, var_4 +14 _DWORD, saved +18, return +1c, arg_0/+4/+8 at +20/+24/+28. Xrefs: 47eced and 520e94. | No action. Preserve exact constructor body/name/type/comments/frame/two xrefs/bytes; this target does not source-audit the sibling constructor. |
| P2 | 0x004f3780-0x004f3803, width 0x83; sub_4F3780; int __thiscall(int this, void *Key) | Address regular absent; address repeatable absent; function regular absent; function repeatable absent. Frame: var_4 +04, saved +08, return +0c, Key +10 void *. Fourteen code xrefs: 47ed98, 47ee37, 521519, 5215b9, 521659, 5216f9, 521799, 521829, 5218b9, 521969, 521a09, 521aa9, 521b4d, 521c0d. | No action. Preserve exact FindFirstEqual sibling body/name/type/comments/frame/xrefs/bytes. |
| P3 | 0x004f38b0-0x004f3947, width 0x97; sub_4F38B0; current prototype `LObject *__thiscall(LObject *Block, char)` with implicit width-4 ECX `Block`/`LObject *` and return type `LObject *` | Address regular absent; address repeatable absent; function regular absent; function repeatable absent. Complete physical frame: `var_C` +08 width 4 `_DWORD`; `var_4` +10 width 4 `_DWORD`; `__saved_registers` +14 width 4 `_DWORD`; `__return_address` +18 width 4 `_UNKNOWN *`; `arg_0` +1c width 4 `_DWORD`. One data xref at vtable slot 61ce58. | No action. Preserve the exact current `LObject *__thiscall(LObject *Block, char)` compiler-wrapper prototype, implicit ECX/return types, all four comment states, complete physical frame, vtable ref, and bytes; do not rename/retype it as a source destructor. |
| P4 | 0x004f3950-0x004f397a, width 0x2a; sub_4F3950; int __thiscall(_DWORD *this, int) | Address regular absent; address repeatable absent; function regular absent; function repeatable absent. Frame: saved +00, return +04, arg_0 +08. One data xref at vtable slot 61ce68. | No action. Preserve sibling GetElementAt identity/type/comments/frame/vtable ref/bytes. |
| P5 | 0x004f3980-0x004f398b, width 0x0b; sub_4F3980; int __thiscall(_DWORD *this) | Address regular absent; address repeatable absent; function regular absent; function repeatable absent. Frame contains return at +00 only. One data xref at vtable slot 61ce78. | No action. Preserve sibling RemoveAll wrapper identity/type/comments/frame/vtable ref/bytes. |
| P6 | 0x004f3990-0x004f3a43, width 0xb3; sub_4F3990; int __thiscall(_DWORD *this, int, int) | Address regular absent; address repeatable absent; function regular absent; function repeatable absent. Frame: var_4 +0c, saved +10, return +14, arg_0 +18, arg_4 +1c. One data xref at vtable slot 61ce74. | No action. Preserve sibling RemoveAt identity/type/comments/frame/vtable ref/bytes. |
| P7 | 0x00516030-0x00516036, width 0x06; GetMemoryMan; MemoryMan *__cdecl GetMemoryMan() | Address regular absent; address repeatable absent; function regular is exactly Returns the process MemoryMan singleton used as receiver for overlap-safe MoveBufferMemory operations.; function repeatable absent. Frame contains return at +00 only. Exactly 612 code xrefs, literal inventory below; normalized lowercase comma-separated inventory SHA256 0C756CF243C102471CFC4A7D25BAB6D6AC3A8FB156D26BE381074104D0BC9178. Target calls are 4f36be and 4f36fa. | No action. Preserve accepted name/type/literal comment/frame, all 612 literal xrefs, xref-inventory hash, and byte hash. |
| P8 | 0x00516050-0x005160ce, width 0x7e; MemoryMan_AllocateBufferMemory; void *__thiscall MemoryMan_AllocateBufferMemory(MemoryMan *this, size_t size) | Address regular absent; address repeatable absent; function regular is exactly MemoryMan::AllocateBufferMemory(size_t). Callers pass the singleton in ECX even though this body does not dereference it; returns malloc storage or throws a Win32Error pointer on failure.; function repeatable absent. Current frame includes Block +04, var_C +08, var_4 +10, saved +14, return +18, pExceptionObject +1c, arg_4 +20. Exactly 132 code xrefs, literal inventory below; normalized lowercase comma-separated inventory SHA256 98C59AE04B8C12B813484245F0D9542D77B105B74C027B3C73FDE2974BAE79AD. Target call is 4f3713. | No action. Preserve accepted name/type/literal comment/frame/EH, all 132 literal xrefs, xref-inventory hash, and byte hash. |
| P9 | 0x00516220-0x00516238, width 0x18; MemoryMan_MemmoveWrapper; void *__thiscall MemoryMan_MemmoveWrapper(MemoryMan *this, void *destination, const void *source, size_t size) | Address regular absent; address repeatable absent; function regular is exactly MemoryMan::MemmoveWrapper(destination, source, size). Callers preserve/reload the MemoryMan singleton in ECX; thin overlap-safe memmove wrapper.; function repeatable absent. Frame: saved +00, return +04, destination +08 void *, Src +0c void *, Size +10 size_t. Target call at 4f376b; current accepted raw-PE fanout is 604. | No action. Preserve accepted name/type/literal comment/frame/xrefs/bytes. |
| P10 | 0x00516240-0x00516258, width 0x18; MemoryMan_MoveBufferMemory; void *__thiscall MemoryMan_MoveBufferMemory(MemoryMan *this, void *destination, const void *source, size_t size) | Address regular absent; address repeatable absent; function regular is exactly MemoryMan overlap-safe buffer move wrapper over memmove; receiver is semantically the MemoryMan singleton even though this compact body does not consume it.; function repeatable absent. Frame: saved +00, return +04, destination +08 void *, Src +0c void *, Size +10 size_t. Target call at 4f3752; exact shared fanout is 19. | No action. Preserve accepted name/type/literal comment/frame/19 xrefs/bytes. |
| P11 | data 0x0061ce58-0x0061ce80, width 0x28; ten separate 4-byte data items at 61ce58/5c/60/64/68/6c/70/74/78/7c. Base item name ??_7SortedList@@6B@; other nine names blank. Current IDA data type is blank/absent on every item; no aggregate/array type exists. | Base address regular absent; base address repeatable absent; function regular/repeatable and frame not applicable because this is data. One constructor data xref at 4f3669. Slots: 4f38b0, 4f4b10, 41b6c0, 4f32a0, 4f3950, 4f32e0, 4f33c0, 4f3990, 4f3980, 4f34b0. | No action. Preserve ten item boundaries, decorated compiler-owned base name, blank types, comments, slots, locator adjacency, constructor xref, and byte hash; do not hand-author, aggregate-type, or rename vtable data. |

Exact byte baselines for every actionable/protected range whose readback promises unchanged bytes:

| ID | Exact range / width | Current byte SHA256 |
| --- | --- | --- |
| P1 | 0x004f3600-0x004f3681 / 0x81 | A35E9F0414CBED494F42819F07CF2D6D07EA8F45A7AEDB1C3C6885EEAF4A4349 |
| F1 | 0x004f3690-0x004f377b / 0xeb | 9C1F40D2F7BEA980924AD322AF568A22F62745CC87FE8CAA2172417AC276C0D9 |
| P2 | 0x004f3780-0x004f3803 / 0x83 | E46770A613E7F18214435B72580E4ABBE3BB21FC1CD9148CD77D6CB45EDF17D0 |
| P3 | 0x004f38b0-0x004f3947 / 0x97 | 0D6E86603C70D31052C0C716FC1A267101C77E6E963C99B5AAEEB1B7905520A7 |
| P4 | 0x004f3950-0x004f397a / 0x2a | 44810F2561A7EC891F1EE7237B5694789F30138BE66DAD596820D69414CF1B3B |
| P5 | 0x004f3980-0x004f398b / 0x0b | E71C4E6B9D7DE83452E0937778DD6674E77D35C225FD844382D0FBCFA91175C3 |
| P6 | 0x004f3990-0x004f3a43 / 0xb3 | 08893E39F93942DAE16DE87A735169487F540F8BB9D4E3B075DF0E9EC03C0290 |
| P7 | 0x00516030-0x00516036 / 0x06 | 208756678E715EF53B49586D4530A514ABAEE90813DD347C836943EC07222327 |
| P8 | 0x00516050-0x005160ce / 0x7e | 99006135CEAC5923120ECDE403D0DB926D805D6FEB9E98C8D2FCC158DC069B3B |
| F2 | 0x00516190-0x00516210 / 0x80 | 8B0432A1F5E34F241F38C092C18B986700EFAF09BAD0E7C5B95F903C95A4B2CA |
| P9 | 0x00516220-0x00516238 / 0x18 | B5A8648EB3914D883E7D3D92AE3CFE0A391689D691346400F3791A8AE638F33A |
| P10 | 0x00516240-0x00516258 / 0x18 | 30888A5036BC2B61C7CE54B492A49B1D05491DDE0066E217EDB66DFE0A96E2C3 |
| P11 | 0x0061ce58-0x0061ce80 / 0x28 | F637D86D908BB138D6831C6161FF6057C8695945C979A17A6A81BF2E5AD6F990 |

P7 literal 612-xref baseline, sorted ascending:

- P7[001-048]: 0x457aca, 0x457c7a, 0x457e09, 0x457e18, 0x457f39, 0x45801d, 0x45802e, 0x45828d, 0x4583ef, 0x458451, 0x4584b5, 0x4584c8, 0x458504, 0x45c3f1, 0x45c6c9, 0x45c98d, 0x45cc93, 0x45d830, 0x45d8ac, 0x45d92b, 0x45d9ef, 0x465353, 0x465469, 0x466139, 0x46d5a5, 0x46eac1, 0x4720fb, 0x47248d, 0x472d2b, 0x473337, 0x474296, 0x474367, 0x474490, 0x4746e7, 0x474803, 0x475478, 0x475ba5, 0x47690d, 0x476a23, 0x47733d, 0x477483, 0x4775b2, 0x47781c, 0x477ce0, 0x47868a, 0x47898d, 0x478ad3, 0x478c02
- P7[049-096]: 0x47919b, 0x47973d, 0x47a405, 0x47a540, 0x47a793, 0x47b2b5, 0x47bb3f, 0x47ca3d, 0x47cb73, 0x47da6d, 0x47dba3, 0x47dcd2, 0x47f1a3, 0x47f2f3, 0x47f346, 0x47fda1, 0x47feac, 0x47ffb5, 0x4804aa, 0x4834ce, 0x483583, 0x483e9a, 0x4842d1, 0x484ff6, 0x4850c5, 0x48513e, 0x48518b, 0x4851ec, 0x48524d, 0x4852a5, 0x485358, 0x4853b9, 0x4855a9, 0x4859e8, 0x485ae4, 0x485cd8, 0x485e38, 0x485f98, 0x4860f8, 0x486258, 0x486354, 0x486728, 0x4877f3, 0x487a04, 0x487c71, 0x487d94, 0x487e43, 0x487edd
- P7[097-144]: 0x488194, 0x488244, 0x4882f4, 0x488394, 0x488484, 0x488533, 0x48869b, 0x488a20, 0x488bb8, 0x489198, 0x4892c8, 0x4893f8, 0x489528, 0x48967a, 0x48a234, 0x48a884, 0x48aef5, 0x48b253, 0x48b945, 0x48c71a, 0x48da0f, 0x48dd2a, 0x48e1e1, 0x48e896, 0x48f416, 0x48f4ec, 0x48f6f0, 0x48fcd4, 0x490526, 0x490826, 0x490b50, 0x4910e6, 0x491466, 0x4917a6, 0x4950d6, 0x4950fb, 0x49517a, 0x4951bb, 0x49575b, 0x499a1a, 0x49b341, 0x49b7f1, 0x49db78, 0x49dbcf, 0x49ff38, 0x4a315b, 0x4a352e, 0x4a3672
- P7[145-192]: 0x4a3e31, 0x4a407b, 0x4a50ce, 0x4a5173, 0x4a526c, 0x4a53a3, 0x4a5450, 0x4a54b1, 0x4a556b, 0x4a583a, 0x4a58fa, 0x4a59a2, 0x4a5b0f, 0x4a5c16, 0x4a5caf, 0x4a8ba4, 0x4a9b97, 0x4a9d47, 0x4aab07, 0x4aacb7, 0x4ab527, 0x4ab75d, 0x4ac90e, 0x4ad3cb, 0x4ad5af, 0x4ad68c, 0x4adb2f, 0x4add77, 0x4ade93, 0x4b052e, 0x4b5fb7, 0x4b6237, 0x4b63b2, 0x4b9aa0, 0x4bad99, 0x4bb148, 0x4bb268, 0x4bb29f, 0x4bc0bc, 0x4c0fb8, 0x4c61b2, 0x4c61c4, 0x4c628e, 0x4c629d, 0x4c646f, 0x4c6525, 0x4c6534, 0x4c7039
- P7[193-240]: 0x4c704f, 0x4c72da, 0x4c8b61, 0x4ccd11, 0x4ce478, 0x4ce5b1, 0x4ce88a, 0x4ce9da, 0x4d00a0, 0x4d0153, 0x4d03bf, 0x4d0ddd, 0x4d0f0f, 0x4d0f81, 0x4d15d5, 0x4d1665, 0x4d19d0, 0x4d1bab, 0x4d2a33, 0x4d4b03, 0x4d4b27, 0x4d4b4b, 0x4d4b6f, 0x4d4b93, 0x4d4bb7, 0x4d4bdb, 0x4d4bff, 0x4d4c23, 0x4d4c47, 0x4d4c6b, 0x4d4c8f, 0x4d4cb3, 0x4d4cd7, 0x4d4cfb, 0x4d4d1f, 0x4d4d43, 0x4d4d67, 0x4d4d90, 0x4d4dad, 0x4d4dca, 0x4db8db, 0x4dbc8e, 0x4dbf9c, 0x4dc39f, 0x4dc760, 0x4dcfbe, 0x4dd211, 0x4dd272
- P7[241-288]: 0x4dda8b, 0x4dde3a, 0x4de128, 0x4de44b, 0x4dfe8c, 0x4e02bb, 0x4e0e64, 0x4e1093, 0x4e1a01, 0x4e1f35, 0x4e63cf, 0x4e64d7, 0x4e66d7, 0x4e68e7, 0x4e69ca, 0x4e6a35, 0x4e90c1, 0x4e9283, 0x4f0081, 0x4f02bd, 0x4f0404, 0x4f04c0, 0x4f05e8, 0x4f1b8f, 0x4f309b, 0x4f3113, 0x4f3149, 0x4f3171, 0x4f321f, 0x4f3279, 0x4f32eb, 0x4f332b, 0x4f33ec, 0x4f346a, 0x4f34b8, 0x4f3566, 0x4f35bc, 0x4f363b, 0x4f36be, 0x4f36fa, 0x4f384a, 0x4f38ea, 0x4f399c, 0x4f3a1a, 0x4f4aa6, 0x4f4ae2, 0x4f4bcd, 0x4f7110
- P7[289-336]: 0x4f7204, 0x4f8d45, 0x4f8d8e, 0x4f8e62, 0x4fa3d1, 0x4fa5e9, 0x4fab43, 0x4fb2eb, 0x4fcb43, 0x4fe7ca, 0x4fea11, 0x4fec23, 0x4fee79, 0x4ff0c2, 0x4ff482, 0x50093a, 0x50331a, 0x503359, 0x5034c0, 0x503654, 0x503891, 0x5041fc, 0x504647, 0x5083bb, 0x5086ce, 0x50f63a, 0x50ff1d, 0x50ffed, 0x510188, 0x51050d, 0x5109b7, 0x510ea1, 0x511df3, 0x513685, 0x513ad4, 0x513cad, 0x517fd0, 0x518557, 0x51912b, 0x519261, 0x5193a8, 0x51961e, 0x519736, 0x519980, 0x519e23, 0x51a2e7, 0x51a43a, 0x51a5b0
- P7[337-384]: 0x51ad39, 0x51afff, 0x51b1ab, 0x51b917, 0x51be4a, 0x51cadd, 0x51d024, 0x51d5a9, 0x51d7ff, 0x51d91b, 0x51dbd7, 0x51e07d, 0x51ea30, 0x52137e, 0x52144b, 0x521b75, 0x521c35, 0x522a76, 0x522c00, 0x522cf8, 0x522df8, 0x522f0c, 0x522f77, 0x5231fc, 0x5235cc, 0x5238a8, 0x523b9d, 0x52483f, 0x524963, 0x524a15, 0x52bbf1, 0x52c010, 0x52c159, 0x52d5e1, 0x52d9e0, 0x52db29, 0x52ef81, 0x52f3d0, 0x52f519, 0x530f1f, 0x53128e, 0x533f8b, 0x5347f8, 0x54321a, 0x543b4d, 0x54567f, 0x54578f, 0x54589c
- P7[385-432]: 0x547b3c, 0x547c6c, 0x547d6c, 0x549c94, 0x54abb1, 0x54ce8f, 0x54d4b7, 0x54dc0f, 0x54e23a, 0x54e9a5, 0x54f117, 0x54fbb5, 0x55032a, 0x5515a6, 0x551b1d, 0x55218f, 0x55292b, 0x5531e0, 0x55336b, 0x5534e5, 0x553688, 0x553a1b, 0x553a93, 0x553ac6, 0x553b16, 0x553baa, 0x554e1e, 0x5557f8, 0x55611b, 0x55640e, 0x556513, 0x556587, 0x5565f7, 0x5567ea, 0x5582d9, 0x56585e, 0x5658cf, 0x56a667, 0x56cb4a, 0x56dddd, 0x56e240, 0x56e5ba, 0x5700ae, 0x570119, 0x5735d1, 0x5736c5, 0x5737b5, 0x57398a
- P7[433-480]: 0x573a61, 0x573ad6, 0x573b3b, 0x573b88, 0x573bca, 0x573c09, 0x573cb6, 0x574853, 0x574bbc, 0x574bd9, 0x574c4b, 0x574c6d, 0x574d0a, 0x574df2, 0x574e04, 0x57525a, 0x57527b, 0x5755f7, 0x57563e, 0x575b95, 0x575cb6, 0x575f93, 0x575fc4, 0x57669e, 0x576711, 0x57687d, 0x577036, 0x577170, 0x577378, 0x577b11, 0x577e23, 0x578265, 0x5783e8, 0x578863, 0x57a627, 0x57a63c, 0x57a64f, 0x57b445, 0x57b45a, 0x57b46d, 0x5851ac, 0x585531, 0x58597f, 0x585b35, 0x585bbc, 0x585ed5, 0x586512, 0x5865bd
- P7[481-528]: 0x58662f, 0x586a29, 0x586a95, 0x586c81, 0x586d0e, 0x586db8, 0x586e4d, 0x58703d, 0x5870cd, 0x587177, 0x587204, 0x58736b, 0x587544, 0x587880, 0x5879ae, 0x587a43, 0x588f32, 0x5890b2, 0x589148, 0x589445, 0x58971f, 0x5898d5, 0x58994f, 0x58a56b, 0x58a744, 0x58aa80, 0x58ab8a, 0x58e389, 0x58e4d3, 0x58e62f, 0x5901be, 0x5901c6, 0x590220, 0x5902b4, 0x5902c7, 0x590311, 0x590441, 0x590450, 0x5904b4, 0x59059a, 0x590ba1, 0x590ba9, 0x590bba, 0x5917f8, 0x591800, 0x591814, 0x59183f, 0x59184f
- P7[529-576]: 0x591a28, 0x591a30, 0x591ba1, 0x591bcc, 0x591bdc, 0x591c10, 0x591c1d, 0x591cbe, 0x591d6e, 0x594f9c, 0x594ff4, 0x595058, 0x59506c, 0x5950a8, 0x5950b7, 0x5950e7, 0x5950f9, 0x595147, 0x595157, 0x5951ab, 0x595275, 0x5952e7, 0x595300, 0x59533b, 0x59534b, 0x5956e3, 0x595c26, 0x595d4e, 0x595f5a, 0x59609a, 0x599ad2, 0x599b5f, 0x599c46, 0x599d3a, 0x59b5e2, 0x59bd2a, 0x59de03, 0x59e6a7, 0x59ef4f, 0x59f648, 0x5a16c4, 0x5a21a8, 0x5a3895, 0x5a39a5, 0x5a3c6b, 0x5a3d58, 0x5a77bd, 0x5a8046
- P7[577-612]: 0x5aa735, 0x5aaaaf, 0x5ab8ae, 0x5ac0a5, 0x5ac391, 0x5ac6ea, 0x5ad18a, 0x5ae0d4, 0x5ae1cb, 0x5b16ba, 0x5b1842, 0x5b1ada, 0x5b1d72, 0x5b1ffa, 0x5b2182, 0x5b240a, 0x5b2592, 0x5b3705, 0x5b3808, 0x5b3ad5, 0x5b3bd8, 0x5b42e6, 0x5b43d8, 0x5b547a, 0x5b5568, 0x5b6ee3, 0x5b7029, 0x5b7263, 0x5b7379, 0x5b857a, 0x5bac4a, 0x5bac9b, 0x5bdbba, 0x5bfdf1, 0x5bfeb1, 0x5bff71

P8 literal 132-xref baseline, sorted ascending:

- P8[001-048]: 0x457c24, 0x457dc3, 0x457e5a, 0x457ebf, 0x457eea, 0x457f0c, 0x457f7b, 0x457fa8, 0x457fca, 0x4580ec, 0x4581e6, 0x45834b, 0x4583f6, 0x458458, 0x4584bc, 0x4584cf, 0x465391, 0x4654b1, 0x466145, 0x4834f9, 0x495102, 0x49dbd6, 0x4b624e, 0x4bb17d, 0x4c61b9, 0x4c61cb, 0x4c7040, 0x4cdd76, 0x4cdd87, 0x4ce899, 0x4d01a9, 0x4d03f9, 0x4d0de4, 0x4d112d, 0x4d1266, 0x4d143f, 0x4d149e, 0x4d169d, 0x4d16cb, 0x4d1c3c, 0x4d1d62, 0x4d2a86, 0x4d2ed8, 0x4d2f7c, 0x4db96c, 0x4dba92, 0x4dc02e, 0x4dd004
- P8[049-096]: 0x4dd05e, 0x4ddb1c, 0x4ddc42, 0x4dde84, 0x4ddedd, 0x4de4dc, 0x4de602, 0x4e1ab7, 0x4e1bd0, 0x4e1d91, 0x4e1de3, 0x4e90c8, 0x4f00bf, 0x4f0192, 0x4f01f5, 0x4f04c7, 0x4f31a7, 0x4f3238, 0x4f3344, 0x4f34ce, 0x4f357c, 0x4f3713, 0x4f4aad, 0x4ff0fb, 0x4ff4bb, 0x50431f, 0x511f63, 0x51205a, 0x5213d1, 0x52147b, 0x523211, 0x523226, 0x523baf, 0x523bc8, 0x543221, 0x573add, 0x573b42, 0x573c10, 0x574864, 0x57488c, 0x574be0, 0x574c74, 0x574d17, 0x574e0b, 0x575282, 0x57672d, 0x57678b, 0x57689e
- P8[097-132]: 0x5865e9, 0x586a4f, 0x586caa, 0x586de9, 0x587069, 0x5871a0, 0x5879d9, 0x588f3d, 0x5890d9, 0x58e636, 0x590289, 0x5902ce, 0x5903a2, 0x590457, 0x590bc1, 0x59181b, 0x591856, 0x591ac8, 0x591afe, 0x591b55, 0x591be3, 0x591c24, 0x591d1d, 0x591df5, 0x595073, 0x5950be, 0x595100, 0x59515e, 0x5951c6, 0x595307, 0x595352, 0x595c6c, 0x595fa2, 0x599ae0, 0x5a38a3, 0x5a39b3

Safety/readback:

- Re-read prestates immediately; T1 precedes F1 semantic type. F1 and F2 may proceed only when their complete deterministic prestate tables match, including every physical row name/type/offset/width and the implicit-register state. Bind every request to the one current session returned by immediate `idb_list`; do not reuse any evidence-time or rollback session ID.
- Apply each name, semantic function type, occupied-row rename dry-run/actual, occupied-row stack type, complete-frame readback, semantic-profile readback, and comment independently in the literal order above. Semantic type success never substitutes for direct physical-frame success. For F1, the only final physical frame change is `+0x1c` width 4 `Src`/`void *` to `element`/`const void *`; ECX remains implicit and refines from `int this` to `SortedList *this`. For F2, ECX is newly implicit as `MemoryMan *this`, `+0x18` remains width 4 `void *` while `Block` becomes `block`, and `+0x1c` remains width 4 while `pExceptionObject`/`int` becomes `newSize`/`size_t`.
- Preserve bytes against the exact SHA table, bounds, complete unaffected frame rows, row counts, stack sizes, complete xref inventories/hashes, internal target comments, helper EH, and decorated vtable item boundaries/name/blank types.
- Read back UDT members, all four comment states, decompile, the complete F1/F2 binding tables, exact xref counts/inventories, byte hashes, and protected entities. Decompiler presentation is secondary; the required contract is the exact function type plus implicit bindings and physical frame rows.
- Stop before mutation on any prestate mismatch. On any poststate mismatch, including missing/error tool result, failed dry run, semantic/physical divergence outside the required intermediate, extra/deleted/shifted row, unexpected local/special-row rename/type, physical `this` row, stack-size change, range/xref/comment/EH drift, or byte-hash change, stop all later actions and save nothing. The supervisor discards the entire unsaved worker transaction, verifies canonical disk SHA/size against the exact backup, opens a clean session, and proves exact full prestate restoration before any repaired retry. Save only after every exact accepted T1/F1/F2 poststate and P1-P11 protection reads back.
- Completed safety result: every prestate and poststate matched. The first verifier's exact-inventory assertion encountered MCP batch-result truncation, not an entity mismatch; individual F1/F2 xref queries proved the exact inventories before save. All other protections passed, `idb_save` returned `ok:true`, and fresh `b005-persist-reopen` persistence verification reproduced the accepted T1/F1/F2 state and P1-P11 protections from canonical SHA256 `92CD98A20133155CEC96C4AB6B60A00B7C5635A7C47E0A3F51BE918C13ACC5A0`.
<!-- END CLEANUP-20260813-00037J-SECTION21 -->

