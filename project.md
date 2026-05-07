# Portfolio Projects

> A curated set of projects ranked by resume impact — covering systems, ML, real-time infrastructure, mobile, and AI.

---

## Table of Contents

- [S Tier — Instant Wow](#s-tier--instant-wow)
  - [Live DDoS Attack Map](#1-live-ddos-attack-map)
  - [Neural Network Game Agent](#2-neural-network-game-agent-reinforcement-learning)
  - [Distributed Vector Search Engine](#3-distributed-vector-search-engine)
- [A Tier — Strong Signal](#a-tier--strong-signal)
  - [UnAlone — Loneliness App](#4-unalone--worldwide-loneliness-app)
  - [Lightweight Map Engine](#5-lightweight-map-engine)
  - [Real-time Collaborative Code Editor](#6-real-time-collaborative-code-editor)
- [B Tier — Solid + Polish](#b-tier--solid--polish)
  - [Shazam Clone](#7-shazam-clone--audio-fingerprinting-engine)
  - [Selfie Storyboard](#8-selfie-storyboard)
- [Resume Strategy](#resume-strategy)

---

## S Tier — Instant Wow

> These projects combine visual impact with genuine technical depth across multiple domains. Lead with these in every interview conversation.

---

### 1. Live DDoS Attack Map

**Elevator pitch:** A real-time threat intelligence dashboard that ingests Cloudflare traffic data, classifies IPs using an ML confidence model, and renders live global attack vectors on a 3D globe.

**Why it stands out:** Crosses three hot domains simultaneously — cybersecurity, machine learning, and real-time systems. The visual spectacle earns attention; the ML pipeline earns respect.

#### What it does

- Periodically fetches traffic trends and attack spike data from the Cloudflare API
- Queries AbuseIPDB to enrich IPs with abuse confidence scores and metadata
- Classifies IPs with a ML model trained on DDoS behavioral patterns (packet rate, SYN ratio, geo anomalies)
- Maps remote IPs to geographic coordinates using a geolocation database
- Renders live attack arcs on a rotating 3D globe using Aceternity UI / Three.js
- Exposes a streaming WebSocket endpoint for the frontend to consume real-time events

#### Tech stack

| Layer | Technology |
|---|---|
| Backend API | FastAPI (Python) |
| Data ingestion | Cloudflare API, AbuseIPDB API |
| ML classification | scikit-learn / XGBoost — binary classifier on IP feature vectors |
| Feature engineering | Pandas, NumPy |
| Geolocation | MaxMind GeoLite2 / ip-api |
| Real-time transport | WebSockets (FastAPI WebSocket) |
| Frontend | React + TypeScript |
| 3D globe | Aceternity UI Globe component (Three.js under the hood) |
| State management | Zustand |
| Deployment | Docker + Uvicorn |

#### Key skills demonstrated

- Machine learning pipeline: feature extraction → training → inference serving
- Real-time streaming architecture (producer/consumer via WebSocket)
- REST API design and third-party API integration
- Geospatial data processing
- 3D data visualization

#### Resume hook

> "Built a real-time threat intelligence dashboard ingesting Cloudflare traffic data, scoring IPs with an XGBoost classifier (AUC 0.94), and streaming attack vectors to a 3D globe — processing ~500 events/sec through a FastAPI WebSocket layer."

---

### 2. Neural Network Game Agent (Reinforcement Learning)

**Elevator pitch:** A PPO/DQN agent trained from scratch — no hand-crafted rules, pure self-play — that learns to beat human-level performance at a card, PvP, or racing game.

**Why it stands out:** RL is one of the hardest and most respected ML subfields. Custom environment design plus full training loop plus evaluation metrics signals serious ML engineering maturity.

#### What it does

- Implements a custom Gymnasium-compatible environment wrapping the game
- Designs a reward function that shapes behavior toward winning strategies
- Trains a policy network using PPO (for continuous action spaces / racing) or DQN (for discrete actions / card games)
- Evaluates agent performance against a rule-based baseline and human testers
- Logs training metrics (episode reward, policy entropy, value loss) to TensorBoard
- Exports the final policy for inference in a live demo

#### Tech stack

| Layer | Technology |
|---|---|
| RL framework | Stable-Baselines3 / CleanRL |
| Deep learning | PyTorch |
| Environment | Gymnasium (custom env) |
| Algorithm | PPO (Proximal Policy Optimization) or DQN |
| Neural architecture | MLP policy / CNN policy (for pixel-based input) |
| Training logging | TensorBoard / Weights & Biases |
| Game engine interface | Pygame / custom Python game logic |
| Inference serving | FastAPI (for live demo endpoint) |

#### Key skills demonstrated

- Reward shaping and exploration strategy design
- Policy gradient methods and Q-learning theory
- Custom environment design following Gymnasium API
- Training loop engineering (vectorized environments, gradient clipping)
- Evaluation methodology: ELO ratings, win-rate curves, human baselines

#### Resume hook

> "Trained a PPO agent from scratch on a custom Gymnasium environment — no hand-crafted heuristics — achieving a 73% win rate against human testers after 2M training steps, with reward curves logged in W&B."

---

### 3. Distributed Vector Search Engine

**Elevator pitch:** A Pinecone-lite built in Rust — approximate nearest-neighbor search with HNSW indexing, distributed sharding via Raft consensus, querying 1M vectors in under 10ms.

**Why it stands out:** Combines systems programming, ML infrastructure, and distributed systems. The kind of project that differentiates candidates at top-tier companies focused on infra, search, or AI tooling.

#### What it does

- Implements HNSW (Hierarchical Navigable Small World) graph index in Rust for ANN search
- Uses SIMD intrinsics for vectorized cosine/dot-product distance computation
- Shards index across multiple nodes with consistent hashing
- Implements Raft consensus for leader election and log replication across shards
- Exposes a gRPC API for upsert, query, and delete operations
- Benchmarks query latency and recall@K against brute-force and FAISS baselines

#### Tech stack

| Layer | Technology |
|---|---|
| Language | Rust |
| ANN algorithm | HNSW (implemented from scratch) |
| SIMD acceleration | `std::arch` intrinsics (AVX2) |
| Distributed consensus | Raft (via `openraft` crate or custom) |
| Node communication | gRPC (`tonic` crate) |
| Serialization | Protocol Buffers |
| Consistent hashing | Custom ring implementation |
| Benchmarking | Criterion.rs |
| Client SDK | Python bindings via PyO3 |

#### Key skills demonstrated

- Systems programming and memory management in Rust
- Algorithm implementation: HNSW graph construction and search
- SIMD-level performance optimization
- Distributed systems: consensus, replication, partitioning
- API design (gRPC + Protobuf)
- Rigorous benchmarking methodology

#### Resume hook

> "Built a distributed ANN search engine in Rust — HNSW index with AVX2 SIMD distance computation, Raft-based sharding across 3 nodes — achieving p99 query latency of 8ms on 1M 768-dim vectors."

---

## A Tier — Strong Signal

> Full-stack projects with strong product narratives and real technical complexity. Solid for all engineering interviews.

---

### 4. UnAlone — Worldwide Loneliness App

**Elevator pitch:** A social platform for the loneliness epidemic — find real people planning real meetups nearby, coordinate in real-time, build trust through a reputation system, and stay safe through multi-layer verification.

**Why it stands out:** Strong narrative hook (the loneliness crisis is widely covered), genuine product complexity (trust scoring is a hard problem), and a modern full-stack architecture with real deployment.

#### What it does

- Shows a live map of "hotspots" — locations where people have posted planned meetups
- Clusters nearby events using geohash-based spatial grouping
- Provides a per-room real-time chat for meetup coordination
- Implements a trust score system: verified email, phone, government ID, and social proof from past meetups
- Anti-scam verification: flagging patterns, report system, community moderation queue
- Friend graph with trust propagation (friends-of-friends trust boost)
- Push notifications for nearby meetup activity

#### Tech stack

| Layer | Technology |
|---|---|
| Frontend | React + TypeScript, Mapbox GL JS / Leaflet |
| State management | Zustand / React Query |
| Backend API | Go (Gin or Echo framework) |
| Real-time chat | WebSocket (Go `gorilla/websocket`) |
| Pub/Sub | Redis Pub/Sub (fan-out chat messages to connected clients) |
| Session cache | Redis |
| Primary database | PostgreSQL with PostGIS extension (geospatial queries) |
| Auth | JWT + refresh tokens, OAuth2 (Google/Apple) |
| File storage | Amazon S3 (profile photos, verification docs) |
| Deployment | Amazon EC2, Nginx reverse proxy |
| Background jobs | Go worker goroutines / Redis queue |

#### Key skills demonstrated

- Real-time systems: WebSocket connection management, Redis pub/sub fan-out
- Geospatial data: PostGIS queries, geohash clustering
- Trust and reputation algorithm design
- Auth security: token rotation, rate limiting, abuse detection
- Full production deployment on AWS

#### Resume hook

> "Built a real-time social platform in Go + React with WebSocket chat, PostGIS geospatial hotspot clustering, Redis pub/sub fan-out, and a trust-score reputation system with multi-layer identity verification — deployed on EC2."

---

### 5. Lightweight Map Engine

**Elevator pitch:** A cross-platform map renderer built on OpenStreetMap vector tiles — 60fps pan/zoom on mid-range Android with under 15MB memory footprint, no Google Maps dependency.

**Why it stands out:** Native mobile performance work is rare and highly valued. Cross-platform delivery (Android + iOS + React Native) with real benchmarks is a strong differentiator at mobile-focused companies.

#### What it does

- Parses Mapbox Vector Tile (MVT) binary format (.pbf) on-device
- Renders tile layers using the platform's native 2D canvas APIs
- Implements smooth tile caching with LRU eviction to stay within memory budget
- Handles zoom-level-dependent style rules (line width, label visibility, layer ordering)
- Pre-fetches adjacent tiles on scroll prediction to eliminate loading flicker
- Provides a minimal public API: `MapView`, `addMarker`, `setCenter`, `flyTo`

#### Tech stack

| Layer | Technology |
|---|---|
| Android | Jetpack Compose + Canvas API, Kotlin |
| iOS | SwiftUI + Core Graphics / Metal, Swift |
| Cross-platform | React Native + Skia (via `@shopify/react-native-skia`) |
| Tile source | OpenStreetMap via a self-hosted or public tile server |
| Tile format | Mapbox Vector Tiles (MVT / .pbf), parsed with `protobuf` |
| Style spec | Subset of Mapbox GL Style Spec |
| Tile cache | LRU in-memory + SQLite disk cache |
| Networking | Platform HTTP client with conditional GET (ETag caching) |
| Benchmarking | Android Macrobenchmark, XCTest Performance |

#### Key skills demonstrated

- Native mobile graphics programming (Canvas, Core Graphics, Skia)
- Binary protocol parsing (Protocol Buffers)
- Memory-constrained performance optimization
- Cross-platform architecture design
- Tile-based rendering pipeline

#### Resume hook

> "Built a cross-platform map renderer (Jetpack Compose, SwiftUI, React Native) on OpenStreetMap vector tiles — 60fps rendering with LRU tile caching under 15MB, no third-party map SDK dependency."

---

### 6. Real-time Collaborative Code Editor

**Elevator pitch:** Google Docs for code — conflict-free concurrent editing using Yjs CRDTs, peer-to-peer sync via WebRTC, Monaco editor, with live awareness cursors showing collaborators in real time.

**Why it stands out:** CRDTs are academically rigorous and practically relevant. Demonstrates distributed systems thinking, deep understanding of consistency models, and real product utility.

#### What it does

- Implements conflict-free shared document state using `Y.Text` (Yjs YATA CRDT)
- Syncs document state peer-to-peer via WebRTC (`y-webrtc`) with a WebSocket fallback for NAT traversal
- Persists document history to IndexedDB for offline editing (`y-indexeddb`)
- Binds the Yjs shared type to Monaco Editor via `y-monaco` binding
- Broadcasts ephemeral awareness state (cursor position, selection, username, color) to all peers
- Renders remote cursors and selections as Monaco editor decorations
- Supports multiple files via namespaced `Y.Doc` instances

#### Tech stack

| Layer | Technology |
|---|---|
| CRDT library | Yjs (`yjs` package) |
| Sync transport | WebRTC (`y-webrtc`), WebSocket fallback (`y-websocket`) |
| Offline persistence | IndexedDB (`y-indexeddb`) |
| Code editor | Monaco Editor (`monaco-editor`) |
| Editor binding | `y-monaco` |
| Presence/awareness | Yjs Awareness protocol |
| Frontend | React + TypeScript |
| Signaling server | Node.js + `ws` (WebRTC signaling only, not in document path) |
| Styling | Tailwind CSS |

#### Key skills demonstrated

- CRDT theory: YATA algorithm, state-based vs operation-based merging
- Distributed consistency without a coordinator
- WebRTC peer-to-peer data channels
- Offline-first architecture
- Complex Monaco Editor integration

#### Resume hook

> "Built a peer-to-peer collaborative code editor using Yjs CRDTs and WebRTC — conflict-free concurrent edits, IndexedDB offline persistence, live awareness cursors via Monaco decorations — no central document server required."

---

## B Tier — Solid + Polish

> Strong technical angle when framed correctly. Lead with the hard problem, not the feature.

---

### 7. Shazam Clone — Audio Fingerprinting Engine

**Elevator pitch:** Implements the Wang 2003 audio fingerprinting algorithm from the paper — FFT spectrogram, constellation peak extraction, and hash-based matching — identifying songs from noisy 5-second clips.

**Why it stands out:** Citing the original academic paper immediately elevates this from "fun clone" to "I read research papers and implemented algorithms." Include accuracy benchmarks vs noise level.

#### What it does

- Records or loads an audio clip and computes its Short-Time Fourier Transform (STFT)
- Generates a spectrogram and extracts peak constellation points (local maxima in time-frequency space)
- Creates combinatorial hash pairs: `hash(freq1, freq2, delta_t)` — robust to noise and tempo shifts
- Stores hashes in an inverted index: `hash → [(song_id, time_offset)]`
- Matches a query clip by looking up its hashes and voting by time-offset coherence
- Returns a ranked list of candidate songs with match confidence scores
- Benchmarks recall and precision across SNR levels (clean, +10dB, +5dB, 0dB noise)

#### Tech stack

| Layer | Technology |
|---|---|
| Language | Python (primary), optional C extension for FFT hot path |
| Signal processing | NumPy, SciPy (`scipy.signal.spectrogram`, STFT) |
| FFT | NumPy FFT / PyFFTW (faster) |
| Peak detection | SciPy `find_peaks` with local maxima neighborhood filter |
| Hash storage | SQLite (development) / Redis hash index (production scale) |
| Audio I/O | `librosa`, `sounddevice`, `pydub` |
| Visualization | Matplotlib (spectrogram plots, constellation maps) |
| API | FastAPI (query endpoint) |
| Frontend demo | React + Web Audio API |

#### Key skills demonstrated

- Digital signal processing: STFT, spectrogram analysis, windowing functions
- Algorithm implementation from academic paper (Wang 2003)
- Hash-based indexing and inverted index design
- Evaluation methodology: precision/recall curves across noise conditions
- Audio I/O pipeline

#### Upgrade path to A tier

Add locality-sensitive hashing (LSH) for approximate hash matching, enabling recognition of pitch-shifted or time-stretched versions. This transforms it from an exact lookup into a proper approximate similarity search problem.

#### Resume hook

> "Implemented the Wang 2003 audio fingerprinting algorithm — STFT spectrogram, constellation peak extraction, combinatorial hash index — achieving 91% recall on 5s clips at 0dB SNR with a SQLite inverted index."

---

### 8. Selfie Storyboard

**Elevator pitch:** A mobile app that transforms a selfie into a narrative storyboard — identity-preserving face embeddings keep the person consistent across generated panels, with style coherence via ControlNet + IP-Adapter.

**Why it stands out:** GenAI is everywhere, but identity preservation across generated frames is a genuinely hard computer vision problem. Frame the project around that, not the "fun app" angle.

#### What it does

- Takes a selfie and extracts a face embedding using a recognition model (ArcFace / InsightFace)
- Uses IP-Adapter to condition the image generation on the identity embedding
- Applies ControlNet (pose / depth conditioning) to maintain consistent character posture across panels
- Generates a 4-6 panel storyboard from a text prompt describing the narrative
- Post-processes panels with consistent color grading for visual coherence
- Mobile UI for capture, prompt input, and swipeable storyboard output

#### Tech stack

| Layer | Technology |
|---|---|
| Face embedding | InsightFace / ArcFace (identity extraction) |
| Image generation | Stable Diffusion XL via `diffusers` |
| Identity conditioning | IP-Adapter (image prompt adapter for SD) |
| Pose/structure control | ControlNet (OpenPose or depth map) |
| CLIP guidance | OpenCLIP (style and semantic consistency) |
| Inference backend | Python + FastAPI, GPU inference (CUDA) |
| Mobile frontend | React Native |
| Image handling | `Pillow`, `torchvision` |
| Model hosting | Replicate API or self-hosted on GPU VM |

#### Key skills demonstrated

- Diffusion model conditioning: IP-Adapter, ControlNet
- Face recognition and embedding extraction
- Inference pipeline optimization (model batching, fp16, attention slicing)
- Mobile + ML backend integration
- Prompt engineering for narrative coherence

#### Upgrade path to A tier

Add per-user LoRA fine-tuning on 10–20 photos of the user's face. This personalizes the model weights rather than just conditioning — dramatically improves identity fidelity and is a much harder ML problem.

#### Resume hook

> "Built a mobile storyboard generator using SD-XL + IP-Adapter for identity-preserving face conditioning and ControlNet for pose consistency — maintaining character identity across 6 generated panels from a single selfie."

---

## Resume Strategy

### General principles

- Lead with the hard problem, not the feature set. "Built a DDoS map" is a feature. "Classifies IPs using a behavioral ML model scoring packet-rate anomalies" is a problem.
- Cite numbers everywhere: latency (p99), throughput (events/sec), accuracy (AUC, recall@K), scale (vector count, concurrent users). Even approximate benchmarks beat no benchmarks.
- Name academic papers when you implement algorithms. "Wang 2003 audio fingerprinting" is more credible than "audio fingerprinting."
- Order your resume projects by tier: S → A → B. Never lead with a CRUD app.
- Tailor per role: for ML roles, lead with the RL agent and DDoS classifier; for systems roles, lead with the vector search engine; for mobile roles, lead with the map engine.

### Project ordering by role type

| Target role | Lead project | Second project |
|---|---|---|
| ML / AI engineer | Neural Network Game Agent | Live DDoS Attack Map |
| Backend / systems | Distributed Vector Search Engine | Collaborative Code Editor |
| Mobile engineer | Lightweight Map Engine | Selfie Storyboard |
| Full-stack | UnAlone App | Collaborative Code Editor |
| Security / infra | Live DDoS Attack Map | Distributed Vector Search Engine |

### What to avoid

- Generic CRUD apps with no hard technical constraint
- Weather / news API wrappers (pure integration, no original engineering)
- Any project where "React + Node + MongoDB" is the entire story
- Clones without a specific technical twist called out explicitly

---

*Last updated: 2026*