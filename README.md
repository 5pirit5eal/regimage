# RegImage
Repository with a image registration algorithm implemented in c++.

## Goal
The following goals were defined for the tool. The tool should in the end be available as a docker image.

| Goals                               | Requirements                                                                                                                                                           | Tools |
|-------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------|
| Registration of two images          | 1. Provide images to program<br>2. Load images using tool<br>3. Create moving and fixed image<br>4. Register fixed on moving using tool<br>5. Provide moving to system |       |
| Configurable registration algorithm | 1. Implement registration<br>2. Implement regularization<br>3. Implement configuration                                                                                 |       |
| Integrate into Docker               | 1. Create REST interface for images<br>2. Integrate algorithm<br>3. Show to friends and family                                                                         |       |
| Make N-Dimensional Data work        | 1. Implement 3D registration<br>2. Implement 4D consistent registration<br>3. Cry                                                                                      |       |