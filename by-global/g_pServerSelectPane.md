*** UID:0000S8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ServerSelectPane;

ServerSelectPane *g_pServerSelectPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ServerSelectPane;

extern ServerSelectPane *g_pServerSelectPane;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Sole externally linked C++03 definition and header declaration for the loader-zeroed ServerSelectPane singleton pointer; emitted first in ServerSelectPane.cpp, with exact physical storage retained false/non-emitting under UID0002XN. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# g_pServerSelectPane

## Status

- Confidence: very strong for address, pointer type, loader-zero initialization, seven-reference lifecycle, direct Singleton cause, external linkage, sole-definition route, generated placement, and owner; exact original lexical spelling remains inferred.
- Address: `0x0069b4ac`
- Canonical source name: `g_pServerSelectPane`.
- Historical aliases: documentation `g_serverSelectPane`; IDA `dword_69B4AC`; current first-head IDA name `unk_69B4AC`. These are not separate source variables.
- Proposed owner file: [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)
- Exact storage evidence: [UID:0002XN][0x0069b4ac-0x0069b4b0.g_pServerSelectPane](by-memory/0x0069b4ac-0x0069b4b0.g_pServerSelectPane.md), now false/non-emitting.
- Emission order: position `0` under UID0000NO, before class/method children.

## Symbol Role

`g_pServerSelectPane` tracks the active pre-login server-selection dialog. This semantic page owns the sole source definition and matching header declaration. Physical page UID0002XN records address/storage evidence but must not emit a duplicate object.

Use `g_pServerSelectPane` as the canonical source-facing name because the value is a process-wide pointer to the active pane and the project uses the `g_p...` singleton convention. `g_serverSelectPane` is retained only as a rejected historical alias; it is not an unresolved second symbol.

The direct `Singleton<ServerSelectPane>` base explains constructor publication and ordinary/EH/scalar teardown clears as template/compiler lowering. Final source expresses the inheritance and this one global, not handwritten registration wrappers copied from compiler output.

## Accepted Source Definition And Header Declaration

The exact formal blocks above are the accepted one-definition route:

```cpp
class ServerSelectPane;

ServerSelectPane *g_pServerSelectPane = NULL;
```

```cpp
class ServerSelectPane;

extern ServerSelectPane *g_pServerSelectPane;
```

- The CPP forward declaration makes the position-0 pointer definition valid before the complete class declaration is emitted.
- The H forward declaration plus `extern` supplies cross-translation-unit consumers without defining storage twice.
- Explicit `NULL` is the best current late-1999 through mid-2000s source-shape inference. `= 0` and implicit static zero are binary-equivalent but lower-ranked lexical alternatives; `0xffffffff` is disproved.
- Do not make the pointer file-local `static`, class-static, a smart pointer, a reference, or a field in the physical aggregate. Main-menu code consumes the externally linked storage from outside the ServerSelect implementation cluster.

## Static Storage And Zero-Fill Proof

- Current live IDA MCP session `5a570ede` reads `00 00 00 00` at `0x0069b4ac`; signed and unsigned dword values are `0`, and global readback is `0x0`.
- The active executable has image base `0x00400000`, SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, and target RVA `0x29b4ac`.
- `.data` begins at RVA `0x26d000`, has virtual size `0x2fe24`, raw size `0xd800`, and raw pointer `0x26ac00`. Target delta `0x2e4ac` is beyond raw-backed `.data`, which ends at RVA `0x27a800`.
- Therefore no raw initializer bytes exist for this storage. Windows loader zero-fill provides the exact initial null state. Earlier `0xffffffff` wording is historical and superseded, not a competing current initializer.

## Direct Singleton RTTI And Layout Cause

- `ServerSelectPane` type descriptor: `0x006791a4`.
- `Singleton<ServerSelectPane>` type descriptor: `0x006791c4`.
- ServerSelectPane hierarchy/base-array records: `0x00650298` and `0x006502a8`.
- Direct Singleton base descriptor at `0x006502e8`: type pointer `0x006791c4`, zero contained bases, PMD `620/-1/0` (`+0x26c/-1/0`), attributes `0x40`.
- Existing `DialogPane` UDT is size `0x26c`. The empty Singleton base occupies the one-past-DialogPane address and can overlap `m_serverDirectory` at `+0x26c` under EBO; complete `ServerSelectPane` allocation is `0x270`.

The RTTI relationship and five write/clear sites prove the pointer dynamic type and lifetime. No full IDA `ServerSelectPane` UDT is needed to emit human source; an opaque forward declaration is sufficient for this global.

## IDA MCP Evidence

Current accepted evidence retains the earlier checks and adds live session `5a570ede` plus raw-image proof:

- Logical storage is one four-byte `.data` pointer, but current IDA physically presents four separate one-byte undefined heads. The first is `unk_69B4AC`, the remaining three are unnamed, all types/comments are blank, and exact `g_pServerSelectPane` name/global collision queries return zero.
- Main-menu cleanup at `0x004f69a0` reads the pointer at `0x004f69fb`, tests it, and calls `0x0049dad0` when non-null. This is part of the same cleanup run that closes adjacent pre-login singleton panes.
- Main-menu startup / server-select creation path at `0x004f6d80` tests `dword_69B4AC` at `0x004f70a8`; when it is null, it allocates `0x270` bytes and proceeds toward ServerSelectPane construction.
- `0x00573d20` is the ServerSelectPane construction path. It stores the adjusted object pointer into `dword_69B4AC` at `0x00573d7e`, clears it on the null fallback at `0x00573d85`, and then installs `ServerSelectPane` vtables at `0x00573d8f`, `0x00573d98`, and `0x00573da2`.
- `0x00574310` is a non-deleting destructor-like helper. It restores ServerSelectPane vtables and clears `dword_69B4AC` at `0x0057432a`.
- `0x00574750` is a tiny cleanup helper that clears `dword_69B4AC` directly.
- `0x00574780` is the scalar deleting destructor path; it restores ServerSelectPane vtables and clears `dword_69B4AC` at `0x005747a0`.
- IDA MCP `get_bytes` on 2026-06-12 C001 reconfirmed the exact slot as `0x0069b4ac-0x0069b4b0`, bytes `00 00 00 00`, initial dword `0x00000000`; `xrefs_to` reports the same seven direct xrefs. The exact storage subrange is split as [UID:0002XN][0x0069b4ac-0x0069b4b0.g_pServerSelectPane](by-memory/0x0069b4ac-0x0069b4b0.g_pServerSelectPane.md).

## Complete Lifecycle Inventory

| Address | Access | Source-level meaning |
| --- | --- | --- |
| `0x004f69fb` | read | Main-menu cleanup closes the active pane when non-null. |
| `0x004f70a8` | read | Server-list/startup handling guards allocation/construction. |
| `0x00573d7e` | write object pointer | `ServerSelectPane`/Singleton construction publishes the active object. |
| `0x00573d85` | write zero | Constructor fallback clears a null-adjusted publication. |
| `0x0057432a` | write zero | Ordinary non-deleting destructor clears before base teardown. |
| `0x00574750` | write zero | Constructor EH/unwind support clears partially published state. |
| `0x005747a0` | write zero | Scalar deleting destructor wrapper includes the ordinary clear side effect. |

Interior bytes have no refs, while next slot `0x0069b4b0` has 20 separate refs. This supports exact four-byte width and clean separation from `g_pTransferServerDialog`.

## One-Definition And Generated Topology

- UID0000S8 is reconstructable and emits through UID0000NO at position `0`.
- UID0002XN remains canonically linked here but is false/non-emitting with blank CPP/H.
- UID00029W remains a false/non-emitting mixed-owner physical index.
- UID0001HR remains a blank broad class/helper/thunk aggregate.
- After scoped validation, generated `ServerSelectPane.cpp` must contain this definition exactly once, generated `ServerSelectPane.h` must contain this declaration once, UID0002XN must have no empty marker, and unrelated empty markers must remain until their own passes.

## Ownership Notes

- Keep this global with `login/ServerSelectPane.cpp`, not with generic dialog or chat code.
- MainMenuPane is a consumer/coordinator, not the declaration owner. Physical adjacency with create-user and transfer globals does not create aggregate source ownership.
- Preserve `g_serverSelectPane`, `dword_69B4AC`, and `unk_69B4AC` only in historical/current-IDA evidence; finalized source uses `g_pServerSelectPane`.

## Score Rationale

- Completion `92`: exact formal CPP/H, position/order, external linkage, semantic/physical split, current zero-fill proof, full seven-ref lifecycle, direct Singleton RTTI cause, source owner, current IDA prestate, boundaries, generated expectations, and rejected alternatives are documented.
- Confidence `94`: live IDA, PE mapping, RTTI, constructor/destructor writes, cross-TU consumers, and current source-tree evidence agree. The cap preserves uncertainty only for unrecoverable original lexical tokens and pending supervisor IDA/generated Gate 2 verification.

## Cross-References

- [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)
- [UID:0000D2][ServerSelectPane](by-class/ServerSelectPane.md)
- [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)

## Changes

- 2026-06-05: Marked reconstructable and attached to [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md) to resolve the global unclassified coverage row.
  - Reasoning: live IDA xrefs bind the singleton to the pre-login server-selection constructor/destructor paths and main-menu cleanup/create guards, and the proposed source tree keeps this module under `login/ServerSelectPane.cpp`. No score change and no reconstruction C++ were added.
- What existed before: this page had correct older IDA notes but remained unevaluated for completion/confidence and still framed the alias decision around source-output reconciliation.
- What changed to: the page now records the current live IDA MCP xref set, constructor/destructor write sites, main-menu read sites, and a scoped alias decision. Completion/confidence were set to `82/88`.
- Summary and evidence: IDA MCP on 2026-05-30 verified `0x0069b4ac` / `dword_69B4AC` as a 4-byte `.data` global with 7 xrefs: main-menu cleanup read at `0x004f69fb`, startup/create guard at `0x004f70a8`, constructor assignment at `0x00573d7e`, constructor fallback clear at `0x00573d85`, destructor helper clear at `0x0057432a`, cleanup helper clear at `0x00574750`, and scalar deleting destructor clear at `0x005747a0`.
- 2026-06-07 Batch 043 split-parent refresh:
  - Before: `82/88`, below the corrected child-and-parent `85/85` completion gate for the exact storage split.
  - After: `86/88`.
  - Evidence: live IDA MCP reconfirmed the exact four-byte item, initial bytes/dword, and all seven lifecycle xrefs; the new exact memory page carries the storage-side row and this page remains the direct canonical global owner.
- 2026-06-12 C001 Batch C001-020:
  - Before: `86/88`, with stale `0xffffffff` initialization notes.
  - After: `87/90`.
  - Evidence: live IDA MCP `get_bytes` returned `00 00 00 00` for the exact slot in the active `b001_nexustk` database; `xrefs_to` still reports the same seven lifecycle refs.
- 2026-07-26 B005 UID0002XN implementation callback:
  - Raised `87/90` to `92/94`, retained UID0000NO owner/emitter, assigned position `0`, and installed exact formal CPP/H for the sole external definition and declaration.
  - Reconciled current `unk_69B4AC` four-head IDA prestate, loader-zero PE proof, seven-reference lifecycle, direct `Singleton<ServerSelectPane>` RTTI/PMD/EBO cause, physical UID0002XN false/non-emitting route, generated one-definition expectations, canonical source name, rejected alternatives, and score rationale.
